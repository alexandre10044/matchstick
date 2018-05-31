/*
** EPITECH PROJECT, 2017
** my_utils.c
** File description:
** Utils
*/

#include "matchstick.h"

int my_strlen(const char *str)
{
	int len;

	for (len = 0; str[len]; len++);
	return (len);
}

int entities_number(struct request *req)
{
	int len = 0;

	for (int i = 0; i < req->size; i++)
		for (int j = 0; req->content[i][j]; j++)
			if (req->content[i][j] == '|')
				len++;
	return (len);
}

int entities_number_line(struct request *req, int line)
{
	const char *error_size = "Error: this line is out of range\n";
	int len = 0;

	if (line >= req->size) {
		my_put_str(error_size);
		return (-1);
	}
	for (int i = 0; req->content[line][i]; i++)
		if (req->content[line][i] == '|')
			len++;
	return (len);
}

int crand(int a, int b)
{
	return (rand() % (b - a) + a);
}