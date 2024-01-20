//circular linked list with header node
#include<stdio.h>
#include<stdlib.h>
typedef struct nodeptr
{
	int info;
	struct nodeptr*next;
}node;
node *getnode()
{
	return ((node*)malloc(sizeof(node)));
}

void insertbeg(node**head,int x)
{
	node*p,*q;
	p=getnode();
	p->info=x;
	p->next=(*head)->next;
	(*head)->next=p;                                    
	
}
void deletefirst(node **head)
{
	int x;
	node*p,*q;
	p=(*head)->next;
	if(p==*head) printf("circular linkedlist is empty");
	else{
		x=p->info;
		(*head)->next=p->next;
		free(p);
	}
}
void insertatend(node**head,int x){
	node*p,*q;
	p=getnode();   p->info=x;
	q=(*head)->next;
	while(q->next!=*head)
		q=q->next;
	p->next=*head;  q->next=p;
}
void deletenode(node **head,int x){
	node *p,*q;
	q=*head;  p=(*head)->next;
	while(p!=*head&&p->info!=x){
		q=p;
		p=p->next;
	}
	if(p==*head)
	printf("\n element not present");
	else
	{
		q->next=p->next;
		free(p);
	}
}
void sumavg(node *head){
	int sum=0, count=0;  float avg=0;
	node *p;
	p=head->next;
	while(p!=head){
		sum+=p->info;
		count++;
		p=p->next;
	}
	avg=(float)sum/count;
	printf("\n sum of node vaue=%d",sum);
	printf("\n avg of node vaue=%0.2f",avg);
}
void display(node *head){
	node *p;
	p=head->next;
	printf(" \n circular linked list\n");
	printf("head->  ");
	while(p!=head)
	{
		printf("%d->",p->info);
		p=p->next;
	}
}
void main(){
	node *head;
	int ch,x;
	head=getnode();
	head->info=0;
	head->next=head;
	do
	{
		printf("  1.insertatbeg  2.deletefirst   3.insertatend  4.deletenode 5.sumavg  6.exit\n");
		printf(" Enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter element to insert:");
				scanf("%d",&x);
				insertbeg(&head,x);
				display(head);
				break;
			case 2: deletefirst(&head);
					display(head);
					break;
			case 3: printf("enter element to insert :");
					scanf("%d",&x);
					insertatend(&head,x);
					display(head);  break;
			case 4: printf("enter element to delete :");
					scanf("%d",&x);
					deletenode(&head,x);
					display(head);  break;
			case 5: sumavg(head);
					break;
			case 6: printf("Thankyou");
					break;
					
		}
	}while(ch>=1&&ch<=5);
}
