/*
** EPITECH PROJECT, 2017
** my_put.c
** File description:
** Put
*/

#include "matchstick.h"

void my_put_char(char c, int output)
{
	write(output, &c, 1);
}

void my_put_str(const char *str)
{
	int length = 0;

	while (str[length] != '\0') {
		my_put_char(str[length], 1);
		length++;
	}
}

int my_put_nbr(int nb, int output)
{
	if (nb > 9)
		my_put_nbr(nb / 10, output);
	else if (nb < 0) {
		nb = nb * -1;
		write(output, "-", 1);
		my_put_nbr(nb / 10, output);
	}
	my_put_char((nb % 10 + '0'), output);
	return (0);
}