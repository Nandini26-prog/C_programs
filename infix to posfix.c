//infix to postfix by Nandini Jain
#include<stdio.h>
#define max 20
struct stack{
	int top;
	char item[max];
};
void push(struct stack*s,char x){
	if(s->top==max-1)
	printf("\n stack is overflow");
	else{
		s->top++;
		s->item[s->top]=x;
		
	}
}
char pop(struct stack*s){
	char x;
	if(s->top==-1){
		printf("\n stack is undeflow");
		x='0';
	}
	else{
		x=s->item[s->top];
		s->top--;
	}
	return x;
}
int empty (struct stack s){
	if(s.top==-1)
	return 1;
	return 0;
}
char stacktop(struct stack s){
	if(!empty (s))
	 return s.item[s.top];
	 else return '0';
}
int isopr(char symb){
	if((symb>'A'&&symb<='Z')||(symb>'a'&&symb<='z'))
	return 1;
	else
	return 0;
}
int prcd(char symb){
	int p;
	switch(symb)
	{
		case '$':p=3; break;
		case '/':
		case '*':p=2;break;
		case '+':
		case '-':p=1;break;
		case ')':p=0;break;
		case '(':p=-1;break;
	}
	return (p);
}
void conv(char infix[],char postfix[]){
	int i=0,j=0;
	char symb,topsymb;
	struct stack s;
	s.top=-1;
	while(infix[i]!='\0'){
		symb=infix[i];
		if(symb=='(')
		push (&s,symb);
		else if(isopr(symb)){
			postfix[j]=symb;
			j++;
		}
		else{
			if(stacktop(s)=='$')
			while(!empty(s)&&(prcd(stacktop(s))>prcd(symb))){
				topsymb=pop(&s);
				postfix[j]=topsymb;
				j++;
			}
			else while(!empty(s)&&(prcd(stacktop(s))>=prcd(symb)))
			{
				topsymb=pop(&s);
				postfix[j]=topsymb;
				j++;
			}
			if(empty(s)||symb!=')')
			push (&s,symb);
			else topsymb=pop(&s);
		}
		i++;
	}
	while(!empty(s)){
		topsymb=pop(&s);
		postfix[j]=topsymb;
		j++;
	}
	postfix[j]='\0';

}
int main(){
	char infix[max],postfix[max];
	printf("\nenter an infix expression");
	gets(infix);
	conv(infix,postfix);
	printf("postfix epr is");
	puts(postfix);
	return 0;
}