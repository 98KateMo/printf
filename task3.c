#include <unistd.h>
#include "main.h"
#include <stdlib.h>
#include <stdarg.h>

int  _unsigned_dec(va_list args)
{
        unsigned int val, x, num, mul, tens = 1;
        int characters = 0;
        unsigned int i = va_arg(args, unsigned int);
        char digit[2];

        for (val = i; val / 10 >= 1; val /= 10)
                ++tens;
        x = tens;
        mul = 1;
        for (val = i; val / 10 >= 1; val /= 10)
        {
                while (x > 1)
                {
                        mul *= 10;
                        --x;
                }
                digit[0] = (i / mul) + '0';
                digit[1] = '\0';
                num = (i / mul) * mul;
                mul /= 10;
                i -= num;
                write(1, &digit[0], 1);
                ++characters;
        }
        digit[0] = (i % 10) + '0';
        write(1, &digit[0], 1);
        ++characters;
        return (characters);
}

int _octal(va_list args)
{
        int x, j = 0, characters = 0;
        unsigned int i = va_arg(args, unsigned int);
        char digit[BUFFER_SIZE];

        if (i == 0)
        {
                write(1, "0", 1);
                return (1);
        }
        while (i != 0)
        {
                x = i % 8;
                digit[j++] = x + '0';
                i /= 8;
        }
        for (i = j - 1; i > 0; i--)
        {
                write(1, &digit[i], 1);
                ++characters;
        }
        write(1, &digit[i], 1);
        ++characters;
        return (characters);
}
   
