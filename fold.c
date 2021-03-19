#include <stdio.h>

#define MAXLINE 70	/* max output line length */
#define IN	1	/* inside a word */
#define OUT	0	/* outside a word */
#define MAXTAB	8	/* max tab size */


int getline(char line[], int lim);
int lastnonblank(char [], int len);

/* folds long input lines into two or more shorter lines after the
   last nonblank character that occurs before the MAXLINE-th column
   of input. */
main()
{
	char line[MAXLINE];
	char i;
	int len, nonblank;

	while ((len = getline(line, MAXLINE)) > 0) {
		nonblank = lastnonblank(line, len);

		line[nonblank + 1] = '\0';
		printf("%s", line);
		putchar('\n');

	}
	return 0;
}

/* reads line from the stdin with lim max pos */
getline(char s[], int lim)
{
	char c, tabstop;
	int i;

	tabstop = MAXTAB;
	for (i = 0; (c=getchar()) != EOF && c != '\n' && i < lim-1; ++i) {
		if (c == '\t') {
			lim -= tabstop;
			tabstop = MAXTAB;
		} else if (--tabstop == 0)
			tabstop = MAXTAB;
		s[i] = c;
	}
	if (i >= lim-1)
		s[i++] = c;
	else if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

/* returns the idx of the last non blank char, if none returns -1 */
lastnonblank(char s[], int i)
{
	char c;

	for (; i >= 0; --i) {
		c = s[i];
		if (c != ' ' && c != '\n' && c != '\t' && c != '\0')
			return i;
	}
	return -1;
}
