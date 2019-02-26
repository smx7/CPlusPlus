#pragma once
#include<iostream>
#include<string>
using namespace std;
enum Color
{
	RED,
	BLACK,
};
template<class T>
struct RBNode
{
	RBNode<T>* left;
	RBNode<T>* right;
	RBNode<T>* parent;
	T val;
	Color color;
	RBNode(const T& value = T(), Color _color = RED)
		:left(nullptr)
		, right(nullptr)
		, parent(nullptr)
		, val(value)
		, color(_color)
	{}
};
template<class T>
class Iterator
{
	typedef RBNode<T> Node;
public:
	Iterator(Node* _node = nullptr)
		:pNode(_node)
	{}
	Iterator(const Iterator& it)
		:pNode(it.pNode)
	{}
	T& operator*()
	{
		return pNode->val;
	}
	T* operator->()
	{
		return &(operator*());
	}
	Iterator<T>& operator++()
	{
		increasement();
		return *this;
	}
	Iterator<T>& operator++(int)
	{
		Iterator<T> temp(*this);
		increasement();
		return temp;

	}
	Iterator<T>& operator--()
	{
		decreasement();
		return *this;
	}
	Iterator<T>& operator--(int)
	{
		Iterator<T> temp(*this);
		decreasement();
		return temp;
	}
	bool operator!=(const Iterator& it)
	{
		return pNode != it.pNode;
	}
	bool operator==(const Iterator& it)
	{
		return pNode == it.pNode;
	}
private:
	void increasement()
	{
		if (pNode->right)
		{
			pNode = pNode->right;
			while (pNode->left)
			{
				pNode = pNode->left;
			}
		}
		else
		{
			Node* pParent = pNode->parent;
			while (pParent->right == pNode)
			{
				pNode = pParent;
				pParent = pParent->parent;
			}
			if (pNode->right != pParent)
			{
				pNode = pParent;
			}
		}
	}
	void decreasement()
	{
		if (pNode->parent->parent == pNode&&pNode->color == RED)
		{
			pNode = pNode->right;
		}
		else if (pNode->right)
		{
			pNode = pNode->left;
			while (pNode->right)
			{
				pNode = pNode->right;
			}
		}
		else
		{
			Node* pParent = pNode->parent;
			while (pParent->left == pNode)
			{
				pNode = pParent;
				pParent = pParent->parent;
			}
			pNode = pParent;
		}
	}
	Node* pNode;
};

template<class K, class T,class KeyOfVlaue>
class RBTree
{
public:
	typedef RBNode<T> Node;
	typedef Iterator<T> _iterator;
	_iterator begin()
	{
		return _iterator(header->left);
	}
	_iterator end()
	{
		return _iterator(header);
	}
	RBTree()
	{
		header = new Node;
		header->parent = nullptr;
		header->left = header;
		header->right = header;
	}
	pair<_iterator, bool> insert(const T& value)
	{
		if (header->parent == nullptr)
		{
			Node* root = new Node(value, BLACK);
			root->parent = header;
			header->left = root;
			header->right = root;
			header->parent = root;
			return make_pair(_iterator(root), true);
		}
		KeyOfVlaue keyofvalue;

		Node* parent = nullptr;
		Node* root = header->parent;
		Node* cur = root;
		while (cur)
		{
			if (keyofvalue(cur->val) > keyofvalue(value))
			{
			parent = cur;
			cur = cur->left;
			}
			else if (keyofvalue(cur->val) < keyofvalue(value))
			{
			parent = cur;
			cur = cur->right;
			}
			else
			{
				return make_pair(_iterator(cur), false);
			}
		}
		cur = new Node(value, RED);
		Node* newNode = cur;
		if (keyofvalue(parent->val) > keyofvalue(cur->val))
		{
		parent->left = cur;
		cur->parent = parent;
		}
		else
		{
			parent->right = cur;
			cur->parent = parent;
		}
		while (cur != root&&cur->parent->color == RED)
		{
			parent = cur->parent;
			Node* grandpa = parent->parent;
			if (grandpa->left == parent)
			{
				Node* uncle = grandpa->right;
				if (uncle&&uncle->color == RED)
				{
					parent->color = BLACK;
					uncle->color = BLACK;
					grandpa->color = RED;
					cur = grandpa;
				}
				else
				{
					if (cur == parent->right)
					{
						rotateL(parent);
						swap(parent, cur);
					}
					rotateR(grandpa);
					parent->color = BLACK;
					grandpa->color = RED;
					break;
				}
			}
			else
			{
				Node* uncle = grandpa->left;
				if (uncle&&uncle->color == RED)
				{
					parent->color = BLACK;
					uncle->color = BLACK;
					grandpa->color = RED;
					cur = grandpa;
				}
				else
				{
					if (cur == parent->left)
					{
						rotateR(parent);
						swap(parent, cur);
					}
					rotateL(grandpa);
					parent->color = BLACK;
					grandpa->color = RED;
					break;
				}
			}
		}

		header->parent->color = BLACK;
		header->left = LeftMost();
		header->right = RightMost();

		return make_pair(_iterator(newNode), true);
	}
	void rotateR(Node* parent)
	{
		Node* subL = parent->left;
		Node* subLR = subL->right;
		parent->left = subLR;
		if (subLR)
		{
			subLR->parent = parent;
		}
		subL->right = parent;

		Node* grandpa = parent->parent;
		parent->parent = subL;
		if (header->parent == parent)
		{
			header->parent = subL;
			subL->parent = header;
		}
		else
		{
			if (grandpa->left == parent)
			{
				grandpa->left = subL;
			}
			else
			{
				grandpa->right = subL;
			}
			subL->parent = grandpa;
		}
	}
	void rotateL(Node* parent)
	{
		Node* subR = parent->right;
		Node* subRL = subR->left;

		parent->right = subRL;
		if (subRL)
		{
			subRL->parent = parent;
		}
		subR->left = parent;
		Node* grandpa = parent->parent;
		parent->parent = subR;
		if (header->parent == parent)
		{
			header->parent = subR;
			subR->parent = header;
		}
		else
		{
			if (grandpa->left == parent)
			{
				grandpa->left = subR;
			}
			else
			{
				grandpa->right = subR;
			}
			subR->parent = grandpa;
		}
	}
	Node* LeftMost()
	{
		Node* cur = header->parent;
		if (nullptr == cur)
		{
			return header;
		}
		while (cur->left)
		{
			cur = cur->left;
		}
		return cur;
	}
	Node* RightMost()
	{
		Node* cur = header->parent;
		if (nullptr == cur)
		{
			return header;
		}
		while (cur->right)
		{
			cur = cur->right;
		}
		return cur;
	}
	void inorder()
	{
		_inorder(header->parent);
		cout << endl;
	}
	bool empty()
	{
		return header->parent == nullptr;
	}
	bool IsValidRBTree()
	{
		Node* root = header->parent;
		if (root == nullptr)
		{
			return true;
		}
		if (BLACK != root->color)
		{
			cout << "不满足根结点为黑色！" << endl;
			return false;
		}
		size_t blackcount = 0;
		Node* cur = root;
		while (cur)
		{
			if (cur->color == BLACK)
			{
				++blackcount;
			}
			cur = cur->left;
		}
		size_t k = 0;
		_IsValidRBTree(root, k, blackcount);
	}
private:
	Node* header;
	void _inorder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_inorder(root->left);
		cout << root->val << " ";
		_inorder(root->right);
	}
	bool _IsValidRBTree(Node* root, size_t k, size_t blackcount)
	{
		if (nullptr == root)
		{
			return true;
		}
		if (BLACK == root->color)
		{
			++k;
		}
		Node* pParent = root->parent;
		if (pParent&&pParent->color == RED&&root->color == RED)
		{
			cout << "不满足不存在两个连接的红色节点！" << endl;
			return false;
		}
		if (nullptr == root->left&&nullptr == root->right)
		{
			if (k != blackcount)
			{
				cout << "不满足每条路径上黑色节点个数相同！" << endl;
				return false;
			}
		}
		return _IsValidRBTree(root->left, k, blackcount) && _IsValidRBTree(root->right, k, blackcount);
	}
};
