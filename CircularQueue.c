//circular queue implementation by Nandini Jain
#include<stdio.h>
#define max 10
struct cqueue{
	int item[max];
	int front,rear;
};
void insertcq(struct cqueue*cq,int x){
//	temp=cq->rear;
	if(cq->rear==max-1)
		printf("queue is overflow");
	else{
		cq->rear++;	
		cq->item[cq->rear]=x;
	}
}
void deletecq(struct cqueue *cq){
	int x;
	if(cq->rear<cq->front)
		printf("queue is overflow");
	else{
		x=cq->item[cq->front];
		cq->front++;
		printf("deleted item is = %d",x);
		if(cq->rear < cq->front){
			cq->rear=-1;
			cq->front=0;
		}
	}
}
int emptycq(struct cqueue *cq){
	if(cq->front ==cq->rear)
		return 1;
	else return 0;
}

void displaycq(struct cqueue cq){
	int i;
	printf("queue elements are = \n");
	for(i=cq.front;i<=cq.rear;i++)
		printf("%d\t",cq.item[i]);
}
void main(){
	struct cqueue cq;
	int ch,x;
	cq.front=max-1,cq.rear=max-1;
	do
	{ printf("\n 1.insertcq	2.deletecq	3.displaycq	4.exit\n");
	printf("enter your choice\n");
	scanf("%d",&ch);
	switch(ch)
	{	case 1: printf("\nenter element to insert");
				scanf("%d",&x);
				insertcq(&cq,x);
				displaycq(cq);break;
		case 2: deletecq(&cq)	;
				displaycq(cq);break;
		case 3: displaycq(cq);break;
		case 4: printf("thankyou")	;
		default: ("\n incorrect input");break;
	}
	}
	while(ch>=1&&ch<=3);
}
