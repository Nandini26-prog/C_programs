//quick sort by Nandini Jain  (hoare partition)
#include<stdio.h>
void quicksort(int a[10],int low,int high);
int partition(int a[10],int low,int high);
void swap(int *x,int *y);
void main(){
	int a[10],n,i;
	printf("enter the size of the array");
	scanf("%d",&n);
	printf("enter elements of array to sort");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
    quicksort(a,0,n-1);
   	printf("sorted array is \n");
	for(i=0;i<n;i++){
		printf("%d\t",a[i]);
	}
}
void quicksort(int a[10],int low,int high){
	int j,i;
	if(low<high){
		j=partition(a,low,high);
		quicksort(a,low,j-1);
		quicksort(a,j+1,high);
	}

}

int partition(int a[10],int low,int high){
	int x,i,j;
	x=a[low];
	i=low,j=high;
	while(i<j){
		while(a[i]<=x)  i=i+1;
		while(a[j]>x)	j=j-1;
		if(i<j)		swap(&a[i],&a[j]);
	}
	swap(&a[low],&a[j]);
	return (j);
}

void swap(int *x,int *y){
	int temp;
	temp=*x;
	*x=*y;
	*y=temp;
}