#include "iterator.h"
#include "KSet.h"

long find(Kset* set, int num) {
    ksi it = set->GetIterator();
    for (int i = 0;;i++) {
        try {
            if (it.get() == num) {
                return i;
            }
            it.forward();
        } catch (ksi::Exception) {
            return -1;
        }
    }
}

long find2(Kset* set, int num) {
    ksi it = set->GetIterator();
    for (int i = 0;;i++) {
        try {
            if (*it == num) {
                return i;
            }
            it++;
        } catch (ksi::Exception) {
            return -1;
        }
    }
}

int main() {
    KSet set({0,3,5,6,8,1});
    std::cout << find(&set, 3) << std::endl;
    std::cout << find2(&set, 3) << std::endl;
    std::cout << find(&set, 4) << std::endl;
    return 0;
}