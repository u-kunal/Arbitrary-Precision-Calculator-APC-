#include "apc.h"

void print_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	    while (head)		
	    {
			if(head->prev==NULL){
			}
			else if(head->data<10)
				printf("000");
			else if(head->data>=10 && head->data<=99)
				printf("00");
			else if(head->data>= 100&& head->data<=999)
				printf("0");
		    /* Printing the list */
		    printf("%d", head -> data);
		    /* Travering in forward direction */
		    head = head -> next;
	    }
    	printf("\n");
    }
}