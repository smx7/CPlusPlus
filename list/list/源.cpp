#include<iostream>
using namespace std;
namespace smx
{
	template<class T>
	struct ListNode
	{
		ListNode(const T& _val=T()) :prev(nullptr), next(nullptr), val(_val)
		{

		}
		ListNode<T>* prev;
		ListNode<T>* next;
		T val;
	};
	template<class T>
	class Iterator   //迭代器类
	{
	public:
		Iterator(ListNode<T>* _pNode = nullptr) :pNode(_pNode)
		{
		}
		Iterator(const Iterator<T>& it) :pNode(it.pNode)
		{
		}
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
			pNode = pNode->next;
			return *this;
		}
		Iterator<T>& operator++(int)
		{
			Iterator<T> tmp(*this);
			pNode = pNode->next;
			return tmp;
		}
		Iterator<T>& operator--()
		{
			pNode = pNode->prev;
			return *this;
		}
		Iterator<T>& operator--(int)
		{
			Iterator<T> tmp(*this);
			pNode = pNode->prev;
			return tmp;
		}
		bool operator!=(const Iterator<T>& it)
		{
			return pNode != it.pNode;
		}
		bool operator==(const Iterator<T>& it)
		{
			return pNode == it.pNode;
		}
	private:
		ListNode<T>* pNode;
	};

	template<class T>
	class ReverseIterator //反向迭代器
	{
	public:
		ReverseIterator(ListNode<T>* _pNode = nullptr) :pNode(_pNode)
		{
		}
		ReverseIterator(const ReverseIterator<T>& rit) :pNode(rit.pNode)
		{
		}
		T& operator*()
		{
			return pNode->val;
		}
		T* operator->()
		{
			return &(operator*());
		}
		ReverseIterator<T>& operator++()
		{
			pNode = pNode->prev;
			return *this;
		}
		ReverseIterator<T>& operator++(int)
		{
			ReverseIterator<T> tmp(*this);
			pNode = pNode->prev;
			return tmp;
		}
		ReverseIterator<T>& operator--()
		{
			pNode = pNode->next;
			return *this;
		}
		ReverseIterator<T>& operator--(int)
		{
			ReverseIterator<T> tmp(*this);
			pNode = pNode->next;
			return tmp;
		}
		bool operator!=(const ReverseIterator<T>& rit)
		{
			return pNode != rit.pNode;
		}
		bool operator==(const ReverseIterator<T>& rit)
		{
			return pNode == rit.pNode;
		}
	private:
		ListNode<T>* pNode;

	};
	template<class T>
	class ConstIterator //const 迭代器
	{
	public:
		ConstIterator(ListNode<T>* _pNode = nullptr) :pNode(_pNode)
		{
		}
		ConstIterator(const ConstIterator<T>& cit) :pNode(cit.pNode)
		{
		}
		const T& operator*() const
		{
			return pNode->val;
		}
		const T* operator->() const
		{
			return &(operator*());
		}
		ConstIterator<T>& operator++()
		{
			pNode = pNode->next;
			return *this;
		}
		ConstIterator<T>& operator++(int)
		{
			ConstIterator<T> tmp(*this);
			pNode = pNode->next;
			return tmp;
		}
		ConstIterator<T>& operator--()
		{
			pNode = pNode->prev;
			return *this;
		}
		ConstIterator<T>& operator--(int)
		{
			ConstIterator<T> tmp(*this);
			pNode = pNode->prev;
			return tmp;
		}
		bool operator!=(const ConstIterator<T>& it)
		{
			return pNode != it.pNode;
		}
		bool operator==(const ConstIterator<T>& it)
		{
			return pNode == it.pNode;
		}
	private:
		ListNode<T>* pNode;
	};
	template<class T>
	class ConstReverseIterator  //反向 const迭代器
	{
	public:
		ConstReverseIterator(ListNode<T>* _pNode = nullptr) :pNode(_pNode)
		{
		}
		ConstReverseIterator(const ConstReverseIterator<T>& crit) :pNode(crit.pNode)
		{
		}
		const T& operator*() const
		{
			return pNode->val;
		}
		const T* operator->() const
		{
			return &(operator*());
		}
		ConstReverseIterator<T>& operator++()
		{
			pNode = pNode->prev;
			return *this;
		}
		ConstReverseIterator<T>& operator++(int)
		{
			ConstReverseIterator<T> tmp(*this);
			pNode = pNode->prev;
			return tmp;
		}
		ConstReverseIterator<T>& operator--()
		{
			pNode = pNode->next;
			return *this;
		}
		ConstReverseIterator<T>& operator--(int)
		{
			ConstReverseIterator<T> tmp(*this);
			pNode = pNode->next;
			return tmp;
		}
		bool operator!=(const ConstReverseIterator<T>& rit)
		{
			return pNode != rit.pNode;
		}
		bool operator==(const ConstReverseIterator<T>& rit)
		{
			return pNode == rit.pNode;
		}
	private:
		ListNode<T>* pNode;
	};

	template<class T>
	class list
	{
	public:
		typedef Iterator<T> iterator;
		typedef ReverseIterator<T> reverse_iterator;
		typedef ConstIterator<T> const_iterator;
		typedef ConstReverseIterator<T> const_reverse_iterator;
	public:
		list()
		{
			CreateHead();
		}
		list(size_t n, const T& val = T())
		{
			CreateHead();
			for (size_t i = 0; i < n; i++)
			{
				push_back(val);
			}
		}
		//template<class iterator>
		list(iterator first, iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		list(const_iterator first, const_iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		list(const list<T>& l)
		{
			CreateHead();
			list<T> tmp(l.cbegin(), l.cend());
			std::swap(this->pHead, tmp.pHead);
		}
		list<T>& operator=(const list<T>& l)
		{
			if (this != &l)
			{
				list<T> tmp(l);
				std::swap(this->pHead,tmp.pHead);
			}
			return *this;
		}
		~list()
		{
			clear();
			delete pHead;
			pHead = nullptr;
		}
		iterator begin()
		{
			return iterator(pHead->next);
		}
		iterator end()
		{
			return iterator(pHead);
		}
		reverse_iterator rbegin()
		{
			return reverse_iterator(pHead);
		}
		reverse_iterator rend()
		{
			return reverse_iterator(pHead->prev);
		}
		const_iterator cbegin() const
		{
			return const_iterator(pHead->next);
		}
		const_iterator cend() const
		{
			return const_iterator(pHead);
		}
		const_reverse_iterator crbegin() const
		{
			return const_reverse_iterator(pHead);
		}
		const_reverse_iterator crend() const
		{
			return const_reverse_iterator(pHead->prev);
		}

		size_t size() const
		{
			size_t count = 0;
			ListNode<T>* cur = pHead->next;
			while (cur != pHead)
			{
				++count;
				cur = cur->next;
			}
			return count;
		}
		bool empty() const
		{
			return pHead->next == pHead;
		}
		void resize(size_t n, const T& value = t())
		{
			size_t _size = size();
			if (_size > n)
			{
				for (size_t i = n; i < _size; i++)
				{
					pop_back();
				}
			}
			if (_size < n)
			{
				for (size_t i = _size; i < n; i++)
				{
					push_back(value);
				}
			}
		}
		T& front()
		{
			return pHead->next->val;
		}
		const T& front() const
		{
			return pHead->next->val;
		}
		T& back()
		{
			return pHead->prev->val;
		}
		const T& back() const
		{
			return pHead->prev->val;
		}
		void push_back(const T& value)
		{
			ListNode<T>* newNode = new ListNode<T>(value);
			newNode->next = pHead;
			newNode->prev = pHead->prev;

			pHead->prev->next = newNode;
			pHead->prev = newNode;

		}
		void pop_back()
		{
			ListNode<T>* cur = pHead->prev;
			if (cur != pHead)
			{
				pHead->prev = cur->prev;
				cur->prev->next = pHead;
				delete cur;
			}
		}
		void push_front(const T& value)
		{
			ListNode<T>* newNode = new ListNode<T>(value);
			newNode->prev = pHead;
			newNode->next = pHead->next;

			newNode->next->prev = newNode;
			pHead->next = newNode;
		}
		void pop_front()
		{
			ListNode<T>* cur = pHead->next;
			if (cur != pHead)
			{
				pHead->next = cur->next;
				cur->next->prev = pHead;
				delete cur;
			}
		}
		iterator insert(iterator pos, const T& value)
		{
			ListNode<T>* newNode = new ListNode<T>(value);
			ListNode<T>* cur = pos.pNode;

			newNode->next = cur;
			newNode->prev = cur->prev;
			newNode->prev->next = newNode;
			newNode->next->prev = newNode;
			return iterator(newNode);
		}
		iterator erase(iterator pos)
		{
			ListNode<T>* cur = pos.pNode;
			ListNode<T>* next = cur->next;
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			delete cur;
			return iterator(next);

		}
		void clear()
		{
			ListNode<T>* cur = pHead->next;
			while (cur != pHead)
			{
				pHead->next = cur->next;
				delete cur;
				cur = pHead->next;
			}
			pHead->next = pHead;
			pHead->prev = pHead;
		}



	private:
		void CreateHead()
		{
			pHead = new ListNode<T>;
			pHead->next = pHead;
			pHead->prev = pHead;
		}
		ListNode<T>* pHead;
	};
}
using namespace smx;
template<class T>
void print(list<T>& l)
{
	for (auto e : l)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}
int main()
{

	system("pause");
	return 0;
}