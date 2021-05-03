#include <stdio.h>
#include <algorithm>

#define MAX_ITEM 100
#define MAX_CAPACITY 100000

using namespace std;

int w[MAX_ITEM];
int v[MAX_ITEM];
int dp[MAX_ITEM][MAX_CAPACITY+1];

void solution(int n, int k);

int main(int argc, char const *argv[])
{
    int n, k;

    scanf("%d %d", &n, &k);

    for (int i = 0 ; i < n; i++) {
        scanf("%d %d", &w[i], &v[i]);
    }

    solution(n, k);

    return 0;
}

void solution(int n, int k) {
    for(int i = w[0]; i <= k; i++) {
        dp[0][i] = v[0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if(j >= w[i]) dp[i][j] = max(dp[i-1][j-w[i]] + v[i], dp[i-1][j]);
            else dp[i][j] = dp[i-1][j];
        }
    }
    printf("%d\n",dp[n-1][k]);
}