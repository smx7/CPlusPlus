#include"MyRBTree.h"

template<class K>
class set
{
	class KeyOfValue
	{
	public:
		const K& operator()(const K& key)
		{
			return key;
		}
	};

public:
	typedef typename RBTree<K, K, KeyOfValue>::_iterator iterator;

	iterator begin()
	{
		return tree.begin();
	}
	iterator end()
	{
		return tree.end();
	}
	bool empty() const
	{
		return tree.empty();
	}
	pair<iterator, bool> insert(const K& key)
	{
		return tree.insert(key);
	}
private:
	RBTree<K, K, KeyOfValue> tree;
};
void testset()
{
	set<int> s;
	s.insert(3);
	s.insert(6);
	s.insert(3);
	s.insert(1); 
	s.insert(4); 
	s.insert(7);
	s.insert(2);

	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}