#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
typedef struct st
{
int rollno;
char name[20];
float marks;
struct st *next;
}SLL;
void add_begin(SLL **);
void add_end(SLL**);
void add_middle(SLL **);
int count_node(SLL *);
void print_node(SLL *);
void save_file(SLL *);
void print_rev(SLL *);
void print_rec(SLL *);
void print_rev_rec(SLL *);
void read_file(SLL **);
void delete_node(SLL **);
void rev_links(SLL **);
void delete_all(SLL **);
void search_node(SLL *);
void sort_data(SLL *);





