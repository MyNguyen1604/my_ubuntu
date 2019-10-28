#include <iostream>

using namespace std;
class Box
{
     public:
         //dinh nghia contructor
         Box(double dai = 1.0, double rong = 1.0, double cao = 1.0)
         {
            cout << "Contructor da duoc goi."<<endl;
            chieudai = dai;
            chieurong = rong;
            chieucao = cao;
         }
         double thetich()
         {
            return chieudai*chieurong*chieucao;
         }
         int sosanh(Box box)
         {
            return this->thetich() > box.thetich();//con tro this chi den doi tuong hien tai
         }//con tro this chi dung cho cac ham thanh vien
      private:
         double chieudai;
         double chieurong;
         double chieucao;
           
};
int main()
{
    Box box1(2.4,4.2,2.2);
    Box box2(4.5, 2.0, 3.2);
    //box1:Box(2.4,4.2,2.2); // cach khac de goi Box contructor cua class
    if(box1.sosanh(box2)) //con tro this chi toi vi tri hien tai cua doi tuong box1
    {
       cout<<"box2 co the tich nho hon box1"<<endl;
    }
    else
    {
       cout<<"box2 co the tich bang hoac lon hon box1"<<endl;
    }
    return 0;
}
