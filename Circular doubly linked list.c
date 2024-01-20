//cicular doubly linked list by nandini jain
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node*next,*prev;
}node;

node*getnode()
{
   node*p;
	p=(node*)malloc(sizeof(node));
	return p;
}
void insertbeg(node**cdlist,int x){
	node *p,*q;
	p=getnode();
	p->info=x;
	if(*cdlist==NULL){
		p->prev=p->next=p;
		*cdlist=p;
	}
	else{
		q=(*cdlist)->prev;
		p->next=*cdlist;
		(*cdlist)->prev=p;
		p->prev=q;
		q->next=p;
		*cdlist=p;
	}
}
void insertend(node**cdlist,int x){
		node *p,*q;
	p=getnode();
	p->info=x;
	if(*cdlist==NULL){
		p->prev=p->next=p;
		*cdlist=p;
	}
	else{
		q=(*cdlist)->prev;
		p->next=*cdlist;
		(*cdlist)->prev=p;
		p->prev=q;
		q->next=p;
	}

}
node* search(node*cdlist,int x){
	node *p,*q;
	p=cdlist;
	q=p->prev;
	while(p!=q&&p->info!=x)
	p=p->next;
	if(x==p->info)	return(p);
	else return(NULL);
}
void deletenode(node **cdlist,int x){
	node*p,*q;
	p=*cdlist;
	q=p->prev;
	while(p!=q&&p->info!=x)
		p=p->next;
	if(p->info!=x)	printf("node not present");
	else{
		 if((p->prev==p)&&(p->next==p))
		 	*cdlist=NULL;
		else{
				if(p==*cdlist)
					*cdlist=p->next;
				(p->next)->prev=p->prev;
				(p->prev)->next=p->next;
		}
	
	}	free(p);
}
void display( node *cdlist){
	node *p,*q; p=cdlist;
	q=p->prev;
	printf("circular doubly linked list");
	while(p!=q){
		printf("%d=> ",p->info);
		p=p->next;
	}
	printf("%d=> ",p->info);
	printf("\n");
}
void insertafter(node *p, int x){
	node *q;

		q=getnode();
		q->info=x;
		q->next=p->next;
		q->prev=p;
		(p->next)->prev=q;
		p->next=q;
	}

void main(){
	node*cdlist,*p;
	int ch,x,n;
	cdlist=NULL;
	do
	{
		printf("\n 1.insertbeg 2.insertEnd");
		printf("3.search  4.deletenode  5.insertafter \n");
		printf("\n enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\enter the element to insert :");
					scanf("%d",&n);
					insertbeg(&cdlist,n);
				 	display(cdlist);
					break;
					
			case 2 : printf("\enter elements to insert");
						scanf("%d",&x);
						insertend(&cdlist,x);display(cdlist);break;
			case 3:  printf("\enter element to search");
						scanf("%d",&x);
						p=search(cdlist,x);
						if(p==NULL) printf("\n element not present ");
						else printf("\n element is present ");
						break;
			case 4:  printf("\enter element to delete");
						scanf("%d",&x);
						deletenode(&cdlist,x);
						display(cdlist);break;
			case 5:  printf("enter the element you wish to insert after");
						scanf("%d",&x);
						p=search(cdlist,x);
						if(p==NULL)
						   printf("void insertion");
						else
							printf("enter the element to insert");
							scanf("%d",&n);
						  insertafter(p, n);
					 display(cdlist);break;
			default: printf("\n incorrect choice");break;
	}
	}while(ch>=1&&ch<=5);
}
