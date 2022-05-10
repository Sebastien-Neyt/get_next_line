#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd;
    char *line;
    int i;
    i = 1;

    fd = open("test", O_RDONLY);
    while (i <= 2)
    {
        line = get_next_line(fd);
        printf("%s", line);
        if (line == 0)
            break;
        free(line);
    }
    return (0);
}
