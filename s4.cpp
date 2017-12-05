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
float MIL_TIME :: TimeAsHours()
{

	float min = ((float)(minutes * 0.016667));
	float hour = ((float)hours + min);
	return hour;
}

//#include "maintimeclass200.cpp"
int main()
{
   char colon;
   int hh, mm;

   cin >>  hh >> colon >> mm;
   MIL_TIME yourtime (hh, mm);

   yourtime.Show("\nTIME ");
   cout << showpoint << fixed << setprecision(2);
   cout << "  in Hours = " << yourtime.TimeAsHours() << endl;

   cout << endl; return 0;    // DO NOT TOUCH!!
}
