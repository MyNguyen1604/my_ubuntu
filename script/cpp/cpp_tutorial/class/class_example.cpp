#include <iostream>

using namespace std;

class Box
{
    public:
        double chieudai;
        double chieurong;
        double chieucao;
        
        //Khai bao ham thanh vien//Cac ham thanh vien co the truy cap truc tiep cac bien thanh vien
        double thetich(void);
        double laydodai(double dai);
        double laydorong(double rong);
        double laychieucao(double cao);
};

//Dinh nghia cac ham thanh vien trong lop Box
double Box::thetich(void)
{
    return chieudai*chieurong*chieucao; 
}
double Box::laydodai(double dai)
{
    chieudai = dai; 
}
double Box::laydorong(double rong)
{
    chieurong = rong;
}
double Box::laychieucao(double cao)
{
    chieucao = cao;
}

int main(int argc, char **agrv)
{
    Box box1; //khai bao doi tuong box1 co cac dac diem cua class Box
    Box box2;
    
    box1.laydodai(2.3);
    box1.laydorong(5.6);
    box1.laychieucao(4.5);
    
    box2.laydodai(7.4);
    box2.laydorong(4.2);
    box2.laychieucao(3.8);
    
    cout<<"The tich box1: "<<box1.thetich()<<endl;
    cout<<"The tich box2: "<<box2.thetich()<<endl;
    return 0;
}
