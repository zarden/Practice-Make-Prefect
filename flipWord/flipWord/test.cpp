class Solution {
public:
	void Reverse(string& str, int start, int end)
	{
		while (start<end)
		{
			char temp = str[start];
			str[start] = str[end];
			str[end] = temp;
			start++;
			end--;
		}
	}

	string ReverseSentence(string str) {
		////先局部逆置，在整体逆置
		if (str.size() == 0)
			return str;

		int i = 0;
		int j = i;
		int len = str.size();

		while (i<len)
		{
			while (i<len && !isspace(str[i]))
				i++;
			//让i一直往后走，碰到第一个空格 
			Reverse(str, j, i - 1);
			//逆置当前有效子串，我们采用闭区间 
			while (i<len && isspace(str[i]))
				i++;
			//过滤所有空格，指向下一个有效子 串的开始 
			j = i; //保存起始位置 
		}
		//走到这里，一定是 i == str.size()了，但是后一个有效子串并没有被逆置,则逆置
		Reverse(str, j, i - 1);
		Reverse(str, 0, i - 1);
		//最后在整体逆置 
		return str;
	}
};