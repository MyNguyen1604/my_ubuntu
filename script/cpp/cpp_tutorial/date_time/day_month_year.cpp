#include <iostream>
#include <ctime>

using namespace std;
/*
struct tm {
  int tm_sec;   // so giay trong mot phut, tu 0 toi 61
  int tm_min;   // so phut trong mot gio, tu 0 toi 59
  int tm_hour;  // so gio trong mot ngay, tu 0 toi 24
  int tm_mday;  // ngay trong thang, tu 1 toi 31
  int tm_mon;   // thang trong nam, tu 0 toi 11
  int tm_year;  // nam, bat dau tu 1900
  int tm_wday;  // ngay, bat dau tu Sunday
  int tm_yday;  // ngay, bat dau tu 1/1
  int tm_isdst; // so gio cua Daylight Savings Time
}
*/
int main()
{
    time_t now = time(0);//khoi tao bien now voi cau truc time_t
    
    cout << "So giay ke tu ngay 1/1/1970: "<<now<<endl;
    
    tm *ltm = localtime(&now); //Tao con tro ltm voi kieu dinh dang tm cho toi dia chi luu gia tri trong cau truc tm //Ham localtime() tra ve dia chi cua vung nho chua cau truc struct tm
    
    cout << "Year: "<<1900 + ltm->tm_year << endl;
    cout << "Month: "<< 1  + ltm->tm_mon<<endl;
    cout << "Day: "<<ltm->tm_mday<<endl;
    cout << "Time: "<<ltm->tm_hour<<":";
    cout << ltm->tm_min<<":";
    cout << ltm->tm_sec<<endl;
    return 0;
    
}
