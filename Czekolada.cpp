#include <iostream>
#include <stdio.h>
#include <cstdio>
using namespace std;
#define MAX_N 1000
int pionowe[MAX_N], poziome[MAX_N];
int main()
{
    int n, m, k, lpion=0, lpoz=0;
    long koszt=0;
    scanf("%d%d",&n, &m);
    for(int i=0; i<n-1; i++)
    {
        scanf("%d",&k);
        pionowe[k]+=1;
    }
    for(int i=0; i<m-1; i++)
    {
        scanf("%d",&k);
        poziome[k]+=1;
    }
    for(int i=MAX_N; i>0; i--)
    {
        koszt+=(lpoz+1)*pionowe[i]*i;
        lpion+=pionowe[i];
        koszt+=(lpion+1)*poziome[i]*i;
        lpoz+=poziome[i];
    }
    printf("%ld", koszt);
    return 0;
}
