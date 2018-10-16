//Colin Hosking Jared Asch
//Project 0: MyTunez
//Systems pd05
//2018-10-19

#ifndef LIBRARY_H
#define LIBRARY_H

#include "linked_list.h"

struct library {
    struct song_node * table[27];
};

struct library * add_song(struct library *, char[], char[]);

struct song_node * search_song(struct library *lib, char* song, char* artist);

struct song_node * search_artist(struct library *lib, char* artist);

void print_library(struct library *);

void print_letter(struct library *, char);

int get_table_index(char);

#endif


//Caps? * vs []? notes?