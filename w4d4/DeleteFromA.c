int DeleteFromA(int* p, int n, int post)
{
    for (int i = post; i < n; i++)
    {
        p[i] = p[i + 1];
    }
    p[n - 1] = 0;
    return n - 1;
}