#include<iostream>
#include<string> 
#include<map> 
using namespace std;

int main()
{
	string str, res;
	while (cin >> str >> res) 
	{     // sta ���������ʾ��ǰ�Ƿ����� B �е����� A ���д���, ������Ŀ������ A ��. 
		bool sta = true;     // strdata ������ A �е���. key Ϊ�������, value Ϊ�����Ŀ 
		// resdata ������ B �е���. key Ϊ�������, value Ϊ�����Ŀ    
		map<char, int> strdata, resdata;     // ͳ�����������е����������Ŀ   
		for (auto c : str)       
			strdata[c]++;   
		for (auto c : res)     
			resdata[c]++;     // �� B ���б����������, �� A �е�ͬ���������Ŀ�Ա�.  
		for (map<char, int>::iterator it = resdata.begin(); it != resdata.end(); it++)     
		{    // ֻҪ��һ������Ŀ����������, ���� sta ���Ϊ false    
			// ��֮, ����������������ܹ���������, ���ܱ���Ϊ true      
			if (strdata[it->first] < it->second)    
			{             sta = false;        
			break;    
			}     
		}    
		if (true == sta)
		cout << "Yes" << endl;
		else     
			cout << "No" << endl;
	}
	return 0;
}