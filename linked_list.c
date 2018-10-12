#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct song_node { 
  char name[256];
  char artist[256];
  struct song_node *next;
};

struct song_node * insert_front(struct song_node *next, char name[], char artist[]){
	struct song_node *new_node = malloc(sizeof(struct song_node));
	new_node->next = next;
	strcpy(new_node->name, name);
	strcpy(new_node->artist, artist);
	return new_node;
}

struct song_node * insert_at_index(struct song_node *node, char name[], char artist[], int index){
	if(!index){
		return insert_front(node, name, artist);
	}
	struct song_node *head = node;
	while(index - 1 > 0){
		node = node->next;
		index--;
	}
	node->next = insert_front(node->next, name, artist);
	return head;
}


void print_list(struct song_node *n){
	while(n){
		printf("%s by %s\n", n->name, n->artist);
		n = n->next;
	}
}

int main(){
	printf("\n");
	struct song_node *list  = insert_front(0, "Replay", "Iyaz");
	print_list(list);

	printf("\n");
	list = insert_front(list, "Dynamite", "Taio Cruz");
	print_list(list);

	printf("\n");
	list = insert_at_index(list, "Thrift Shop", "Macklemore", 2);
	print_list(list);

	return 0;
}