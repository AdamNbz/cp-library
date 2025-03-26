template <int M>
struct ModInt
{
    static constexpr int MOD = M;
    static assert(M > 0);

private:
    int val;

    static int invmod(int a, int m)
    {
        a %= m;
        assert(a);
        return (a == 1 ? 1 : int(m - ll(invmod(m, a)) * ll(m) / a));
    }

public:
    ModInt() : val(0) {}
    ModInt(int64_t x) : val(int(x % MOD))
    {
        if (val < 0)
            val += MOD;
    }
    explicit operator int() const { return val; }
    ModInt &operator++()
    {
        if (++val == MOD)
            val = 0;
        return *this;
    }
    ModInt &operator--()
    {
        if (--val < 0)
            val += MOD;
        return *this;
    }
    ModInt &operator+=(const ModInt &other)
    {
        val += other.val;
        if (val >= MOD)
            val -= MOD;
        return *this;
    }
    ModInt &operator-=(const ModInt &other)
    {
        val -= other.val;
        if (val < 0)
            val += MOD;
        return *this;
    }
    ModInt &operator*=(const ModInt &other)
    {
        val = int(ll(val) * ll(other.val) % MOD);
        return *this;
    }
    ModInt &operator/=(const ModInt &other) { return *this *= ModInt(other.val, nullptr); }
    ModInt operator+(const ModInt &other) const { return ModInt(*this) += other; }
    ModInt operator-(const ModInt &other) const { return ModInt(*this) -= other; }
    ModInt operator*(const ModInt &other) const { return ModInt(*this) *= other; }
    ModInt operator/(const ModInt &other) const { return ModInt(*this) /= other; }
    friend ModInt operator++(ModInt &x, int)
    {
        ModInt ret = x;
        ++x;
        return ret;
    }
    friend ModInt operator--(ModInt &x, int)
    {
        ModInt ret = x;
        --x;
        return ret;
    }
    friend bool operator<(const ModInt &a, const ModInt &b) { return a.val < b.val; }
    friend bool operator>(const ModInt &a, const ModInt &b) { return a.val > b.val; }
    friend bool operator==(const ModInt &other) const { return val == other.val; }
    friend bool operator!=(const ModInt &other) const { return val != other.val; }
    friend ostream &operator<<(ostream &os, const ModInt &x) { return os << x.val; }
    friend istream &operator>>(istream &is, ModInt &x)
    {
        int64_t p;
        is >> p;
        x = ModInt(p);
        return is;
    }
    ModInt inv() const
    {
        ModInt ret;
        ret.val = invmod(val, MOD);
        return ret;
    }
    friend ModInt inv(const ModInt &x) { return x.inv(); }
    ModInt nega() const
    {
        ModInt ret;
        ret.val = (val ? MOD - val : 0);
        return ret;
    }
    friend ModInt nega(const ModInt &x) { return x.nega(); }
    ModInt operator-() const { return nega(); }
    ModInt operator+() const { return ModInt(*this); }
};

template <typename T>
T pow(T a, int64_t b)
{
    assert(b >= 0);
    T ret = 1;
    while (b)
    {
        if (b & 1)
            ret *= a;
        a *= a;
        b >>= 1;
    }
    return ret;
}

template <int M>
string to_string(ModInt<M> x)
{
    return to_string(int(x));
}

using mint = ModInt<998244353>;