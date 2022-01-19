#include <iostream>
#include <algorithm>

using namespace std;
int p;
long long k;
int main()
{
    cin >> p;
    for(int i=0; i<p; i++)
    {
        cin >> k;
        long long x = 1, y = 1;
        while(y < k)
        {
            long long z = x + y;
            x = y; y = z;
        }
        int r = 0;
        while(k > 0)
        {
            if(k - x <= y - k) k -= x;
            else k = y - k;
            r++;
            while(x >= k)
            {
                long long z = y - x;
                y = x; x = z;
            }
        }
        cout << r << "\n";
    }
    return 0;
}
