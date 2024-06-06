diceware:
	cc -std=c89 diceware.c -o diceware

clean:
	rm -f diceware || true

.PHONY: clean
