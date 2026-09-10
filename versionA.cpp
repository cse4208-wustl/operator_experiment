#include <iostream>

#include "versionA.h"

using namespace std;

int VersionA::copyCount = 0;
int VersionA::assignCount = 0;

VersionA::VersionA(int v) : value_(v) {}

VersionA::VersionA(const VersionA &rhs) : value_(rhs.value_) {
    ++copyCount;
    std::cout << "  [A] copy constructor   (copyCount=" << copyCount << ")\n";
}

VersionA& VersionA::operator=(const VersionA &rhs) {
    value_ = rhs.value_;
    ++assignCount;
    std::cout << "  [A] copy-assignment    (assignCount=" << assignCount << ")\n";
    return *this;
}

// += does the *real* work directly on this object -- no extra objects.
VersionA& VersionA::operator+=(const VersionA &rhs) {
    value_ += rhs.value_;
    return *this;
}

// + is implemented by copying lhs once, then reusing +=.
VersionA operator+(const VersionA &lhs, const VersionA &rhs) {
    VersionA sum = lhs;
    sum += rhs;   // no extra copy here - sum is already our own local copy
    return sum;
}

