struct dsu
{
    int n;
    vector<int> par, s, r;
    dsu(int _n): n(_n), par(n), s(n, 1), r(n, 0) { iota(all(par), 0); }
    int get(int u) { return u == par[u] ? u : par[u] = get(par[u]); }
    int disjointSet() { return n; }
    int sizes(int u) { return s[get(u)]; }
    bool same(int u, int v) { return get(u) == get(v); }
    bool unite(int u, int v) 
    {
        u = get(u), v = get(v);
        if (u == v) return;
        if (r[u] < r[v]) swap(u, v);
        p[v] = u;
        r[u] += r[u] == r[v];
        s[u] += s[v];
        --n;
        return 1;
    }
};