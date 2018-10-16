struct library {
    struct song_node * table[27];
};

struct library * insert_song(struct library *, char[], char[]);

void print_library(struct library *);

void print_letter(struct library *, char);

int get_table_index(char);
