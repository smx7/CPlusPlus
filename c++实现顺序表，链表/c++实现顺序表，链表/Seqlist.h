#pragma once

//Seqlist 类名
//Seqlist<T> 类型
template<class T>
class Seqlist
{
private:
	T* _array;
	size_t _size;
	size_t _capacity;
public:
	Seqlist() :_array(NULL), _size(0), _capacity(0)//构造函数
	{

	}
	Seqlist(const Seqlist<T>& s)   //拷贝构造函数
	{
		if (s._size != 0)
		{
			_array = new T[s._size];
			for (size_t i = 0; i < s._size; i++)
			{
				_array[i] = s._array[i];
			}
		}
		else
		{
			_array = NULL;
		}
		_size = s._size;
		_capacity = s._capacity;
	}
	Seqlist<T>& operator= (Seqlist<T> s) //赋值运算符重载
	{
		swap(_array, s._array);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
		return *this;
	}
	~Seqlist()                           //析构函数
	{
		if (_array)
		{
			delete[] _array;
			_array = NULL;
			_size = 0;
			_capacity = 0;
		}
	}
	void PushBack(const T& x)
	{
		Insert(_size, x);
	}
	void PopBack()
	{
		Erase(_size - 1);
	}
	void Insert(size_t pos,const T& x)
	{
		if (pos > _size)
		{
			return;
		}
		if (_size == _capacity)
		{
			size_t _newcapacity = 0;
			if (_capacity == 0)
				_newcapacity = 3;
			else
				_newcapacity = _capacity * 2;
			T* _newarray = new T[_newcapacity];
			for (size_t i = 0; i < _size; i++)
			{
				_newarray[i] = _array[i];
			}
			delete[] _array;
			_array = _newarray;
			_capacity = _newcapacity;
		}
		for (size_t i = _size; i>pos; i--)
		{
			_array[i] = _array[i - 1];
		}
		_array[pos] = x;
		++_size;
	}
	void Erase(size_t pos)
	{
		if (pos >= _size)
		{
			return;
		}
		for (size_t i = pos; i < _size - 1; i++)
		{
			_array[i] = _array[i + 1];
		}
		--_size;
	}
	size_t Find(const T& x)
	{
		size_t i = 0;
		while (i < _size)
		{
			if (_array[i] == x)
			{
				return i;
			}
		}
	}
	size_t Size()
	{
		return _size;
	}
	bool Empty()
	{
		return Size() == 0;
	}
	T& operator[](size_t pos)
	{
		return _array[pos];
	}
	void Print()
	{
		for (size_t i = 0; i < _size; i++)
		{
			cout << _array[i] << " ";
		}
		cout << endl;
	}

};

void TestSeqlist()
{
	Seqlist<int> s1;
	s1.PushBack(1);
	s1.PushBack(2);
	s1.PushBack(3);
	s1.PushBack(4);
	s1.PushBack(5);
	s1.Print();
	s1.Insert(3, 10);
	s1.Print();
	//s1.Erase(3);
	//s1.Print();
	std::cout << s1[3] << std::endl;
	Seqlist<int> s2(s1);
	s2.Print();

	Seqlist<int> s3;
	s3 = s1;
	s3.Print();
}