#include <stdio.h>
#define MAX 200

int map[MAX+1][MAX+1];

bool isOutOfBounds(int x, int y, int R , int C);
void solution(int R, int C, int N);

int main(int argc, char const *argv[])
{
    int R, C, N;
    char c;
    int i, j;
    scanf("%d %d %d", &R, &C, &N);
    getchar();
    for(i = 0; i < R; i++) {
        for(j = 0; j < C; j++) {
            c = getchar();
            if(c == 'O') {
                map[i][j] = 1;
                if(!isOutOfBounds(i-1, j, R, C) && map[i-1][j] == 0) map[i-1][j] = 2;
                if(!isOutOfBounds(i+1, j, R, C) && map[i+1][j] == 0) map[i+1][j] = 2;
                if(!isOutOfBounds(i, j-1, R, C) && map[i][j-1] == 0) map[i][j-1] = 2;
                if(!isOutOfBounds(i, j+1, R, C) && map[i][j+1] == 0) map[i][j+1] = 2;
            } else if(map[i][j] != 2) map[i][j] = 0;
        }
        getchar(); // 개행
    }

    solution(R, C, N);

    return 0;
}

bool isOutOfBounds(int x, int y, int R , int C) {
    return !(x >= 0 && x < R && y >= 0 && y < C);
}

void solution(int R, int C, int N) {
    int i, j;
    char c;
    // N 이 1인 경우, 예외 케이스이다.
    // N 이 짝수인 경우는 폭탄과 상관없이 항상 폭탄으로 차있어야 한다.
    // N 이 3 이상인경우, N-3 을 4로 나눴을때, 나머지가 있는 경우와 나머지가 없는 경우 두가지 케이스가 존재한다.
    if(N == 1) {
        for(i = 0; i < R; i++) {
            for(j = 0; j < C; j++) {
                c = map[i][j] == 1 ? 'O' : '.'; 
                printf("%c",c);
            }
            printf("\n");
        } 
    }
    
    else {
        // N 이 3이상인 경우, 기존에 map 에서 0 인 값들만 폭탄으로 바꿔준다. 
        for(i = 0; i < R; i++) {
            for(j = 0; j < C; j++) {
                map[i][j] = map[i][j] == 0 ? 1 : 0;
            }
        }
        // 새롭게 만들어진 map 에서 폭탄 (1) 주변 (상,하,좌,우) 폭탄을 인접폭탄 (2) 으로 바꿔준다.
        for(i = 0; i < R; i++) {
            for(j = 0; j < C; j++) {
                if(map[i][j] == 1) {
                    if(!isOutOfBounds(i-1, j, R, C) && map[i-1][j] == 0) map[i-1][j] = 2;
                    if(!isOutOfBounds(i+1, j, R, C) && map[i+1][j] == 0) map[i+1][j] = 2;
                    if(!isOutOfBounds(i, j-1, R, C) && map[i][j-1] == 0) map[i][j-1] = 2;
                    if(!isOutOfBounds(i, j+1, R, C) && map[i][j+1] == 0) map[i][j+1] = 2;
                }
            }
        } 
        // 출력 부분 
        for(i = 0; i < R; i++) {
            for(j = 0; j < C; j++) {
                if(N % 2 == 0) c = 'O';
                else if((N-3) % 4 != 0) c = map[i][j] == 0 ? 'O' : '.'; // 5, 9, 13, ...
                else c = map[i][j] == 1 ? 'O' : '.'; // 3, 7, 11, ...
                printf("%c",c);
            }
            printf("\n");
        } 
    }
}