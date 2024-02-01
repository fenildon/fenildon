#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#define RED "\033[1;31m"
#define MEG "\033[1;35m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"
typedef struct student
{
int rollno;
char name[20];
float marks;
struct student *next;
}CSLL;
extern CSLL *hptr; 
void add_begin(void);
void add_end(void);
void add_middle(void);
int count_node(void);
void print_node(void);
void print_rev(void);
void print_rec(CSLL *);
void print_rev_rec(CSLL *);
void read_file(void);
void save_file(void);
void rev_links(void);
void sort_data(void);
void delete_node(void);
void delete_all(void);
void delete_pos(void);
void search_node(void);
void rev_links_dma(void);




