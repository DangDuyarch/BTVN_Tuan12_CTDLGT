#include <iostream>

struct Node {
    int id;
    Node* next;
    Node(int val) : id(val), next(nullptr) {}
};

int findWinner(int n, int m) {
    if (n <= 0) return -1;
    if (n == 1) return 1;

    Node* head = new Node(1);
    Node* curr = head;
    for (int i = 2; i <= n; i++) {
        curr->next = new Node(i);
        curr = curr->next;
    }
    curr->next = head; 

    Node* prev = curr; 
    curr = head;      

    while (curr->next != curr) { 
        // Truyền bóng qua M lần
        for (int i = 0; i < m; i++) {
            prev = curr;
            curr = curr->next;
        }

       
        prev->next = curr->next;
        std::cout << "Loai nguoi so: " << curr->id << std::endl;
        
        Node* temp = curr;
        curr = prev->next; 
        delete temp;       // Giải phóng bộ nhớ
    }

    int winnerId = curr->id;
    delete curr; // Giải phóng người chiến thắng cuối cùng
    return winnerId;
}

int main() {
    int n, m;
    std::cout << "Nhap so nguoi va buoc truyen: ";
    if (!(std::cin >> n >> m)) return 0;

    int winner = findWinner(n, m);
    if (winner != -1) {
        
        std::cout << "Nguoi con lai la: " << winner << std::endl;
    }

    return 0;
}