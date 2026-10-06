#include<iostream>
#include<string> 
#include<iomanip> 
using namespace std; 
class Hocsinh {
private: 
 string mhs;
 string ten;
 int tuoi;
 float diemtoan, diemly, diemhoa;
public:
 Hocsinh() {
  mhs="";
  ten="";
  tuoi=0;
  diemtoan=0;
  diemly=0;
  diemhoa=0;
 }
 Hocsinh(string mhs, string ten, int tuoi, float diemtoan, float diemly, float diemhoa) {
  this->mhs=mhs;
  this->ten=ten;
  this->tuoi=tuoi;
  this->diemtoan=diemtoan;
  this->diemly=diemly;
  this->diemhoa=diemhoa;
 }
 float tinhtongdiem() {
  return this->diemtoan + this->diemly + this->diemhoa;
 }
 void nhap() {
  cin.ignore(); 
  cout<<"Ma hoc sinh:";
  getline(cin, mhs);
  cout<<"Ten hoc sinh:";
  getline(cin, ten);
  cout<<"Tuoi hoc sinh:";
  cin>>tuoi;
  cout<<"Diem toan:";
  cin>>diemtoan;
  cout<<"Diem ly:";
  cin>>diemly;
  cout<<"Diem hoa:";
  cin>>diemhoa;
 }
 void hienthi() {
  cout<<left 
   <<setw(15)<<mhs<<"|"
   <<setw(15)<<ten<<"|"
   <<setw(15)<<tuoi<<"|"
   <<setw(15)<<diemtoan<<"|"
   <<setw(15)<<diemly<<"|"
   <<setw(15)<<diemhoa<<"|"
   <<setw(15)<<this->tinhtongdiem()<<"|" 
   <<endl;
 }
 
}; 
int main() {
 int n;
 cout<<"Nhap so hoc sinh:";
 cin>>n;
 
 Hocsinh *ds=new Hocsinh[n];
 
 for(int i=0;i<n;i++) {
  cout<<"\nHoc sinh thu:"<<i+1<<endl;
  ds[i].nhap();
 } 
 
 cout<<"\nDANH SACH HOC SINH\n";
 cout<<left
  <<setw(15)<<"Ma HS"<<"|"
  <<setw(15)<<"Ten"<<"|"
  <<setw(15)<<"Tuoi"<<"|"
  <<setw(15)<<"Diem Toan"<<"|"
  <<setw(15)<<"Diem Ly"<<"|"
  <<setw(15)<<"Diem Hoa"<<"|"
  <<setw(15)<<"Tong diem"<<"|"
  <<endl; 
 for(int i=0;i<n;i++) {
  ds[i].hienthi(); 
 } 
 delete[] ds;
 return 0; 
}