#include <iostream>
#include <cstdio>

using namespace std;
#define MAX_N 200000
int odw[MAX_N];
int main(void)
{
    int n, m, a, b;
    scanf("%i%i", &n, &m);
    for(int i=0; i<m; i++){
        scanf("%i%i", &a, &b);
        a--; b--;
        if(odw[a] && !odw[b]) odw[b] = 3-odw[a];
        else if(!odw[a] && odw[b]) odw[a] = 3-odw[b];
        else if(!odw[a] && !odw[b]){
            odw[a] = 1;
            odw[b] = 2;
        }
    }
    for(int i=0; i<n; i++){
        if(!odw[i]){
            printf("%s", "NIE");
            return 0;
        }
    }
    printf("%s\n", "TAK");
    for(int i=0; i<n; i++) printf("%c\n", odw[i]==1?'K':'S');
    return 0;
}
