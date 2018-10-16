//Colin Hosking Jared Asch
//Project 0: MyTunez
//Systems pd05
//2018-10-19

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linked_list.h"

struct song_node * insert_front(struct song_node *next, char name[], char artist[]){
	struct song_node *new_node = malloc(sizeof(struct song_node));
	new_node->next = next;
	strcpy(new_node->name, name);
	strcpy(new_node->artist, artist);
	return new_node;
}

int compare_songs(char * name1, char * artist1, char * name2, char * artist2){ // Returns 1 if song1 bigger than song2, -1 if other way, 0 if equal
    if(strcmp(artist1, artist2) < 0){
        return 1;
    } else if(strcmp(artist1, artist2) > 0){
        return -1;
    } else {
        return -1 * strcmp(name1, name2);
    }
}

struct song_node * insert_ordered(struct song_node *head, char name[], char artist[]){
    if(!head || compare_songs(name, artist, head->name, head->artist) > 0){
        // printf("Inserted %s in front\n", name);
        return insert_front(head, name, artist);
    } else {
        struct song_node *original_head = head;
        while(head->next != 0 && compare_songs(name, artist, head->next->name, head->next->artist) < 0){
            head = head->next;
        }
        // printf("%s after %s\n", name, head->name);
        head->next = insert_front(head->next, name, artist);
        return original_head;
    }
}

struct song_node * remove_node(struct song_node *head, char name[], char artist[]){
	if(!head)	return 0;
	struct song_node *to_remove = find_node(head, name, artist);

	if(head == to_remove){
		struct song_node * tmp = head->next;
		free(to_remove);
		return tmp;
	}

	struct song_node * cur = head;
	while(1){
		if(!cur->next)	return head;
		if(cur->next == to_remove){
			struct song_node * tmp = cur->next;
			free(to_remove);
			return tmp;
		}
		cur = cur->next;
	}
}

struct song_node * find_node(struct song_node *head, char *name, char *artist){
	while(strcmp(name, head->name) != 0 || strcmp(artist, head->artist) != 0){
		head = head->next;
		if(!head)	return head;
	}
	return head;
}

struct song_node * find_node_artist(struct song_node *head, char *artist){
	while(strcmp(artist, head->artist) != 0){
		head = head->next;
		if(!head)	return head;
	}
	return head;
}

struct song_node * random_node(struct song_node *head){
	int index = rand() % len(head);
	// printf("%d\n", index);
	while(index--){
		head = head->next;
	}
	return head;
}

struct song_node * free_list(struct song_node *n){
	while(n){
		struct song_node *p = n->next;
		free(n);
		n = p;
	}
	return n;
}

int len(struct song_node *head){
	int len = 0;
	while(head){
		head = head->next;
		len++;
	}
	return len;
}

void print_list(struct song_node *n){
	while(n){
		printf("%s : %s\n", n->artist, n->name);
		n = n->next;
	}
}

void print_node(struct song_node *n){
	if(n){
		printf("%s : %s\n", n->artist, n->name);
	}
	else {
		printf("Null\n");
	}
}
