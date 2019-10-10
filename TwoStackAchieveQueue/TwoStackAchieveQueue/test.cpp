#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

class Queue
{
	stack<int> stack1;
	stack<int> stack2;
public:
	//�����
	void push(const int&data){
		stack1.push(data);
	}
	//������
	void Pop()
	{
		//�������ջ���ǿ�ջ����ʱ˵�������ǿյ�
		if (stack1.empty() && stack2.empty())
			cout << "this queue is empty" << endl;
		//���ջ2����Ԫ�أ��ǳ����оͳ�ջ2�е�
		if (!stack2.empty()){
			stack2.pop();
		}
		//��ʱ����ջ2���ǿ�ջ����Ҫ�����еĻ����Ǿ���Ҫ��ջ1�е�����Ԫ
		//����ջ��ջ2��,ע��һ��Ҫ��ջ1�е�����Ԫ�ض���ջ��ջ2��
		else{
			while (stack1.size() > 0){
				stack2.push(stack1.top());
				stack1.pop();
			}
			stack2.pop();
		}
	}
	int Front()//��ȡ��ͷԪ�أ���ʱ��ͷλ��ջ2��ջ��
	{
		assert(!stack1.empty() || !stack2.empty());
		if (stack2.empty()){
			while (!stack1.empty()){
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		return stack2.top();
	}
};
void TestQueue()
{
	Queue q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);;
	cout << "��ͷΪ:   " << q.Front() << endl;
	q.Pop();
	q.Pop();
	cout << "��ͷΪ:   " << q.Front() << endl;
	q.push(5);
	q.Pop();
	cout << "��ͷΪ:   " << q.Front() << endl;
}
int main()
{
	TestQueue();
	system("pause");
	return 0;
}