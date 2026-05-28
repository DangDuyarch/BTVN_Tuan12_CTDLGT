#include <iostream>
using namespace std;

void inserttreeArray(int tree[], int max, int a) {
    int i = 0;
    while (i < max) {
        if (tree[i] == 0) {
            tree[i] = a;
            return;
        }
        if (a < tree[i])  i = 2 * i + 1;
        else if (a > tree[i]) i = 2 * i + 2;
        else return;
    }
}


int main() {
    int tree[100] = {0}; 
    int arr[] = {2001,2002,2006,2007,2003,2004,2005,2001,1999,2004};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        inserttreeArray(tree, 100, arr[i]);
    }

for (int i = 0; i < n; i++) {
        inserttreeArray(tree, 100, arr[i]);
    }

    // --- ĐOẠN IN MẢNG THẤY CẢ SỐ 0 ---
    cout << "Cay sau khi sap xep:\n";
    for (int i = 0; i < 100; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;
    // ---------------------------------

    return 0;
}