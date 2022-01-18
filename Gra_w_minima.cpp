#include <cstdio>
#include <algorithm>
#define MAX 1001000
int cards[MAX];
int result[MAX];

int main() {
  int n;
  scanf("%d", &n);
  for (int i=0; i<n; i++)
  {
    scanf("%d", &cards[i]);
  }
  std::sort(&cards[0], &cards[n]);
  result[0] = 0;
  for (int i=0; i<n; i++)
  {
      result[i+1] = std::max(result[i], cards[i] - result[i]);
  }
  printf("%d\n", result[n]);
  return 0;
}
