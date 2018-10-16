#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"
#include "library.h"

int get_table_index(char chr){
    if(65 <= chr && chr <= 90)
        return (int ) chr - 'A';
    return 26;
}

void print_tab(int index){
    if(index != 26) {
        printf("%c\n", 65 + index);
    } else {
        printf("Misc\n");
    }
}

struct library * insert_song(struct library *lib, char name[], char artist[]){
    int index = get_table_index(*artist);
    lib->table[index] = insert(lib->table[index], name, artist);
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

void print_library(struct library *lib){
    for(int i = 0; i < 27; i++){
        if(lib->table[i])
            print_tab(i);
        print_list(lib->table[i]);
    }
    printf("\n");
}
