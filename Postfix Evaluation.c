//evaluation of postfix expression by Nandini Jain
#include<stdio.h>
#include<math.h>
#include<string.h>
#define size 20
struct stack
{
	float item[size];
	int top;
	
};
float eval(char[]);
void push(struct stack*,float );
float pop(struct stack *);
int empty(struct stack );
float prcs(float,float ,char );
int isopr(char );
float findvalue(char );

void main(){
	float c;
	int i;
	char expr[size];
	printf("\n enter a postfix expr");
	for(i=0;i<strlen(expr);i++){
		scanf("%c",&expr[i]);
	}
	c=eval(expr);
	printf("ans:=%.2f",c);
}
float eval(char expr[]){
	int i=0,j=0;
	float value,opr1,opr2,p;
	char symb;
	struct stack s;
	s.top=-1;
	while(expr[i]!='\0'){
		symb=expr[i];
		if(isopr(symb))
		{
			p=findvalue(symb);
			push(&s,p);
			}
			else{
				opr2=pop(&s);
				opr1=pop(&s);
				value=prcs(opr1,opr2,symb);
				push(&s,value);
			}
			i++;
		}
		if(!empty(s))
		return(s.item[s.top]);	
	}
	
void push(struct stack*ps,float symb)
	{
		ps->top++;
		ps->item[ps->top]=symb;
	}
float pop(struct stack *ps){
		float x;
		x=ps->item [ps->top];
		ps->top--;
		return x;
	}
int isopr(char symb){
		if(symb>='a'&&symb<='z')
		return 1;
		return 0;
	}
int empty(struct stack s){
		if(s.top==-1)
			return 1;
		return 0;	
	}
float prcs(float a,float b,char symb){
	float c;
	switch (symb){
		case '+':c=a+b;break;
		case '-':c=a-b;break;
		case '*':c=a*b;break;
		case '/':c=a/b;break;
		case '$':c=pow(a,b);break;
	} return c;
}
float findvalue(char symb){
		float p;
		printf("enter the values of %c",symb);
		scanf("%f",&p);
		return p;
	
}
