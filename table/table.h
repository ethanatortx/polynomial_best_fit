#ifndef MD5H_TABLE_H
#define MD5H_TABLE_H

#include <algorithm>
#include <cmath>
#include <exception>
#include <iostream>
#include <string>
#include <utility>
#include "..\hash\md5.h"
#include "..\list\list.h"
#include "..\math\prime.h"

// this is so gross
int hex_val(char h)
{
	switch(h)
	{
		case 0: return 0;
		case 1: return 1;
		case 2: return 2;
		case 3: return 3;
		case 4: return 4;
		case 5: return 5;
		case 6: return 6;
		case 7: return 7;
		case 8: return 8;
		case 9: return 9;
		case 'a': return 10;
		case 'b': return 11;
		case 'c': return 12;
		case 'd': return 13;
		case 'e': return 14;
		case 'f': return 15;
	}
	return -1;
}

unsigned long htoul(std::string hash)
{ return std::stoul(hash, nullptr, 16); }

unsigned get_hash_index(std::string hash, unsigned tblSize)
{
	unsigned long q1, q2, q3, q4;
	q1 = htoul(hash.substr(0, 8));
	q2 = htoul(hash.substr(8, 8));
	q3 = htoul(hash.substr(16, 8));
	q4 = htoul(hash.substr(24, 8));
	return (q1 ^ q2 ^ q3 ^ q4) % tblSize;
}

template<class Key,
		 class Value = Key>
class hash_table
{
	struct hash_node
	{
		hash_node(Key k = Key(), Value v = Value()): key(k), value(v) {}
		Key key;
		Value value;
	};

	typedef list<hash_node> bucket;

public:
	hash_table(unsigned s = 13);
	~hash_table();

	hash_table<Key, Value>& operator=(const hash_table<Key, Value>&);
	Value& operator[](const Key&);

	unsigned size() const;
	unsigned node_count() const;
	void resize(unsigned);

	void add(const Key& k, const Value& v);
	bool remove(const Key& k);

	bool empty() const;
	void clear();

	template<class K, class V>
	friend void print(const hash_table<K, std::string>&);
	template<class K, class V>
	friend void print(const hash_table<K, int>&);
	template<class K, class V>
	friend void print(const hash_table<K, unsigned>&);
	template<class K, class V>
	friend void print(const hash_table<K, std::pair<std::string, std::string> >&);
	void printh() const;

private:
	const unsigned _size;
	bucket* arr;
};

template<class Key, class Value>
hash_table<Key, Value>::hash_table(unsigned s): _size(s)
{
	arr = new bucket[_size];
}

template<class Key, class Value>
hash_table<Key, Value>::~hash_table()
{
	delete[] arr;
}

template<class Key, class Value>
hash_table<Key, Value>& hash_table<Key, Value>::operator=(const hash_table<Key, Value>& other)
{
	this->_size = other.size();
	delete[] arr;
	arr = new bucket[_size];
	for(int i = 0; i < _size; ++i)
		arr[i].operator=(other.arr[i]);
	return (*this);
}

template<class Key, class Value>
Value& hash_table<Key, Value>::operator[](const Key& k)
{
	for(typename list<hash_node>::const_iterator i = arr[get_hash_index(md5(k), _size)].begin();
		i != arr[get_hash_index(md5(k), _size)].end(); ++i)
	{
		if(i->key == k)
			return i->value;
	}
}

template<class Key, class Value>
unsigned hash_table<Key, Value>::size() const
{ return _size; }

template<class Key, class Value>
unsigned hash_table<Key, Value>::node_count() const
{
	unsigned ncount = 0;
	for(int i = 0; i < _size; ++i)
		ncount += arr[i].size();
	return ncount;
}

template<class Key, class Value>
void hash_table<Key, Value>::resize(unsigned nsize)
{
	bucket* old = arr;
	arr = new bucket[nsize];
	int i;
	for(i = 0; i < _size; ++i)
		arr[i] = old[i];
	delete[] old;
	_size = nsize;
}

template<class Key, class Value>
void hash_table<Key, Value>::add(const Key& k, const Value& v)
{ arr[get_hash_index(md5(k), _size)].push_back(hash_node(k, v)); }

template<class Key, class Value>
bool hash_table<Key, Value>::remove(const Key& k)
{
	for(typename list<hash_node>::iterator i = arr[get_hash_index(md5(k), _size)].begin();
		i != arr[get_hash_index(md5(k), _size)].end(); ++i)
	{
		if(i->key == k)
		{
			arr[get_hash_index(md5(k), _size)].erase(i);
			return true;
		}
	}

	return false;
}

template<class Key, class Value>
bool hash_table<Key, Value>::empty() const
{
	for(int i = 0; i < _size; ++i)
		if(arr[i].size() > 0)
			return false;

	return true;
}

template<class Key, class Value>
void hash_table<Key, Value>::clear()
{
	delete[] arr;
	arr = new bucket[_size];
}

template<class Key, class Value>
void print(const hash_table<Key, Value>& tbl)
{
	for(int k = 0; k < tbl.size(); ++k)
		for(typename list<typename hash_table<Key, Value>::hash_node>::const_iterator i = tbl.arr[k].cbegin(); i != tbl.arr[k].cend(); ++i)
			std::cout << "Key: " << i->key << ", Value: " << i->value << '\n';
}

template<class Key, class Value>
void hash_table<Key, Value>::printh() const
{
	typename hash_table<Key, Value>::bucket::iterator curr;
	for(int i = 0; i < _size; ++i)
	{
		curr = arr[i].begin();
		while(curr++ != arr[i].end())
			std::cout << "x ";
		std::cout << std::endl;
	}
}


#endif