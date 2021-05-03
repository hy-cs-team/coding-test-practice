#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

void test(int arr[][2]) {
  arr[0][0] = -1;
}

void test2(vector<int> arr, int n) {
    printf("%d : ", n);
    if(n > 0) {
        arr.push_back(n);
        for(int i = 0 ; i < arr.size(); i++) {
           cout<< arr[i] << " ";
        }
        printf("\n");
        test2(arr, n-1);
        arr.pop_back();
        printf("come back %d : ", n);
        for(int i = 0 ; i < arr.size(); i++) {
            cout<< arr[i] << " ";
        }
        printf("\n");
    } else if(n == 0) {
        printf("Terminate program\n");
        arr.push_back(1000);
        for(int i = 0 ; i < arr.size(); i++) {
            cout<< arr[i] << " ";
        }
        printf("\n");
    }
}

int main() {
    int arr[2][2] = {{1, 2}, {3, 4}};
    vector<int> temp;
    printf("%d\n", arr[0][0]);
    test(arr);
    printf("%d\n", arr[0][0]);
    
    test2(temp, 3);
    // temp.push_back(0);
    // temp.push_back(0);
    // temp.push_back(0);
    // temp.push_back(0);

    // cout << temp.size() << endl;
    // for(int i = 0 ; i < temp.size(); i++) {
    //     printf("%d," temp[i]);
    // }
    // printf("\n");

    return 0;
}
