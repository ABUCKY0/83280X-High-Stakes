################################################################################
######################### User configurable parameters #########################
# filename extensions
CEXTS:=c
ASMEXTS:=s S
CXXEXTS:=cpp c++ cc

# probably shouldn't modify these, but you may need them below
ROOT=.
FWDIR:=$(ROOT)/firmware
BINDIR=$(ROOT)/bin
SRCDIR=$(ROOT)/src
INCDIR=$(ROOT)/include
EXTRA_INCDIR=$(ROOT)/include/packages

# create macros for compile info
# const char* build_date = "2024-09-06 19:40:07";
# const char* git_branch = "develop";
# const char* git_commit = "b744993be84b89f67b934cbf84bfac953517b167";
# const char* compiler_version = "arm-none-eabi-g++.exe (GNU Arm Embedded Toolchain 10.3-2021.10) 10.3.1 20210824 (release)";
# const char* build_environment = "Build on MSYS_NT-10.0-22631, x86_64";
# const int build_number = 11;
# const char* developer_name = "ABUCKY0";
# const char* application_environment = "alpha";
# const char* codebase_version = "0.0.5";

BUILD_DATE:=$(shell date "+%Y-%m-%d %H:%M:%S")
GIT_BRANCH:=$(shell git rev-parse --abbrev-ref HEAD)
GIT_COMMIT:=$(shell git rev-parse HEAD)
COMPILER_VERSION:=$(shell arm-none-eabi-g++ --version | head -n 1 | sed 's/(/\\(/g' | sed 's/)/\\)/g')
BUILD_ENVIRONMENT:=$(shell uname -a | sed 's/(/\\(/g' | sed 's/)/\\)/g')
BUILD_NUMBER:=$(shell cat $(SRCDIR)/AutonomousSelector/BuildInfo/build_number.txt)
$(shell echo $$(($(BUILD_NUMBER) + 1)) > $(SRCDIR)/AutonomousSelector/BuildInfo/build_number.txt)
DEVELOPER_NAME:=ABUCKY0
APPLICATION_ENVIRONMENT:=alpha
CODEBASE_VERSION:=0.0.5


WARNFLAGS+=
EXTRA_CFLAGS= -D_PROS_INCLUDE_LIBLVGL_LLEMU_H -D_PROS_INCLUDE_LIBLVGL_LLEMU_HPP
EXTRA_CXXFLAGS= -D_PROS_INCLUDE_LIBLVGL_LLEMU_H -D_PROS_INCLUDE_LIBLVGL_LLEMU_HPP -DBUILD_DATE="\"$(BUILD_DATE)\"" -DGIT_BRANCH="\"$(GIT_BRANCH)\"" -DGIT_COMMIT="\"$(GIT_COMMIT)\"" -DCOMPILER_VERSION="\"$(COMPILER_VERSION)\"" -DBUILD_ENVIRONMENT="\"$(BUILD_ENVIRONMENT)\"" -DBUILD_NUMBER=$(BUILD_NUMBER) -DDEVELOPER_NAME="\"$(DEVELOPER_NAME)\"" -DAPPLICATION_ENVIRONMENT="\"$(APPLICATION_ENVIRONMENT)\"" -DCODEBASE_VERSION="\"$(CODEBASE_VERSION)\""
# Set to 1 to enable hot/cold linking
USE_PACKAGE:=1

# Add libraries you do not wish to include in the cold image here
# EXCLUDE_COLD_LIBRARIES:= $(FWDIR)/your_library.a
EXCLUDE_COLD_LIBRARIES:= 

# Set this to 1 to add additional rules to compile your project as a PROS library template
# TODO: SET TO 1 FOR LIBRARY
IS_LIBRARY:=0
LIBNAME:=highstakes
VERSION:=0.0.1-precompalpha
# EXCLUDE_SRC_FROM_LIB= $(SRCDIR)/unpublishedfile.c
# this line excludes opcontrol.c and similar files
EXCLUDE_SRC_FROM_LIB+=$(foreach file, $(SRCDIR)/main,$(foreach cext,$(CEXTS),$(file).$(cext)) $(foreach cxxext,$(CXXEXTS),$(file).$(cxxext)))

# files that get distributed to every user (beyond your source archive) - add
# whatever files you want here. This line is configured to add all header files
# that are in the the include directory get exported
TEMPLATE_FILES=$(INCDIR)/**/*.h $(INCDIR)/**/*.hpp

.DEFAULT_GOAL=quick

################################################################################
################################################################################
########## Nothing below this line should be edited by typical users ###########
-include ./common.mk
