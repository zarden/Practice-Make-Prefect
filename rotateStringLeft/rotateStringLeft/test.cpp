//·½·¨Ò»
//class Solution {
//public:
//	void LeftRotateStringOne(string& str)
//	{
//		char temp = str[0];
//		int len = str.length();
//		int i = 0;
//		for (; i<len - 1; i++)
//		{
//			str[i] = str[i + 1];
//		}
//		str[i] = temp;
//	}
//
//	string LeftRotateString(string str, int n) {
//		if (n == 0 || str.empty())
//			return str;
//
//		n %= str.size();
//		while (n)
//		{
//			LeftRotateStringOne(str);
//			n--;
//		}
//		return str;
//
//	}
//};
