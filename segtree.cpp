ll st[4*LimN];

template<typename T>
void update(T id, T l, T r, T i, T val)
{
    if (l > i || i > r) return;
    if (l == r) 
    {
        st[id] = val;
        return;
    }
    T m = l+r >> 1;
    update(2*id, l, m, i, val);
    update(2*id+1, m+1, r, i, val);
    // If calculate sum:
    st[id] = st[2*id] + st[2*id+1];
    // If finding min:
    st[id] = min(st[2*id], st[2*id+1]);
}

template<typename T>
T get(T id, T l, T r, T u, T v)
{
    if (l > v || u > r) return inf;
    if (l >= u && r <= v) return st[id];
    T m = l+r>>1;
    // If finding min:
    return min(get(2*id, l, m, u, v), get(2*id+1, m+1, r, u, v));
    // If calculate sum:
    return get(2*id, l, m, u, v) + get(2*id+1, m+1, r, u, v);
}