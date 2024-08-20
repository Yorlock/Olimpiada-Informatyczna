#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 1000001;
vector<int> adj[MAXN];
bool visited[MAXN];

int Check(int u, int k) {
    int numChildren = 0, sumTree = 0;
    visited[u] = true;
    for (int i = 0; i < (int)adj[u].size(); i++)
    {
        if (!visited[adj[u][i]]) 
        {
            numChildren++;
            sumTree += Check(adj[u][i], k);
        }
    }

    return max(0, numChildren+sumTree-k);
}

int main() {
    int N, resultCrew = 0, enoughCrew;
    cin >> N;
    if (N < 0) return 0;
    for (int i = 0; i < N-1; i++) 
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    enoughCrew = N;
    while (resultCrew < enoughCrew) 
    {
        int checkNumberCrew = (resultCrew+enoughCrew)/2;
        fill(visited, visited+N, false);
        if (Check(0, checkNumberCrew) == 0)
        {
            enoughCrew = checkNumberCrew;
        }
        else
        {
            resultCrew = checkNumberCrew+1;
        }
    }

    cout << resultCrew << "\n";
    return 0;
}
