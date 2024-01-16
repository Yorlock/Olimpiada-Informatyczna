#include <iostream>
#define N 1000000
using namespace std;
bool winning[N + 1], sold[N + 1];
int last[N + 1];
int m, n, maxWinning, nResult;
long long result[N + 1];

int main() {
    cin >> m;
    for (int i = 1; i <= m; ++i) {
        int b;
        cin >> b;
        winning[b] = true;
        maxWinning = b;
    }
    long long clients = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a;
        cin >> a;
        if (last[a] == 0) {
            last[a] = a;
        }
        int served = 0;
        for (; last[a] <= maxWinning && served < a; last[a] += a) {
            if (!sold[last[a]]) {
                sold[last[a]] = true;
                ++served;
                if (winning[last[a]]) {
                    result[++nResult] = clients + served;
                }
            }
        }
        clients += a;
    }
    cout << nResult << "\n";
    for (int i = 1; i <= nResult; ++i) {
        cout << result[i] << "\n";
    }
}


