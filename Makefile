SRCDIR = sources
SOURCES := $(wildcard $(SRCDIR)/*)
DSTDIR ?= dest
TARGET ?= $(DSTDIR)/diceware
USRCDIR = $(SRCDIR)/utils
UDSTDIR = $(DSTDIR)/utils
UTILS = text_to_array

$(TARGET): $(SOURCES) | $(DSTDIR)
	cc -std=c89 -o $(TARGET) $(SRCDIR)/diceware.c

$(DSTDIR):
	mkdir $(DSTDIR)

$(UDSTDIR):
	mkdir $(UDSTDIR)

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

text_to_array: $(USRCDIR)/text_to_array.h $(USRCDIR)/text_to_array.c | $(UDSTDIR)
	cc -std=c89 -o $(UDSTDIR)/text_to_array $(USRCDIR)/text_to_array.c

utils: $(UTILS)

.PHONY: clean info
