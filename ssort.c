#include<stdio.h>
#include<time.h>
void ssort(int arr[],int n){
	int i,j,temp,minIDX;
	for(i=0;i<n-1;i++){
		minIDX=i;
		for(j=i+1;j<n;j++){
			if(arr[j]<arr[minIDX]){
				minIDX=j;
			}
		}
		temp=arr[minIDX];
		arr[minIDX]=arr[i];
		arr[i]=temp;
	}
}
int main(){
	int i,n
	clock_t start,end;
	double cpu_time_used;
	printf("Enter the number of elements:\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	start=clock();
	ssort(arr,n);
	end=clock();
	printf("The sorted array is :\n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
	}
	cpu_time_used=(double)(end-start)/CLOCKS_PER_SEC;
	printf("The time taken is %f seconds",cpu_time_used);
	return 0;
}

