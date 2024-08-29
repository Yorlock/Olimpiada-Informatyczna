#include<iostream>
#include<vector>
using namespace std;
std::vector<int>sa[200002];
bool odw[200002];

int res,n,a,b;
int dyn(int ve)
{
	odw[ve]=true;
	int best=0, second_best=0;
	int re;
	for(auto s:sa[ve])
	{
		if(!odw[s])
		{
			re=dyn(s);
			if(re > second_best)
			{
				swap(re,second_best);
				if(second_best > best) swap(second_best,best);
			}
		}
	}
	int new_res = second_best + best + sa[ve].size() - 2 + (second_best==0);
	res=max(new_res,res);
	return best + sa[ve].size() - 2 + (best==0);
}

int main() 
{
	ios_base::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		sa[a].push_back(b);
		sa[b].push_back(a);
	}
	
	dyn(1);
	cout<<res<<"\n";
}
