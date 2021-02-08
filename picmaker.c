#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{

    int fd;
    char data[50];
    int x, y;
    int r, g, b;

    fd = open("img.ppm", O_CREAT | O_WRONLY | O_TRUNC, 0777);
    char header[] = "P3 500 500 255\n";
    write(fd, header, sizeof(header) - 1);

    for (y = 0; y < 500; y++)
    {
        for (x = 0; x < 500; x++)
        {
            if (((x - 300) * (x - 300)) + ((y - 220) * (y - 220)) <= (225 * 225))
            {
                r = 0;
                g = 0;
                b = 0;
                snprintf(data, sizeof(data), "%d %d %d ", r, g, b);
                write(fd, data, strlen(data));
            }
            else if (((x - 250) * (x - 250)) + ((y - 250) * (y - 250)) <= (230 * 230))
            {
                r = 192;
                g = 192;
                b = 192;
                snprintf(data, sizeof(data), "%d %d %d ", r, g, b);
                write(fd, data, strlen(data));
            }
            else
            {
                if (x % 8 == 0 && y % 8 == 0 && x < 200)
                {
                    r = 255;
                    g = 255;
                    b = 0;
                    snprintf(data, sizeof(data), "%d %d %d ", r, g, b);
                    write(fd, data, strlen(data));
                }
                else
                {
                    r = 0;
                    g = 0;
                    b = 0;
                    snprintf(data, sizeof(data), "%d %d %d ", r, g, b);
                    write(fd, data, strlen(data));
                }
            }
        }
        snprintf(data, sizeof(data), "\n");
        write(fd, data, strlen(data));
    }

    close(fd);
    //printf("test\n");
    return 0;
}
