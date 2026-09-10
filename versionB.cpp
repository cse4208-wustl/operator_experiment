#include <iostream>

#include "versionB.h"

using namespace std;

int VersionB::copyCount = 0;
int VersionB::assignCount = 0;

VersionB::VersionB(int v) : value_(v) {}

VersionB::VersionB(const VersionB &rhs) : value_(rhs.value_) {
    ++copyCount;
    std::cout << "  [A] copy constructor   (copyCount=" << copyCount << ")\n";
}

VersionB& VersionB::operator=(const VersionB &rhs) {
    value_ = rhs.value_;
    ++assignCount;
    std::cout << "  [A] copy-assignment    (assignCount=" << assignCount << ")\n";
    return *this;
}

// += is implemented by calling +
VersionB& VersionB::operator+=(const VersionB &rhs) {
    *this = *this + rhs;
    return *this;
}

// + does the real work: adds the values, constructs new object and returns it
VersionB operator+(const VersionB &lhs, const VersionB &rhs) {
    VersionB sum(lhs);
    sum.value_+= rhs.value_;
    return sum;
}
