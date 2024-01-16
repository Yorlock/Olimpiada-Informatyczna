#include <iostream>
#include <algorithm>

using namespace std;
#define INF 999999999
#define MAXN 1000000

int weight[MAXN], original[MAXN], expected[MAXN];
bool checked[MAXN];
int minWeight = INF, n;
long long result = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        minWeight = min(minWeight, weight[i]);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> original[i];
        original[i]--;
    }

    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        number--;
        expected[number] = original[i]; // na miejscu słonia expected[number] stoi słoń original[i]
    }

    for (int i = 0; i < n; i++)
    {
        if (!checked[i])
        {
            int minLocal = INF, elephant = i, nCycle = 0;
            long long sum = 0;
            while (true)
            {
                minLocal = min(minLocal, weight[elephant]);
                sum += weight[elephant];
                elephant = expected[elephant];
                checked[elephant] = true;
                nCycle++;
                if (elephant == i) break;
            }

            result += min(sum + (nCycle - 2)*(long long)minLocal, 
                sum + minLocal + (nCycle + 1)*(long long)minWeight);
        }
    }

    cout << result;
}