/*
** EPITECH PROJECT, 2017
** my_map.c
** File description:
** Map file
*/

#include "matchstick.h"

void fill_alums(struct request *req)
{
	int x;
	int y;

	for (y = 0; y < req->size; y++) {
		for (x = 0; x < (2 * (req->size)); x++) {
			if (x <= req->size - 2 - y ||
			x >= (2 * (req->size)) - req->size + 1 + y - 1) {
				req->content[y][x] = ' ';
			} else {
				req->content[y][x] = '|';
			}
		}
		req->content[y][x - 1] = '\0';
	}
}