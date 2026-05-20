// Cài đặt cấu trúc cây cấu trúc lưu trữ tuần tự, gốc của cây mang thứ tự 0, khác với tlieu slide là 1

#include <iostream>
using namespace std;

#define MAX_NODES 100     
#define MAXLENGTH 100     // so ptu tối đa của cây là 100
#define NIL -1            // nut rỗng

typedef int DataType;
typedef int Node;

typedef struct {
    DataType Data[MAXLENGTH]; // Lưu giá trị của nút
    int MaxNode;              
} Tree;        // tạo kiểu dl để lưu trữ cây


int EmptyTree(Tree T)     // Ktra cây rỗng
{      
    return T.MaxNode == 0;  }

Node Root(Tree T) {        // Xác định nút gốc trong cây
    if (!EmptyTree(T))        return 0;        // Nếu cây kh rỗng thì nút gốc luôn nằm ở vtri 0
    else                      return NIL;  // cây rỗng thì trả về NIL   
}

int Left_Child(Node p, Tree T) {    // Hàm xđ vtri con trái của nút p
    if (p == NIL) return NIL;   

    int left = 2 * (p + 1) - 1; // Vị trí nút con trái của nút vtri p theo slide: 2*(p+1) - 1
    if (left < T.MaxNode) 
    return left; // trả về vtri nút con bên trái nút p nếu nó có dl
    return NIL;            }

int Right_Child(Node p, Tree T) {   // Hàm xđ vtri con trái của nút p, như nút trái
    if (p == NIL) return NIL;
    
    int right = 2 * (p + 1);    // công thức: 2*(p+1)
    if (right < T.MaxNode)      return right;
    return NIL;       }

void InitTree(Tree &T) { // hàm khởi tạo cây rỗng
    T.MaxNode = 0;
    for (int i = 0; i < MAXLENGTH; i++) {
        T.Data[i] = NIL;       //các vtri ban đầu đều là NIL 
    }      }

/*void InputTree(Tree &T) {       // Hàm nhập dl cho cây
    InitTree(T);
    int n;
    cout << "Nhap so luong nut cua cay: ";
    cin >> n;
    if (n <= 0) return;
    cout << "Nhap gia tri cho cac nut tu trai sang phai, tu tren xuong duoi, neu nut trong nhap NIL.\n";
    int lastindex = -1;   // tao bien last index de luu vi tri nut cuoi cung co dl
    
    for (int i = 0; i < n; i++) {
        if (i >= MAXLENGTH) {
        cout << "Vuot qua so luong nut!\n";
         break;
        }
        cin >> T.Data[i];    // nhap gtri cac nut theo thu tu
        if (T.Data[i] != NIL) {
        lastindex = i;        // gan vitri nut cuoi cung co dl vao bien lastindex
        }
    }
    T.MaxNode = lastindex + 1;// cap nhat maxnode la vitri node cuoi cung co dl +1, cat cac o trong duoi cung khong dl
}   */


// Duyet và in cây theo thứ tự lưu trữ kế tiếp
void Printtree(Node p, Tree T) {
    if (p == NIL || p >= T.MaxNode) {  // Dừng nếu vượt ranh giới 
        return; 
    }
// 2. Nếu vị trí p hợp lệ nhưng ô mảng đó mang giá trị trống (NIL) -> In số 0
    if (T.Data[p] == NIL) {  cout << "0 ";  }   // Nếu ô trống thì in số 0
    
    else {     cout << T.Data[p] << " ";    }   // Nếu ô mảng đó có dữ liệu -> In giá trị của nút
    Printtree(Left_Child(p, T), T);        // In ra con trái trước
    Printtree(Right_Child(p, T), T);       // Con phải sau 
}

int main() {
    Tree Tziczac;
    InitTree(Tziczac); 
    Tziczac.Data[0]  = 1;  // Nút gốc (1) ở ô 0
    Tziczac.Data[1]  = 2;  // Con trái của 1 ở ô 1
    Tziczac.Data[4]  = 3;  // Con phải của 2 ở ô 4
    Tziczac.Data[9]  = 4;  // Con trái của 3 ở ô 9
    Tziczac.Data[20] = 5;  // Con phải của 4 ở ô 20
 
    Tziczac.MaxNode = 21;
    cout << "Duyet cay theo thu tu truoc (Pre-order): ";
    Printtree(Root(Tziczac), Tziczac);
    cout << endl; 
    return 0;
}