# Oliver Kullmann, 10.4.2005 (Swansea)

SHELL = /bin/sh
.SUFFIXES :

# the main definition of OKsystem is given in makefile_generic, and should (somehow) be imported from there (the problem however is, that OKBuildsystem is not known without OKsystem);
# at the moment we use cut and paste.
ifndef OKplatform
  ifdef OKPLATFORM
    OKplatform := $(OKPLATFORM)
  else
    $(error Either OKplatform (a make-variable) or OKPLATFORM (an environment-variable) must be defined when calling this makefile!)
  endif
endif

ifndef OKsystem
  ifdef OKSYSTEM
    OKsystem := $(OKSYSTEM)
  else
    OKsystem := $(OKplatform)/OKsystem
  endif
endif

# main definition in makefile_generic cut and paste
OKBuildsystem := $(OKsystem)/Transitional/Buildsystem

export

include $(OKBuildsystem)/makefile_standardgoals.mak

export

include $(OKBuildsystem)/makefile_recursive_noneincluded.mak

