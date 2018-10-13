#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "linked_list.h"

struct song_node { 
 	char name[100];
 	char artist[100];
 	struct song_node *next;
};

struct song_node * create_song(char name[], char artist[], struct song_node *next){
	struct song_node *new_node = malloc(sizeof(struct song_node));
	new_node->next = next;
	strcpy(new_node->name, name);
	strcpy(new_node->artist, artist);
	return new_node;
}

struct song_node * insert(struct song_node *head, char name[], char artist[]){
	if(!head || strcmp(artist, head->artist) < 0 || (strcmp(artist, head->artist) == 0 && strcmp(name, head->name) < 0)){
		return create_song(name, artist, head);
	}
	else {
		struct song_node *original_head = head;
		while(strcmp(artist, head->artist) < 0 || (strcmp(artist, head->artist) == 0 && strcmp(name, head->name) < 0)){
			head = head->next;
		}
		head->next = create_song(name, artist, head->next);
		return original_head;
	}
}

struct song_node * remove_song(struct song_node *head, struct song_node *to_remove){
	struct song_node *cur = head;
	while(cur->next != to_remove){
		cur = cur->next;
	}
	cur->next = to_remove->next;
	return head;
}

struct song_node * find_song(struct song_node *head, char *name, char *artist){
	while(strcmp(name, head->name) != 0 || strcmp(artist, head->artist) != 0){
		head = head->next;
		if(!head)	return head;
	}
	return head;
}

struct song_node * find_song_by_artist(struct song_node *head, char *artist){
	while(strcmp(artist, head->artist) != 0){
		head = head->next;
		if(!head)	return head;
	}
	return head;
}

struct song_node * random_song(struct song_node *head){
	int index = rand() % len(head);
	while(index--){
		head = head->next;
	}
	return head;

}

int len(struct song_node *head){
	int len = 0;
	while(head){
		head = head->next;
		len++;	
	}
	return len;
}

struct song_node * free_list(struct song_node *n){
	while(n){
		struct song_node *p = n->next;
		free(n);
		n = p;
	}
	return n;
}

void print_list(struct song_node *n){
	while(n){
		printf("%s - %s\n", n->artist, n->name);
		n = n->next;
	}
}