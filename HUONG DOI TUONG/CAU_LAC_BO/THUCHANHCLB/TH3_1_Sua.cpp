// Định nghĩa cấu trúc (struct) Date gồm các thuộc tính: day, month, year.
// 2. Định nghĩa lớp (class) Person gồm các thuộc tính: string name, Date dob;
// 3. Định nghĩa lớp Student kế thừa lớp Person và được bổ sung các thuộc tính: string 
// address, email, telephone.
// 4. Định nghĩa lớp Undergrad kế thừa lớp Student và được bổ sung các thuộc tính: string 
// school, major; person parents.
// 5. Định nghĩa lớp Degree gồm các thuộc tính: string university, discipline; Date awarded.
// 6. Định nghĩa lớp GradStudent kế thừa lớp Student và bổ sung các thuộc tính: string dept; 
// Degree lastDegree.
// Viết chương trình thực hiện các công việc sau:
// - Nhập một danh sách sinh viên đại học (Undergrad), in các thông tin của những sinh 
// viên đó ra màn hình.
// - In danh sách các sinh viên học ngành (major) là CNTT.
// - In danh sách các sinh viên thuộc một trường (school) nào đó (tên trường nhập từ bàn 
// phím).
// - Tìm thông tin của một sinh viên (tên sinh viên nhập từ bàn phím).
// - Nhập một danh sách học viên cao học (GradStudent), in các thông tin của những học 
// viên đó ra màn hình.
// - In danh sách các học viên có bằng cấp trước đây (Degree) ngành (discipline) là CNTT 
// và được cấp sau năm 2010.
// - In danh sách các học viên của khoa (department) CNTT
#include<bits/stdc++.h> 
using namespace std;
struct Date {
  int Day;
  int Month;
  int Year;
};
class Person {
    private:
      string name;
      Date dob;
    public:
      Person() {
      }
      Person(string name, Date dob) {
        this->name = name;
        this->dob = dob;
      }
      void Nhap() {
        cout << "\nTen: ";
        getline(cin, name);
        cout << "Ngay sinh: ";
        cin >> dob.Day >> dob.Month >> dob.Year;
        cin.ignore();
      }
      void Xuat() {
        cout <<name <<":("<< dob.Day << "/" << dob.Month << "/" << dob.Year<<")"<<endl;
      }
};
class Student: public Person {
    private:
      string address;
      string email;
      string telephone;
    public:
      Student() {
      }
      Student(string name, Date dob, string address, string email, string telephone):Person(name, dob) {
        this->address = address;
        this->email = email;
        this->telephone = telephone;
      }
      void Nhap() {
        Person::Nhap();
        cout << "Nhap dia chi: ";
        getline(cin, address);
        cout << "Nhap email: ";
        getline(cin, email);
        cout << "Nhap SDT: ";
        getline(cin, telephone);
      }
      void Xuat() {
        Person::Xuat();
        cout<< address << " - " << email << " - " << telephone;
      }
};
class Undergrad: public Student {
    private:
      string school, major;
      Person parent;
    public:
      Undergrad() {
      }
      Undergrad(string name, Date dob, string address,string email, string telephone, string school, string major,Person parent):Student(name, dob, address, email, telephone) {
        this->school = school;
        this->major = major;
        this->parent = parent;
      }
      void Nhap() {
        Student::Nhap();
        cout << "Nhap truong: ";
        getline(cin, school);
        cout << "Nhap chuyen nganh: ";
        getline(cin, major);
        cout << "Nhap thong tin phu huynh: ";
        parent.Nhap();
      }
      void Xuat() {
        Student::Xuat();
        cout << school << " - " << major<< " - [";
        parent.Xuat();
        cout << "]";
      }
      string getMajor() {
        return major;
      }
      string getSchool() {
        return school;
      }
};
class Degree {
    private:
      string university, discipline;
      Date awarded;
    public:
      Degree() {
      }
      Degree(string university, string discipline, Date awarded) {
        this->university = university;
        this->discipline = discipline;
        this->awarded = awarded;
      }
      void Nhap() {
        cout << "\nTruong dai hoc: ";
        getline(cin, university);
        cout << "Nganh hoc: ";
        getline(cin, discipline);
        cout << "Thoi gian nhan bang: "; cin >> awarded.Day >> awarded.Month >> awarded.Year;
        cin.ignore();
      }
      void Xuat() {
        cout << university << "-" << discipline << "-(" << awarded.Day << "/" << awarded.Month << "/" << awarded.Year << " )-"<<endl;
      }
      string getDiscipline() {
        return discipline;
      }
      Date getAwarded() {
        return awarded;
      }
};
class GradStudent: public Student {
    private:
      string dept;
      Degree lastDegree;
    public:
      GradStudent() {
      }
      GradStudent(string name, Date dob, string address, string email, string telephone, string dept, Degree lastDegree):Student(name, dob, address, email, telephone) {
        this->dept = dept;
        this->lastDegree = lastDegree;
      }
      void Nhap() {
        Student::Nhap();
        cout << "Nhap khoa: ";
        getline(cin, dept);
        cout << "Nhap bang cap: ";
        lastDegree.Nhap();
      }
      void Xuat() {
        Student::Xuat();
        cout <<dept<<endl;
        lastDegree.Xuat();
      }
      Degree getLastDegree() {
        return lastDegree;
      }
      string getDept() {
        return this->dept;
      }
};
int main () {
      int n;
      vector<Undergrad> undergrads;
      cout << "Nhap so luong sinh vien dai hoc: ";
      cin >> n; cin.ignore();
      undergrads.resize(n);

      cout<<"\nNhap n sinh vien:"<<endl;
      for (int i=0; i<n; i++) {
        undergrads[i].Nhap();
      }

      cout<<"\nCac sinh vien khoa CNTT la :"<<endl;
      for (int i=0; i<undergrads.size(); i++) {
        if (undergrads[i].getMajor() == "CNTT") {
          cout << endl;
          undergrads[i].Xuat();
        }
      }


      string Search;
      cout << "\nNhap ten truong can tim: ";
      getline(cin, Search);
      cout << ">> Danh sach sinh vien thuoc truong: "<< Search;
      for (int i=0; i<undergrads.size(); i++) {
        if (undergrads[i].getSchool() == Search) {
          cout << endl;
          undergrads[i].Xuat();
        }
      }

      int m;
      vector<GradStudent> gradStudents;
      cout << "\nNhap so luong hoc vien cao hoc: ";
      cin >> m;
      cin.ignore();
      gradStudents.resize(m);
      cout<<"\nNhap cac sinh vien học cao hoc:"<<endl;
      for (int i=0; i<gradStudents.size(); i++) {
        gradStudents[i].Nhap();
      }


      cout<<"\nCac sinh vien hoc cao hoc :"<<endl;
      for (int i=0; i<gradStudents.size(); i++) {
        cout << endl;
        gradStudents[i].Xuat();
      }
      
      cout << "\nCac hoc vien co bang CNTT cap sau nam 2010 :"<<endl;
      for (int i=0; i<gradStudents.size(); i++) {
        if (gradStudents[i].getLastDegree().getDiscipline() == "CNTT" && gradStudents[i].getLastDegree().getAwarded().Year >= 2010) {
          cout << endl;
          gradStudents[i].Xuat();
        }
      }

      cout<<"\nDanh sach hoc vien thuoc khoa CNTT";
      for (int i=0; i<gradStudents.size(); i++) {
        if (gradStudents[i].getDept() == "CNTT") {
          cout << endl;
          gradStudents[i].Xuat();
        }
      }
      
      return 0;
}

