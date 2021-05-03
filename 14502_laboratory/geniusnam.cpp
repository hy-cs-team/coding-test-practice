#include <stdio.h>
#include <vector>
#include <iostream>
#include <utility>
#include <queue>
#define MAX 8
#define Point pair<int, int>
#define Direction pair<int, int>
using namespace std;

// global variable;

vector<Point> virusArea;
vector<Point> safeArea;
vector<Point> dir {make_pair(0, -1), make_pair(0, 1), make_pair(-1, 0), make_pair(1, 0)}; // 상하좌우

int bfs(int map[][8], int n, int m, queue<Point > q);

int combination(int map[][8], int n, int m, int r, int idx, vector<int> temp);

void solution(int map[][8], int n, int m);

bool isOutOfBounds(int x, int y, int R , int C);

int main(int argc, char const *argv[]) {
    int n, m;
    int map[MAX][MAX];

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int status;
            scanf("%d", &status);
            map[i][j] = status;
            if(status == 0) safeArea.push_back(make_pair(i, j));
            else if(status == 2) virusArea.push_back(make_pair(i, j));
        }
    }

    solution(map, n, m);
    
    return 0;
}

void solution(int map[][8], int n, int m) {
    vector<int> temp;
    int maxSafeArea = combination(map, n, m, 3, -1, temp);

    printf("%d\n", maxSafeArea);
}

// combination(r, idx) : 벽을 r개 추가할 때, idx 번째 빈곳에 벽을 추가했을 때, 최댓값
int combination(int map[][8], int n, int m, int r, int idx, vector<int> temp) {
    int maxArea = -1;

    if (idx == -1) {
        for (int i = 0; i < (int)safeArea.size(); i++) {
            temp.push_back(i);
            int s = combination(map, n, m, r, i, temp);
            maxArea = s > maxArea? s: maxArea;
            temp.pop_back();
        }
        return maxArea;
    }
    
    if (r > 1) {
        for (int i = idx+1; i < (int)safeArea.size(); i++) {
            temp.push_back(i);
            int s = combination(map, n, m, r-1, i, temp);
            if (s > maxArea)
                maxArea = s;
            temp.pop_back();
        }
        return maxArea;
    } else { // n 이 1일때  
        int cMap[MAX][MAX];
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cMap[i][j] = map[i][j];
            }
        }

        for (int idx : temp) { // 새로운 벽을 copy 된 Map 에 추가
            cMap[safeArea[idx].first][safeArea[idx].second] = 1;
        }

        queue<Point > q; // 독이 있는 점을 q 에 넣어준다.
        for (Point vp: virusArea) {
             q.push(vp);
        }
        // bfs 돌리고 0 의 갯수를 반환한다.
        return bfs(cMap, n, m, q);
    }
}

bool isOutOfBounds(int x, int y, int R , int C) {
    return !(x >= 0 && x < R && y >= 0 && y < C);
}

int bfs(int map[][8], int n, int m, queue<Point > q) {
    int count = 0;
    while(!q.empty()) {
        Point front = q.front();
        q.pop();

        for (Direction d: dir) {
            int x = front.first + d.first;
            int y = front.second + d.second;

            if (!isOutOfBounds(x, y, n, m) && map[x][y] == 0) {
                map[x][y] = 2;
                q.push(make_pair(x, y));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0) count++;
        }
    }

    return count;
}