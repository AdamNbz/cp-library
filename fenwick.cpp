/*
Author : Nguyen Vo Ngoc Bao
School : University of Information Technology, VNU-HCM
*/

template <typename T>
class fenwick {
public:
    vector<T> fw;
    int n;

    // Constructor for initialization of size 
    fenwick(int _n) : n(_n + 1) 
    {
        fw.resize(n);
    }

    // to modify , add or replace value at index x
    void modify(int x, T v) 
    {
        while (x <= n) 
        {
            fw[x] += v;
            x += (x & -x);
        }
    }

    // To get sum of prefix ending at x
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

    // To get largest value with cumulative sum less than or equal to x
    // For smallest version, pass x-1 and add 1 to result
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