#include <iostream>
using namespace std;

int main()
{
    int i, j;
    for (i=2; i<=50; i++)
    {
        for (j=2; j<=(i/j); j++)
            if (!(i%j)) break;
        if (j>(i/j)) cout << i << " is prime number!"<<endl;
    }
    return 0;
}
