#include "iterator.h"


KSetIterator::KSetIterator(KSet* s) : set(s) {
    
}

void KSetIterator::forward() {
    index++;
    if (index >= set->Size()) {
        throw Exception::OutOfRange;
    }
}

void KSetIterator::back() {
    index--;
    if (index < 0) {
        throw Exception::OutOfRange;
    }
}

int& KSetIterator::get() const {
    if (set->IsEmpty()) {
        throw Exception::OutOfRange;
    }
    return set->v[index];
}

ksi KSetIterator::operator--()
{
    ksi temp = *this;
    back();
    return temp;
}

ksi& KSetIterator::operator--(int i)
{
    back();
    return *this;
}

ksi KSetIterator::operator++()
{
    ksi temp = *this;
    forward();
    return temp;
}

ksi& KSetIterator::operator++(int i)
{
    forward();
    return *this;
}

int& KSetIterator::operator*()
{
    return get();
}