/*
** EPITECH PROJECT, 2017
** file.h
** File description:
**
*/

#ifndef matchstick_
#define matchstick_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

struct request {
	char **content;
	int limit;
	int size;
	int exit;
};

// main.c
int check(int ac, char **as);

// my_bot.c
void play_bot(struct request *req);
void print_status(int nbr, int i);
void remove_random_match(struct request *req);
void remove_silent_match(struct request *req, int line, int match);

// my_engine.c
void process(struct request *req);
int input(struct request *req, int line);
int remove_match(struct request *req, int line, int match);
void my_remove(struct request *req, int match, int line);
void display(struct request *req);

// my_error.c
int handle_match_error(struct request *req, int match);
int handle_line_error(int line);

// my_get.c
struct request *get_request(char **str);
int my_getnbr(char *str);

// my_map.c
void fill_alums(struct request *req);

// my_put.c
void my_put_char(char c);
void my_put_str(const char *str);
int my_put_nbr(int nb);

// my_reader.c
char *read_line(void);
int my_getchar(void);
char *my_realloc(char *src, int pos);

// my_utils.c
int my_strlen(const char *str);
int entities_number(struct request *req);
int entities_number_line(struct request *req, int line);
int crand(int a, int b);

#endif /* matchstick */