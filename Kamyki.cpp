#include <iostream>

#define MAX_N 1000
int a[MAX_N+1], d[MAX_N+1];
int main()
{
    int u;
    scanf("%d", &u);
    for(int i=0; i<u; i++)
    {
        int n, result = 0;
        scanf("%d", &n);
        for (int j=1; j<=n; j++)
        {
            scanf("%d", &a[j]);
        }
        for (int j=1; j<n; j++)
        {
            d[j] = a[n-j+1] - a[n-j];
        }
        d[n] = a[1];
        for(int j=1; j<=n; j+=2)
        {
            result ^= d[j];
        }
        printf("%s\n", result ? "TAK" : "NIE");
    }
    return 0;
}
