#include<iostream>
#include <assert.h>
#include<string>
using namespace std;

namespace smx
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		iterator begin()
		{
			return start;
		}
		iterator end()
		{
			return finish;
		}
		const_iterator cbegin() const
		{
			return start;
		}
		const_iterator cend() const
		{
			return finish;
		}
		size_t size() const
		{
			return finish - start;
		}
		size_t capacity() const
		{
			return endofstorage - start;
		}
		vector() :start(nullptr)
			, finish(nullptr)
			, endofstorage(nullptr)
		{
		}
		vector(size_t n, const T& value = T()) :start(nullptr)
			, finish(nullptr)
			, endofstorage(nullptr)
		{
			reserve(n);
			while (n--)
			{
				push_back(value);
			}
		}
		/*template<class input_iterator>*/
		vector(iterator first, iterator last)
		{
			reserve(last - first);
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}
		vector(const vector<T>& v)
		{
			reserve(v.capacity());
			iterator it = begin();
			const_iterator cit = v.cbegin();
			while (cit != v.cend())
			{
				*it++ = *cit++;
			}
			finish = start + v.size();
			endofstorage = start + v.capacity();
		}
		vector<T>& operator=(const vector<T>& v)
		{
			if (this != &v)
			{
				iterator tmp = new T[v.capacity()];
				const_iterator cit = v.cbegin();
				for (size_t i = 0; i < v.size(); i++)
				{
					*(tmp + i) = *(cit + i);
				}
				delete[] start;
				start = tmp;
				finish = start + v.size();
				endofstorage = start + v.capacity();
			}
			return *this;
		}
		~vector()
		{
			delete[] start;
			start = nullptr;
			finish = nullptr;
			endofstorage = nullptr;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t _size = size();
				iterator tmp = new T[n];
				if (start)
				{
					for (size_t i = 0; i < _size; i++)
					{
						*(tmp + i) = *(start + i);
					}
				}
				delete[] start;
				start = tmp;
				finish = start + _size;
				endofstorage = start + n;
			}
		}
		void resize(size_t n, const T& value = T())
		{
			if (n < size())
			{
				finish = start + n;
				return;
			}
			if (n > capacity())
			{
				reserve(n);
			}
			iterator it = finish;
			finish = start + n;
			while (it != finish)
			{
				*it = value;
				it++;
			}
		}
		void push_back(const T& x)
		{
			insert(end(), x);
		}
		void pop_back()
		{
			iterator it = end();
			it--;
			erase(it);
		}
		iterator insert(iterator pos,const T& x)
		{
			assert(pos <= finish);
			if (size() == capacity())
			{
				size_t _size = size();
				size_t position = pos - start;
				size_t newcapacity = capacity() == 0 ? 1 : capacity() * 2;
				reserve(newcapacity);
				pos = start + position;
			}
			iterator _end = finish - 1;
			while (_end >= pos)
			{
				*(_end + 1) = *_end;
				--_end;
			}
			*pos = x;
			++finish;
			return pos;
		}
		iterator erase(iterator pos)
		{
			iterator _begin = pos + 1;
			while (_begin <= finish)
			{
				*(_begin - 1) = *_begin;
				++_begin;
			}
			--finish;
			return pos;
		}
		T& operator[](size_t pos)
		{
			return *(start + pos);
		}
	private:
		iterator start;
		iterator finish;
		iterator endofstorage;
	};
}
using namespace smx;

template<class type>
void print(vector<type>& v)
{
	for (auto e : v)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}
int main()
{
	vector<std::string> v1;
	v1.push_back("aaaa");
	v1.push_back("bbbb");
	v1.push_back("cccc");
	v1.push_back("dddd");
	print(v1);


	system("pause");
	return 0;
}