#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
using namespace std;

int fib1(int n){ //running time: 1.6^n
	if (n==0)return 0;
	if(n==1) return 1;
	else return fib1(n-1) + fib1(n-2);
}

int fib2(int n){
	if (n==0) return 0;
	int *f = new int[n];
	f[0] = 0; f[1] = 1;
	for(int i = 2; i<=n; i++){
		f[i] = f[i-1] + f[i -2];
	}
	return f[n];

}

int main()
{
	for(int i=0; i < 20; i++){
		cout << fib2(i) << endl;
	}

	getch();

	return 0;
}