//Colin Hosking Jared Asch
//Project 0: MyTunez
//Systems pd05
//2018-10-19

#ifndef LIBRARY_H
#define LIBRARY_H

#include "linked_list.h"

struct library {
    struct song_node * table[27];
    int size;
};

struct library * add_song(struct library *, char[], char[]);

void delete_song(struct library *, char[], char[]);

struct song_node * search_song(struct library *, char *, char *);

struct song_node * search_artist(struct library *, char* );

struct song_node * random_song(struct library *);

struct library * free_library(struct library *);

void print_library(struct library *);

void print_letter(struct library *, char);

void print_artist(struct library *, char *);

void shuffle(struct library *, int);

int get_table_index(char);

#endif


//Caps? * vs []? notes?
