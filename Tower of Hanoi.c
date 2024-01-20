//tower of hanoi by Nandini Jain
#include<stdio.h>
void towerOfHanoi (int n,char ta,char tb,char tc){
	if(n==1)
		printf("\n move disk %dth from tower %c to tower %c ",n,ta,tc);
	else{
		towerOfHanoi(n-1,ta,tc,tb);
		printf("\n move disk %d from tower %c to tower %c",n,ta,tc);
		towerOfHanoi(n-1,tb,ta,tc);
	}
}

void main(){
	int n; char ta,tb,tc;
	ta='A';
	tb='B';
	tc='C';
	printf("\n enter the no. of disks");
	scanf("%d",&n);
	towerOfHanoi(n,ta,tb,tc);
}