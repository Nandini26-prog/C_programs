//radix sort by nandini jain
#include<stdio.h>


void radixsort(int a[10],int n);

void radixsort(int a[10],int n)
{
int bkt[10][10],nelebkt[10],mxele,maxno,ndgt,itr,i,j,k,bktno,radix;
mxele=a[0]; ndgt=0;
for(i=1;i<n;i++) // find maxno from array
if(a[i]>mxele) mxele=a[i];
maxno=mxele;
while(mxele != 0) // find the no. of digits
{ ndgt++; mxele=mxele/10;
}
printf("\n maxele =%d no of digit=%d",maxno,ndgt);
radix=1;
for(itr=0;itr<ndgt;itr++)
{
for(i=0;i<10;i++) nelebkt[i]=0; // initialize no of elements in each bucket to zero
for(i=0;i<n;i++)
{ bktno=(a[i]/radix)%10; // find bucket to insert the element
bkt[bktno][nelebkt[bktno]]=a[i];
nelebkt[bktno] +=1;
}
k=0;
for(i=0;i<10;i++)
for(j=0;j<nelebkt[i];j++)
a[k++]=bkt[i][j];
radix= radix*10;
printf("\n element sorted on ssignificatn place-%d\n",itr+1);
for(i=0;i<n;i++)
printf("%d\t",a[i]);
}
}
void main()
{

int n,i,a[10];
printf("\nEnter the number of elements");
scanf("%d",&n);
printf("\nEnter the array elements for sorting");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("\nOriginal array:\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
radixsort(a,n);
printf("\nArray after sort\n");
for(i=0;i<n;i++)
printf("%d\t",a[i]);
}

// void radixsort(int a[],int n){
// 	int r[20][10],i,ele,j;
// 	for(i=0;i<20;i++)
// 		for(j=0;j<10;j++){
// 			r[i][j]=0;
//		 }
// 	j=0;
// 	for(i=0;i<n;i++){
// 		ele=a[i]%10;
// 		if(ele==0)
// 			ele=a[i];
// 		if(r[j][ele]!=0) //check this further
// 			j++;
// 		r[j][ele]=a[i];
//	 }
//	while(i<n){
//	 	if(r[j][ele]!=0){
//	 	 a[i]=r[j][ele];
//	 	 i++;
//	 	 j++;
//	 	 ele++;
//	 }
//	 radixsort(a,n);
//	 printf("\n count");
// }
//}
// 
// void main(){
// 	int a[20],i,n;
// 	printf("enter the size of the array");
// 	scanf("%d",&n);
// 	printf("enter the elements you want to insert");
// 	for(i=0;i<n;i++){
// 		scanf("%d",&a[i]);
//	 }
//	 radixsort(a,n);
//	 printf("sorted elements are:");
//	 	for(i=0;i<n;i++){
//	 		printf("%d\t", a[i]);
//		 }
// }