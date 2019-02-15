#include<iostream>
using namespace std;

template<class T>
struct BSTNode
{
	BSTNode(const T& value = T()) 
	:left(nullptr), right(nullptr), val(value)
	{
	}
	BSTNode* left;
	BSTNode* right;
	T val;
};

template<class T>
class BSTree
{
public:
	BSTree() :root(nullptr)
	{
	}
	BSTNode<T>* find(const T& value)
	{
		BSTNode<T>* cur = root;
		while (cur)
		{
			if (value > cur->val)
				cur = cur->right;
			else if (value < cur->val)
				cur = cur->left;
			else
				return cur;
		}
		return nullptr;
	}
	bool insert(const T& value)
	{
		if (root == nullptr)
		{
			root = new BSTNode<T>(value);
			return true;
		}
		BSTNode<T>* cur = root;
		BSTNode<T>* parent = nullptr;
		while (cur)
		{
			if (cur->val > value)
			{
				parent = cur;
				cur = cur->left;
			}
			else if (cur->val < value)
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				return false;
			}
		}
		cur = new BSTNode<T>(value);
		if (value < parent->val)
		{
			parent->left = cur;
		}
		else
		{
			parent->right = cur;
		}
		return true;
	}
	bool erase(const T& value = T())
	{
		if (nullptr == root)
		{
			return false;
		}
		BSTNode<T>* cur = root;
		BSTNode<T>* parent = nullptr;
		while (cur)
		{
			if (cur->val > value)
			{
				parent = cur;
				cur = cur->left;
			}
			else if (cur->val < value)
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				if (cur->left == nullptr)
				{
					if (cur == parent->left)
					{
						parent->left = cur->right;
					}
					else
					{
						parent->right = cur->right;
					}
				}
				else if (cur->right == nullptr)
				{
					if (cur == parent->left)
					{
						parent->left = cur->left;
					}
					else
					{
						parent->right = cur->left;
					}
				}
				else
				{
					BSTNode<T>* min_right = cur->right;
					parent = cur;
					while (min_right->left)
					{
						parent = min_right;
						min_right = min_right->left;
					}
					cur->val = min_right->val;
					if (min_right == parent->left)
					{
						parent->left = min_right->right;
					}
					else
					{
						parent->right = min_right->right;
					}
					delete min_right;
					min_right = nullptr;
					return true;
				}
			}
		}
		return false;
	}
	void inorder()
	{
		_InOrder(root);
		cout << endl;
	}
	~BSTree()
	{
		_Destroy(root);
	}
private:
	BSTNode<T>* root;

	void _InOrder(BSTNode<T>* _root)
	{
		if (_root)
		{
			_InOrder(_root->left);
			cout << _root->val << " ";
			_InOrder(_root->right);
		}
	}
	void _Destroy(BSTNode<T>* &_root)
	{
		if (_root)
		{
			_Destroy(_root->left);
			_Destroy(_root->right);
			_root = nullptr;
		}
	}
};

int main()
{
	BSTree<int> bst;
	bst.insert(6);
	bst.insert(4);
	bst.insert(8);
	bst.insert(3);
	bst.insert(5);
	bst.insert(7);
	bst.insert(9);
	bst.inorder();
	bst.erase(4);
	bst.inorder();
	system("pause");
	return 0;

}