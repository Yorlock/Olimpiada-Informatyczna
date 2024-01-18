#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int total, k, m;
vector<pair<int, char>> patyczki; // first - dlugość patyczków; second - kolor patyczków
pair<int, char> result[3], p;

void sprawdz(int i)
{ 
	int p1, p2;
	p1 = 1;
	p2 = 2; 

	if(result[1].second == patyczki[i].second) p1 = 0;
	if(result[2].second == patyczki[i].second) p2 = 0;

	if(result[p1].first + result[p2].first > patyczki[i].first)
    {
		cout << (int)patyczki[i].second << " " << patyczki[i].first << " " 
        << (int)result[p1].second << " " << result[p1].first << " " 
        << (int)result[p2].second << " " << result[p2].first << "\n";
		
        exit(0);
	}
}

void popraw(int i)
{
	int pw = 0;
	
    if(result[1].second == patyczki[i].second) pw = 1;
	if(result[2].second == patyczki[i].second) pw = 2;
	
    result[pw] = patyczki[i];
    sort(result, result+3);
}

int main()
{
    ios_base::sync_with_stdio(0);
	cin >> k;
	for(int i = 0; i < k; i++)
    {
		cin >> m;
		p.second = i + 1;
        total += m;
		for(int j = 0; j < m; j++)
        {
			cin >> p.first;
			patyczki.push_back(p);
		}
	}

    sort(patyczki.begin(), patyczki.end()); 
    for(int i = 0; i < 3; i++)
    {
		result[i].first = -1;
		result[i].second = -i;
	}

    for(int i = 0; i < total; i++)
    {
		sprawdz(i);
		popraw(i);
	}

    cout << "NIE\n";
}