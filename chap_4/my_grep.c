#include <stdio.h>
#define MAXLINE 1000


int get_line(char s[], int max);
int strindex(char s[], char t[]);


int main()
{
	char line[MAXLINE];

	while (get_line(line, MAXLINE)) {
		if (strindex(line, "this") != -1)
			printf("%s", line);
	}
}


int get_line(char s[], int max)
{
	int i = 0;
	char c;
	
	while ((c = getchar()) != EOF && c != '\n' && i < max)
		s[i++] = c;

	if (c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0';
	return i;
}


int strindex(char s[], char t[])
{
	int i = 0;
	int j;

    for (; s[i] != '\0'; i++)
        for (int k = 0, j = i; s[j++] == t[k++]; )
            if (t[k] == '\0')
                return j - 1;
    return -1;
}

