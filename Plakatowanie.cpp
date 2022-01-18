#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

int n, helper, element, result;
std::stack<int> stos;

int main()
{
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &helper, &element);
        while(!stos.empty() && stos.top() > element){
            stos.pop();
        }
        if(stos.empty() || stos.top() < element){
            stos.push(element);
            result++;
        }

    }
    printf("%d\n",result);
    return 0;
}
