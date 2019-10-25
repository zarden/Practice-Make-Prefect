#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :
		val(x),
		left(NULL),
		right(NULL)
	{

	}
};

vector<vector<int>>levelOrder(TreeNode* root)
{
	vector<vector<int>> res;
	if (!root)
	{
		return res;
	}

	vector<int> vtmp;
	queue<TreeNode*> qu;

	TreeNode * cur;
	int len = 1;

	qu.push(root);

	while (!qu.empty())
	{
		for (int i = 0; i < len; ++i)
		{
			cur = qu.front();
			vtmp.push_back(cur->val);
			cout << cur->val << ' ';
			qu.pop();

			if (cur->left)
			{
				qu.push(cur->left);
			}
			if (cur->right)
			{
				qu.push(cur->right);
			}
		}
		cout << endl;
		res.push_back(vtmp);
		vtmp.clear();
		len = qu.size();
	}
	return res;
}

int main()
{
	TreeNode* root = new TreeNode(3);

	TreeNode* tmpl = new TreeNode(9);
	root->left = tmpl;
	TreeNode* tmpr = new TreeNode(20);
	root->right = tmpr;

	levelOrder(root);
	system("pause");
	return 0;
}