#include <iostream>
#include <string>
#include <iomanip> 

using namespace std;

struct Date {
    int day, month, year;
};

struct SinhVien {
    string maSV;
    string hoTen;
    string gioiTinh;
    string diaChi; 
    string lop;
    string khoa;
    Date ngaySinh;
};

struct Node {
    SinhVien data;
    Node* next;
};

int main() {
    Node* head = NULL;
    Node* tail = NULL;

    SinhVien ds[4] = {
        {"202414085", "Dang Van Duy", "Nam", "HN", "DT01", "Dien tu", {15, 5, 2005}},
        {"202414001", "Dang Van Duy", "Nam", "HP", "DT02", "Dien tu", {20, 10, 2005}},
        {"202414099", "Dang Van Duy", "Nu", "ND", "DT01", "Dien tu", {15, 5, 2005}},
        {"202413500", "Dang Van Duy", "Nam", "TH", "DT03", "CNTT", {1, 1, 2005}}
    };

    for (int i = 0; i < 4; i++) {
        Node* newNode = new Node;
        newNode->data = ds[i];
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // --- XUẤT (In danh sách ra) ---
    cout << left << setw(12) << "MSSV" << setw(20) << "Ho Ten" << setw(10) << "Lop" << "Ngay Sinh" << endl;
    cout << "------------------------------------------------------------" << endl;
    
    Node* p = head;
    while (p != NULL) {
        cout << left << setw(12) << p->data.maSV 
             << setw(20) << p->data.hoTen 
             << setw(10) << p->data.lop 
             << p->data.ngaySinh.day << "/" << p->data.ngaySinh.month << "/" << p->data.ngaySinh.year << endl;
        p = p->next;
    }

    // Giải phóng bộ nhớ (nên làm để tránh rò rỉ bộ nhớ)
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}