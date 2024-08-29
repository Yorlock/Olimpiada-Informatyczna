#include<vector>
#include<iostream>
#include <unordered_set>
using namespace std;

#define MAXN 100007
#define MAXK 1007
unordered_set<int> pair_na[MAXN]; // pary nieprzemienne
vector<int> W[2][MAXK];
int cia[2][MAXN], pref[2][MAXN];
int n, k, m;

bool czy()
{
  for(int i=1; i<=k; i++)
  {
    if((int)W[0][i].size() != (int)W[1][i].size()) return false;
    for(int e=0; e<2; e++)
    {
      for(int p=1; p<=n; p++)
      {
        pref[e][p] = pref[e][p-1];
        if(pair_na[i].find(cia[e][p]) != pair_na[i].end()) pref[e][p]++;
      }

      pref[e][n+1] = pref[e][n];
    }

    vector<int> poprz = {0, 0};
    for(int j=1; j<(int)W[0][i].size(); j++)
    {
      vector<int> akt = {W[0][i][j], W[1][i][j]};
      if(pref[0][akt[0]] - pref[0][poprz[0]] != pref[1][akt[1]] - pref[1][poprz[1]]) return false;
      poprz = akt;
    }
  }

  return true;
}

int main()
{
  cin >> n >> k >> m;
  while(m--)
  {
    int a, b;
    cin >> a >> b;
    pair_na[a].insert(b);
    pair_na[b].insert(a);
  }

  for(int i=1; i<=k; i++)
  {
    W[0][i].push_back(0);
    W[1][i].push_back(0);
  }

  for(int e=0; e<2; e++)
    for(int i=1; i<=n; i++)
    {
      cin >> cia[e][i];
      W[e][cia[e][i]].push_back(i);
    }

  for(int i=1; i<=k; i++)
  {
      W[0][i].push_back(n+1);
      W[1][i].push_back(n+1);
  }

  cout << (czy() ? "TAK\n" : "NIE\n");
}
