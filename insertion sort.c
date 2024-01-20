//insertion sort by Nandini Jain
#include<stdio.h>
void InserionSort(int a[20],int n){
	int i,j,item;
	for(j=1;j<n;j++){
		item=a[j];
		i=j-1;
		while(i>0&&a[i]>item){
			a[i+1]=a[i];
			i=i-1;
		}
		a[i+1]=item;
	}
	for(i=0;i<n;i++){
		printf("\n%d",a[i]);
	}
}

void main(){
	int a[30],i,n;
	printf("enter the size of an array");
	scanf("%d",&n);
	printf("enter elements to sort");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	InserionSort(a,n);
}
