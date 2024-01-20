#include<stdio.h>
int main(){
	int x[]={2,4,6,8,10},*p,i;
	p=&x[0];
	for(i=0;i<5;i++){
		printf("%u-%d\n",p,*p);
		p=p+1;
	}
}
