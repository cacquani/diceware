TARGET = diceware
SOURCES = diceware.c diceware.h

$(TARGET): $(SOURCES)
	cc -std=c89 -o $(TARGET) diceware.c

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
	-rm $(TARGET)

.PHONY: clean info
