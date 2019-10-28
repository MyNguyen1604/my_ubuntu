#include <iostream>

using namespace std;
const int MAX = 3;

int main()
{
    int array[MAX] = {10,100,200};
    int *ptr;
    ptr = array;
    int i = 0;
    while(ptr <= &array[MAX-1])
    {
        cout<<"Address of array["<<i<<"] = ";
        cout<<ptr<<endl;
        
        cout<<"Value of array["<<i<<"] = ";
        cout<<*ptr<<endl;
        ptr++;
        i++;
    }
    return 0;
}
