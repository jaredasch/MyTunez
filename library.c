//Colin Hosking Jared Asch
//Project 0: MyTunez
//Systems pd05
//2018-10-19

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"
#include "library.h"

int get_table_index(char chr){
    if(65 <= chr && chr <= 90)
        return (int ) chr - 'A';
    if(97 <= chr && chr <= 122)
        return (int) chr - 'a';
    return 26;
}

struct song_node * search_song(struct library *lib, char *song, char *artist){
    int i = get_table_index(artist[0]);
    struct song_node *tmp = find_node(lib->table[i], song, artist);
    return tmp;
}

struct song_node * search_artist(struct library *lib, char* artist){
    int i = get_table_index(artist[0]);
    struct song_node *tmp = find_node_artist(lib->table[i], artist);
    return tmp;
}

struct song_node * random_song(struct library *lib){
    int index = rand() % lib->size;
    for(int i = 0; i < 27; i++){
        for(struct song_node * head = lib->table[i]; head; head = head->next){
            if(!index--)    return head;
        }
    }
    return 0;
}

void shuffle(struct library *lib, int n){
    while(n--)  print_node(random_song(lib));
}

void print_artist(struct library *lib, char *artist){
    int i = get_table_index(*artist);
    struct song_node *tmp = lib->table[i];
    while (tmp){
        if (!strcmp(artist, tmp->artist)){
            print_node(tmp);
            tmp = tmp->next;
        } else {
            break;
        }
    }
}

void delete_song(struct library *lib, char name[], char artist[]){
    int i = get_table_index(*artist);
    lib->table[i] = remove_node(lib->table[i], name, artist);
    lib->size--;
}

struct library * add_song(struct library *lib, char name[], char artist[]){
    int index = get_table_index(*artist);
    lib->table[index] = insert_ordered(lib->table[index], name, artist);
    lib->size++;
    return lib;
}

void print_letter(struct library *lib, char chr){
    int index = get_table_index(chr);
    if(lib->table[index]){
        // printf("Artists starting with %c\n", index + 65);
        print_list(lib->table[index]);
        printf("\n");
    } else {
        printf("No artists found starting with %c\n", chr);
    }
}

void print_library(struct library *lib){
    if(lib){
        for(int i = 0; i < 27; i++){
            print_list(lib->table[i]);
        }
    }
}

struct library * free_library(struct library *lib){
    for(int i = 0; i < 27; i++){
        free_list(lib->table[i]);
    }
    free(lib);
    return 0;
}
