#include<iostream>
#include<assert.h>
using namespace std;

template<class K,class V>
struct AVLNode
{
	AVLNode(const pair<K,V>& _kv) 
	:left(nullptr)
	, right(nullptr)
	, parent(nullptr)
	, kv(_kv)
	, bf(0)
	{}
	AVLNode<K,V>* left;
	AVLNode<K, V>* right;
	AVLNode<K, V>* parent;
	pair<K,V> kv;
	int bf;
};

template <class K,class V>
class AVLTree
{
	typedef AVLNode<K, V> Node;
public:
	bool insert(const pair<K,V>& _kv)
	{
		if (root == nullptr)
		{
			root = new Node(_kv);
			return true;
		}
		Node* cur = root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->kv.first > _kv.first)
			{
				parent = cur;
				cur = cur->left;
			}
			else if (cur->kv.first < _kv.first)
			{
				parent = cur;
				cur = cur->right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(_kv);
		if (cur->kv.first < parent->kv.first)
		{
			parent->left = cur;
			cur->parent = parent;
		}
		else
		{
			parent->right = cur;
			cur->parent = parent;
		}

		while (parent)
		{
			if (cur == parent->left)
			{
				--parent->bf;
			}
			else
			{
				++parent->bf;
			}

			if (parent->bf == -1 || parent->bf == 1)
			{
				cur = parent;
				parent = parent->parent;
			}
			else if (parent->bf == 0)
			{
				break;
			}
			else if (parent->bf == 2 || parent->bf == -2)
			{
				if (parent->bf == -2 && cur->bf == -1) // ÓÒµ¥Ðý
				{
					rotateR(parent);
				}
				else if (parent->bf == 2 && cur->bf == 1)  //×óµ¥Ðý
				{
					rotateL(parent);
				}
				else if (parent->bf == -2 && cur->bf == 1) //×óÓÒË«Ðý
				{
					Node* subL = parent->left;
					Node* subLR = parent->left->right;

					int _bf = subLR->bf;
					rotateL(parent->left);
					rotateR(parent);
					if (_bf == -1)
					{
						parent->bf = 1;
						subL->bf = 0;
					}
					else if (_bf == 1)
					{
						parent->bf = 0;
						subL->bf = -1;
					}
					else
					{
						parent->bf = 0;
						subL->bf = 0;
					}
				}
				else if (parent->bf == 2 && cur->bf == -1) //ÓÒ×óË«Ðý
				{
					Node* subR = parent->right;
					Node* subRL = parent->right->left;

					int _bf = subRL->bf;
					rotateR(parent->right);
					rotateL(parent);
					if (_bf == -1)
					{
						parent->bf = 0;
						subR->bf = 1;
					}
					else if (_bf == 1)
					{
						parent->bf = -1;
						subR->bf = 0;
					}
					else
					{
						parent->bf = 0;
						subR->bf = 0;
					}
				}
				break;
			}
			else
			{
				assert(false);
			}

		}
	}
	void rotateR(Node* _parent)
	{
		Node* subL = _parent->left;
		Node* subLR = _parent->left->right;

		_parent->left = subLR;
		if (subLR)
		{
			subLR->parent = _parent;
		}
		subL->right = _parent;
		Node* pNode = _parent->parent;
		_parent->parent = subL;
		if (_parent == root)
		{
			subL->parent = nullptr;
			root = subL;
		}
		else
		{
			if (pNode->left == _parent)
			{
				pNode->left = subL;
			}
			else
			{
				pNode->right = subL;
			}
			subL->parent = pNode;
		}
		subL->bf = 0;
		_parent->bf = 0;
	}
	void rotateL(Node* _parent)
	{
		Node* subR = _parent->right;
		Node* subRL = _parent->right->left;

		_parent->right = subRL;
		if (subRL)
		{
			subRL->parent = _parent;
		}

		subR->left = _parent;
		Node* pNode = _parent->parent;
		_parent->parent = subR;
		if (_parent == root)
		{
			subR->parent = nullptr;
			root = subR;
		}
		else
		{
			if (pNode->left == _parent)
			{
				pNode->left = subR;
			}
			else
			{
				pNode->right = subR;
			}
			subR->parent = pNode;
		}
		_parent->bf = 0;
		subR->bf = 0;
	}

	void inorder()
	{
		_inorder(root);
		cout << endl;
	}
	bool isbalance()
	{
		return _isbalance(root);
	}
private:
	Node* root = nullptr;

	void _inorder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}
		_inorder(root->left);
		cout << root->kv.first << " ";
		_inorder(root->right);
	}
	int _deep(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int left = _deep(root->left);
		int right = _deep(root->right);

		return left > right ? left + 1 : right + 1;
	}

	bool _isbalance(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}
		int leftdeep = _deep(root->left);
		int rightdeep = _deep(root->right);

		int dis = rightdeep - leftdeep;

		if (dis != root->bf)
		{
			cout << "½ÚµãÆ½ºâÒò×Ó´íÎó" << endl;
			return false;
		}
		if (dis > 1 || dis < -1)
		{
			return false;
		}
		else
		{
			return _isbalance(root->left) && _isbalance(root->right);
		}

	}
};

int main()
{
	int arr[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	//int arr[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
	AVLTree<int, int> tree;

	for (auto e : arr)
	{
		tree.insert(make_pair(e, 0));
		//tree.insert(pair<int, int>(e, 0));
		cout << e << "---" << tree.isbalance() << endl;
	}
	tree.inorder();

	system("pause");
	return 0;
}

