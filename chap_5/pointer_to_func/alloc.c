#define BUFFSIZE 1000 * 1000

static char buff[BUFFSIZE];
char* allocp = buff;

char* alloc(int n)
{
    if (allocp + n <= buff + BUFFSIZE) {
        allocp += n;
        return allocp - n;
    } else {
        return 0;
    }
}

