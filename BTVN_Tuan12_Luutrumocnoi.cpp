#include <iostream>
#include <iomanip>

using namespace std;

struct Node {     // dinh nghiea 1 cautruc nut
    int data;     
    Node* left;   
    Node* right; 

    Node(int val) {  // val la gia tri duoc them vao
    data = val;
    left = nullptr;   // khoi tao con trai, con phai 
    right = nullptr;
    }
};
Node* TLeft() {        // Cai dat thu cong cay lẹch trái
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->left->left = new Node(4);
    root->left->left->left->left = new Node(5);
    return root;
}

Node* TRight() {    // Cai dat thu cong cay lech phai
    Node* root = new Node(1);
    root->right = new Node(2);
    root->right->right = new Node(3);
    root->right->right->right = new Node(4);
    root->right->right->right->right = new Node(5);
    return root;
}

Node* Tziczac() {     // Cai dat thu cong cay ziczac
    Node* root = new Node(1);
    root->left = new Node(2);        
    root->left->right = new Node(3); 
    root->left->right->left = new Node(4); 
    root->left->right->left->right = new Node(5); 
    return root;
}

// Hàm in cây, mô tả bằng hình 
void PrintTree(Node* root, int space = 0) {
    if (root == nullptr) return;

    // Tăng khoảng cách giữa các tầng
    space += 8;

    // In nhánh bên phải trước
    PrintTree(root->right, space);

    // In nút hiện tại
    cout << endl;
    for (int i = 8; i < space; i++) cout << " ";
    
    // Biển diễn dưới dạng móc nối trực quan [L| Data |R]
    cout << "[" << (root->left ? "•" : "X") << "|" << root->data << "|" << (root->right ? "•" : "X") << "]\n";

    // In nhánh bên trái
    PrintTree(root->left, space);
}

// --- HÀM MAIN ĐỂ CHẠY THỬ ---
int main() {

    cout << "\n=== 2. CAY LECH TRAI ===";
    Node* leftSkewed = TLeft();
    PrintTree(leftSkewed);

    cout << "\n=== 3. CAY LECH PHAI ===";
    Node* rightSkewed = TRight();
    PrintTree(rightSkewed);

    cout << "\n=== 4. CAY ZIGZAC ===";
    Node* zigzag = Tziczac();
    PrintTree(zigzag);

    return 0;
}