#include<stdio.h>
#include<time.h>
int partition(int a[],int low,int high);
void qsort(int a[],int low, int high);
int partition(int a[],int low,int high){
	int i,j,temp,key;
	key=a[low];
	i=low+1;
	j=high;
	while(1){
		while(i<high && key>=a[i]){
	
		i++;
	}
		while(key<a[j]){
		
		j--;
	}
		if(i<j){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
		else{
			temp=a[low];
			a[low]=a[j];
			a[j]=temp;
			return j;
		}
	}
}
void qsort(int a[],int low,int high){
	int j;
	if(low<high){
		j=partition(a,low,high);
		qsort(a,low,j-1);
		qsort(a,j+1,high);
	}
}
int main(){
	int i,n,a[20];
	double cpu_used_time;
	clock_t start,end;
	float f;
	printf("Enter the no of elements:\n");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	start=clock();
	qsort(a,0,n-1);
	end=clock();
	cpu_used_time=(double)(end-start)/CLOCKS_PER_SEC;
	printf("the sorted array is :\n");
	for(i=0;i<n;i++)
	printf("%d\t",a[i]);
	printf("time taken= %f seconds",cpu_used_time);
	return 0;
}
