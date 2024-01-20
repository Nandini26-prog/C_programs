//bubble sort by Nandini Jain
#include<stdio.h>
void swap(int *x,int *y);
void BubbleSort(int a[30],int n){
	int i,j;
	for(i=0;i<n-1;i++){         //here i is for passes
		for(j=0;j<n-i-1;j++)
			if(a[j]>a[j+1])
			 swap(&a[j],&a[j+1]);  
//without pointer it will be a call by value function which do not changes the value at that particular index throughout; for that we have to call it by refrence
			 
	}
	
}
void swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;

}
void main(){
    int a[30],n,k;
    printf("enter the size of the array");
    scanf("%d",&n);
    printf("enter elements");
    for(k=0;k<n;k++){
    	scanf("%d",&a[k]);
	}
	BubbleSort(a,n);
	printf("sorted array is\n");
	for(k=0;k<n;k++){
		printf("\n%d",a[k]);
	}

}
