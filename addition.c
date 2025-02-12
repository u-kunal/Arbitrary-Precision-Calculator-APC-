
#include "apc.h"
/*perform addition*/
void addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
	int carry=0,sum=0;
	Dlist *temp1=*tail1;
	Dlist *temp2=*tail2;
	/*travese list until reaching null*/
	while(temp1||temp2){
		if(temp1)
			sum=temp1->data;//sum the data from first list
		else
			sum=0;
		if(temp2)
			sum=sum+ (temp2->data);//sum the data from second list
		else 
			sum=sum+0;
		sum = carry + sum;/*get sum*/
		carry = sum / 10000;
        sum = sum % 10000;
		/*insert sum into result list*/
		if((insert_at_first(headR,tailR,sum))==FAILURE)
			printf("Info: Node is not created!\n");
		//traverse through the nodes
        if (temp1)
            temp1 = temp1->prev;
        if (temp2)
            temp2 = temp2->prev;
	}
	/*at last insert carry*/
	if(carry){
		if((insert_at_first(headR,tailR,carry))==FAILURE)
			printf("Info: Node is not created!\n");
	}

}
