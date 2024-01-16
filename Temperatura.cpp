#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX_N 1000000

int Tmin[MAX_N], Tmax[MAX_N];

// first - poziom, second - temperatura
int main(void){
    int n, result = 0;
    cin >> n;
    if (n == 1) return 1;
    for(int i=0; i<n; i++) cin >> Tmin[i] >> Tmax[i];
    deque<pair<int, int>> Queue;
    for(int i=0; i<n; i++)
    {
        int a=Tmin[i], b=Tmax[i];
        int maxTemp = i;
        while(!Queue.empty() && Queue.front().second <= a)
        {
            maxTemp = min(maxTemp, Queue.front().first);
            Queue.pop_front();
        }

        Queue.push_front(pair<int, int>(maxTemp, a));
        while(!Queue.empty() && Queue.back().second > b)
        {
            result = max(result, i-Queue.back().first);
            Queue.pop_back();
        }
    }

    while(!Queue.empty())
    {
        result = max(result, n-Queue.back().first);
        Queue.pop_back();
    }

    cout << result;
    return 0;
}
