#include "iterator.h"
#include <set>
#include <algorithm>

KSet::KSet()
{
}

KSet::~KSet()
{
}

KSet::KSet(const std::vector<int>& v) : v(v) {

}

KSet& KSet::operator=(const KSet& rhs)
{
	if (this != &rhs) {
		v = rhs.v;
	}
	return *this;
}

KSet KSet::operator|(const KSet& rhs) const
{
	std::set<int> s(v.begin(),v.end());
	for (const auto& i : rhs.v) {
		s.insert(i);
	}
	std::vector<int> q(s.begin(), s.end());
	return KSet(q);
}

KSet& KSet::operator|=(const KSet& rhs)
{
	*this = *this | rhs;
	return *this;
}

kset KSet::operator&(const kset& rhs) const
{
	std::vector<int> q, w1(v), w2(rhs.v);
	std::sort(w1.begin(), w1.end());
	std::sort(w2.begin(), w2.end());
	for (auto i = w1.begin(), j = w2.begin(); i != w1.end() || j != w2.end();) {
		if (*i != *j) {
			*i < *j ? i++ : j++;
			continue;
		}
		q.push_back(*i);
	}
}

kset& KSet::operator&=(const kset& rhs)
{
	*this = *this & rhs;
	return *this;
}

kset KSet::operator/(const kset& rhs) const
{
	std::vector<int> q, w1(v), w2(rhs.v);
	std::sort(w1.begin(), w1.end());
	std::sort(w2.begin(), w2.end());
	for (auto i = w1.begin(), j = w2.begin(); i != w1.end() || j != w2.end();) {
		if (*i == *j) {
			*i < *j ? i++ : j++;
			continue;
		}
		q.push_back(*i);
	}
}

kset& KSet::operator/=(const kset& rhs)
{
	*this = *this / rhs;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const kset& rhs)
{
	for (const auto& i : rhs.v) {
		os << i << " ";
	}
	return os;
}

size_t KSet::Size() const {
	return v.size();
}

void KSet::Clear() {
	v.clear();
}

bool KSet::IsEmpty() const {
	return v.empty();
}

bool KSet::IsFull() const {
	return false;
}

KSetIterator KSet::GetIterator() {
	return KSetIterator(this);
}