#include <stdio.h>
#define MAX_LEN 1000
#define TABW 8


int main()
{
    char line[MAX_LEN];
    int ns, pos, c;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            pos = 0;
            putchar(c);
        }
        else  if (c == ' ') {
            ++pos, ++ns;

            // if ns eq 1, there's no need for substitution of tab
            if (ns > 1 && (TABW - ((pos - ns - 1) % TABW)) == ns) {
                ns = 0;
                putchar('\t');
            } else {
                for (; ns > 0; --ns)
                    putchar(c);
            }
        }
        else {
            ++pos;
            putchar(c);
        }
    }

    return 0;
}


int get_line(char* line, int max_len)
{
    char* line_0 = line;
    int c;

    while ((c = getchar()) != EOF && c != '\n' && (line - line_0) < max_len - 1)
        *line++ = c;

    if (c == '\n')
        *line++ = c;

    *line = '\0';
    return line - line_0;
}

