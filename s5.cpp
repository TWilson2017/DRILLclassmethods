#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

//#include "MIL_TIME.h"
class MIL_TIME
{
  public:
     MIL_TIME(){hours=minutes=0;}
     MIL_TIME(int H, int M){hours=H; minutes=M;}
     bool operator< (MIL_TIME t);
     MIL_TIME operator+ (MIL_TIME t);
     MIL_TIME operator- (MIL_TIME t);

     void Show(string Label)
     {
        cout << Label << setfill('0') << setw(2) << hours
             << ':' << setw(2) << minutes << setfill(' ');
     }

     float TimeAsHours();
     int TimeAsMinutes();
     int get_hours();
     int get_minutes();
  private:
     int minutes;
     int hours;
};//class

// Write the following MIL_TIME methods (member functions).
int MIL_TIME :: get_minutes()
{
	return minutes;
}

int MIL_TIME :: get_hours()
{
	return hours;
}

//#include "maintimeclass210.cpp"

int main()
{
   int hh, mm;

   cin >>  mm;
   MIL_TIME myTime ( (mm/60)%24, mm % 60);

   cout << myTime.get_hours() << "hh, "
        << myTime.get_minutes() << "mm";

   cout << endl; return 0;    // DO NOT TOUCH!!
}
