template <typename T>
void make(T v)
{
    par[v] = v;
    //size[v] = 1; - implementation by size
    //rank[v] = 0; - implementation by rank
}

template <typename T>
T find(T v)
{
    if (v == par[v]) return v;
    return par[v] = find(par[v]);
}

template <typename T>
void merge(T a, T b)
{
    a = find(a);
    b = find(b);
    if (a != b) par[b] = a;
    /* Implementation by size
    if (a != b)
    {
        if (size[a] < size[b]) swap(a, b);
        par[b] = a;
        size[a] += size[b];
    }
    */
   
   /* Implementation by rank
   if (a != b)
   {
        if (rank[a] < rank[b]) swap(a, b);
        par[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
   }
   */
}