/*
** EPITECH PROJECT, 2017
** my_get.c
** File description:
** Get file
*/

#include "matchstick.h"

struct request *get_request(char **str)
{
	struct request *req = malloc(sizeof(struct request));

	if (req == NULL)
		return (NULL);
	req->size = my_getnbr(str[1]);
	req->limit = my_getnbr(str[2]);
	req->content = malloc(sizeof(char *) * req->size);
	req->exit = 0;
	if (req->content == NULL)
		return (NULL);
	for (int i = 0; i < req->size; i++) {
		req->content[i] = malloc(sizeof(char) *
			(1 + (2 * (req->size))));
		if (req->content[i] == NULL)
			return (NULL);
	}
	return (req);
}

int my_getnbr(char *str)
{
	int val = 0;

	while (*str) {
		if (*str >= '0' && *str <= '9') {
			val *= 10;
			val += *str - '0';
		}
		else
			return (-1);
		str++;
	}
	return (val);
}

int input_matches(struct request *req, int line)
{
	char *str;
	int match;

	my_put_str("Matches: ");
	str = get_next_line(0);
	if (str == NULL) {
		req->exit = 0;
		return (84);
	}
	match = my_getnbr(str);
	if (handle_match_error(req, match) == 0)
		return (input(req, 1));
	return (remove_match(req, line, match));
}