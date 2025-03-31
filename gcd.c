// A C program to find the GCD using Euclid's algorithm, Middleschool procedure, and Factorization algorithm
#include<stdio.h>
int euclid(int a,int b);
int mschool(int a,int b);
int pfactorization(int a,int b);

int main(){
	int num1,num2;
	printf("Enter the value for num1:\n");
	scanf("%d",&num1);
	printf("Enter the value of num2:\n");
	scanf("%d",&num2);
	
	printf("GCD from euclid:%d\n",euclid(num1,num2));
	printf("GCD from middle school:%d\n",mschool(num1,num2));
	printf("GCD using prime factorization:%d\n",pfactorization(num1,num2));
}
int euclid(int a,int b){
	int temp;
	while(b!=0){
		temp=b;
		b=a%b;
		a=temp;
	}
}
int mschool(int a,int b){
	while(a!=b){
		if(a>b)
	    a-=b;
	    else
	    b-=a;
	}
}
int pfactorization(int a,int b){
	int gcd=1;
	int factor=2;
	while(a>1 && b>1){
	if (a%factor==0 && b%factor==0){
	   gcd*=factor;
		a/=factor;
		b/=factor;
	} else if(a%factor==0){
		a/=factor;
	} else if(b%factor==0){
		b/=factor;
	}
	else{
		factor++;
	}
	}
	return gcd;
}
