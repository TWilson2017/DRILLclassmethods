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

//-----------------------------------------------------------
// Write the following MIL_TIME - operator. Resulting time
// MUST BE A MILITARY TIME.
//-----------------------------------------------------------
MIL_TIME MIL_TIME :: operator- (MIL_TIME t)
{
	 MIL_TIME timeTotal;
	 timeTotal.hours = this ->hours - t.hours;
	 timeTotal.minutes = this -> minutes - t.minutes;
	
	 if(timeTotal.minutes < 0)
	 {
		 timeTotal.minutes = timeTotal.minutes + 60;
		 timeTotal.hours = timeTotal.hours - 1;
	 }//for
	
	if(timeTotal.hours < 0)
		timeTotal.hours = timeTotal.hours + 24;
	
	return timeTotal;
}//operator

//#include "maintimeclass225.cpp"

int main()
{
   char colon;
   int hh, mm;

   cin >>  hh >> colon >> mm;
   MIL_TIME mytime (hh, mm);
   cin >>  hh >> colon >> mm;
   MIL_TIME yourtime (hh, mm);

   MIL_TIME diffMY = mytime - yourtime;
   mytime.Show ("");
   yourtime.Show(" - ");
   diffMY.Show (" = ");

   cout << endl; return 0;    // DO NOT TOUCH!!
}
