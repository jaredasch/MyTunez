//Colin Hosking Jared Asch
//Project 0: MyTunez
//Systems pd05
//2018-10-19

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"
#include "library.h"

int main(){
    srand(time(NULL));

    printf("--------------- Testing Linked List Functions ---------------\n");

    printf("== Testing print_list() for null Linked List ==\n");
    struct song_node *list = 0;
    print_list(list);

    printf("\n== Testing Linked List insert_front ==\n");
    list = insert_front(list, "Despacito", "Luis Fonsi");
    list = insert_front(list, "Replay", "Iyaz");
    print_list(list);

    printf("\n== Testing Linked List insert_ordered()\n");
    list = insert_ordered(list, "Billie Jean", "Michael Jackson");
    list = insert_ordered(list, "Mr. Brightside", "The Killers");
    list = insert_ordered(list, "Smells Like Teen Spirit", "Nirvana");
    list = insert_ordered(list, "Yea!", "Usher");
    print_list(list);

    printf("\n== Testing Linked List find_node() ==\n");
    printf("Searching for Billie Jean by Michael Jackson\n");
    print_node(find_node(list, "Billie Jean", "Michael Jackson"));
    printf("Searching for Replay by Iyaz\n");
    print_node(find_node(list, "Replay", "Iyaz"));
    printf("Searching for Country Roads by John Denver (Not in list)\n");
    print_node(find_node(list, "Country Roads", "John Denver"));

    printf("\n== Testing Linked List find_node_artist() ==\n");
    printf("Searching for the first song by Michael Jackson\n");
    print_node(find_node_artist(list, "Michael Jackson"));
    printf("Searching for the first song by Iyaz\n");
    print_node(find_node_artist(list, "Iyaz"));
    printf("Searching for the first song by Queen (Not in list)\n");
    print_node(find_node_artist(list, "Queen"));

    printf("\n== Testing Linked List random_node() ==\n");
    print_node(random_node(list));
    print_node(random_node(list));
    print_node(random_node(list));
    print_node(random_node(list));
    print_node(random_node(list));

    printf("\n== Testing Linked List remove_node() ==\n");
    printf("Removing Replay by Iyaz\n");
    list = remove_node(list, "Replay", "Iyaz");
    printf("Removing Country Roads by John Denver (Not in list)\n");
    list = remove_node(list, "Country Roads", "John Denver");
    print_list(list);

    printf("\n== Testing Linked List free_list() ==\n");
    list = free_list(list);
    printf("Printing the freed list\n");
    print_list(list);


    struct library *lib = calloc(1, sizeof(struct library));
    printf("\n== Testing Library add_song() and print_library() ==\n");
    add_song(lib, "Billie Jean", "Michael Jackson");
    add_song(lib, "Thriller", "Michael Jackson");
    add_song(lib, "Mr. Brightside", "The Killers");
    add_song(lib, "Smells Like Teen Spirit", "Nirvana");
    add_song(lib, "Yea!", "Usher");
    add_song(lib, "Despacito", "Luis Fonsi");
    add_song(lib, "Replay", "Iyaz");
    add_song(lib, "Purple Haze", "Jimi Hendrix");
    add_song(lib, "I Feel Good", "James Brown");
    print_library(lib);

    printf("\n== Testing Library search_song() ==\n");
    printf("Searching for Billie Jean by Michael Jackson\n");
    print_node(search_song(lib, "Billie Jean", "Michael Jackson"));
    printf("Searching for Country Roads by John Denver (Not in library)\n");
    print_node(search_song(lib, "Country Roads", "John Denver"));

    printf("\n== Testing Library search_artist() ==\n");
    printf("Searching for the first song by Iyaz\n");
    print_node(search_artist(lib, "Iyaz"));
    printf("Searching for the first song by Luis Fonsi\n");
    print_node(search_artist(lib, "Luis Fonsi"));
    printf("Searching for the first song by Beethoven (Not in library)\n");
    print_node(search_artist(lib, "Beethoven"));

    printf("\n== Testing Library print_letter() ==\n");
    printf("Printing songs from aritsts starting with J\n");
    print_letter(lib, 'J');
    printf("Printing songs from aritsts starting with Z\n");
    print_letter(lib, 'Z');

    printf("\n== Testing Library print_artist() ==\n");
    printf("Printing songs from Michael Jackson\n");
    print_artist(lib, "Michael Jackson");
    printf("Printing songs from Usher\n");
    print_artist(lib, "Usher");
    printf("Printing songs from Elvis (Not in list)\n");
    print_artist(lib, "Elvis");

    printf("\n== Testing Library shuffle() ==\n");
    shuffle(lib, 4);

    printf("\n== Testing Library delete_song() ==\n");
    printf("Deleting Thriller by Michael Jackson\n");
    delete_song(lib, "Thriller", "Michael Jackson");
    printf("Removing Country Roads by John Denver (Not in list)\n");
    delete_song(lib, "Country Roads", "John Denver");
    print_library(lib);

    printf("\n== Testing Library free_library() ==");
    lib = free_library(lib);
    print_library(lib);

    return 0;
}
