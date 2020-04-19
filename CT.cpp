/*
Darshan Sohaliya
DA-IICT
201901219
CT111
*/

#include <bits/stdc++.h>
using namespace std;

void BSC(int *op , int size);

long double random_no()
{
	srand(time(NULL));
	long double getn = rand()%100 + 1.0;
	long double res = getn/100.0;
	return res;
}

int main()
{
	int length;
	cout << "Enter input length : " << "\n";
	cin >> length;
	
	int n;
	cout << "Enter no. of vectors : " << "\n";
	cin >> n;
	
	string G[n];
	for(int i=0 ; i<n ; i++)
	{
		cout << "Enter your vector's no. " << i + 1 << " :" << "\n";
		cin >> G[i];
	} 
	
	string mssage;
	cout << "Enter your message signal :" << "\n";
	cin >> mssage;
	
	int msglen = mssage.length();

	int insize = msglen  + 2*length;
	int opsize = n * (msglen + length);
	
	int in[insize] , op[opsize];
	
	memset(in , 0 , sizeof(in));
	memset(op , 0 , sizeof(op));
	
	for(int i=0 ; i<msglen ; i++)
	{
		in[length - 1 + i] = mssage[i] - '0';
	}
	
	int cur = 0;
	for(int i=0 ; i<msglen + length ; i++)
	{
		for(int j=0 ; j<n ; j++)
		{
			int cursum = 0;
			for(int k=i ; k<length + i ; k++)
			{
				int temp = G[j][k - i]  - '0';
				cursum = (cursum + in[k] * temp)%2;
			}
			op[cur++] = cursum;
		}
	}
		
	cout << "Encoded message is : ";
	for(int i=0 ; i<n*(length + msglen -1) ; i++)	cout << op[i];
	cout << "\n";
	
	BSC(op , n*(length + msglen -1));
	return 0;
}


void BSC(int *op , int size)
{
	long double p;
	cout << "The Probability of error is : ";
	cin >> p;
	cout << "\n";
	
	for(int i=0 ; i<size ; i++)
	{
		if(p > random_no())
		{
			op[i] ^= 1;
		}
	}
	
	cout <<  "Encoded message with error : ";
	for(int i=0 ; i<size ; i++)
	{
		cout << op[i];
	}
	cout << "\n";
}



