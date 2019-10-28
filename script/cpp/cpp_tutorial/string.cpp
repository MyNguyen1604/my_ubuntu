#include <iostream>
#include <string>

using namespace std;

int main()
{
    string chuoi1 = "Hello";
    string chuoi2 = "Christmas";
    string chuoi3;
    int len;
    
    chuoi3 = chuoi1;
    cout<<"chuoi3: "<<chuoi3<<endl;
    
    chuoi3 = chuoi1 + chuoi2;
    cout<<"chuoi3: "<<chuoi3<<endl;
    
    len = chuoi3.size();
    cout<<"length of chuoi3: "<<len<<endl;
    
    return 0;
}
