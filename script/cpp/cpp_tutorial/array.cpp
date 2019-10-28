#include <iostream>
#include <ctime>
#include <stdlib.h>

using namespace std;

int * songaunhien()
{
     static int r[10];
     
     srand((unsigned)time(NULL));
     
     for (int i=0; i< 10; i++)
     {
         r[i] = rand();
         cout<<r[i]<<endl;
     }
     return r;
}

int main()
{
   int *p;
   
   p = songaunhien();
   cout<<"============================="<<endl;
   for (int i=0; i<10; i++)
   {
      cout<<*(p+i)<<endl;
   }
   return 0;
}
