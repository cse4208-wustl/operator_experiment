# Operator Experiment

The code in this repository is designed to demonstrate that the answer to the following question is Version A. Defining `operator+` in terms of `operator+=` is more efficient than the other way around. The reason for this is because `operator+` has to make an extra copy, while `operator+=` can perform the calculation in place. If we define `operator+=` in terms of `operator+`, we give `operator+=` the inefficiency of `operator+`, which is unnecessary.

Both versions compile and give identical results. Which one is more efficient, and why?

```c++
// Version A: + calls +=
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;   // copy lhs
    sum += rhs;             // reuse compound assignment
    return sum;
}

// Version B: += calls +
Sales_data& Sales_data::operator+=(const Sales_data &rhs) {
    *this = *this + rhs;    // reuse arithmetic operator
    return *this;
}
```
