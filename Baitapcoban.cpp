#include <iostream>
#include <string>
using namespace std;

struct Ngay
  {
	int ngay, thang, nam;
  };

struct SinhVien
  {
	char maSV[8];
	char hoTen[50];
	int gioiTinh;
	Ngay ngaySinh;
	char diaChi[100];
	char lop[12];
	char khoa[7];
   };

struct Node
{
	SinhVien data;
	Node *link;
};
struct List
{
 	Node *first;
	Node *last;
};


int main() {
   
    List L;
    L.first = L.last = NULL;

    SinhVien ds[4] = {
        {"SV001", "Dang Van Duy", 1, {15, 5, 2005}, "HN", "DT01", "DT"},
        {"SV002", "Dang Van Duy", 1, {20, 10, 2005}, "HP", "DT02", "DT"},
        {"SV003", "Dang Van Duy", 0, {15, 5, 2005}, "ND", "DT01", "DT"},
        {"SV004", "Dang Van Duy", 1, {1, 1, 2005}, "TH", "DT03", "CNTT"}
    };

    for (int i = 0; i < 4; i++) {
        Node* newNode = new Node;
        newNode->data = ds[i];
        newNode->link = NULL;

        if (L.first == NULL) {
            L.first = L.last = newNode;
        } else {
            L.last->link = newNode;
            L.last = newNode;
        }
    }

    cout  << "MSSV" << "Ho Ten"  << "Lop" << "Ngay Sinh" << endl;
    cout << "------------------------------------------------------------" << endl;
    
    Node* p = L.first;
    while (p != NULL) {
        cout  << p->data.maSV << p->data.hoTen  << p->data.lop  << p->data.ngaySinh.ngay << "/" << p->data.ngaySinh.thang << "/" << p->data.ngaySinh.nam << endl;
        p = p->link;
    }

    // 4. Giải phóng bộ nhớ
    while (L.first != NULL) {
        Node* temp = L.first;
        L.first = L.first->link;
        delete temp;
    }

    return 0;
}