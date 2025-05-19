#include<stdio.h>
#include<time.h>
void mergesort(int *,int,int);
void merge(int *,int,int,int);

void mergesort(int a[],int low,int high){
	int mid;
	if(low<high){
		mid=(low+high)/2;
		mergesort(a,low,mid);
		mergesort(a,mid+1,high);
		merge(a,low,mid,high);
	}
}
void merge(int a[],int low,int mid,int high){
	int i,j,k,h,b[20];
	h=i=low;
	j=mid+1;
	while(h<=mid && j<=high){
		if(a[h]<a[j])
		b[i++]=a[h++];
		else
		b[i++]=a[j++];
		if (h > mid) {
    for (k = j; k <= high; k++)
        b[i++] = a[k];
} else {
    for (k = h; k <= mid; k++)
        b[i++] = a[k];
}

for (k = h; k <= high; k++)
    a[k] = b[k]; 

		
		
	}
}

void main(){
	int i,n,a[20];
	double cpu_time_used;
	clock_t start,end;
	printf("Enter the limit:");
	scanf("%d",&n);
	printf("Enter the elements:");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	start=clock();
	mergesort(a,0,n-1);
	end=clock();
	printf("The sorted array is:\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	cpu_time_used=(double)(end-start)/CLOCKS_PER_SEC;
	printf("The time taken is : %f seconds",cpu_time_used);
}

