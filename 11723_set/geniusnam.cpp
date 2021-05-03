#include <stdio.h>
#include <iostream>
#include <string>

#define MAX 21

using namespace std;

int arr[MAX];

int main(int argc, char const *argv[])
{
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        char command[7];
        int num;

        scanf("%s", command);
    
        if (command[0] == 'a') {
            if (command[1] == 'l') {
                for (int i = 1; i < MAX; i++) arr[i] = 1;
            } else {
                scanf("%d", &num);
                if (!arr[num]) arr[num] = 1;
            }
        } else if (command[0] == 'r') {
            scanf("%d", &num);
            if (arr[num]) arr[num] = 0;
        } else if (command[0] == 'c') {
            scanf("%d", &num);
            printf("%d\n", arr[num]); 
        } else if (command[0] == 't') {
            scanf("%d", &num);
            arr[num] = !arr[num];
        } else if (command[0] == 'e') {
            fo r(int i = 1; i < MAX; i++) arr[i] = 0;
        } else { /* never happen */}
    }
    return 0;
}