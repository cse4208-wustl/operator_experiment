class VersionA {
public:
    static int copyCount;
    static int assignCount;

    VersionA(int v = 0);

    VersionA(const VersionA &rhs);

    VersionA &operator=(const VersionA &rhs);

    VersionA &operator+=(const VersionA &rhs);

    int value() const { return value_; }

private:
    int value_;
};

VersionA operator+(const VersionA &lhs, const VersionA &rhs);
