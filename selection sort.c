//selection sort by nandini jain
#include<stdio.h>
void selectionsort(int a[50],int n);
int main(){
	int a[50],n,i;
	printf("enter the size of the element");
	scanf("%d",&n);
	printf("enter the elements");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
 selectionsort(a,n);
 printf("\nsorted are\n");
    for(i=0;i<n;i++){
	    printf("%d\t",a[i]);	  
	}
  return 0;
}
	
 void selectionsort(int a[50],int n){
	int i,j,k,temp;
	for(i=1;i<=n;i++){
		k=i;
		for(j=i+1;j<=n;j++){
			if(a[j]<a[k])
			 k=j;
		}
	 if(i!=k){
	 	temp=a[i];
	 	a[i]=a[k];
	 	a[k]=temp;
	 }
	}
}
