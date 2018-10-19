//Colin Hosking Jared Asch
//Project 0: MyTunez
//Systems pd05
//2018-10-19

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct song_node {
 	char name[100];
 	char artist[100];
 	struct song_node *next;
};

struct song_node * insert_front(struct song_node *, char[], char[]);

struct song_node * insert_ordered(struct song_node *, char[], char[]);

struct song_node * remove_node(struct song_node *, char[], char[]);

struct song_node * remove_node_help(struct song_node *, char[], char[], struct song_node *);

struct song_node * find_node(struct song_node *, char *, char *);

struct song_node * find_node_artist(struct song_node *, char *);

struct song_node * random_node(struct song_node *);

struct song_node * free_list(struct song_node *);

int compare_songs(char *, char *, char *, char *);

int strcmp_lower(char *, char *);

int len(struct song_node *);

void print_list(struct song_node *);

void print_node(struct song_node *);

#endif
