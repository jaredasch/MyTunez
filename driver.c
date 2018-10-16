#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "linked_list.h"
#include "library.h"

int main(){
    srand(time(NULL));

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
    list = insert_ordered(list, "Yea", "Usher");
    print_list(list);

    printf("\n== Testing Linked List find_node() ==\n");
    printf("Searching for Billie Jean : Michael Jackson\n");
    print_node(find_node(list, "Billie Jean", "Michael Jackson"));
    printf("Searching for Replay : Iyaz\n");
    print_node(find_node(list, "Replay", "Iyaz"));
    printf("Searching for Country Roads : John Denver (Not in list)\n");
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
    printf("Removing Replay : Iyaz\n");
    list = remove_node(list, "Replay", "Iyaz");
    printf("Removing Country Roads : John Denver (Not in list)\n");
    list = remove_node(list, "Country Roads", "John Denver");
    print_list(list);

    printf("\n== Testing Linked List free_list() ==\n");
    list = free_list(list);
    printf("Printing the freed list\n");
    print_list(list);

    return 0;
}
