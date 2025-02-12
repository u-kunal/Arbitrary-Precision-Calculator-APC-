
#include "apc.h"

int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
	/* Definition goes here */
	Dlist *temp1=*tail1;
	Dlist *temp2=*tail2;
	unsigned long long int carry=0,rem,res,count=0,mul=1;
	int num=temp2->data;
	Dlist *result=NULL;
	Dlist *rres=NULL;
	Dlist *list=NULL;
	Dlist *rlist=NULL;
	//insert result at first
	if((insert_at_first(&result,&rres,0))==FAILURE)
			printf("Info: Node is not created!\n");
	//traverse through the node
	while(temp2){
		
		rem=num%10;
		res=temp1->data * rem * mul+carry;//get result
		if(temp1->next==NULL){
			//if count is not zero multilty result with 10 
			for(int i=0;i<count;i++){
				res=res*10;
				mul=mul*10;
				
			}
		}
		carry=res/10000;
		res=res%10000; 
		//insert the result
		if((insert_at_first(&list,&rlist,res))==FAILURE)
			printf("Info: Node is not created!\n");
		 //print_list(list);
		temp1=temp1->prev;
		//if temp1 became null
		if(temp1==NULL){
			if(carry!=0){
			if((insert_at_first(&list,&rlist,carry))==FAILURE)
			printf("Info: Node is not created!\n");
			}
			//print_list(list);
			//perform addition on result
			addition(&list, &rlist, &result, &rres, headR, tailR);
			//delete list
			dl_delete_list(&result,&rres);
			dl_delete_list(&list,&rlist);
			insert(&result,&rres,headR,tailR);//insert result list into rresult
			dl_delete_list(headR,tailR);
			num/=10;
			temp1=*tail1;
			count++;
			// printf("%ld\n",count);
			carry=0;
			mul=1;
		}
		if(num==0){
			
			temp2=temp2->prev;
			if(temp2!=NULL)
			num=temp2->data;
			carry=0;
			mul=1;
		}

	}
	insert(headR,tailR,&result,&rres);
	dl_delete_list(&result,&rres);
}

//deleting list
int dl_delete_list(Dlist **head, Dlist **tail)
{
    if(*head==NULL){
        return FAILURE;
    }
    Dlist *temp=*head;
    while(temp!=NULL){
        *head=(*head)->next;
        free(temp);
        temp=*head;
    }
    *tail=NULL;
    return SUCCESS;
}
//insert one list into another
int insert(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2){
	Dlist *temp=*tail2;
	while(temp!=NULL){
		int n=temp->data;
		if((insert_at_first(head1,tail1,n))==FAILURE)
			printf("Info: Node is not created!\n");
		temp=temp->prev;
	}
	return SUCCESS;
}