#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

#define SIZE 500001
int n, i, inst[SIZE], a, b;
int visited[SIZE];
vector<int> edg[SIZE];

pair<int,int> dfs(int i) {
    visited[i] = 1;
    vector<pair<int,int>> pom;
    for(int j = 0; j < edg[i].size(); j++)
    {
        if(!visited[edg[i][j]])
        {
            pom.push_back(dfs(edg[i][j]));
        }
    }

    sort(pom.begin(), pom.end());
    int ti = 0;
    int in = inst[i] + ti;
    for(int j = pom.size() - 1; j > 0; j--) 
    {
        if(pom[j].first + pom[j-1].second < pom[j-1].first + pom[j].second)
        {
            swap(pom[j], pom[j-1]);
        }

        in = max(in, ti + pom[j].first);
        ti += pom[j].second;
    }

    if(pom.size() > 0) 
    {
        in = max(in, ti + pom[0].first);
        ti += pom[0].second;
    }

    return make_pair(in + 1,ti + 2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(i=0; i<n; i++) 
    {
        cin >> inst[i+1];
    }
    
    for(i = 0; i < n - 1; i++)  {
        cin >> a >> b;
        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    cout<< max(dfs(1).first - 1, inst[1] + 2*n - 2)<< "\n";
}
