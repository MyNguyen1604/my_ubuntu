#include <iostream>

using namespace std;
double array[] = {5.6, 11.4, 43.1, 25.6, 20.2};

/*Dung tham chieu*/
double & revalue(int i)
{
   return array[i];
}

int main()
{
    cout << "Gia tri truoc khi thay doi: "<<endl;
    int len = int(sizeof(array)/sizeof(*array)); //length of array
    for (int i=0; i<len; i++)
    {
         cout << "array["<<i<<"] =";
         cout <<array[i]<<endl;
    }
    revalue(1) = 12.44;
    revalue(3) = 25.0;
    
    cout<< "Gia tri sau khi thay doi la: "<<endl;
    for (int i=0; i<len; i++)
    {
         cout << "array["<<i<<"] =";
         cout <<array[i]<<endl;
    }
    return 0;
}
/* Dung pointer
double * revalue(int i)
{
   return &array[i];
}

int main()
{
    cout << "Gia tri truoc khi thay doi: "<<endl;
    int len = int(sizeof(array)/sizeof(*array)); //length of array
    for (int i=0; i<len; i++)
    {
         cout << "array["<<i<<"] =";
         cout <<array[i]<<endl;
    }
    *revalue(1) = 12.44;
    *revalue(3) = 25.0;
    
    cout<< "Gia tri sau khi thay doi la: "<<endl;
    for (int i=0; i<len; i++)
    {
         cout << "array["<<i<<"] =";
         cout <<array[i]<<endl;
    }
    return 0;
}
*/
