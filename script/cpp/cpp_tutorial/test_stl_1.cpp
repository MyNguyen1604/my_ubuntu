#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
   vector <float> gcost;
   int pose;
   
   /*for (unsigned int i =0; i < 10; i ++){
      gcost.push_back(20*i);
   }*/
   gcost.push_back(10);
   gcost.push_back(11);
   gcost.push_back(12);
   gcost.push_back(0);
   gcost.push_back(5);
   gcost.push_back(8);
   pose = distance(gcost.begin(), min_element(gcost.begin(), gcost.end())); // tra ve khoang cach tu phan tu dau tien den phan tu nho nhat
   for(int i = 0; i<gcost.size(); i++) cout << gcost[i] <<endl;
   cout << "Min of gcost: " << gcost[pose]<<endl;
   cout << static_cast<int>(round(3.5)) <<endl;
   //cout << "Final element of gcost: "<<gcost.front()<<endl;
   cout << static_cast<unsigned int >(8006001.056/4000) << endl;
   cout << sqrt(pow(4,2) + pow(7,2))<<endl;
   return 0;
}
