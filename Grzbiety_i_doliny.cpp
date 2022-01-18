#include <cstdio>

#define MAX_N 1000
#define code(i, j) ((i)*MAX_N+j)
int map[MAX_N][MAX_N];
bool odw[MAX_N][MAX_N];
int stack[MAX_N*MAX_N];
int n, grzbiet, dolina, stackSize;

void Szukaj(int i, int j)
{
    odw[i][j] = 1;
    stackSize = 1;
    stack[0] = code(i, j);
    while(stackSize)
    {
        int x = stack[--stackSize];
        j = x%MAX_N;
        i = x/MAX_N;
        for(int ni=i - 1; ni<=i + 1; ni++)
            for(int nj=j - 1; nj<=j + 1; nj++)
            {
                if(ni >= 0 && ni < n && nj >= 0 && nj < n)
                {
                    if(map[ni][nj] == map[i][j] && !odw[ni][nj])
                    {
                        odw[ni][nj] = 1;
                        stack[stackSize++] = code(ni, nj);
                    }
                    else if(map[ni][nj] < map[i][j]) dolina = 0;
                    else if(map[ni][nj] > map[i][j]) grzbiet = 0;
                }
            }
    }
}

int main()
{
    int grzbiety = 0, doliny = 0;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            odw[i][j] = 0;
            scanf("%d", &map[i][j]);
        }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            if(!odw[i][j])
            {
               grzbiet = 1;
               dolina = 1;
               Szukaj(i, j);
               grzbiety += grzbiet;
               doliny += dolina;

            }
        }
    printf("%d %d\n", grzbiety, doliny);
    return 0;
}
