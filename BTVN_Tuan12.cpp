#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


struct Node {
    char data;
    Node *left, *right;
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

// 1. Hàm tính chiều cao của cây
int getHeight(Node* root) {
    if (root == nullptr) return 0;
    return 1 + max(getHeight(root->left), getHeight(root->right));
}

// 2. Hàm đệ quy phẳng hóa cây móc nối vào mảng tuần tự
void flattenTreeToArray(Node* root, int index, vector<string>& arr) {
    if (root == nullptr || index >= arr.size()) return;
    
    arr[index] = string(1, root->data); 
    
    // Tiếp tục duyệt các nút con
    flattenTreeToArray(root->left, 2 * index + 1, arr);
    flattenTreeToArray(root->right, 2 * index + 2, arr);
}

// 3. Hàm cài đặt tuần tự và in cấu trúc cây
void printSequentialTree(Node* root) {
    if (root == nullptr) {
        cout << "Cay rong!" << endl;
        return;
    }

    int height = getHeight(root);
    int max_size = pow(2, height) - 1;
   
    vector<string> sequentialArr(max_size, "0");

    flattenTreeToArray(root, 0, sequentialArr);

    cout << "=== BIEU DIEN TUAN TU (DANG MANG) ===" << endl;
    cout << "Chi so (Index): ";
    for (int i = 0; i < max_size; i++) {
        printf("%3d ", i);
    }
    cout << "\ Gia tri (Data): ";
    for (int i = 0; i < max_size; i++) {
        printf("%3s ", sequentialArr[i].c_str());
    }
    cout << "\n\n";

    cout << "=== MO PHONG THEO TANG CAY ===" << endl;
    int current_level = 0;
    int items_in_level = 1;
    int printed_items = 0;

    for (int i = 0; i < max_size; i++) {
        if (printed_items == 0) {
            cout << "Tang " << current_level << ": ";
        }
        
        cout << sequentialArr[i] << " ";
        printed_items++;

        if (printed_items == items_in_level) {
            cout << endl;
            current_level++;
            items_in_level *= 2; // Số lượng nút ở tầng kế tiếp nhân đôi
            printed_items = 0;
        }
    }
    cout << "-------------------------------------" << endl;
}

int main() {

    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->right->left = new Node('E'); 

    // Chạy hàm in cấu trúc tuần tự
    printSequentialTree(root);

    return 0;
}