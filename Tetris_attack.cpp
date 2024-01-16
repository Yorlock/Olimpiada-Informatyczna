#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int used[50001];
vector<int> tower;

int main()
{
    cin >> n;
    int tmp;
    for (int i = 0; i < 2*n; i++)  {
        cin >> tmp;
        tower.push_back(tmp);
    }

    reverse(tower.begin(), tower.end());
    int result = 0;
    vector<int> holder;
    vector<int> changes;

    while(!tower.empty())
    {
        int top = tower.back();
        tower.pop_back();

        if(!used[top])
        {
            holder.push_back(top);
            used[top] = true;
        }
        else
        {
            int top2 = holder.back();
            if(top != top2)
            {
                tower.push_back(top2);
                tower.push_back(top);
                result++;
                changes.push_back(holder.size());
                used[top2] = false;
            }
            holder.pop_back();
        }
    }

    cout << result << "\n";
    for (int i = 0 ; i < changes.size(); i++) 
    {
        cout << changes[i] << "\n";
    }
}