#include <iostream>

#define i_max 10000
int t[i_max];
int main()
{
    int sum=0, n, var;
    std::cin >> n;
    for(int i=0; i<n; i++)
    {
        std::cin >> var;
        t[var]++;
        sum += var;
    }
    int i=1, j=0;
    while(i<=i_max && j<n)
    {
        if(2*(j+1) > (n+1))
        {
            sum+=t[i]*i;
        }
        else if(2*(j+t[i])<(n+1))
        {
            sum-= t[i]*i;
        }
        else
        {
            sum+=((j+t[i]-(n+1) / 2)-((n / 2)-j))*i;
        }
        j+=t[i];
        i++;
    }
    std::cout << sum;
    return 0;
}
