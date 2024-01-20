//linear search by Nandini Jain
#include<stdio.h>
int linearsearch(int a[50],int x,int n);
int main(){
	int a[50],x,n,i,ans;
	printf("enter the size of the array");
	scanf("%d",&n);
	printf("enter the elements");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\n enter the element to search\n");
	scanf("%d",&x);
	
	ans=linearsearch(a,x,n);
	if(ans==-1){
		printf("element is not present");
	}
	else
	  printf("element is at %d",ans+1);
}
int linearsearch(int a[50],int x,int n){
	int j;
	j=0;
	while(j<n&&a[j]!=x){
		j=j+1;
	}
	if(a[j]==x)
	  return j;
	else
	  return -1;
}
