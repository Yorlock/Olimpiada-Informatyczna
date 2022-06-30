#include <vector>
#include <iostream>
using namespace std;
#define MAX 1000000

int m, n, k, a[MAX];
vector<int> b[MAX], worek[MAX], swapper;

int main()
{
    cin >> m;
    for(int i=0; i < m; i++) cin >> a[i];
    cin >> n;
    for(int i=0; i<n; i++)
	{
        cin >> k;
        b[i] = vector<int>(k, 0);
        for(int j = 0; j < k; j++) cin >> b[i][k - j - 1];
        worek[b[i].back() - 1].push_back(i);
    }
    for(int i=0; i<m; i++)
	{
		swapper.clear();
		swap(swapper, worek[a[i] - 1]);
		for(int j = 0; j < (int)swapper.size(); j++)
		{
			b[swapper[j]].pop_back();
			if(!b[swapper[j]].empty())
				worek[b[swapper[j]].back() - 1].push_back(swapper[j]);
		}
	}
    for(int i=0; i<n; i++) cout << (b[i].empty()?"TAK\n":"NIE\n");
	return 0;
}