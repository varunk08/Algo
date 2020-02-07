#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;


int main()
{
	bool prime = true;
	int a, b, gcd;
	char opt = 'n';
	do{
		cout<<"Enter number to be tested (N): ";
		cin >> a;
		cout<<"Enter number of iterations (k): ";
		cin >> b;
		srand((unsigned int) time(0));
		for(int i = 0; i < b; i++){
			int randNum = 1 + rand() % (a-1);
			cout<<"Rand Num: "<<randNum<<endl;
			long long int test = pow(randNum,a-1) - 1;
			cout<<"Test: "<<test<<endl;
			
			if(fmod(test,a) != 0){
				cout<<"fmod: "<<fmod(test,a)<<endl;
				prime = false;
				break;
			}
			
		}
		if (prime) cout<<"Number is a prime"<<endl;
		else cout<<"Number is NOT a prime"<<endl;
	cout<<"Again? (y/n): "<<endl;
	cin >> opt;
	}while(opt == 'y');
	return 0;
}