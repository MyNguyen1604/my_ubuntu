#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    time_t hientai = time(0);
    
    char* dt = ctime(&hientai);
    cout<<"Date and Time Local: "<<dt<<endl;
    
    //Convert to UTC
    tm *gmtm = gmtime(&hientai);
    dt = asctime(gmtm);
    cout<<"UTC date and time: "<<dt<<endl;
    return 0;
}
