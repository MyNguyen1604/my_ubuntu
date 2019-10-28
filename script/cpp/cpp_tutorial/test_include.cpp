#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <limits>
void test(float& x, float& y)
{
  x = x + 2;
  y = y +2;
}
struct cells{
  int index;
  float fcost;
};
struct cmp{
  bool operator()(cells a, cells b) {return a.fcost < b.fcost;}
};

using namespace std;
float infinity = numeric_limits<float>::infinity();
int main()
{
    //cells cp;
    //static const float INFINIT_COST = INT_MAX;
    //std::vector <int> a;
    //cout << a<<endl;
    /*float a = 10, b = 20;
    cout << "Before using test(), a: "<< a <<", b: "<< b << endl;
    test(a,b);
    cout <<"After using test(), a: "<<a<<", b: "<< b <<endl;*/
    /*float infinity = numeric_limits<float>::infinity();
    cout << "infinity of float: "<<INFINIT_COST<<endl;*/
    
    /*multiset<cells, cmp> OPEN;
    
    cells ce;
    ce.index = 1;
    ce.fcost = 1.0;
    
    OPEN.insert(ce);
    ce.index = 1;
    ce.fcost = 2.0;
    OPEN.insert(ce);
    ce.index = 1;
    ce.fcost = 0.5;
    OPEN.insert(ce);
    cout << "Open is empty: "<<OPEN.empty()<<endl;*/
    int mapsize = 10;
    float a[10];
    for (unsigned int i = 0; i<mapsize; i++){
         a[i] = infinity;
    }
    return 0;
}
