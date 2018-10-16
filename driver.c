#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"
#include "library.h"

int main(){
    srand(time(NULL));

    struct library *lib = calloc(1, sizeof(struct library));
    insert_song(lib, "Don't Stop Me Now", "Queen");
    insert_song(lib, "Bohemian Rhapsody", "Queen");
    insert_song(lib, "Replay", "Iyaz");
    insert_song(lib, "We Will Rock You", "Queen");
    insert_song(lib, "Despacito", "Luis Fonsi");
    insert_song(lib, "Counting Stars", "1Republic");

    print_library(lib);
    print_letter(lib, 'K');

    return 0;
}
