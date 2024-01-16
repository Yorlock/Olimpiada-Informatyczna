#include<iostream>
#include<cmath>
using namespace std;
#define MAXN 1000001
#define INF 9999999999LL

long long tab[MAXN], dp[MAXN];


int main()
{
    int n, s;
    cin >> n >> s;
    for(int i=1; i<=n; i++) { 
        cin >> tab[i];
    }

    for(int i=2; i<=n; i++) {
        if(tab[i-1] >= tab[i]) {
            tab[i] = tab[i-1] + 1;
        }
    }
        
    int load = 0;
    for(int i=1; i<=n; i++)
    {
        dp[i] = INF;
        int trains = i-load-1;
        while(load < i && max(dp[load]+trains, tab[i]) + trains + 2*s < dp[i])
        {
            dp[i] = max(dp[load]+trains, tab[i]) + trains + 2*s;
            load++; trains--;
        }
        load--;
    }

    cout << dp[n] << "\n";
    return 0;
}