#include<iostream>
#include<string.h>
#include<assert.h>
namespace smx
{
	class string
	{
	private:
		size_t capacity;
		size_t size;
		char *str;
		static const size_t npos = -1;
	private:
		friend std::ostream& operator<<(std::ostream& _cout, const smx::string& s);
	public:
		typedef char* Iterator;
	public:
		string(const char *_str = "")
		{
			if (nullptr == _str)
			{
				return;
			}
			size = strlen(_str);
			capacity = size;
			str = new char[capacity + 1];
			strcpy(str, _str);
		}
		string(const string& s) :str(new char[s.capacity + 1]), size(s.size), capacity(s.capacity)
		{
			strcpy(str, s.str);
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				char *pstr = new char[s.capacity + 1];
				strcpy(pstr, s.str);
				delete str;
				str = pstr;
				size = s.size;
				capacity = s.capacity;
			}
			return *this;
		}
		~string()
		{
			if (str)
			{
				delete[] str;
				str = nullptr;
			}
		}

		Iterator begin()
		{
			return str;
		}
		Iterator end()
		{
			return str + size;
		}

		void push_back(char c)
		{
			if (size == capacity)
			{
				reserve(capacity * 2);
			}
			str[size++] = c;
			str[size] = '\0';
		}
		void append(const char* _str)
		{
			for (size_t i = 0; i < strlen(_str); i++)
			{
				push_back(_str[i]);
			}
		}
		void append(size_t n, char c)
		{
			for (size_t i = 0; i < n; i++)
			{
				push_back(c);
			}
		}
		string& operator+=(const char c)
		{
			push_back(c);
			return *this;
		}
		string& operator+=(const char* _str)
		{
			append(_str);
			return *this;
		}
		bool operator<(const string& s)
		{
			return strcmp(str, s.str) < 0;
		}
		bool operator<=(const string& s)
		{
			return strcmp(str, s.str) <= 0;
		}
		bool operator>(const string& s)
		{
			return strcmp(str, s.str) > 0;
		}
		bool operator>=(const string& s)
		{
			return strcmp(str, s.str) >= 0;
		}
		bool operator==(const string& s)
		{
			return strcmp(str, s.str) == 0;
		}
		bool operator!=(const string& s)
		{
			return strcmp(str, s.str) != 0;
		}
		void clear()
		{
			size = 0;
			str[size] = '\0';
		}

		const char* c_str() const
		{
			return str;
		}
		size_t Size() const
		{
			return size;
		}
		size_t Capacity() const
		{
			return capacity;
		}
		bool empty() const
		{
			return size == 0;
		}
		void resize(size_t n,char c)
		{
			if (n > size)
			{
				if (n > capacity)
				{
					reserve(n);
				}
				for (size_t i = size; i < n; i++)
				{
					str[i] = c;
				}
			}
			str[n] = '\0';
			size = n;
		}
		void resize(size_t n)
		{
			if (n > size)
			{
				if (n > capacity)
				{
					reserve(n);
				}
				memset(str + size, '\0', n - size);
			}
			size = n;
			str[n] = '\0';
		}
		void reserve(size_t n)
		{
			if (n > capacity)
			{
				char *_str=new char[n + 1];
				strcpy(_str, str);
				delete str;
				str = _str;
				capacity = n;
			}
		}

		const char& operator[](size_t index)
		{
			assert(index < size);
			return str[index];
		}
		const char& operator[](size_t index) const
		{
			assert(index < size);
			return str[index];
		}
		size_t find(char c, size_t pos = 0) const
		{
			assert(pos < size);
			for (size_t i = pos; i < size; i++)
			{
				if (str[i] == c)
				{
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* s, size_t pos = 0) const
		{
			assert(pos < size);
			if (strstr(str, s) == nullptr)
			{
				return npos;
			}
			char *_str = strstr(str, s);
			for (size_t i = pos; i < size; i++)
			{
				if (&str[i] == _str)
				{
					return i;
				}
			}
			return npos;
		}
		string substr(size_t pos, size_t n)
		{
			string s(str);
			s.erase(0, pos);
			s.erase(n, s.size - n);
			return s;
		}
		string& insert(size_t pos, char c)
		{
			assert(pos<size);
			if (size == capacity)
			{
				reserve(capacity * 2);
			}
			for (size_t i = size; i > pos; i--)
			{
				str[i] = str[i - 1];
			}
			str[pos] = c;
			size++;
			str[size] = '\0';
			return *this;
		}
		string& insert(size_t pos, const char* _str)
		{
			assert(pos<size);
			size_t len = strlen(_str);
			if (len + size > capacity)
			{
				reserve(capacity * 2 + len);
			}
			for (size_t i = size + len; i > pos; i--)
			{
				str[i] = str[i - len];
			}
			for (size_t i = pos; i < pos + len; i++)
			{
				str[i] = _str[i - pos];
			}
			size += len;
			str[size] = '\0';
			return *this;
		}
		string& erase(size_t pos, size_t len)
		{
			assert(pos + len <= size);
			for (size_t i = pos; i < size; i++)
			{
				str[i] = str[i + len];
			}
			size -= len;
			str[size] = '\0';
			return *this;
		}
	};
}
std::ostream& smx::operator<<(std::ostream& _cout, const smx::string& s)
{
	std::cout << s.str;
	return _cout;
}
using namespace smx;
int main()
{
	string s1("abcdefghijklmn");
	auto it = s1.begin();
	while (it != s1.end())
	{
		std::cout << *it++;
	}
	std::cout << std::endl;
	system("pause");
	return 0;
}