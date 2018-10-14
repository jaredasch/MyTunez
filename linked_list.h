struct song_node * insert_front(struct song_node *, char[], char[]);

struct song_node * insert(struct song_node *, char[], char[]);

struct song_node * remove_song(struct song_node *, struct song_node *);

struct song_node * find_song(struct song_node *, char *, char *);

struct song_node * find_song_by_artist(struct song_node *, char *);

struct song_node * random_song(struct song_node *);

struct song_node * free_list(struct song_node *);

int compare_songs(char *, char *, char *, char *);

int len(struct song_node *);

void print_list(struct song_node *);
