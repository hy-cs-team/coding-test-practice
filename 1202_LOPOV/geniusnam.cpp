#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>

#define Pii pair<int, int>
#define MAX 300000
#define WEIGHT first
#define VALUE second

using namespace std;

bool compare(const Pii a, const Pii b);

struct compare_for_queue {
    bool operator()(const Pii& a, const Pii& b) {
        return a.VALUE < b.VALUE;
    }
};

vector<int> bags;
vector<Pii> jewels;
priority_queue<Pii, vector<Pii>, compare_for_queue> pq;

int main(int argc, char const *argv[])
{
    int n, k;
    long long value = 0;
    scanf("%d %d", &n, &k);

    for(int i = 0; i < n; i++) {
        Pii p;
        scanf("%d %d", &p.WEIGHT, &p.VALUE);
        jewels.push_back(p);
    }

    for(int i = 0; i < k; i++) {
        int capacity;
        scanf("%d", &capacity);
        bags.push_back(capacity);
    }

    sort(bags.begin(), bags.end()); // 오름차순
    sort(jewels.begin(), jewels.end(), compare); // 무게 오름차순

    for(vector<Pii>::iterator it = jewels.begin(); it != jewels.end(); it++) {
        printf("(weight: %d, value: %d) ", it->WEIGHT, it->VALUE);
    }
    printf("\n");
    // 가방은 사이즈가 작은 것부터 큰 순으로 정렬
    // 보석은 1. 비싼 순, 2. 가벼운 순으로 정렬했다.
    int j = 0;
    for(int b = 0; b < bags.size(); b++) {
        int bag = bags[b];
        printf("%d 크기의 가방에 넣을 보석을 탐색해보자\n", bag);
        for(; j < jewels.size() && jewels[j].WEIGHT <= bag; j++) {
            pq.push(jewels[j]);
            printf("pq에 %d 크기와 %d 값어치의 보석을 넣어둔다. pq.size = %lu, pq.top()= %d\n", jewels[j].WEIGHT, jewels[j].VALUE, pq.size(), pq.top().VALUE);
        }

        if(pq.empty()) continue;
        printf("가방에 넣을 보석의 값어치는 %d이다.\n", pq.top().VALUE);
        value += pq.top().VALUE;
        pq.pop();
    }
    
    printf("%lld\n", value);
    return 0;
}

bool compare(const Pii a, const Pii b) {
    return a.WEIGHT < b.WEIGHT;
}

// #include <stdio.h>
// #include <vector>
// #include <utility>
// #include <algorithm>

// #define Pii pair<int, int>
// #define MAX 300000
// #define WEIGHT first
// #define VALUE second
// using namespace std;

// vector<int> bags;
// vector<Pii> jewels;
// priority_queue<Pii, vector<Pii>,
// bool compare(const Pii a, const Pii b) {
//     if(a.second == b.second) 
//         return a.first < b.first;
//     return a.second > b.second; 
// }

// int main(int argc, char const *argv[])
// {
//     int n, k;
//     int value = 0;
//     scanf("%d %d", &n, &k);

//     for(int i = 0; i < n; i++) {
//         pair<int, int> p;
//         scanf("%d %d", &p.WEIGHT, &p.VALUE);
//         jewels.push_back(p);
//     }

//     for(int i = 0; i < k; i++) {
//         int capacity;
//         scanf("%d", &capacity);
//         bags.push_back(capacity);
//     }

//     sort(bags.begin(), bags.end()); // 오름차순
//     sort(jewels.begin(), jewels.end(), compare); // 내림차순

//     for(vector<pair<int, int>>::iterator it = jewels.begin(); it != jewels.end(); it++) {
//         printf("(weight: %d, value: %d) ", it->WEIGHT, it->VALUE);
//     }
//     printf("\n");
//     // 가방은 사이즈가 작은 것부터 큰 순으로 정렬
//     // 보석은 1. 비싼 순, 2. 가벼운 순으로 정렬했다.
//     int j
//     for(int b = 0; b < bags.size(); b++) {
//         int bag = bags[b];
//         printf("%d 크기의 가방에 넣을 보석을 탐색해보자\n", bag);
//         bool flag = false;
//         for(; j < jewels.size(); j++) {
//             if(jewels[j].WEIGHT <= bag) {
//                 printf("%d 값어치의 %d 무게인 보석을 담는다.\n", jewels[j].VALUE, jewels[j].WEIGHT);
//                 value += jewels[j].VALUE;
//                 break;
//             } 
//         }
//     }
    
//     printf("%d\n", value);
//     return 0;
// }