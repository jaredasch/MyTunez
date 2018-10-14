#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"

int main(){
    srand(time(NULL));

    struct song_node * song_list = 0;
    song_list = insert(song_list, "Don't Stop Me Now", "Queen");
    print_list(song_list);

    song_list = insert(song_list, "Bohemian Rhapsody", "Queen");
    print_list(song_list);

    song_list = insert(song_list, "Replay", "Iyaz");
    print_list(song_list);

    song_list = insert(song_list, "We Will Rock You", "Queen");
    print_list(song_list);

    song_list = insert(song_list, "Despacito", "Luis Fonsi");
    print_list(song_list);

    return 0;
}
