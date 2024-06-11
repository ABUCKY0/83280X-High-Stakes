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

WARNFLAGS+=
EXTRA_CFLAGS=
EXTRA_CXXFLAGS=

# Set to 1 to enable hot/cold linking
USE_PACKAGE:=1

# Add libraries you do not wish to include in the cold image here
# EXCLUDE_COLD_LIBRARIES:= $(FWDIR)/your_library.a
EXCLUDE_COLD_LIBRARIES:= 

# Set this to 1 to add additional rules to compile your project as a PROS library template
IS_LIBRARY:=0
# TODO: CHANGE THIS!
LIBNAME:=PostCompTests
VERSION:=0.0.5
# EXCLUDE_SRC_FROM_LIB= $(SRCDIR)/unpublishedfile.c
# this line excludes opcontrol.c and similar files
EXCLUDE_SRC_FROM_LIB+=$(foreach file, $(SRCDIR)/main,$(foreach cext,$(CEXTS),$(file).$(cext)) $(foreach cxxext,$(CXXEXTS),$(file).$(cxxext)))

# files that get distributed to every user (beyond your source archive) - add
# whatever files you want here. This line is configured to add all header files
# that are in the the include directory get exported
TEMPLATE_FILES=$(INCDIR)/**/*.h $(INCDIR)/**/*.hpp

################################################################################
# Build information
DEVELOPER_NAME := "ABUCKY0"
APPLICATION_ENVIRONMENT := "alpha"
CODEBASE_VERSION := "$(VERSION)"
BUILD_DATE := $(shell date "+%Y-%m-%d %H:%M:%S")
GIT_BRANCH := $(shell git rev-parse --abbrev-ref HEAD)
GIT_COMMIT := $(shell git rev-parse HEAD)
COMPILER_VER := $(shell arm-none-eabi-g++ --version | head -n 1)
BUILD_ENV := "Build on $(shell uname -s), $(shell uname -m)"
BUILD_NUMBER_FILE := $(SRCDIR)/AutonomousSelector/BuildInfo/build_number.txt
BUILD_NUMBER := $(shell if [ -f $(BUILD_NUMBER_FILE) ]; then echo $$(($$(cat $(BUILD_NUMBER_FILE)) + 1)); else echo 1; fi)
BUILD_INFO_SRC := $(SRCDIR)/AutonomousSelector/BuildInfo/build_info.c
# print incdir to console
$(info INCDIR: $(INCDIR)/AutonomousSelector/BuildInfo/build_info.h)
BUILD_INFO_HDR := $(INCDIR)/AutonomousSelector/BuildInfo/build_info.h

generate_build_info:
	@echo "Generating build info..."
	@echo "/* Automatically generated build information */" > $(BUILD_INFO_SRC)
	@echo "#include \"build_info.h\"" >> $(BUILD_INFO_SRC)
	@echo "const char* build_date = \"$(BUILD_DATE)\";" >> $(BUILD_INFO_SRC)
	@echo "const char* git_branch = \"$(GIT_BRANCH)\";" >> $(BUILD_INFO_SRC)
	@echo "const char* git_commit = \"$(GIT_COMMIT)\";" >> $(BUILD_INFO_SRC)
	@echo "const char* compiler_version = \"$(COMPILER_VER)\";" >> $(BUILD_INFO_SRC)
	@echo "const char* build_environment = \"$(BUILD_ENV)\";" >> $(BUILD_INFO_SRC)
	@echo "const int build_number = $(BUILD_NUMBER);" >> $(BUILD_INFO_SRC)
	@echo "const char* developer_name = \"$(DEVELOPER_NAME)\";" >> $(BUILD_INFO_SRC)
	@echo "const char* application_environment = \"$(APPLICATION_ENVIRONMENT)\";" >> $(BUILD_INFO_SRC)
	@echo "const char* codebase_version = \"$(CODEBASE_VERSION)\";" >> $(BUILD_INFO_SRC)
	@echo $(BUILD_NUMBER) > $(BUILD_NUMBER_FILE)

generate_build_info:  # Call the target immediately after its definition

.DEFAULT_GOAL=quick
quick: generate_build_info
-include ./common.mk
