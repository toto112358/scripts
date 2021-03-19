#include <stdio.h>

#define TABSTOP	8
#define FILL	' '

main()
{
	register char c, spacenum;

	spacenum = TABSTOP;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for (; spacenum > 0; --spacenum)
				putchar(FILL);
			spacenum = TABSTOP;
			continue;
		}
		putchar(c);
		if (--spacenum == 0)
			spacenum = TABSTOP;
		if (c == '\n')
			spacenum = TABSTOP;
	}
}
