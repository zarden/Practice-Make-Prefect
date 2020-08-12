class Solution {
public:
	void Reverse(string& str, int start, int end)
	{
		while (start<end)
		{
			int temp = str[start];
			str[start] = str[end];
			str[end] = temp;
			++start, --end;
		}
	}

	string ReverseSentence(string str) {
		if (str.size() == 0)
			return str;

		int i = 0, j = i;
		int len = str.size();
		while (i<len)
		{
			while (i<len && !isspace(str[i])) i++;
			Reverse(str, j, i - 1);
			while (i<len && isspace(str[i])) i++;
			j = i;
		}
		Reverse(str, j, i - 1);
		Reverse(str, 0, i - 1);
		return str;
	}
};