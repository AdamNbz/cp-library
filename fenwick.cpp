/*
Author : Nguyen Vo Ngoc Bao
School : University of Information Technology, VNU-HCM
*/

template <typename T>
class Fenwick {
public:
    vector<T> fw;
    int n;

    Fenwick(int _n) : n(_n + 1) 
    {
        fw.resize(n);
    }

    void modify(int x, T v) 
    {
        while (x <= n) 
        {
            fw[x] += v;
            x += (x & -x);
        }
    }

    T get(int x) 
    {
        T v{};
        while (x > 0) 
        {
            v += fw[x];
            x -= (x & -x);
        }
        return v;
    }

    T getind(int x)
    {
        T idx = 0, mask = n;
        while (mask && idx < n)
        {
            int t = idx+mask;
            if (t >= fw[t]) 
            {
                idx = t;
                x -= tree[t];
            }
            mask >>= 1;
        }
        return idx;
    }
};