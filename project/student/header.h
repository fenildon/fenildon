#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<unistd.h>
typedef struct student
{
int rn;
char name[30];
float marks;
struct student *next;
}SLL;

void stud_add(SLL **);
void stud_show(SLL *);
void stud_del(SLL **);
void stud_mod(SLL *);
void stud_del_all(SLL **);
void stud_exit(SLL **);
void del_rn(SLL ***);
void del_name(SLL ***);
void stud_save_file(SLL *);
void stud_del_all(SLL **);
void stud_rev_list(SLL *);
void stud_sort_list(SLL *);
void mod_rn(SLL *);
void mod_name(SLL *);
void mod_perc(SLL *);
int count_node(SLL *);
