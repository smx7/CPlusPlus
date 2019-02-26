#include"MyRBTree.h"


	template<class K, class V>
	class map
	{
		class KeyOfValue
		{
		public:
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
	public:
		typedef typename RBTree<K, pair<K, V>, KeyOfValue>::_iterator iterator;

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
		V& operator[](const K& key)
		{
			return (*(tree.insert(make_pair(key, V()))).first).second;
		}
		pair<iterator, bool> insert(const pair<K, V>& kv)
		{
			return tree.insert(kv);
		}
	private:
		RBTree<K, pair<K, V>, KeyOfValue> tree;
	};

	void testmap()
	{
		map<int, string> m;
		
		m.insert(make_pair(3, "three"));
		m.insert(make_pair(5, "five"));
		m.insert(make_pair(4, "four"));
		m.insert(make_pair(1, "one"));
		m.insert(make_pair(2, "two"));

		map<int, string>::iterator it = m.begin();
		while (it != m.end())
		{
			cout << (*it).first << "-->" << (*it).second << "  ";
			cout << it->first << "-->" << it->second << endl;
			it++;
		}

		m[6];
		m[7] = "seven";

		it = m.begin();
		while (it != m.end())
		{
			cout << (*it).first << "-->" << (*it).second << "  ";
			cout << it->first << "-->" << it->second << endl;
			it++;
		}
		cout << m[4] << endl;
	}