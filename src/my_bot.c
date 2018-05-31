/*
** EPITECH PROJECT, 2017
** my_bot.c
** File description:
** AI file
*/

#include "matchstick.h"

void play_bot(struct request *req)
{
	const char *won = "I lost... snif... but I'll get you next time!!\n";
	const char *lose = "You lost, too bad...\n";
	const char *play = "AI's turn...\n";

	if (entities_number(req) == 0) {
		my_put_str(lose);
		req->exit = 2;
		return;
	}
	my_put_str(play);
	remove_random_match(req);
	if (entities_number(req) == 0) {
		display(req);
		my_put_str(won);
		req->exit = 1;
		return;
	}
}

void remove_random_match(struct request *req)
{
	int len = 0;
	int nbr = 0;
	int i = crand(0, req->size - 1);

	while ((len = entities_number_line(req, i)) != -1) {
		if (len == 0) {
			i = crand(0, req->size);
			continue;
		}
		if (len == 1 || (entities_number(req) == 2 && len == 2))
			nbr = 1;
		else if (len > req->limit && req->limit - 1 != 1)
			nbr = crand(1, req->limit - 1);
		else
			nbr = len - 1;
		if (len == req->limit + 1)
			nbr = req->limit;
		remove_silent_match(req, i, nbr);
		print_status(nbr, i);
		break;
	}
}

void print_status(int nbr, int i)
{
	const char *play_start = "AI removed ";
	const char *play_mid = " match(es) from line ";

	my_put_str(play_start);
	my_put_nbr(nbr, 1);
	my_put_str(play_mid);
	my_put_nbr(i + 1, 1);
	my_put_char('\n', 1);
}

void remove_silent_match(struct request *req, int line, int match)
{
	int i = my_strlen(req->content[0]) - 1;

	for (; i >= 0 && match != 0; i--) {
		if (req->content[line][i] == '|') {
			req->content[line][i] = ' ';
			match--;
		}
	}
}