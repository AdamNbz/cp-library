template<typename T>
T mod(T a, T b)
{
    return ((a%b)+b)%b;
}

template<typename T>
T lcm(T a, T b)
{
    return a/gcd(a, b)*b;
}

template<typename T>
T binpow(T a, T b, T m)
{
    T ret = 1;
    while (b)
    {
        if (b & 1)
            ret = mod(ret*a, m);
        a = mod(a*a, m);
        b >>= 1;
    }
    return ret;
}

template<typename T>
void euler_totient(T n)
{
    for (T i=1; i<=n; i++) phi[i] = i;
    for (T i=2; i<=n; i++)
    {
        if (phi[i] == i)
            for (T j=i; j<=n; j+=i) phi[j] -= phi[j]/i;
    }
}

template<typename T>
void precalc_mobius()
{
    mobius[1] = 1;
    for (T i=2; i<LimN; i++)
    {
        mobius[i]--;
        for (T j=i+1; j<LimN; j+=i) mobius[j] -= mobius[i];
    }
}