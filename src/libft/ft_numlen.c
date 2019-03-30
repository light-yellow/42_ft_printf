int	ft_numlen(unsigned int num, unsigned int base)
{
        int     len;

        len = 1;
        while (num >= base)
        {
                num /= base;
                len += 1;
        }
        return (len);
}
