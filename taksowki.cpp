#include <algorithm>
#include <iostream>
#define MAX_N 500000

using namespace std;

int n;
long long m, d;
long long taxi[MAX_N];

int solution()
{
    if (taxi[0] < m-d) return 0;
    int k = 0;
    while(k+1 < n && taxi[k+1] >= m-d) k++;
    long long last = taxi[k];
    while(k+1 < n)
    {
        taxi[k] = taxi[k+1];
        k++;
    }
    n--;
    long long position = 0;
    for(int i=0; i<n; i++)
    {
        if(2LL*(d - position) + m - d <= last) return i+1;
        if(d - position > taxi[i]) return 0;
        position += (taxi[i] - (d - position));
        if(position >= m) return i+1;
        if(position > d) position = d;
    }
    if(2LL*(d - position) + m - d <= last) return n+1;
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> d >> n;
    for(int i=0; i<n; i++) cin >> taxi[i];
    sort(taxi, taxi + n, greater<long long>());
    cout << solution() << "\n";
    return 0;
}