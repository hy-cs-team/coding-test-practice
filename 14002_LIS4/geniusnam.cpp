#include <stdio.h>
#include <stack>
#define MAX 1000

using namespace std;

void solution(int* arr, int n);

int main(int argc, char const *argv[])
{
    int n;
    int arr[MAX];
 
    scanf("%d", &n);

    for (int i = 0; i < n; i++) 
        scanf("%d", &arr[i]);
        
    solution(arr, n);

    return 0;
}

void solution(int* arr, int n) {
    int dp[MAX];
    int backTracking[MAX];
    int max = -1;

    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        backTracking[i] = i;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j]+1;
                backTracking[i] = j;
            }
        }
    }
    int maxIdx = 0;
    for (int i = 0; i < n; i++) {
        if (max < dp[i]) {
            max = dp[i];
            maxIdx = i;
        }
    }

    printf("%d\n", max);
    stack<int> s;
    while (maxIdx != backTracking[maxIdx]) {
        s.push(arr[maxIdx]);
        maxIdx = backTracking[maxIdx];
    }
    s.push(arr[maxIdx]);

    while (!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
}