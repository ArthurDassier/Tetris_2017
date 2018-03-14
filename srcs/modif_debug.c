/*
** EPITECH PROJECT, 2018
** modif_debug.c
** File description:
** Arthur
*/

#include "tetris.h"

char *change_str(char *arg, char *printer)
{
	int	i = 0;
	int	j = 0;
	char	*tmp = malloc(sizeof(char) * 1024);

	while (printer[i] != ':') {
		tmp[i] = printer[i];
		++i;
	}
	tmp[i] = printer[i];
	++i;
	tmp[i] = printer[i];
	++i;
	tmp[i] = printer[i];
	while (arg[j] != '\0') {
		tmp[i] = arg[j];
		++i;
		tmp[i] = '\0';
		my_realloc(tmp);
		++j;
	}
	tmp[i] = '\0';
	return (tmp);
}

int get_argv(int oc, char_arg *ptb)
{
	switch (oc) {
		case 'D':
			break;
		case 'L':
			ptb->key_level = change_str(optarg, ptb->key_level);
			break;
		case 'l':
			ptb->key_left = change_str(optarg, ptb->key_left);
			break;
		case 'r':
			ptb->key_right = change_str(optarg, ptb->key_right);
			break;
		case 't':
			ptb->key_turn = change_str(optarg, ptb->key_turn);
			break;
		case 'd':
			ptb->key_drop = change_str(optarg, ptb->key_drop);
			break;
		case 'q':
			ptb->key_quit = change_str(optarg, ptb->key_quit);
			break;
		case 'p':
			ptb->key_pause = change_str(optarg, ptb->key_pause);
			break;
		case 'm':
			ptb->key_next = change_str(optarg, ptb->key_next);
			break;
		case 'w':
			ptb->key_size = change_str(optarg, ptb->key_size);
			break;
		case ':':
			my_puterror("read --help before testing random"
			" arguments retard\n");
			return (84);
		case '?':
			my_puterror("read --help before testing random"
			" arguments retard\n");
		return (84);
	}
	return (0);
}

int modif_debug(int ac, char **av, char_arg *printable)
{
	int			oc;
	struct option		longopts[] = {
		{"level", required_argument, NULL, 'L'},
		{"key-left", required_argument, NULL, 'l'},
		{"key-right", required_argument, NULL, 'r'},
		{"key-turn", required_argument, NULL, 't'},
		{"key-drop", required_argument, NULL, 'd'},
		{"key-quit", required_argument, NULL, 'q'},
		{"key-pause", required_argument, NULL, 'p'},
		{"map-size", required_argument, NULL, 'm'},
		{"without-next", required_argument, NULL, 'w'},
		{"debug", no_argument, NULL, 'D'},
		{NULL, 0, NULL, 0}
	};
	optind = 1;
	while ((oc = getopt_long(ac, av, "DL:l:r:t:d:q:p:m:w:", longopts, NULL)) != -1)
		if (get_argv(oc, printable) == 84)
			return (84);
	return (0);
}
