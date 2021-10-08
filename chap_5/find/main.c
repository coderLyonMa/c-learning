#include <stdio.h>
#include "prt_macros.h"
#include "line.h"

#define MAX_LEN 1000

int main(int argc, char** argv)
{
    int except, se_nu, len, lineno, found;
    except = se_nu = len = lineno = found = 0;
    char pattern[MAX_LEN], line[MAX_LEN];

    // get cmd line options
    while (--argc > 0 && **++argv == '-')
        while (*(++*argv))
            switch (**argv) {
            case 'x':
                except = 1;
                break;
            case 'n':
                se_nu = 1;
                break;
            default:
                printf("invalid option: %c\n", **argv);
                return -1;
                break;
        }

    if (argc != 1) {
        printf("Error: missing argument [pattern]\n");
    } else {
        while (len = get_line(line, MAX_LEN)) {
            lineno++;
            if ((strindex(line, *argv) != -1) ^ except) {
                found++;
                if (se_nu)
                    printf("%d:\t", lineno);

                printf("%s", line);
            }
        }
    }

    return found;
}

