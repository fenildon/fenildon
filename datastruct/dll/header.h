#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#define RED "\033[31;1m"
#define GREEN "\033[32;1m"
#define RESET "\033[0m"
#define MEG "\033[33;1m"
typedef struct st
{
int rn;
char name[20];
struct st *next;
struct st *prev;
}DLL;
extern DLL *head;
void add_end();
void add_middle();
void add_begin();
void print_node();
void print_rev();
int count_node();
void rev_links();
void search_name();
void save_file();
void read_file();
void delete_node();
void delete_all();
void delete_pos();
void sort_data();
void rev_data();



