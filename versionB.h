class VersionB {
public:
    static int copyCount;
    static int assignCount;

    VersionB(int v = 0);

    VersionB(const VersionB &rhs);

    VersionB &operator=(const VersionB &rhs);

    VersionB &operator+=(const VersionB &rhs);

    int value() const { return value_; }

    friend VersionB operator+(const VersionB &lhs, const VersionB &rhs);
private:
    int value_;
};

VersionB operator+(const VersionB &lhs, const VersionB &rhs);
