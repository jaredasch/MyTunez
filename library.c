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
    return 26;
}

struct song_node * search_song(struct library *lib, char* song, char* artist){
    int i = get_table_index(artist[0]);
    struct song_node *tmp = find_node(lib->table[i], song, artist);
    if (tmp){
        printf("%s by %s was not found.\n", song, artist);
        return tmp;
    }
    printf("%s by %s was found.\n", song, artist);
    return tmp;
} 

struct song_node * search_artist(struct library *lib, char* artist){
    int i = get_table_index(artist[0]);
    struct song_node *tmp = find_node_artist(lib->table[i], artist);
    if (tmp){
        printf("No songs by %s were found.\n", artist);
        return tmp;
    }
    printf("Artist %s was found.\n", artist);
    return tmp;
}

void print_artist(struct library *lib, char *artist){
    int i = get_table_index(artist[0]);
    struct song_node *tmp = lib->table[i];
    printf("All songs by the artist %s:\n", artist);
    while (tmp){
        if (!(tmp->artist.strcmp(artist))){
            print_node(tmp);
        }    
    } 
}

struct library * add_song(struct library *lib, char name[], char artist[]){
    int index = get_table_index(*artist);
    lib->table[index] = insert_ordered(lib->table[index], name, artist);
    return lib;
}

void print_letter(struct library *lib, char chr){
    int index = get_table_index(chr);
    if(lib->table[index]){
        printf("Artists starting with %c\n", index + 65);
        print_list(lib->table[index]);
        printf("\n");
    } else {
        printf("No artists found starting with %c\n\n", index + 65);
    }
}

void print_tab(int index){ //prints letter/symbol that is in table[index]
    if(index != 26) {
        printf("%c\n", 65 + index);
    } else {
        printf("Misc\n");
    }
}

void print_library(struct library *lib){
    for(int i = 0; i < 27; i++){
        if(lib->table[i])
            print_tab(i);
        print_list(lib->table[i]);
    }
    printf("\n");
}
