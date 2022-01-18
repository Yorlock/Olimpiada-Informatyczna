#include <iostream>
#include <algorithm>

int n, m, last, puck;

int main()
{
    scanf("%d%d", &n, &m);
    int tower[n];
    scanf("%d", &tower[0]);
    for(int i=1; i<n; i++)
    {
        scanf("%d", &tower[i]);
        tower[i] = std::min(tower[i], tower[i-1]);
    }
    last=n;
    for(int i=0; i<m; i++)
    {
        scanf("%d", &puck);
        while(last>0 && tower[last-1]<puck)
        {
          last--;
        }
        last--;
    }
    printf("%d\n", std::max(last+1,0));
    return 0;
}
