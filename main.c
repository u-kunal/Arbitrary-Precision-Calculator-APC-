/*Name: KUNAL U
Date: 24-12-2024
Reg No: 24022_051*/
#include "apc.h"

int main(int argc,char *argv[])
{
	/* Declare the pointers */
	/*validate oprands if return failure print error messege*/
	if(read_and_validations(argc,argv)==FAILURE){
		printf("Invalid arguments\n");
		printf("....................................\n");
		printf("Plese pass like: ./a.out <Operand1(only digits)> <Operator> <Operand2(only digits)>\n");
		printf("Exit Successfully\n");
		return 0;
	}
	/*declaring linked lists*/
	Dlist *head1=NULL, *tail1=NULL, *head2=NULL, *tail2=NULL, *headR=NULL, *tailR=NULL;
	char option, operator;
	char str1[MAX_SIZE];
	char str2[MAX_SIZE];
	char opr[2];
	int flag1=0,flag4=0;
	/*if operand 1 is greater is pass as 1st opreand*/
	if(my_strlen(argv[3])>my_strlen(argv[1])){
	
		strcpy(str2,argv[1]);
		strcpy(str1,argv[3]);
		flag1=1;
	}
	/*if operand 2 is greater is pass as 2nd opreand*/
	else if(my_strlen(argv[3])<my_strlen(argv[1])){
		strcpy(str1,argv[1]);
		strcpy(str2,argv[3]);
	}
	/*if both are same comparing*/
	else if(my_strlen(argv[3])==my_strlen(argv[1])){
		if(my_strcmp(argv[1],argv[3])>0){
			strcpy(str1,argv[1]);
			strcpy(str2,argv[3]);
		}
		else if(my_strcmp(argv[1],argv[3])==0){
			strcpy(str1,argv[1]);
			strcpy(str2,argv[3]);
			flag4=1;
		}
		else{
			strcpy(str2,argv[1]);
			strcpy(str1,argv[3]);
			flag1=1;
		}

	}
	char ch1=str1[0];
	char ch2=str2[0];
	strcpy(opr,argv[2]);
	int af1=0,af2=0,af3=0,sf1=0,sf2=0,sf3=0,flag2=0;
	/*check operator*/
	if((ch1=='-'&&ch2!='-'&&opr[0]=='+')){
		af1=1;
		opr[0]='-';
	}
	/*if opr1 is -ve and opr2 is +ve and oprator is -ve */
	else if((ch2=='-'&&ch1!='-'&&opr[0]=='+')){
		af2=1;
		opr[0]='-';
	}
	/*if both are -ve passed as addition sign will be -ve*/
	else if(ch1=='-'&&ch2=='-'&&opr[0]=='+'){
		af3=1;
		opr[0]='+';
	}
	/*if*/
	else if(ch1=='-'&&ch2!='-'&&opr[0]=='-'){
		sf1=1;
		if(flag1==1)
			sf1=0;
			flag2=1;
		opr[0]='+';
	}
	else if(ch1!='-'&&ch2!='-'&&opr[0]=='-'){
		if(flag1==1){
			flag2=1;
		}
	}
	else if(ch1=='-'&&ch2=='-'&&opr[0]=='-'){
		sf2=1;
		if(flag1==1)
		  sf2=0;
		opr[0]='-';
	}
	else if(ch2=='-'&&ch1!='-'&&opr[0]=='-'){
		sf3=1;
		if(flag1==0){
			sf3=0;
		}
		opr[0]='+';
	}
	else if((ch1=='-'&&ch2!='-'&&(opr[0]=='X'||opr[0]=='x'))||(ch1!='-'&&ch2=='-'&&(opr[0]=='X'||opr[0]=='x'))){
		sf3=1;
	}
	else if((ch1=='-'&&ch2!='-'&&(opr[0]=='/'))||(ch1!='-'&&ch2=='-'&&(opr[0]=='/'))){
		sf3=1;
	}
	strrev(str1);
	strrev(str2);
	int i=0,flag=1;
	/*opr1 store into linked list*/
	while(str1[i])
	{
		char buffer[4];
		int k=0;
		for(int j=i;(j-i)<4;j++)
		{
			if(str1[j]){
			buffer[k]=str1[j];
			k++;
			}
			else{
				i=j;
				flag=0;
				break;
			}
		}
		buffer[k]=0;
		strrev(buffer);
		int n=atoi(buffer);
		if(n<0){
			n=-n;
		}
		//printf("%d\n",n);
		if((insert_at_first(&head1,&tail1,n))==FAILURE)
			printf("Info: Node is not created!\n");
		if(flag)
		i=i+4;
	}
	i=0;
	flag=1;
	/*opr2 store into linked list*/
	while(str2[i])
	{
		char buffer[4];
		int k=0;
		for(int j=i;(j-i)<4;j++){
			if(str2[j]){
			buffer[k]=str2[j];
			k++;
			}
			else{
				i=j;
				flag=0;
				break;
			}
		}
		buffer[k]=0;
		strrev(buffer);
		int n=atoi(buffer);
		if(n<0){
			n=-n;
		}
		//printf("%d\n",n);
		if((insert_at_first(&head2,&tail2,n))==FAILURE)
			printf("Info: Node is not created!\n");
		if(flag)
		i=i+4;
	}
	print_list(head1);
	printf("%s\n",opr);
	print_list(head2);
	/*perform operations based on operator*/
	switch(opr[0])
	{
		case '+' : /*perform addition*/
				  addition(&head1, &tail1, &head2, &tail2, &headR, &tailR);
				   printf("Perform Addition Successfully\n");
				   printf("The Result is: ");
				   if(af3==1||sf1==1||sf3==1){
					printf("-");
				   }
				   print_list(headR);
				   break;
		case '-' : 	//perform subraction
					subtraction(&head1, &tail1, &head2, &tail2, &headR, &tailR);
					printf("Perform Subraction Successfully\n");
					printf("The result is: ");
					if((af1==1||flag2==1||sf2==1)&&flag4==0){
						printf("-");
					}
					print_list(headR);
					break;
		case 'X':
		case 'x':	
					//perform multiplication
					printf("Perform Multiplication Successfully\n");
					printf("The Result is: ");
					if(sf3==1){
						printf("-");
					}
					multiplication(&head1, &tail1, &head2, &tail2, &headR, &tailR);
					print_list(headR);
					break;
		case '/':	
					//perform division
					printf("Perform Division\n");

					printf("The result is: ");
					if(flag1==1){
						printf("0\n");
						return 0;
					}
					if(sf3==1){
						printf("-");
						division(&head1, &tail1, &head2, &tail2, &headR,&tailR);
					}
					else{
						division(&head1, &tail1, &head2, &tail2, &headR,&tailR);
					}
					break;

	}
	
}
/*string reverse*/
void strrev(char *str)
{
	int len=strlen(str)-1;
	int j=0;
	while(j<=len)
	{
		char temp=str[j];
		str[j]=str[len];
		str[len]=temp;
		j++;
		len--;
	}
}

/**/
int my_strlen(char *str){
	int i=0,c=0;
	if(str[0]=='+'||str[0]=='-'){
		i=1;
	}
	if(str[i]=='0'){
		while(str[i]=='0'){
			i++;
		}
	}
	while(str[i]){
		i++;
		c++;
	}
	return c;
}

int my_strcmp(char *str1,char *str2){
	int i=0,j=0;
	if(str1[0]=='+'||str1[0]=='-'){
		i=1;
	}
	if(str1[i]=='0'){
		while(str1[i]=='0'){
			i++;
		}
	}
	if(str2[0]=='+'||str2[0]=='-'){
		j=1;
	}
	if(str2[j]=='0'){
		while(str2[j]=='0'){
			j++;
		}
	}
	while(str1[i]||str2[j]){
		if(str1[i]!=str2[j]){
			printf("%d\n",str1[i]-str2[j]);
		 	return str1[i]-str2[j];
		}
		i++;
		j++;

	}
	return str1[i]-str2[j];
	
}