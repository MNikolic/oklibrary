-- Oliver Kullmann, 1.2.2002

/*
CREATE DATABASE OKRandGen
;
*/


CREATE TABLE Frames
(
        frame_id	SERIAL	NOT NULL,

        l		INT4[]	NOT NULL,
        CHECK(array_dims(l) IS NOT NULL AND l[1] > 0),
	dim		INT4	NOT NULL,
	CHECK(dim = to_number(substr(btrim(array_dims(l), '[]'), 3), '9999999999')),

        PRIMARY KEY(frame_id)
)
;

/*
	UNIQUE(l),
	CHECK(l[i] < l[i+1] for i : 1 .. array_dims(l)-1)

for each occurring dim there is a table bd_dim (see below);
*/



CREATE TABLE bd_1 -- boolean density
(
	m_dens_id	SERIAL			NOT NULL,
	CHECK(m_dens_id IS NOT NULL),
	frame_id	INT			REFERENCES Frames,
	CHECK(frame_id IS NOT NULL),

	d1		NUMERIC(20,10)		NOT NULL,
	CHECK(d1 > 0),

	PRIMARY KEY(m_dens_id),
	UNIQUE(frame_id, d1)
)
;

/*
	CHECK(frame_id -> dim = 1)
*/

-- The accurracy NUMERIC(20,10) is sufficient to store standardised densities.


CREATE TABLE bd_2
(
	m_dens_id	SERIAL			NOT NULL,
	CHECK(m_dens_id IS NOT NULL),
	frame_id	INT			REFERENCES Frames,
	CHECK(frame_id IS NOT NULL),

	d1		NUMERIC(20,10)		NOT NULL,
	CHECK(d1 > 0),
	d2		NUMERIC(20,10)		NOT NULL,
	CHECK(d2 > 0),

	PRIMARY KEY(m_dens_id),
	UNIQUE(frame_id, d1, d2)
)
;

/*
	CHECK(m_dens_id -> dim = 2),
	CHECK(frame_id -> dim = 2)
*/


CREATE TABLE bcls_current_key
(
	key0	INT4	NOT NULL,
	key1	INT4	NOT NULL,
	active	BOOL	NOT NULL,
	UNIQUE(active)
)
;

/* only when using for the first time
INSERT INTO bcls_current_key VALUES(0, 0, 'true')
;
*/

CREATE TABLE gcls_current_key
(
	key0	INT4	NOT NULL,
	key1	INT4	NOT NULL,
	active	BOOL	NOT NULL,
	UNIQUE(active)
)
;

/* only when using for the first time
INSERT INTO gcls_current_key VALUES(0, 0, 'true')
;
*/


CREATE TABLE bcls         -- boolean clause-sets
(
        cls_id		SERIAL		NOT NULL,

	key0		INT4		DEFAULT 0,
	key1		INT4		DEFAULT 0,

        nr0		INT4		DEFAULT 0,
        nr1		INT4		DEFAULT 0,

        n		INT4		NOT NULL,
        CHECK(n > 0),

        m_dens_id	INT		NOT NULL,
        dim		INT4		NOT NULL,
	CHECK(dim > 0),

        sat		BOOLEAN		NOT NULL,

        PRIMARY KEY(cls_id),
        UNIQUE(key0, key1, nr0, nr1, n, m_dens_id, dim) 
)
;

/*
	m_dens_id references table bd_dim;

key0/1 and nr0/1 are originally unsigned 4-byte numbers, and have to be
transformed by a standard procedure.
Densities are *standardised* densities!

*/



CREATE TABLE gcls         -- generalised clause-sets
(
	gcls_id		SERIAL		NOT NULL,

	key0		INT4		DEFAULT 0,
	key1		INT4		DEFAULT 0,

        nr1		INT4		DEFAULT 0,

        n		INT4		NOT NULL,
        CHECK(n != 0),

        d		INT4		NOT NULL,
        CHECK(d != 0),

        m_dens_id	INT		NOT NULL,
        dim		INT4		NOT NULL,
	CHECK(dim > 0),

        sat		BOOLEAN		NOT NULL,

        PRIMARY KEY(gcls_id),
        UNIQUE(key0, key1, nr1, n, d, m_dens_id, dim)
)
;


/* 

key0/1, nr1, n and d are originally unsigned 4-byte numbers, and have to be
transformed by a standard procedure.
The values of l (clause length) in Density_Values are restricted to the interval [0, 2147483647], while from the definition of OKgenerator they could have values in [0, 4294967295] for generalised clause-sets --- however this doesn't look like a severe restriction to me (at this time, at least).

*/


CREATE TABLE Persons
(
	person_id	SERIAL		NOT NULL,
	first_name	TEXT		NULL,
	last_name	TEXT		NOT NULL,
	country		TEXT		NULL,
	e_mail		TEXT		NOT NULL,
        CHECK(e_mail != ''),
	www		TEXT		NULL,

	PRIMARY KEY(person_id),
	UNIQUE(first_name, last_name, e_mail)
)
;

CREATE TABLE Computers
(
        comp_id		SERIAL		NOT NULL,

        name		TEXT		NOT NULL, -- e.g.. 'csoklt'
        domain		TEXT		NULL, -- e.g. 'swan.ac.uk'
	registration	TIMESTAMP	NOT NULL,

        cpu_name	TEXT		NULL, -- e.g. 'Pentium P3'

        cpu_mhz		DECIMAL(9,3)	NULL,
        CHECK (cpu_mhz > 0),

        cache_l1_kb	INT		NULL,
        CHECK (cache_l1_kb > 0),
        cache_l2_kb	INT		NULL,
        CHECK (cache_l2_kb > 0),

        main_mem_mb	INT		NULL,
        CHECK (main_mem_mb > 0),

	sec_mem_type	TEXT		NULL, -- secondary memory (hard disks, ...)
	sec_mem_gb	DECIMAL(7,2)	NULL,

	model		TEXT		NULL, -- e.g. 'Ultinet 3100 C'
        comment		TEXT		NULL,

        PRIMARY KEY(comp_id),
	UNIQUE(name, domain, registration)
)
;


CREATE TABLE Solvers
(
        solv_id		SERIAL		NOT NULL,

        base_name	TEXT		NOT NULL,
	exec_name	TEXT		NOT NULL,

        version		TEXT		NULL,
        options		TEXT		NULL, -- further specification

        person_id	INT		REFERENCES Persons,
	CHECK(person_id IS NOT NULL),

        comment		TEXT		NULL,

        internal	BOOLEAN		NOT NULL, 
	-- whether the solver is only for internal purposes

        PRIMARY KEY(solv_id),
        UNIQUE(base_name, exec_name, version, options)
)
;


CREATE TABLE Sources
(
        source_id	SERIAL		NOT NULL,
        person_id	INT		REFERENCES Persons,
	CHECK(person_id IS NOT NULL),

        date		TIMESTAMP	NOT NULL,

        PRIMARY KEY(source_id),
        UNIQUE(person_id, date)
)
;


CREATE TABLE Experiments
(
        exp_id		SERIAL		NOT NULL,

        date_begin	TIMESTAMP	NOT NULL,
	date_end	TIMESTAMP	NOT NULL,

        comp_id		INT		REFERENCES Computers,
	CHECK(comp_id IS NOT NULL),
        solv_id		INT		REFERENCES Solvers,
	CHECK(solv_id IS NOT NULL),
        comment		TEXT		NULL,
        is_local	BOOLEAN		NOT NULL,
        source_id	INT		REFERENCES Sources,

        PRIMARY KEY(exp_id),
        CHECK(is_local OR source_id IS NOT NULL)
)
;


CREATE TABLE bcls_info
(
	b_info_id	SERIAL		NOT NULL,

        cls_id		INT		REFERENCES bcls,
        CHECK(cls_id IS NOT NULL),
        exp_id		INT		REFERENCES Experiments,
        CHECK(exp_id IS NOT NULL),

	sec		DECIMAL(12,2)	NULL, -- core running time
	CHECK(sec >= 0),
	tree_depth	INT		NULL, -- maximal tree depth
	CHECK(tree_depth >= 0),
	pure_literals	DECIMAL(11,0)	NULL,
	CHECK(pure_literals >= 0),
	real_autarkies	DECIMAL(11,0)	NULL,
	CHECK(real_autarkies >= 0),
	nodes		DECIMAL(11,0)	NULL,
	CHECK(nodes >= 0),
	single_nodes	DECIMAL(11,0)	NULL,
	CHECK(single_nodes >= 0),
	quasi_s_nodes	DECIMAL(11,0)	NULL,
	CHECK(quasi_s_nodes >= 0),
	missed_s_nodes	DECIMAL(11,0)	NULL,
	CHECK(missed_s_nodes >= 0),

	an		INT4		NULL, -- actual n
	CHECK(an >= 0),

 	PRIMARY KEY(b_info_id),
        UNIQUE(cls_id, exp_id)
)
;

/* ATTENTION:

The solver output for the running time may not have more than two digits after the decimal point, otherwise it can not be checked correctly whether an entry for bcls_info is already present.

*/


CREATE TABLE gcls_info
(
	g_info_id	SERIAL		NOT NULL,

        gcls_id		INT		REFERENCES gcls,
        CHECK(gcls_id IS NOT NULL),
        exp_id		INT		REFERENCES Experiments,
        CHECK(exp_id IS NOT NULL),

	sec		DECIMAL(12,2)	NULL, -- core running time
	CHECK(sec >= 0),
	tree_depth	INT		NULL, -- maximal tree depth
	CHECK(tree_depth >= 0),
	pure_literals	DECIMAL(11,0)	NULL,
	CHECK(pure_literals >= 0),
	real_autarkies	DECIMAL(11,0)	NULL,
	CHECK(real_autarkies >= 0),
	nodes		DECIMAL(11,0)	NULL,
	CHECK(nodes >= 0),
	single_nodes	DECIMAL(11,0)	NULL,
	CHECK(single_nodes >= 0),
	quasi_s_nodes	DECIMAL(11,0)	NULL,
	CHECK(quasi_s_nodes >= 0),
	missed_s_nodes	DECIMAL(11,0)	NULL,
	CHECK(missed_s_nodes >= 0),

	PRIMARY KEY(g_info_id),
        UNIQUE(gcls_id, exp_id)
)
;


CREATE TABLE g_measures
(
	g_info_id	INT		REFERENCES gcls_info,
	CHECK(g_info_id IS NOT NULL),

-- reductions:

	taut_c		BOOL		NOT NULL,
	mult_l		BOOL		NOT NULL,
	mult_c		BOOL		NOT NULL,
	unit_c		BOOL		NOT NULL,
	CHECK(n >= 0),

	n		INT4		NULL,
	CHECK(n >= 0),
	c		INT4		NULL,
	CHECK(c >= 0),
	l		INT4		NULL,
	CHECK(l >= 0),
	pmin		INT4		NULL,
	CHECK(pmin >= 0),
	pmax		INT4		NULL,
	CHECK(pmax >= 0),

	UNIQUE(g_info_id, taut_c, mult_l, mult_c, unit_c),
	CHECK(n IS NOT NULL OR c IS NOT NULL OR l IS NOT NULL OR pmin IS NOT NULL OR pmax IS NOT NULL)

)
;


CREATE TABLE b_unit_reductions
(
	b_info_id	INT		REFERENCES bcls_info,
	CHECK(b_info_id IS NOT NULL),

	u_level		INT		NOT NULL,
	CHECK(u_level > 0),
	u_count		DECIMAL(11,0)	NOT NULL,
	CHECK(u_count >= 0),

	UNIQUE(b_info_id, u_level)
)
;

CREATE TABLE g_unit_reductions
(
	g_info_id	INT		REFERENCES gcls_info,
	CHECK(g_info_id IS NOT NULL),

	u_level		INT		NOT NULL,
	CHECK(u_level > 0),
	u_count		DECIMAL(11,0)	NOT NULL,
	CHECK(u_count >= 0),

	UNIQUE(g_info_id, u_level)
)
;


CREATE TABLE b_autarky_reductions
(
	b_info_id	INT		REFERENCES bcls_info,
	CHECK(b_info_id IS NOT NULL),

	a_level		INT		NOT NULL,
	CHECK(a_level >= 1),
	a_count		DECIMAL(11,0),
	CHECK(a_count >= 0),

	UNIQUE(b_info_id, a_level)
)
;

CREATE TABLE g_autarky_reductions
(
	g_info_id	INT		REFERENCES gcls_info,
	CHECK(g_info_id IS NOT NULL),

	a_level		INT		NOT NULL,
	CHECK(a_level >= 1),
	a_count		DECIMAL(11,0),
	CHECK(a_count >= 0),

	UNIQUE(g_info_id, a_level)
)
;



CREATE TABLE b_new_clauses
(
	b_info_id	INT		REFERENCES bcls_info,
	CHECK(b_info_id IS NOT NULL),

	type		CHAR(1)		NOT NULL,
	CHECK(type = 'l' OR type = 'g'),
	specifier	CHAR(1)		NOT NULL,
	CHECK(specifier = 'm' OR specifier = 't'),
	length		INT4		NOT NULL,
	CHECK(length > 0),

	n_count		DECIMAL(11,0)	NOT NULL,
	CHECK(n_count >= 0),

	UNIQUE(b_info_id, type, specifier, length)
)
;
/*
l : local
g : global

m : maximum
t : total sum
*/

CREATE TABLE g_new_clauses
(
	g_new_cl_id	SERIAL		NOT NULL,

	g_info_id	INT		REFERENCES gcls_info,
	CHECK(g_info_id IS NOT NULL),

	type		CHAR(1)		NOT NULL,
	CHECK(type = 'l' OR type = 'g'),
	specifier	CHAR(1)		NOT NULL,
	CHECK(specifier = 'm' OR specifier = 't'),
	length		INT4		NOT NULL,
	CHECK(length > 0),

	n_count		DECIMAL(11,0)	NOT NULL,
	CHECK(n_count >= 0),

	UNIQUE(g_info_id, type, specifier, length)
)
;


CREATE FUNCTION b2i (BOOL)
RETURNS INT
AS 'SELECT CASE $1 WHEN ''true'' THEN 1 WHEN ''false'' THEN 0 ELSE NULL END;'
LANGUAGE 'SQL'
WITH (ISCACHABLE, ISSTRICT);


CREATE TABLE SatUnsatAggregates
(
	key0		INT4		NOT NULL,
	key1		INT4		NOT NULL,

        nr0_begin	INT4		NOT NULL,
        nr1_begin	INT4		NOT NULL,
        nr0_end		INT4		NOT NULL,
        nr1_end		INT4		NOT NULL,

        n		INT4		NOT NULL,
        CHECK(n > 0),

        m_dens_id	INT		NOT NULL,
        dim		INT4		NOT NULL,
	CHECK(dim > 0),

-- m_dens_id references table bd_dim

	exp_id		INT		REFERENCES Experiments,
	CHECK(exp_id IS NOT NULL),

	count_all	INT		NOT NULL,
	CHECK(count_all > 0),
-- count_all = ( (nr0_end * 2^32 + nr1_end) - (nr0_begin * 2^32 + nr1_begin) + 1)
	count_sat	INT		NOT NULL,
	CHECK(count_sat > 0 AND count_sat <= count_all),

	stored_sat	BOOL		NOT NULL,
	stored_unsat	BOOL		NOT NULL,

	UNIQUE(key0, key1, nr0_begin, nr1_begin, nr0_end, nr1_end, n, m_dens_id, dim),
	UNIQUE(exp_id, n, m_dens_id, dim)
)
;


CREATE TABLE StatBasicp3	-- summary (averages except for d1, n, count, countwa, countws, countwq, maxnds, minnds, stdnds, mednds)
(
	d1	NUMERIC(20,10),
	n	INT4,
	nds	FLOAT,	-- average node count
	count	INT,
	depth	FLOAT,
	pl	FLOAT,	-- pure literals
	aut	FLOAT,	-- autarkies
	sn	FLOAT,	-- single nodes
	qsn	FLOAT,	-- quasi-single nodes
	l2r	FLOAT,	-- level-2 reductions
	an	FLOAT,	-- actual n
	countwa	INT,	-- count with autarkies
	ndswa	FLOAT,	-- nds with autarkies
	countws	INT,	-- count with single-nodes
	ndsws	FLOAT,	-- nds with single-nodes
	countwq	INT,	-- count with quasi-single-nodes
	ndswq	FLOAT,	-- nds with quasi-single-nodes
	maxnds	FLOAT,	-- maximum node count
	minnds	FLOAT,	-- minimum node count
	stdnds	FLOAT,	-- standard deviation node count
	mednds	FLOAT	-- median node count
)
;


CREATE TABLE StatUnsatp3	-- additional information for unsatisfiable formulas
(
	prm	FLOAT	-- probability of minimal complexity
)
INHERITS (StatBasicp3);
;


CREATE TABLE StatSatp3	-- summary (averages except for d1, n and count)
(
	trv	FLOAT,	-- probability of trivial complexity
	nb	FLOAT,	-- probability of no backtracking
	ndswb	FLOAT,	-- nds with backtracking
	nl2r	FLOAT	-- probability of no 2-reductions
)
INHERITS (StatBasicp3);
;


CREATE TABLE ProbSatp3
(
	d1	NUMERIC(20,10),
	n	INT4,
	sat	FLOAT,
	c	INT
)
;


CREATE TABLE Computers_bogomips
(
	bmps_id		SERIAL 		NOT NULL,

	comp_id		INT		REFERENCES Computers,
        CONSTRAINT comp_id CHECK(comp_id IS NOT NULL),

        bogomips	DECIMAL(10,4)	NOT NULL,
	CONSTRAINT bogomips CHECK (bogomips > 0),

        PRIMARY KEY(bmps_id),
	UNIQUE(comp_id)
)
;
