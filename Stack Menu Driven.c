//Menu Driven prog. of Stack by Nandini Jain
#include<stdio.h>
#define max 20
int top;
void push(float st[max],float x){
	if(top==max-1)
		printf("stack underflow");
	else{
		top=top+1;
		st[top]=x;
	}
}
int empty(float st[max]){
	if(top==-1)
	  return 1;
	else
	  return 0;
}

float pop(float st[max]){
	float x;
	if(empty(st)){
		printf("stack is underflow");
		x=0;
	}
	else{
		x=st[top];
		top=top-1;
	}
	return x;
}

float peep(float st[max]){
	if(!empty(st))
		return (st[top]);
	else
		return 0;
}
void display(float st[max]){
	int i;
	printf("\nstack elements are");
	for(i=top;i>=0;i--){
		printf("\n%.2f",st[i]);
	}
}

void main(){
	float st[max],item;
	int ch;
	top=-1;
	do{printf("\n enter your choice-1.push 2.pop 3.peep 4.exit ");
	   printf("\nenter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter the element to insert ");
					scanf("%f",&item);
					push(st,item);
					display(st);break;
			case 2: item=pop(st);
					if(item!=0)
						printf("\ndeleted item is %f",item);
					display(st);break;
			case 3: item=peep(st);
					if(item!=0)
						printf("\ntop item is %f",item);
					display(st);break;	
			case 4: printf("Bye!")	;
					break;
			default: printf("invalid choice");	break;
		}
		
	}while(ch>=1&&ch<=3);
}

