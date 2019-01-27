#pragma once
template<class T>
struct ListNode
{
	T _data;
	ListNode<T>* _next;
	ListNode<T>* _prev;
};
template<class T>
class list
{
	typedef ListNode<T> Node;
public:
	list()
	{
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
	}
	~list()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			_head->_next = cur->_next;
			delete cur;
			cur = _head->_next;
		}
		_head->_next = _head;
		_head->_prev = _head;
		delete _head;
		_head = NULL;
	}
	list(const list<T>& lt)    //¿½±´¹¹Ôìº¯Êý
	{
		Node* cur = lt._head->_next;
		_head = new Node;
		_head->_next = _head;
		_head->_prev = _head;
		while (cur!=lt._head)
		{
			PushBack(cur->_data);
			cur = cur->_next;
		}
	}
	list<T>& operator=(list<T> lt)
	{
		swap(_head, lt._head);
		//cout << "=" << endl;
		return *this;
	}
	void PushBack(const T& x)
	{
		Insert(_head, x);
	}
	void PopBack()
	{
		Erase(_head->_prev);
	}
	void PushFront(const T& x)
	{
		Insert(_head->_next, x);
	}
	void PopFront()
	{
		Erase(_head->_next);
	}
	void Insert(Node* pos, const T& x)
	{
		Node* prev = pos->_prev;
		Node* newnode = new Node;
		newnode->_data = x;
		prev->_next = newnode;
		newnode->_prev = prev;
		newnode->_next = pos;
		pos->_prev = newnode;
	}
	void Erase(Node* pos)
	{
		pos->_prev->_next = pos->_next;
		pos->_next->_prev = pos->_prev;
		delete pos;
		pos = NULL;
	}
	Node* Find(const T& x)
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			if (cur->_data == x)
				return cur;
			else
				cur = cur->_next;
		}
		return NULL;
	}
	size_t Size()
	{
		size_t size = 0;
		Node* cur = _head->_next;
		while (cur != _head)
		{
			++size;
			cur = cur->_next;
		}
		return size;
	}
	bool Empty()
	{
		return Size() == 0;
	}
	void Print()
	{
		Node* cur = _head->_next;
		while (cur != _head)
		{
			cout << cur->_data << " ";
			cur = cur->_next;
		}
		cout << endl;
	}
	void Test()
	{
		Node* cur = Find(3);
		Erase(cur);
	}
private:
	Node* _head;
};
void Testlist()
{
	list<int> L;
	L.PushBack(1);
	L.PushBack(2);
	L.PushBack(3);
	L.PushBack(4);
	L.PushBack(5);
	L.Print();
	//L.PopBack();
	//L.Print();
	//L.PopFront();
	//L.Print();
	L.Test();
	L.Print();
	std::cout << L.Size() << std::endl;
	//list<int> L2(L);
	//L2.Print();

	list<int> L3;
	L3.PushBack(6);
	L3.PushBack(7);
	L3.PushBack(8);
	L3.PushBack(9);
	L3.Print();
	L3 = L;
	L3.Print();
}
