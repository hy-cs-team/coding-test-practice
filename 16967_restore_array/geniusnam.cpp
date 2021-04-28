#include <stdio.h>

#define MAX 300

int map[2*MAX][2*MAX];

void solution(int h, int w, int x, int y);

int main(int argc, char const *argv[])
{
    int h, w, x, y;
    int i, j;
    scanf("%d %d %d %d", &h, &w, &x, &y);

    for(i = 0; i < h+x; i++) {
        for(j = 0; j < w+y; j++) {
            scanf("%d", &map[i][j]);
        }
    }

    solution(h, w, x, y);
    
    return 0;
}

void solution(int h, int w, int x, int y) {
    int i, j;
    for(i = 0; i < h; i++) {
        for(j = 0; j < w; j++) {
            if(i >= x && j >= y) map[i][j] -= map[i-x][j-y];
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}


// #include <stdio.h>
// #include <stdlib.h>

// void solution(int** map, int h, int w, int x, int y);

// int main(int argc, char const *argv[])
// {
//     int h, w, x, y;
//     int i, j;
//     scanf("%d %d %d %d", &h, &w, &x, &y);

//     int** map = (int**)malloc(sizeof(int*) * (h+x));

//     for(i = 0; i < h+x; i++) map[i] = (int*)malloc(sizeof(int) * (w+y)); 

//     for(i = 0; i < h+x; i++) {
//         for(j = 0; j < w+y; j++) {
//             scanf("%d", &map[i][j]);
//         }
//     }

//     solution(map, h, w, x, y);

//     for(i = 0; i < h+x; i++) free(map[i]);
//     free(map);
    
//     return 0;
// }

// void solution(int** map, int h, int w, int x, int y) {
//     int i, j;
//     for(i = x; i < h; i++) {
//         for(j = y; j < w; j++) {
//             map[i][j] -= map[i-x][j-y];
//         }
//     }
//     for(i = 0; i < h; i++) {
//         for(j = 0; j < w; j++) 
//             printf("%d ", map[i][j]);
//         printf("\n");
//     }
// }
