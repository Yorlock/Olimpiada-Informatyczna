#include <iostream>
#include <vector>
using namespace std;
int n, helper, sum = 0, result = 0, x = 0, y = 0;
vector<int> cityDiff;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> helper;
        sum += helper;
        cityDiff.push_back(helper);
    }
    int halfSum = sum / 2;
    int minDiff = sum;
    while (y < n)
    {
        if(result < halfSum)
        {
            result += cityDiff[y];
            y++;
        }
        else
        {
            result -= cityDiff[x];
            x++;
        }
        int tmp = abs(halfSum - result);
        if (tmp < minDiff)
        {
            minDiff = tmp;
        } 
    }
    cout << halfSum - minDiff;
}