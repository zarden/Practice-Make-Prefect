#include<iostream>
#include<string> 
#include<map> 
using namespace std;

int main()
{
	string str, res;
	while (cin >> str >> res) 
	{     // sta 这个变量表示当前是否满足 B 盒的球在 A 盒中存在, 并且数目不大于 A 盒. 
		bool sta = true;     // strdata 保存了 A 盒的球. key 为球的种类, value 为球的数目 
		// resdata 保存了 B 盒的球. key 为球的种类, value 为球的数目    
		map<char, int> strdata, resdata;     // 统计两个盒子中的球的类别和数目   
		for (auto c : str)       
			strdata[c]++;   
		for (auto c : res)     
			resdata[c]++;     // 在 B 盒中遍历球的种类, 和 A 盒的同类球进行数目对比.  
		for (map<char, int>::iterator it = resdata.begin(); it != resdata.end(); it++)     
		{    // 只要有一种球数目不满足条件, 就用 sta 标记为 false    
			// 反之, 必须所有种类的球都能够满足条件, 才能保持为 true      
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