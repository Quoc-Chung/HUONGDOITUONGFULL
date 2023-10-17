#include<bits/stdc++.h>
using namespace std;
struct PhanSo{
   int TuSo;
   int MauSo;
};
/*
// Thông thường m lúc  nào cũng thấy nhập nó như này nè 
void NhapPhanSo(PhanSo *p,int n){
    for(int i=0;i<n;i++){
        // Không thể viết luôn là  cin >> p[i] như kiểu mảng được 
        cin>>p[i].TuSo>>p[i].MauSo;
    }
}
// Cả hàm in ra nó cũng vậy 
void InCacPhanSo(PhanSo *p,int n){
  for(int i=0;i<n;i++){
        cout<<p[i].TuSo<<"/"<<p[i].MauSo<<"\n";
    }
}
*/
// m không thể cin ra  như này cin >> p[i]  hoặc cout <<p[i]  như này cùng một lúc đc
// vì một cấu trúc p[i] nó bao hàm cả tử số và mẫu số 

// để giải quyết vấn đề này thì phải thực hiện xây dựng hàm  toán tử 
// Hàm này là xây dựng việc nhập 

// istream&  operator>> (istream &inp ,kiểu dữ liệu  &bien){
//            return inp;
//        }
// Hàm này là xây dựng hàm in như này 

//        ostream& operator<< (ostream &os , kiểu dữ liệu  &bien){

//         return os;
// }
// M phải nhớ là riêng đối với hàm nhập và hàm  in thì mình chỉ cần xây dựng một phân số , hoặc 
// đối tượng cụ thể thôi 
// Nghĩa là bên dưới chỉ truyền vào mỗi một PhaanSSo &p , có tham chiếu vì ta thực hiện 
// nhập nó ở trong hàm  
istream&  operator>> (istream &is , PhanSo &p){
    is>>p.TuSo>>p.MauSo;
    return is;
}
// rồi sau khi xây dựng như này xong rồi thì chúng ta sẽ cin >> p[i] ra bình thường như 
// mảng ý
void NhapPhanSo(PhanSo *p,int n){
    for(int i=0;i<n;i++){
        //Xây dựng nạp chồng rồi nên cái cấu trúc nó biến thành một biến  đại diện luôn 
        // nên lúc này cin ra p[i] tức  là cái p[i] nó đại diện cho cả tử và phân số 
        cout<<"\nNhap phan so"<<i+1<<":";
        cin>>p[i];
    }
}

// Tương tự như mảng hàm xuaart cũng vậy  nó trả về ostream&
  ostream& operator<< (ostream &os , PhanSo &p){
     os<<p.TuSo<<"/"<<p.MauSo;
     return os;
  }

  // lúc này ta chỉ cần cout ra luôn 
void InCacPhanSo(PhanSo *p,int n){
  for(int i=0;i<n;i++){
       cout<<p[i]<<endl;
    }
}


// giờ m chỉ cần nhớ hai hàm nhập xuất nạp chồng nhập xuât này trước nhé  còn mấy hàm toán tử nhân chia 
// các biến cấu trúc nào học cấu trúc sẽ rõ hơn nó cũng  y hệt như này thôi 

int main(){
    int n;
   cout<<"\nNhap n:";
   cin >>n;

   PhanSo *p = new PhanSo[n];
   if(p==NULL){
    cout<<"\nKHong cap phat duoc";
    exit(0);
   }
   NhapPhanSo(p,n);
   InCacPhanSo(p,n);
   return 0;
}
/*
- Tổng quát chung về Ý nghĩa của các HÀM TOÁN TỬ ,HÀM TRÙNG TÊN ,HÀM MẪU
 -HÀM TOÁN TỬ NHẬP CHỒNG :
 + Hàm toán tử nhập  xuất , tính  toán  dùng để định nghĩa  lại  việc nhập  suất một 
kiểu cấu trúc.
 + Nghĩa là ban đầu chúng ta không thể viết như này " cin >> sv[i] " được vì  ban  đầu  sv[i] 
này là một kiểu cấu trúc  , muốn  cin ra luôn thì chúng ta phải xây dựng hàm toán tử đại diện
nhập cho 1 sinh viên rồi  từ đó chúng ta mới có thể cin >> sv[i] (lúc này nó  sẽ đại diện cho 
các thuộc tính của sinh viên) như mảng một cách bình thường được.
 + Một giải thích khác là chúng ta có một kiểu struct như này:
          struct PhanSo{
              int TuSo;
              int MauSo;
          };
  + Chúng ta không thể lấy hai phân số thuộc kiểu struct này cộng với nhau  được nhưng chúng ta
có thể giải quyết sự  bất cập này bằng cách sử dụng HÀM NẠP CHỒNG TOÁN TỬ 
 - HÀM MẪU :
  + Chúng ta muốn giảm thiểu số lượng các dòng code + với việc rút ngắn thời gian code đi 
thì chúng ta sẽ viết các hàm nhập, xuất ,tính toán  đại diện cho cả kiểu mảng , kiểu cấu trúc,
kiểu ma trận  đều có thể dùng được 
  + Trong hầu hết các trường hợp chúng ta phỉa viết hàm toán tử của các biến kiểu cấu  trúc
chúng ta muốn sử dụng các  hàm mẫu chung với mảng thì chúng ta phải đưa chúng về kiểu của mảng 
bằng cách viết các  hàm  nạp  chồng toán  tử 
 - HÀM  TRÙNG TÊN :
     -Đẻ dễ dàng thuận tiện trong việc ghi nhớ tên hàm thì chúng ta có một cách  rát hiệu quả mà 
c++ hỗ trợ đó là viết các  hàm có  cùng chức năng (ví dụ như in một cái gì đó , nhập một cái  gì
đó, tính  toán một cái  gì đó ) cùng một tên miễn là các hàm có cùng  chức  năng như này phải
có cùng chúc năng này phải có sự khác nhau về các  đối số truyền vào hàm để trình biên dịch có 
thể nhận  diện được các hàm  chuẩn xác .  


*/