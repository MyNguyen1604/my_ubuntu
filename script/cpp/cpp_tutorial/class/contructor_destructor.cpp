#include <iostream>

using namespace std;

class Line
{
     public:
         void laychieudai(double dai);
         double htchieudai(void);
         Line(); //khai bao contructor//Huu ich cho viec khoi tao cac bien thanh vien
         ~Line();//khai bao destructor//Huu ich cho viec dong cac file da thao tac..
         
     private: //bien chieudai thuoc khu vuc private, tuc la chi co the truy cap boi cac ham thanh vien, khong duoc truy cap truc tiep nhu public
         double chieudai;
     
};
Line::Line(void) //khong co bat ky kieu tra ve, ke ca kieu void
{
     cout<<"Doi tuong da duoc tao"<<endl;
}
Line::~Line(void)
{
     cout<<"Doi tuong da bi xoa"<<endl;
}
void Line::laychieudai(double dai)
{
     chieudai = dai;
}
double Line::htchieudai(void)
{
      return chieudai;
}

int main(int argc, char **argv)
{
    Line line;
    line.laychieudai(6.0);
    cout<<"Chieu dai line la: "<<line.htchieudai()<<endl;
    return 0;
}
