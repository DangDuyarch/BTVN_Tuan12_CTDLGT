#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct Ngay     // Khai bao cau truc ngay
  {
	int ngay, thang, nam;
  };

struct SinhVien   // Khai bao cau truc sinh vien
  {
	char maSV[10];
	char hoTen[50];
	int gioiTinh;
	Ngay ngaySinh;
	char diaChi[100];
	char lop[12];
	char khoa[7];
   };

struct Node    // Khai bao node
{
	SinhVien data;
	Node *link;
};
struct List     // Khai bao danh sach
{
 	Node *first;
	Node *last;
};

void ThemSV(List &L, SinhVien newSVData) {
    Node* Newnode = new Node;       // Khai bao mot node moi
    Newnode->data = newSVData;
    Newnode->link = nullptr;

    if (L.first == nullptr || strcmp(newSVData.maSV, L.first->data.maSV) < 0) {
        Newnode->link = L.first;
        L.first = Newnode;              // Chen vao dau tien neu ds dang rong
        return;
    }

    Node* p = L.first;
    while (p->link != nullptr && strcmp(p->link->data.maSV, newSVData.maSV) < 0) {
        p = p->link;                           // Tim vi tri chen
    }

    Newnode->link = p->link;                // Chen node
    p->link = Newnode;
}

void XoaSV(Node*& head, Node* toDelete) {
    if (head == nullptr || toDelete == nullptr) return;

    if (head == toDelete) {
        head = head->link;
        delete toDelete;
        return;
    }

    Node* p = head;
    while (p->link != nullptr && p->link != toDelete) {
        p = p->link;
    }

    if (p->link == toDelete) {
        p->link = toDelete->link;
        delete toDelete;
    }
}



void TimXoaSV(Node*& head) {
    Node* curr = head;
    bool DSCotrung = false;

    while (curr != nullptr) {
        bool Cotrung = false;
        for (Node* q = head; q != nullptr; q = q->link) {      // Duyet danh sach de tim
            if (curr != q && 
                curr->data.ngaySinh.ngay == q->data.ngaySinh.ngay &&
                curr->data.ngaySinh.thang == q->data.ngaySinh.thang &&   // So sanh xem co trung ngay sinh kh
                curr->data.ngaySinh.nam == q->data.ngaySinh.nam) {
                Cotrung = true;
                break;
            }
        }

        if (Cotrung) {         //Neu phat hien ra trung ngay sinh
            cout << "Phat hien va dang loai bo: " << curr->data.hoTen          
                 << " (Ngay sinh: " << curr->data.ngaySinh.ngay << "/" << curr->data.ngaySinh.thang << ")" << endl;
            
            Node* temp = curr;
            curr = curr->link; // Nhay sang node tiep theo de dò tiep
            XoaSV(head, temp); // Xoa sinh vien trung ngay sinh
            DSCotrung = true;
        } else {
            curr = curr->link;   }    // Khong trung thi duyet tiep
    }

    if (!DSCotrung) { // Neu ds khong co ai trung nsinh
        cout << "Khong tim thay sinh vien nao co cung ngay sinh." << endl;
    }
}


// Hàm in danh sách đơn giản
void InDanhSach(Node* head) {
    cout << "------------------------------------------" << endl;
    cout << "MSSV\tHo Ten\t\tLop" << endl;
    Node* p = head;
    while (p != nullptr) {
        cout << p->data.maSV << "\t" 
             << p->data.hoTen << "\t" 
             << p->data.lop << endl;
        p = p->link;
    }
    cout << "------------------------------------------" << endl;
}

int main() {
    List L;
    L.first = nullptr; 
    L.last = nullptr;
 
    ThemSV(L, {"202414405", "Tran Hoang Hai", 1, {10, 1, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(L, {"202414406", "Nguyen Duc Duy", 1, {15, 2, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(L, {"202414401", "Nguyen Duc Kien", 1, {20, 3, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(L, {"202414413", "Ha Dang Quang", 1, {5, 4, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(L, {"202414203", "Van Thanh Dat", 1, {12, 5, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(L, {"202414073", "Nguyen Khanh Huyen", 0, {25, 6, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(L, {"202414074", "Le Khanh Linh", 0, {25, 6, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(L, {"202414063", "Nguyen Manh Thien", 1, {30, 7, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(L, {"202414058", "Tran Duc Manh", 1, {30, 7, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(L, {"202414365", "Nguyen Quoc Huy", 1, {30, 7, 2006}, "HN", "DT05", "SEEE"});
    ThemSV(L, {"202414103", "Hoang Lam Que", 0, {18, 8, 2006}, "HN", "DT05", "SEEE"});



    cout << "\n========= TIEN HANH DO TIM VA XOA TRUNG =========" << endl;
    // Gọi hàm gộp ở đây
    TimXoaSV(L.first);

    cout << "\n========= DANH SACH SAU KHI DA XOA =========" << endl;
    InDanhSach(L.first);





    return 0;
}