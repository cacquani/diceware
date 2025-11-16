# Diceware

Small fun project to (re)learn c and make.

[Diceware](https://en.wikipedia.org/wiki/Diceware) generators are usually
limited to one language/dictionary.

The plan is to build a simple generator that will allow polyglot users to
generate passphrases from a mix of dictionaries of their choice.

The lists of words will come from
[here](https://theworld.com/~reinhold/diceware.html).

A good idea would be to advise against mixing different alphabets/encoding, but
I'll see what will happen later on when I get past the initial "setting things
up" stage.

## Static Libraries

Can use static libraries to include and share the dictionaries.

A static library can be statically linked to the main executable, so that the
main executable can be distributed and used without having to install any
(shared) library separately.

[Article on creating
libraries](https://renenyffenegger.ch/notes/development/languages/C-C-plus-plus/GCC/create-libraries/index),
and a rather good one, it also goes into details on the
difference between static and shared libraries, and how to load shared
libraries dynamically from inside the main executable using `libdl` and
pointers.

Will need the additional utility Archive (`ar`) to create the static library
archive from the compiled object(s).

May want to add some functions for search/randomise inside the library, will
need to decide the data format (csv? plain one-entry-per-line?)


## Shared Libraries

[shared libraries](https://renenyffenegger.ch/notes/development/languages/C-C-plus-plus/GCC/libraries/shared/index)
which are the `.so` ones installed in `/usr/lib` or `/usr/local/lib`

Shared libraries are created without using the Archive utility, are linked
dynamically and must be installed separately into the appropriate system path
to be found and used by the main executable.

