int InsertIntoA(int *p, int n, int post, int data)
{

    for (int i = n; i > post; i--)
    {
        p[n] = p[n - 1];
    }
    p[post] = data;
    return n + 1;
}