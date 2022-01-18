#include <iostream>
#define MAX_N 3000

int n, m;
int matrix[MAX_N][MAX_N];
bool erased[MAX_N];

int main()
{
    scanf("%d%d", &n, &m);
    int a, b;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d", &a, &b);
        matrix[a - 1][b - 1] = true;
        matrix[b - 1][a - 1] = true;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n && !erased[i]; j++)
        {
            if(!matrix[i][j] && !erased[j])
            {
                erased[i] = true;
                erased[j] = true;
            }
        }
    }
    int k = 0;
    for(int i=0; n/3>k && i<n; i++)
    {
        if(!erased[i])
        {
            k++;
            printf("%d ", i+1);
        }
    }
    printf("\n");
    return 0;
}
