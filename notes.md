# Notes

## What do I want to achieve

### In general

- go back into C and go back into understanding low level programming concepts
- learn Make syntax
- learn a bit about compilers, their functioning and their quirks

### For this specific task

This specific task is about creating a diceware for random passphrase
generation.

As a polyglot, I find it limiting that diceware usually draw from a single
language, and I want to experiment with the idea of generating a passphrase
with words from different languages.

## Requirements

As a minimum, this should return a list of n random words in the same language.

The value for n should be an argument and defaulting to 6, the language should
be an argument and defaulting to English.

### First pass [done]

The first pass is set up, figure out the basic makefile, and print a help.

This pass includes:

- embedding the help file as a binary array
  - this step includes writing a translation helper executable to convert the
    .txt help into the binary array
- print the help when calling the executable

### Second pass

Second pass should be to have it return 6 random words in English, no arguments
accepted.

The words will be randomised using 6d6 and picked from the list.

This pass includes:

- lint the English dictionary to weed out numbers, special characters and
  random meaningless strings
- embed the English dictionary file using the GCC quirk highlighted below
- write the actual code to randomize and string together the picked words
- expand the help to add this command and re-embed it

### Third pass

Third pass should start accepting number and one language as arguments.

This pass includes:
- write the code to accept arguments
- validate the language to be one of the available ones
- validate the number to be between 1 and 20
- lint and embed .de, .es, .fr and .it dictionaries
- expand the code to choose from the right dictionary, and to randomise the
  required number of words instead of limiting to 6

## Complications

The lists of dictionary words and dice value need to be somehow embedded into
the executable, I won't have a call that breaks if the executable doesn't find
the dictionaries exactly in the place it expects them to be (been there during
my high school software project, never again ^.^')

The C standard library doesn't offer a clean way to do it, but from internet
searches there seem to be options.

### Embed strings (or images) into a .exe

[Codeplea solution](https://codeplea.com/embedding-files-in-c-programs)

[#embed fast alternative](https://thephd.dev/implementing-embed-c-and-c++)

[cpp version](https://caiorss.github.io/C-Cpp-Notes/resources-executable.html)

### Embed entire files into the executable, exploiting GCC capabilities

[Kevin Boone on embedding resources into an executable using
GCC](https://kevinboone.me/gcc-embed-data.html)

This solution is compiler-specific, there is no mechanism in the C standard
library to do this.

According to the information I could find online, it seems to perform better
than the alternatives for large input files, but it's more complex to
implement.

Definitely worth using it for the dictionaries.

### Source code array

Another method that is independent from the compiler and seems to be commonly
used (based on internet search) is converting the input file into an array of
bytes, and embed that into the executable.

Despite being suggested for medium size data, while the help output file can
reasonably qualify as small I may want to try this method for that, just to
experiment and try out the different ways of embedding text into the
executable.

