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

// Write the following MIL_TIME < operator.
bool MIL_TIME :: operator< (MIL_TIME t)
{
	 if(hours < t.hours)
	 {
            return true;
     }//if
         
	if(hours == t.hours && minutes < t.minutes) 
	{
            return true;
    }//if
         
    return false;
}//MIL_TIME

//#include "maintimeclass215.cpp"

int main()
{
   char colon;
   int hh, mm;

   cin >>  hh >> colon >> mm;
   MIL_TIME mytime (hh, mm);
   cin >>  hh >> colon >> mm;
   MIL_TIME yourtime (hh, mm);

   if (mytime < yourtime)
   {
      mytime.Show("");
      yourtime.Show(" < ");
   }
   else if (yourtime < mytime)
   {
      yourtime.Show("");
      mytime.Show(" < ");
   }
   else
   {
      yourtime.Show("");
      mytime.Show(" == ");
   }

   cout << endl; return 0;    // DO NOT TOUCH!!
}
