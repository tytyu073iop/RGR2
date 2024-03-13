#pragma once
#include "KSet.h"

using ksi = KSetIterator;

class KSetIterator {
private:
	KSet* set;
	size_t index = 0;
public:
	KSetIterator(KSet* s);
	void forward();
	void back();
	int& get() const;
	ksi& operator++();
	ksi& operator--();
	ksi& operator++(int i);
	ksi& operator--(int i);
	int& operator*();
};