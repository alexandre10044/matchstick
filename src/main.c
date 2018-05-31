/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Main file
*/

#include "matchstick.h"

int main(int ac, char **as)
{
	const int exit_error = 84;
	const int false = 0;
	struct request *req;

	srand(time(NULL));
	if (check(ac, as) == false)
		return (exit_error);
	req = get_request(as);
	if (req == NULL)
		return (exit_error);
	process(req);
	return (req->exit);
}

int check(int ac, char **as)
{
	const int true = 1;
	const int false = 0;
	int size;
	int limit;

	if (ac != 3)
		return (false);
	size = my_getnbr(as[1]);
	limit = my_getnbr(as[2]);
	if (size < 1 || size > 100 || limit <= 0)
		return (false);
	return (true);
}