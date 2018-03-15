/*
** EPITECH PROJECT, 2018
** the_switch.c
** File description:
** Arthur
*/

#include "tetris.h"

int get_argv_part4(int oc, char_arg *ptb)
{
	switch (oc) {
		case 'w':
			if ((ptb->key_size = change_size(optarg,
					ptb->key_size)) == NULL)
				return (84);
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

int get_argv_part3(int oc, char_arg *ptb)
{
	switch (oc) {
		case 'r':
			if ((ptb->key_right = change_str(optarg,
					ptb->key_right)) == NULL)
				return (84);
			break;
		case 'p':
			if ((ptb->key_pause = change_str(optarg,
					ptb->key_pause)) == NULL)
				return (84);
			break;
		case 'm':
			if ((ptb->key_next = change_str(optarg,
					ptb->key_next)) == NULL)
				return (84);
			break;
	}
	if (get_argv_part4(oc, ptb) == 84)
		return (84);
	return (0);
}

int get_argv_part2(int oc, char_arg *ptb)
{
	switch (oc) {
		case 't':
			if ((ptb->key_turn = change_str(optarg,
					ptb->key_turn)) == NULL)
				return (84);
			break;
		case 'd':
			if ((ptb->key_drop = change_str(optarg,
					ptb->key_drop)) == NULL)
				return (84);
			break;
		case 'q':
			if ((ptb->key_quit = change_str(optarg,
					ptb->key_quit)) == NULL)
				return (84);
			break;
	}
	if (get_argv_part3(oc, ptb) == 84)
		return (84);
	return (0);
}

int get_argv(int oc, char_arg *ptb)
{
	switch (oc) {
		case 'D':
			break;
		case 'L':
			if ((ptb->key_level = change_str(optarg,
					ptb->key_level)) == NULL)
				return (84);
			break;
		case 'l':
			if ((ptb->key_left = change_str(optarg,
					ptb->key_left)) == NULL)
				return (84);
			break;
	}
	if (get_argv_part2(oc, ptb) == 84)
		return (84);
	return (0);
}
