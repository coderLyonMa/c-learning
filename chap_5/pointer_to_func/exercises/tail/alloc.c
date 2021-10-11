#define BUFFSIZE 500 * 1000

static char buff[BUFFSIZE];
static char* allocp = buff;

char* alloc(int len)
{
    if ((allocp + len) <= buff + BUFFSIZE) {
        allocp += len;
        return allocp - len;
    } else {
        return 0;
    }
}

