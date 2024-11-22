#include <stdio.h>
#include <stdlib.h>

int main() {
        FILE    *file;
        char    c;
        int     i = 0;

        file = fopen("/home/user/level09/token", "r");

        if (NULL == file)
                return EXIT_FAILURE;

        while ((c = fgetc(file)) != EOF && (c != '\n'))
                printf("%c", c - i++);

        printf("\n");
        fclose(file);
        return 0;
}