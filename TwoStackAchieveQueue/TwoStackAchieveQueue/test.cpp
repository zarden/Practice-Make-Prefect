#include<iostream>
#include<stack>
#include<assert.h>
using namespace std;

class Queue
{
	stack<int> stack1;
	stack<int> stack2;
public:
	//入队列
	void push(const int&data){
		stack1.push(data);
	}
	//出队列
	void Pop()
	{
		//如果两个栈都是空栈，此时说明队列是空的
		if (stack1.empty() && stack2.empty())
			cout << "this queue is empty" << endl;
		//如果栈2中有元素，那出队列就出栈2中的
		if (!stack2.empty()){
			stack2.pop();
		}
		//此时表明栈2已是空栈，再要出队列的话，那就需要把栈1中的所有元
		//素入栈到栈2中,注意一定要是栈1中的所有元素都入栈到栈2中
		else{
			while (stack1.size() > 0){
				stack2.push(stack1.top());
				stack1.pop();
			}
			stack2.pop();
		}
	}
	int Front()//获取队头元素，此时队头位于栈2的栈顶
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
	cout << "队头为:   " << q.Front() << endl;
	q.Pop();
	q.Pop();
	cout << "队头为:   " << q.Front() << endl;
	q.push(5);
	q.Pop();
	cout << "队头为:   " << q.Front() << endl;
}
int main()
{
	TestQueue();
	system("pause");
	return 0;
}