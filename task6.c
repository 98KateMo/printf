int _address(va_list args)
{
        void *address = va_arg(args, void *);
        intptr_t num = (intptr_t)address;
        char hex[17] = {0};
        int remainder, i = 0;
        int characters = 0;

        write(1, "0x", 2);
        characters = 2;

        while (num != 0)
        {
                remainder = num % 16;
                hex[i++] = (remainder < 10) ? remainder + '0' :
                        remainder - 10 + 'a';
                num /= 16;
        }
        for (i = i - 1; i >= 0; i--)
        {
                write(1, &hex[i], 1);
                ++characters;
        }
        return (characters);
}
