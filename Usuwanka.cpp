#include<iostream>
using namespace std;
#define MAXN 1000001

int stos[MAXN], sum[MAXN], result[MAXN];
int w, n, k, s;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1; i<=n; i++)
    {
        char z;
        cin >> z;
        int val;
        if(z == 'b')
        {
            val = 1;
        } 
        else
        {
            val = -k;
        }
        s++;
        stos[s] = i;
        sum[s] = sum[s-1] + val;
        if(s >= k+1 && sum[s] - sum[s-k-1] == 0) 
        {
            for(int j=0; j<k+1; j++)
            {
                result[w++] = stos[s--];
            }
        }
    }
    for(int i=0; i<n/(k+1); i++)
    {
        for(int j=0; j<k+1; j++)
        {
            cout << result[--w] << ' ';            
        }
        cout << "\n";
    }
    return 0;
}

