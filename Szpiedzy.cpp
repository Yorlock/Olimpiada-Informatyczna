#include <iostream>
using namespace std;
#define MAX 1000000
int n, countBefore, countAfter;
int tracing[MAX], beingTrace[MAX], notBeingTrace[MAX], checked[MAX];

int main()
{
    int spy, result;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) 
    {
        cin >> tmp;
        tracing[i] = tmp - 1;
    }
    for (int i = 0; i < n; i++) beingTrace[tracing[i]]++;
    for (int i = 0; i < n; i++) if (!beingTrace[i]) notBeingTrace[countBefore++] = i;

    result = 0;
    while (countAfter < countBefore) 
    {
        spy = notBeingTrace[countAfter++];
        if (!checked[tracing[spy]]) 
        {
            result++;
            checked[spy] = checked[tracing[spy]] = 1;
            int tmp = tracing[tracing[spy]];
            if (!checked[tmp] && --beingTrace[tmp] == 0) notBeingTrace[countBefore++] = tmp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!checked[i]) 
        {
            spy = i;
            while (!checked[spy] && !checked[tracing[spy]]) 
            {
                result++;
                checked[spy] = checked[tracing[spy]] = 1;
                spy = tracing[tracing[spy]];
            }
        }
    }
    cout << result;
    return 0;
}
