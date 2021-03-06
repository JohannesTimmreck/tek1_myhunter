/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** my_printf
*/

#include "../headerfile_printf.h"

int right_calc_tens(int temp)
{
    int tens = 0;

    while (temp != 0) {
        temp = temp / 10;
        tens = tens + 1;
    }
    tens = tens - 1;
    return (tens);
}

void right_print_nbr(int to_divide_by, int nb, int len)
{
    int out = 1;

    while (to_divide_by >= 1) {
        out = nb / to_divide_by;
        nb = nb % to_divide_by;
        my_putchar(out + '0');
        to_divide_by = to_divide_by / 10;
        len--;
    }
    while (len > 0) {
        len--;
        my_putchar(' ');
    }
}

void my_right_nbr(va_list list, int len)
{
    int tens = 0;
    int to_divide_by = 1;
    int nb = 0;

    nb = va_arg(list, int);
    if (nb == 0) {
        my_putchar('0');
        len--;
    }
    if (nb < 0) {
        my_putchar('-');
        len--;
        nb = nb * (-1);
    }
    tens = right_calc_tens(nb);
    while (tens != 0) {
        to_divide_by = to_divide_by * 10;
        tens = tens - 1;
    }
    right_print_nbr(to_divide_by, nb, len);
}
