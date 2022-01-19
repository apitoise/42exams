/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apitoise <apitoise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 15:36:49 by apitoise          #+#    #+#             */
/*   Updated: 2021/12/02 15:38:24 by apitoise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

typedef struct  s_flag
{
    int     prec;
    int     width;
}               t_flag;

int     str_len(char *str)
{
    int     len;
    len = 0;
    while (str[len])
        len++;
    return (len);
}

void    put_char(unsigned char c, int nb, int *count)
{
    while (nb > 0)
    {
        write(1, &c, 1);
        (*count)++;
        nb--;
    }
}

void    print_char(int c, t_flag *f, int *count)
{
    put_char(' ', f->width - 1, count);
    put_char(c, 1, count);
}

void    print_str(char *str, t_flag *f, int *count)
{
    int     len;
    len = str_len(str);
    len = f->prec >= 0 && f->prec < len ? f->prec : len;
    put_char(' ', f->width - len, count);
    while (len--)
        put_char(*(str++), 1, count);
}

int     nb_len(int nb, int base)
{
    int     len;
    len = 1;
    while (nb / base)
    {
        len++;
        nb /= base; 
    }
    return (len);
}

void    print_rec(unsigned int nb, int base, int *count)
{
    if (nb / base)
        print_rec(nb / base, base, count);
    put_char(nb % base > 9 ? nb % base - 10 + 'a' : nb % base + '0', 1, count);
}

void    print_int(int nb, t_flag *f, int *count)
{
    int     len;
    int     full_len;
    if (!f->prec && !nb)
        return (put_char(' ', f->width, count));
    len = nb_len(nb, 10);
    full_len = f->prec > len ? f->prec : len;
    put_char(' ', nb < 0 ? f->width - 1 - full_len : f->width - full_len, count);
    if (nb < 0)
        put_char('-', 1, count);
    put_char('0', full_len - len, count);
    print_rec(nb < 0 ? nb * -1 : nb, 10, count);
}

void    print_hex(int nb, t_flag *f, int *count)
{
    int     len;
    int     full_len;
    if (!f->prec && !nb)
        return (put_char(' ', f->width, count));
    len = nb < 0 ? 8 : nb_len(nb, 16);
    full_len = f->prec > len ? f->prec : len;
    put_char(' ', f->width - full_len, count);
    put_char('0', full_len - len, count);
    print_rec(nb, 16, count);
}

void    print_exp(const char **str, va_list *arg, int *count)
{
    t_flag  f;
    f.prec = -1;
    f.width = -1;
    (*str)++;
    while ((**str >= '0' && **str <= '9') || **str == '.')
    {
        if (**str == '.')
        {
            (*str)++;
            f.prec = 0;
            while (**str >= '0' && **str <= '9')
            {
                f.prec = f.prec * 10 + **str - '0';
                (*str)++;
            }
        }
        else
        {
            f.width = 0;
            while (**str >= '0' && **str <= '9')
            {
                f.width = f.width * 10 + **str - '0';
                (*str)++;
            }
        }
    }
    if (**str == 'x')
        print_hex(va_arg(*arg, int), &f, count);
    else if (**str == 'd')
        print_int(va_arg(*arg, int), &f, count);
    else if (**str == 's')
        print_str(va_arg(*arg, char *), &f, count);
    else
        print_char(**str, &f, count);
}

int     ft_printf(const char *str, ...)
{
    va_list     arg;
    int         count;
    count = 0;
    va_start(arg, str);
    while (*str)
    {
        if (*str == '%')
            print_exp(&str, &arg, &count);
        else
            put_char(*str, 1, &count);
        str++;
    }
    va_end(arg);
    return (count);
}
