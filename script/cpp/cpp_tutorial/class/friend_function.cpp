#include <iostream>

using namespace std;

class Box
{
     double chieurong;
     public:
         friend void inchieurong(Box box);
         void laychieurong(double rong);
};

//Dinh nghia ham thanh vien
void Box::laychieurong(double rong)
{
     chieurong = rong;
}

//Dinh nghia ham friend
//inchieurong() khong phai la ham thanh vien cua lop Box, nhung co the truy cap truc tiep bats cu thanh vien nao cua lop Box
void inchieurong(Box box)
{
     cout<<"Chieu rong cua box la: "<<box.chieurong<<endl;//Truy cap truc tiep bien thuoc vung private
}

int main()
{
    Box box;
    box.laychieurong(25.3);
    inchieurong(box);
    return 0;
}
