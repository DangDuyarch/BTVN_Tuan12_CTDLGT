#include <iostream>

struct Node {
    int id;
    Node* next;
    Node(int val) : id(val), next(nullptr) {}
};

int findFirstRemoved(int n, int m) {
    if (n <= 0) return -1;

    Node* head = new Node(1);
    Node* curr = head;
    for (int i = 2; i <= n; i++) {
        curr->next = new Node(i);
        curr = curr->next;
    }
    curr->next = head; 
    Node* target = head;
    for (int i = 0; i < m; i++) {
        target = target->next;
    }

    int firstRemovedId = target->id;


    return firstRemovedId;
}

int main() {
    int n, m;
    std::cout << "Nhap N (so nguoi) va M (buoc truyen): ";
    std::cin >> n >> m;

    std::cout << "Nguoi dau tien bi loai la: " << findFirstRemoved(n, m) << std::endl;

    return 0;
}