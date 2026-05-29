// Bài tập dựng cây nhị phân tìm kiếm, yêu cầu tạo hàm thêm node vào cây theo quy tắc, tìm 1 giá trị thỏa mãn xem có tồn tại trong cây nhị phân hay kh

// Cài đặt cây nhị phân bằng lưu trữ kế tiếp, các node rỗng được biểu diễn bởi gtri 0.

#include <iostream>
using namespace std;

void add_nodeBST(int tree[], int max, int a) {    // Hàm thêm node vào cây nhị phân theo quy tắc 
    int i = 0;                                  
    while (i < max) {              
        if (tree[i] == 0)  // Thêm giá trị vào node rỗng
        { tree[i] = a;
            return;
}
        if (a < tree[i])  i = 2 * i + 1;        // Nếu a nhỏ hơn node hiện tại đan xét -> xét sang con bên trái
        else if (a > tree[i]) i = 2 * i + 2;    // Nếu a lớn hơn thì xét sang phải
        else return;
    }
}

int search_BST(int tree[], int max, int find) {
    int i = 0; // Luôn bắt đầu tìm kiếm từ nút gốc (index 0)
    
    while (i < max) {
        if (tree[i] == 0)  return -1; 
        if (tree[i] == find) return i; // Trả về vị trí  tìm thấy
        if (find < tree[i]) {  // Nếu giá trị cần tìm lớn hơn nút hiện tại -> Rẽ sang phải
            i = 2 * i + 1;  }
        else { i = 2 * i + 2; }
    }
    return -1; // Trả về -1 nếu chạy hết mảng mà vẫn không thấy
}

int main() {
    int tree[100] = {0};  // tạo mảng 100 ptu trong đó 0 đại diện cho node rỗng
    int arr[] = {2001,2002,2006,2007,2003,2004,2005,2001,1999,2004};
    int n = sizeof(arr) / sizeof(arr[0]);    

    for (int i = 0; i < n; i++) {
    add_nodeBST(tree, 100, arr[i]);   }    // Dùng hàm đã tạo để add từng node, tạo thành cây nhị phân tìm kiếm

    cout << "Cay sau khi sap xep:\n";
    for (int i = 0; i < 100; i++) {
    cout << tree[i] << " ";
    }

    add_nodeBST(tree, 100, 1777);       // thêm ptu vào cây nhị phân tìm kiếm
    cout << "Cay sau khi them ptu :\n";
    for (int i = 0; i < 100; i++) { 
    cout << tree[i] << " ";
    }
    cout << endl;

int can_tim = 2004;   // thu tìm kiếm 1 giá trị 
    int vi_tri = search_BST(tree, 100, can_tim);
    if (vi_tri != -1) { cout << "Tim thay so " << can_tim << " tai vi tri index: " << vi_tri << endl; } 
    else {  cout << "Khong tim thay so " << can_tim << " trong cay!" << endl;    }

    int can_tim2 = 1111;
    if (search_BST(tree, 100, can_tim2) == -1) {
        cout << "Chinh xac: So " << can_tim2 << " khong ton tai tren cay.\n";
    }


    return 0;
}

