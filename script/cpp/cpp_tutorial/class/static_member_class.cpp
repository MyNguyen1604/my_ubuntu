#include <iostream>
using namespace std;

class Box
{
     public:
         static int count;
         Box(double dai = 1.0, double rong = 1.0, double cao = 1.0)
         {
             cout<<" Constructor da duoc goi"<<endl;
             chieudai = dai;
             chieurong = rong;
             chieucao = cao;
             count++;
         }
         double thetich(void)
         {
             return chieudai*chieurong*chieucao;
         }
         static int laybiendiem()//static function member.. khong the su dung con tro this//Thuong dung de kiem tra co ton tai hay khong mot thanh phan cua class
         {
             return count;
         }
     private:
         double chieudai;
         double chieurong;
         double chieucao;
};
int Box::count = 0;//static var member

int main()
{
    cout<<"Tong so object ban dau la: "<<Box::laybiendiem()<<endl;
    Box box1(2.4,4.2,2.2);
    Box box2(4.5,2.0,3.2);
    cout<<"Tong so object la: "<<Box::count<<endl;
    //cout<<"Tong so object la: "<<box1.count<<endl; //tuong duong dong lenh tren
    return 0;//:: la toan tu phan giai pham vi cua class
}
