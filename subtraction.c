
#include "apc.h"
/*perform subraction*/
void subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	int barrow=0,differ=0;
	Dlist *temp1=*tail1;
	Dlist *temp2=*tail2;
	/*travese list until reaching null*/
	while(temp1||temp2){	
		if(((temp1?temp1->data:0)) < (temp2?temp2->data:0))
		{
			differ=(temp1?temp1->data:0) +10000-barrow - (temp2?temp2->data:0) ;//get differ
			barrow=1;			
		}
		else if((temp1?temp1->data:0) > (temp2?temp2->data:0))
		{	
			differ=(temp1?temp1->data:0)-barrow-(temp2?temp2->data:0) ;//get differ
			barrow=0;
		}
		else if(temp1->data==0&&barrow==1){
			differ=10000-barrow ;//get differ
		}
		else{
			differ=(temp1?temp1->data:0)-barrow-(temp2?temp2->data:0) ;//get differ
			barrow=0;
		}
		if(temp1->prev!=NULL || differ!=0)
		if((insert_at_first(headR,tailR,differ))==FAILURE)//insert differ into nodes
			printf("Info: Node is not created!\n");
		//travese nodes
		if(temp1)
			temp1=temp1->prev;
		if(temp2)
			temp2=temp2->prev;
	}
}




 