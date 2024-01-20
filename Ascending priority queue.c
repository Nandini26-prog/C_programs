//Ascending priority queue
#include<stdio.h>
#include<stdlib.h>
typedef struct nodeptr
{
	int ele,pri;
	struct nodeptr*next;
	
}node;
node *getnode()
{
	node *p;
	p= ((node*)malloc(sizeof(node)));
	return p;
}
void insertpq(node**apq,int x,int y)
{
	node*p,*q; q=NULL;
	for(p=*apq;(p!=NULL)&&(y>p->pri);p=p->next)  
	  q=p;
	p=getnode();
	p->ele=x;  p->pri=y;
	if(q==NULL){
		p->next=*apq;
		*apq=p;
	}
	else{
		p->next=q->next;
		q->next=p;
	}
}
int deletepq(node **apq){
	node *p,*q; int x;
	q=NULL;
	if(*apq==NULL){
		printf("\nQueue is empty");
		return 0;
	}
	else{
		for(p=*apq;p->next!=NULL;p=p->next)
		  q=p;
		x=p->ele;
		if(q==NULL) *apq=NULL;
		else q->next=p->next;
		free(p);
		return x;
	}
}

void display(node *apq)
{ 
   node *p;
   printf("\n APQueue elements:\t");
   for(p=apq;p!=NULL;p=p->next)
   printf("(%d,%d)->",p->ele,p->pri);
}
void main(){
	node *apq; int n,ch,x,y;
	apq=NULL;
	printf("PRIORITY QUEUE");
	do {
		 printf("\n 1.insert 2.delete 3.exit");
		 printf("\n enter your choice");
		 scanf("%d",&ch);
		 switch(ch)
		 {
		 	case 1: printf("Enter elements to insert");
		 			scanf("%d",&x);
		 			printf(" enter its priority");
		 			scanf("%d",&y);
		 			insertpq(&apq,x,y);
		 			display(apq);
		 			break;
		 	case 2: x=deletepq(&apq);
		 			if(x!=0)
		 			  printf("deleted elements is %d",x);
		 			  display(apq);
		 			  break;
		 	case 3: printf("thankyou"); break;
		 			
		 }
	}while(ch>=1&&ch<3);
}

