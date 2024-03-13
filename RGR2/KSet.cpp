#include "KSet.h"
#include <set>
#include <algorithm>

KSet::KSet()
{
}

KSet::~KSet()
{
}

KSet::KSet(std::vector<int> v) : v(v) {

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
	std::vector<int> q, w1(v), w2(rhs.w);
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
	std::vector<int> q, w1(v), w2(rhs.w);
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

