#include <cstdio>
#include <iostream>
#include <vector>
#define MAXN 500001
#define FORE(i,x) for(__typeof((x).begin()) i=(x).begin();i != (x).end();++i)
using namespace std;

int n, m, k;
vector<int> edges[MAXN], towers;
bool safe[MAXN];

int main() 
{
    std::ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
    {
        if(!safe[i]) 
        {
            towers.push_back(i);
            safe[i] = true;
            FORE(j, edges[i])
            {
                safe[*j] = true;
                FORE(p, edges[*j])
                {
                    safe[*p] = true;
                }
            }
        }
    }

    if ((int)towers.size() > k)
    {
        return 0;
    }

    cout << towers.size() << "\n";
    for (int i = 0; i < towers.size(); i++)
    {
        cout << towers[i] << " ";
    }

    cout << "\n";
    return 0;
}
