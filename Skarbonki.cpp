#include <iostream>
#define MAX_N 1000001
using namespace std;

int keys[MAX_N];
int checked[MAX_N];
int n, result = 0;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> keys[i];
    for (int i = 1; i <= n; i++)
    {
        int j = i;
        while (checked[j] == 0)
        {
            checked[j] = i;
            j = keys[j];
        }
        if (checked[j] == i)
            result++;
    }
    cout << result;
}
