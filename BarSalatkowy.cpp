#include <algorithm>
#include <iostream>
#define N 1000000
using namespace std;

int n, result, minValue;
int sums[N + 1], nexts[N + 1], peaks[N + 1], last[N + 1];
char fruits[N];

int main() {
    cin >> n >> fruits;
    for(int i = 1; i <= n; i++) 
    {
        sums[i] = sums[i - 1] + (fruits[i - 1] == 'p' ? 1 : -1);
        minValue = min(minValue, sums[i]);
    }

    for(int i = 0; i <= n; i++) 
    {
        last[i] = -1;
    }

    for(int i = n; i >= 0; i--) // w tablicy nexts mamy w której pozycji kolejny raz wystąpi dana liczba co jest na konkretnej pozycji w sums
    {
        nexts[i] = last[sums[i] - minValue];
        last[sums[i] - minValue] = i;
    }

    int cpeak = n;
    for(int i = 0; i <= n; i++)
    {
        peaks[i] = i;
    } 

    for(int i = n - 1; i >= 0; i--)  
    {
        if(fruits[i] == 'p')
        {
            if(nexts[i] != -1 && sums[peaks[nexts[i]]] >= sums[cpeak]) 
            {
                cpeak = peaks[nexts[i]];
            }

            peaks[i] = cpeak;
            result = max(result, cpeak - i);
        } 
        else 
        {
            cpeak = i;
        }
    }

    cout << result;
    return 0;
}

