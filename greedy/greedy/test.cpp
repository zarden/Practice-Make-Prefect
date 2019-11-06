#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	vector<int> v(3 * n);
	int i;
	for ( i = 0; i < (3*n); ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	long long int sum = 0;
	for ( i = n; i <= 3*n-2; i+=2)
	{
		sum += v[i];
	}
	cout << sum << endl;
	system("pause");
	return 0;
}