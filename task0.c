#include <unistd.h>
#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

int _char(va_list args)
{
        char c = va_arg(args, int);

        write(1, &c, 1);
        return (1);
}

int  _string(va_list args)
{
        int i, characters = 0;
        char *c = va_arg(args, char *);

        for (i = 0; c[i] && c != NULL; i++)
        {
                write(1, &c[i], 1);
                ++characters;
        }
        return (characters);
}
