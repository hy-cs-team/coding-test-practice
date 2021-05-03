#include <stdio.h>
#include <queue>
#define MAX 1000

using namespace std;

int bus[MAX];

void solution(int n, int w, int l);

int main(int argc, char const *argv[]) {
    /* code */
    int n, w, l;
    scanf("%d %d %d", &n, &w, &l);

    for (int i = 0; i < n; i++) {
        scanf("%d", bus+i);
    }

    solution(n, w, l);
    return 0;
}

void solution(int n, int w, int l) {
    queue<int> bridge;

    int acc = 0;
    int idx = 0;
    int time = 0;

    while (bridge.size() != w) bridge.push(0);

    while (idx != n) {
        acc -= bridge.front();
        bridge.pop();
        if (acc + bus[idx] <= l) {
            acc += bus[idx];
            bridge.push(bus[idx++]);
        } else {
            bridge.push(0);
        }
        time++;
    }

    int temp = 1;
    while (!bridge.empty()) { 
        if (bridge.front() == 0) {
            temp++;
        } else {
            time += temp;
            temp = 1;
        }
        bridge.pop();
    }

    printf("%d\n", time);
}