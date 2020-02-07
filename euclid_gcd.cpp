#include <iostream>

using namespace std;

int euclid(int a , int b)
{
	if(b==0) return a;
	return euclid(b, a % b); 
}
int main()
{
	int a, b, gcd;
	char opt = 'n';
	do{
	cout << "Enter first number a: ";
	cin >> a;
	cout << "Enter second number b (a > b): ";
	cin >> b;
	if(a < b) exit(0);
	gcd = euclid(a,b);
	cout << "GCD: "<<gcd<<endl;
	cout<<"Again? (y/n): "<<endl;
	cin >> opt;
	}while(opt == 'y');
	return 0;
}