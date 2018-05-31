/*
** EPITECH PROJECT, 2017
** my_error.c
** File description:
** Error handling
*/

#include "matchstick.h"

int handle_match_error(struct request *req, int match)
{
	const char *error_match = "Error: you cannot remove more than ";
	const char *error_match_end = " matches per turn\n";
	const char *input_str = "Error: invalid input "
		"(positive number expected)\n";
	const char *remove_str = "Error: you have to remove at least one "
		"match\n";

	if (match == 0) {
		my_put_str(remove_str);
		return (0);
	}
	if (match > req->limit) {
		my_put_str(error_match);
		my_put_nbr(req->limit, 1);
		my_put_str(error_match_end);
		return (0);
	} else if (match == -1) {
		my_put_str(input_str);
		return (0);
	}
	return (1);
}

int handle_line_error(int line)
{
	const char *range_str = "Error: this line is out of range\n";
	const char *syntax_str = "Error: invalid input (positive number "
		"expected)\n";

	if (line == 0) {
		my_put_str(range_str);
		return (0);
	}
	if (line == -1) {
		my_put_str(syntax_str);
		return (0);
	}
	return (1);
}