#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1
#define MAX_SIZE 200
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
/*str reverse*/
void strrev(char *str);
/*insert at first*/
int insert_at_first(Dlist **head,Dlist **tail,int data);
/*finding length of the string*/
int my_strlen(char *str);
/*compare two strings*/
int my_strcmp(char *str1,char *str2);
/*for addition*/
void addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
/*print list*/
void print_list(Dlist *head);
/*for subraction*/
void subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
/*read and validations*/
int read_and_validations(data_t argc,char **argv);
/*multiplication*/
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR);
/*delete list*/
int dl_delete_list(Dlist **head, Dlist **tail);
/*insert data*/
int insert(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2);
/*division*/
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR);
/*division checking*/
int checking(Dlist **head,Dlist **tail,Dlist **head2,Dlist **tail2);
/*length*/
int list_length(Dlist *head);
/*repeate the stament getting zeros*/
int repeat(Dlist **temp_head1, Dlist **temp_tail1, Dlist **temp_head2, Dlist **temp_tail2, Dlist **temp_res_head, Dlist **temp_res_tail);
/*remove leading zeros from division*/
void remove_leading_zeros(Dlist **head, Dlist **tail);
int check_greater(Dlist *head1, Dlist *head2);
#endif
