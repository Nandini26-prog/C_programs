//descending priority queue by nandini jain
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{	int ele;
	int pri;
	struct node *next;
}node;

node *getnode()
{ node *p;
	p=(node* )malloc(sizeof(node));
	return p;
}

void insertpq(node **dpq,int x,int y)
{
	node *p,*q;
	q=NULL;
	for(p=*dpq;(p!=NULL)&&(y<p->pri);p=p->next)
		 q=p;
	p=getnode();
	p->ele=x;  p->pri=y;
	if(q==NULL){
		p->next=*dpq;
		*dpq=p;
	}
	else{
		p->next=q->next;
		q->next=p;
	}
}
void deletepq(node **dpq){
	node *p; int x;
	if(*dpq==NULL){
		printf("\nQueue is empty");
		return;
	}
	p=*dpq;
	x=p->ele;
	*dpq=p->next;
	free(p);
	printf("deleted element is: %d",x);
	
}
void display(node *dpq)
{ 
   node *p;
   printf("\n dpqueue elements:\t");
   for(p=dpq;p!=NULL;p=p->next)
   printf("(%d,%d)->",p->ele,p->pri);
}
void main(){
	node *dpq; int n,ch,x,y;
	dpq=NULL;
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
		 			insertpq(&dpq,x,y);
		 			display(dpq);
		 			break;
		 	case 2: deletepq(&dpq);
		 			  display(dpq);
		 			  break;
		 	case 3: printf("thankyou"); break;
		 			
		 }
	}while(ch>=1&&ch<3);
}