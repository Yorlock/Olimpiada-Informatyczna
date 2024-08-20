#include <iostream>
#include <vector>
#define MODULO 1000000000
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    vector<char>c;
    int n;
    cin >> n;
    n--;
    for (int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        c.push_back(temp);
    }

    if (c[0] == '+')
    {
        cout << 0 << "\n";
        return 0;
    }
    
    vector<long>w(n, 1);
    for (int i = 1; i < n - 1; i++)
    {
        if (c[i] == '+' && c[i + 1] == '-')
        {
            for (int j = i + 1; j < n; j++)
            {
                w[j] += w[j - 1];
                w[j] %= MODULO;
            }
        }
    }
    cout << w[n - 1] << "\n";
    return 0;
}