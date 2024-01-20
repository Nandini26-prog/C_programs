//linked list menu driven
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int info;
	struct node*next;
}node;

node*getnode()
{
   node*p;
	p=(node*)malloc(sizeof(node));
	return p;
}

void insertbeg(node**list,int x){
	node*p;
	p=getnode();
	p->info=x;
	if(*list ==NULL)*list=p;
	else{
		p->next=*list;
		*list =p;
	}
}

void insertend(node**list,int x){
	node*p,*q;
	p=getnode();
	p->info=x;
	p->next=NULL;
	if(*list==NULL)
	*list=p;
	else{
		for(q=*list;q->next!=NULL;q=q->next);
		q->next=p;
	}
}
node*create(node*list,int n){
	node*p,*q;int i,x;
	printf("enter the elements to create a list\n");
	for(i=0;i<n;i++){
		scanf("%d",&x);
		insertend(&list,x);
	}
	return list;
}
void display(node*list)
{
	printf("\n list elements are =\n");
	while(list!=NULL){
		printf("%d->",list->info);
		list=list->next;
	}
	printf("null");
}
node*search(node*list, int x){
	node*p;
	for(p=list;p!=NULL&&p->info!=x;p=p->next);
	return p;
}
void deletenode(node**list, int x){
	node*p,*q;
	q=NULL;
	for(p=*list;p!=NULL&&p->info!=x;p=p->next)
		q=p;
	if(p==NULL)
		printf("\n element is not present\n");
	else{
			if(p==*list)
				*list=p->next;
				else q->next=p->next;
				free(p);
		}
}
void reverse(node**list){
	node*p,*q,*r;
	p=*list;
	r=NULL;
	while(p!=NULL){
		q=p;
		p=p->next;
		q->next=r;  r=q;
	}
	*list=q;
}

void main(){
	node*list,*p;
	int ch,x,n;
	list=NULL;
	do
	{
		printf("\n1.Createlist 2.insertbeg 3.insertEnd");
		printf("4.search  5.deletenode  6.reverse  7.exit\n");
		printf("\n enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nenter the no. of elements :");
					scanf("%d",&n);
					list=create(list,n); display(list);break;
					
			case 2 : printf("\enter elements to insert");
						scanf("%d",&x);
						insertbeg(&list,x);display(list);break;
			case 3:  printf("\enter elements to insert");
						scanf("%d",&x);
						insertend(&list,x);display(list);break;
			case 4:  printf("\enter elements to search");
						scanf("%d",&x);
						p=search(list,x);
						if(p==NULL) printf("\n element not present ");
						else printf("\n element is present ");
						break;
			case 5:  printf("\enter elements to delete");
						scanf("%d",&x);
						deletenode(&list,x);
						display(list);break;
			case 6:  reverse(&list);
					 display(list);break;
			default: printf("\n incorrect choice");break;
		}
	}while(ch>=1&&ch<=6);
}