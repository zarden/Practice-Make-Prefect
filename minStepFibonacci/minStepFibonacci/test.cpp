#include<iostream>
#include<algorithm>
using namespace std;  

int main()
{    
	int N;
	cin >> N;
	int f0 = 1, f1 = 1,tmp;
	while (N>f1)
	{
		tmp = f0;
		f0 = f1;
		f1 += tmp;
	}
	cout << min(N - f0, f1 - N);
	system("pause");
	return 0;
}