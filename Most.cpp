#include <iostream>

using namespace std;
int n, first, second, t1, t2, result, size;

int main()
{
    cin >> n >> first;
    if(n==1)
    {
        cout << first; 
        return 0;
    }
    cin >> second;
    result = second;
    size = 2;
    if(n%2==1)
    {
        cin >> t1;
        size++;
        result += t1 + first;
    }
    while(size < n)
    {
        cin >> t1 >> t2;
        if (t1 <= 2 * second - first) result += t1 + t2 + 2 * first; // najszybszy idzie 2x z wolniejszymi
        else result += t2 + 2 * second + first; // wolni idą razem, a po najszybszego idzie drugi najszybszy
        size += 2;
    }
    cout << result; 
    return 0;
}