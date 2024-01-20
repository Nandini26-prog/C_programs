//Binary Search by Nandini Jain
#include<stdio.h>
int BinarySearch(int a[30],int n,int x){
	int j=-1;
	int low=0, high=n-1;

	while(low<=high&&(j==-1)){
		int mid=(low+high)/2;   //need to update the value of mid as well,therefore in the loop
		if(x==a[mid])
		  j=mid;
		else if(x<a[mid])
		  high=mid-1;
		else
		  low=mid+1;
	}
	return j;
}

void main(){
	int a[30],size,ele,i;
	printf("enter the size of array");
	scanf("%d",&size);
	printf("enter the elements");
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	printf("enter the element you want to search");
	scanf("%d",&ele);
	int j=BinarySearch(a,size,ele);
	if(j==-1)
	  printf("\nelement not found");
	else
	    printf("\nelement is found at %d",j+1);
}
