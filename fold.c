#include <stdio.h>

#define IN	1	/* inside a word */
#define OUT	0	/* outside a word */
#define MAXTAB	8	/* maximum tabstop length */
#define MAXWORD	1000	/* maximum input word length */
#define MAXLINE	70	/* maximum output line length */

main()
{
	char state, tabstop, word[MAXWORD];
	short pos, len;	/* len is current word length */

	state = OUT;
	tabstop = MAXTAB;
	pos = 0;
	while ((c = getchar()) != EOF) {
		++pos;
		if (c == '\n') {
			pos = 0;
			state = OUT;
			tabstop = MAXTAB;
			continue;
		if (c == ' ' || c == '\t')
			state = OUT;
		else if (state == OUT)
			state = IN;
		/* keep at end of func */
		if (c == '\t') {
			pos += tabstop;
			tabstop = MAXTAB;
		} else if (--tabstop == 0)
			tabstop = MAXTAB;

	}

}
