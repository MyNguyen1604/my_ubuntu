#include <iostream>
using namespace std;
class Box
{
     public:
         Box(double dai = 1.0, double rong= 1.0, double cao = 1.0)
         {
             cout << "Consttructor duoc goi"<<endl;
             chieudai = dai;
             chieurong = rong;
             chieucao = cao;
         }
         double thetich(void)
         {
             return chieudai*chieurong*chieucao;
         }
     private:
         double chieurong;
         double chieudai;
         double chieucao;
};

int main()
{
    Box box1(2.4,4.2,2.2);
    Box box2(4.5,2.0,3.2);
    
    Box *ptr;
    
    ptr = &box1;
    
    cout << "The tich box1 la: "<<ptr->thetich()<<endl;
    ptr = &box2;
    cout << "The tich box2 la: "<<ptr->thetich()<<endl;
    return 0;
}
