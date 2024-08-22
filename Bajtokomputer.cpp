#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define INFI 1000000005
#define MAXN 1000009
int DATA[MAXN], SUMS[MAXN];
int NNZ[MAXN]; // nastepny niezerowy element (indeks lub N)
int n;

// -1 ? ? ? | 0/1 0 0 0 | 1 ? ? ?
//     A    |      B    |    C

// Suma na [a, b), assert(a <= b)
int sum(int a, int b)
{
    return a ? SUMS[b-1] - SUMS[a-1] : (b ? SUMS[b-1] : 0);
}

// Sprawdza czy mozna dokonczyc jedynkami [l1s, N)
int check1(int l1s) 
{
    int l1 = n - l1s;
    if (!l1 || (l1 && DATA[l1s] == 1)) return l1 - sum(l1s, n);
    return INFI;
}

// Sprawdzamy liczbę -1, liczbę 0 zgadujemy
int check(int l_1) 
{
    int m = 0;

    if (l_1 && DATA[0] != -1) return INFI; // Sprawdzamy -1
    m += l_1 + sum(0, l_1);
    if (l_1 == n) return m;

    int m1 = m, m2 = m;
    m1 += check1(l_1); // m1 = nie próbujemy 0

    // m2 -> znajdujemy najdłuższy przedział 0; Poprawiamy pierwszy element
    if (DATA[l_1] != 0) 
    {
        if (l_1 && DATA[l_1] == 1)
        {
            m2 += 1;
        } 
        else return m1;
    }

    m2 += check1(NNZ[l_1+1]); // Pozycja końca pierwszego 0
    return min(m1, m2);
}

int main() 
{
    iostream::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> DATA[i];
    }

    SUMS[0] = DATA[0];
    for (int i = 1; i <= n; ++i) 
    {
        SUMS[i] = DATA[i] + SUMS[i-1];
    }

    NNZ[n] = n;
    for (int i = n-1; i >= 0; --i) 
    {
        NNZ[i] = DATA[i] != 0 ? i : NNZ[i+1];
    }

    int result = INFI;
    for (int i = 0; i <= n; ++i)
    {
        result = min(check(i), result);
    }

    if (result == INFI) cout << "BRAK" << "\n";
    else cout << result << "\n";
}