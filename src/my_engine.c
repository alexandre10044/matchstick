/*
** EPITECH PROJECT, 2017
** my_engine.c
** File description:
** Engine file
*/

#include "matchstick.h"

void process(struct request *req)
{
	int turn = 0;
	int out;

	fill_alums(req);
	display(req);
	while (entities_number(req) != 0 && req->exit == 0 && turn < 900) {
		out = input(req, 0);
		if (out == 0)
			continue;
		else if (out == 84)
			return;
		display(req);
		play_bot(req);
		if (req->exit != 0)
			break;
		display(req);
		turn++;
	}
}

int input(struct request *req, int line)
{
	char *str;

	if (line == 0)
		my_put_str("Your turn:\n");
	my_put_str("Line: ");
	str = get_next_line(0);
	if (str == NULL) {
		req->exit = 0;
		return (84);
	}
	line = my_getnbr(str);
	if (handle_line_error(line) == 0)
		return (input(req, 1));
	line--;
	if (entities_number_line(req, line) == -1)
		return (input(req, 1));
	return (input_matches(req, line));
}

int remove_match(struct request *req, int line, int match)
{
	const char *error_nbr = "Error: not enough matches on this line\n";

	if (entities_number_line(req, line) >= 0 &&
		match <= entities_number_line(req, line)) {
		my_remove(req, match, line);
		return (1);
	} else {
		my_put_str(error_nbr);
		return (0);
	}
}

void my_remove(struct request *req, int match, int line)
{
	const char *ply_remov = "Player removed ";
	const char *ply_remov_end = " match(es) from line ";
	int i = my_strlen(req->content[0]) - 1;

	my_put_str(ply_remov);
	my_put_nbr(match, 1);
	for (; i >= 0 && match != 0; i--) {
		if (req->content[line][i] == '|') {
			req->content[line][i] = ' ';
			match--;
		}
	}
	my_put_str(ply_remov_end);
	my_put_nbr(line + 1, 1);
	my_put_char('\n', 1);
}

void display(struct request *req)
{
	for (int i = 0; i < my_strlen(req->content[0]) + 2; i++)
		my_put_char('*', 1);
	my_put_char('\n', 1);
	for (int i = 0; i < req->size; i++) {
		my_put_char('*', 1);
		my_put_str(req->content[i]);
		my_put_char('*', 1);
		my_put_char('\n', 1);
	}
	for (int i = 0; i < my_strlen(req->content[0]) + 2; i++)
		my_put_char('*', 1);
	my_put_char('\n', 1);
	my_put_char('\n', 1);
}