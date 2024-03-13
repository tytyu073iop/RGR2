#pragma once
#include <vector>
#include <iostream>

using kset = KSet;
using Kset = KSet;

class KSetIterator;

class KSet {
private:
	std::vector<int> v;
	KSet(std::vector<int> v);
public:
	KSet();
	~KSet();
	KSet& operator=(const KSet& rhs);
	KSet operator|(const KSet& rhs) const;
	KSet& operator|=(const KSet& rhs);
	kset operator&(const kset& rhs) const;
	kset& operator&=(const kset& rhs);
	kset operator/(const kset& rhs) const;
	kset& operator/=(const kset& rhs);
	kset& operator>>(const int& rhs);
	friend std::ostream& operator<<(std::ostream& os, const kset& rhs);
	size_t Size() const;
	void Clear();
	bool IsEmpty() const;
	bool IsFull() const;
	KSetIterator* GetIterator() const;
};