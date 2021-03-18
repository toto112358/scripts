#!/usr/bin/tcc -run
#include <stdio.h>

#define TABSTOP	8

main()
{
	register char c;
	register int cur;		/* current tabstop length */
	register int bc;		/* blank space count */

	bc = 0;
	cur = 8;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			++bc;
			while (bc >= cur) {
				bc -= cur;
				cur = TABSTOP;
				putchar('\t');
			}
			continue;
		}
		while (bc > 0) {
			--bc;
			putchar(' ');
			if (--cur == 0)
				cur = TABSTOP;
		}
		putchar(c);
		if (--cur == 0)
			cur = TABSTOP;
		if (c == '\t')
			cur = 8;
		if (c == '\n') {
			cur = 8;
			bc = 0;
		}
	}
	return 0;
}
