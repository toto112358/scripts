#include <stdio.h>

#define MAXLINE 70	/* max output line length */
#define IN	1	/* inside a word */
#define OUT	0	/* outside a word */


int getline(char line[], int lim);
int lastnonblank(char [], int len);

main()
{
	char line[MAXLINE];
	char len;

	while ((len = getline(line, MAXLINE)) > 0) {
		printf("%d\n", lastnonblank(line, len));
	}
	return 0;
}

getline(char s[], int lim)
{
	char c;
	int i;

	for (i = 0; (c=getchar()) != EOF & c != '\n' & i < lim-1; ++i)
		s[i] = c;
	if (i >= lim-1)
		s[i++] = c;
	else if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

lastnonblank(char s[], int i)
{
	char c;

	for (; i >= 0; --i) {
		c = s[i];
		if (c != ' ' & c != '\n' & c != '\t' & c != '\0')
			return i;
	}
	return 0;
}
