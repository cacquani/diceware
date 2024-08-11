SRCDIR = sources
SOURCES := $(wildcard $(SRCDIR)/*)
DSTDIR ?= dest
TARGET ?= $(DSTDIR)/diceware

$(TARGET): $(SOURCES) | $(DSTDIR)
	cc -std=c89 -o $(TARGET) $(SRCDIR)/diceware.c

$(DSTDIR):
	mkdir $(DSTDIR)

info:
	echo "MAKEFILE_LIST=$(MAKEFILE_LIST)"
	echo ".DEFAULT_GOAL=$(.DEFAULT_GOAL)"
	echo ".RECIPEPREFIX='$(.RECIPEPREFIX)'"
	echo ".VARIABLES=$(.VARIABLES)"
	echo ".INCLUDE_DIRS=$(.INCLUDE_DIRS)"
	echo ".EXTRA_PREREQS=$(.EXTRA_PREREQS)"
	echo "ARGS=$(ARGS)"
	echo ".FEATURES=$(.FEATURES)"

clean:
ifneq "$(filter-out $(SOURCES),$(TARGET))" ""
	-rm $(TARGET)
	-rm -r $(DSTDIR)
endif

.PHONY: clean info
