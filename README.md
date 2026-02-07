# Diceware

Small fun project to (re)learn c and make.

[Diceware](https://en.wikipedia.org/wiki/Diceware) generators are usually
limited to one language/dictionary.

The plan is to build a simple generator that will allow polyglot users to
generate passphrases from a mix of dictionaries of their choice.

The lists of words will come from
[here](https://theworld.com/~reinhold/diceware.html).

For the first draft, it will just be Latin alphabet, no accented characters,
and likely a common subset of symbols.

## Credits

This is a strictly educational project (aka I'm doing it to learn C and have
some fun), so for now I don't think there's anything wrong if I take some
inspiration from other projects, but it seems fair to be explicit about it.

### Diceware

First of all, the [original
diceware](https://theworld.com/~reinhold/diceware.html) devised by Arnold G.
Reinhold.

If this implementation goes anywhere, I'll bother him for advice and permission
to use the name, but as long as this stays an educational thing, I'm sure he
has more important and fun things to do than read emails from me.

### EFF English word list

The [EFF](https://www.eff.org/) published [an alternative list of
words](https://www.eff.org/files/2016/07/18/eff_large_wordlist.txt) that are
on average longer, have the prefix property (aka no word in the list is the
prefix of another word), doesn't include meaningless words, and is handcrafted
to exclude offensive words and include words that are on average more common
than the ones in the original list.

