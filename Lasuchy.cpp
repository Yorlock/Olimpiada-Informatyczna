#include <vector>
#include <iostream>
using namespace std;
int n, holder;
vector<int> result, cakes;

void change(int pos)
{
    int next = pos % n + 1;
    int previous = (pos + n - 2) % n + 1;  
    int nextValue = cakes[next] * (1 + (result[next] != next));
    int posValue = cakes[pos] * (1 + (result[previous] == previous));
    if (nextValue < posValue) 
    {
        result[pos] = pos;
    }
}

int main() 
{
    ios_base::sync_with_stdio(false);    
    cin >> n;
    cakes.push_back(-1);
    result.push_back(-1);
    for(int i = 1; i <= n; i++)
    {
        cin >> holder;
        cakes.push_back(holder);
        result.push_back(i % n + 1);
    }

    for (int i = 0; i < 2; i++)
    {
        for (int x = 1; x <= n; x++) 
        {
            change(x);
        }
    }

    for (int i = 0; i < 2; i++)
    {
        for (int x = n; x >= 1; x--) 
        {
            change(x);
        }
    }

    for (int i = 1; i <= n; i++) 
    {
        if(i != 1)
        {
            cout << " ";
        }
        
        cout << result[i];
    }
}