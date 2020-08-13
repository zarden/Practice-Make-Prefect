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
		////�Ⱦֲ����ã�����������
		if (str.size() == 0)
			return str;

		int i = 0;
		int j = i;
		int len = str.size();

		while (i<len)
		{
			while (i<len && !isspace(str[i]))
				i++;
			//��iһֱ�����ߣ�������һ���ո� 
			Reverse(str, j, i - 1);
			//���õ�ǰ��Ч�Ӵ������ǲ��ñ����� 
			while (i<len && isspace(str[i]))
				i++;
			//�������пո�ָ����һ����Ч�� ���Ŀ�ʼ 
			j = i; //������ʼλ�� 
		}
		//�ߵ����һ���� i == str.size()�ˣ����Ǻ�һ����Ч�Ӵ���û�б�����,������
		Reverse(str, j, i - 1);
		Reverse(str, 0, i - 1);
		//������������� 
		return str;
	}
};