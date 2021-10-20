#include <iostream>
#include <stdio.h>
using namespace std;
class date {
private :int day ;
int month;
int year ;


 public :
     date ();
     ~date();
     date (int d,int m ,int y);
     void setdate(int d,int m ,int y  );
     void setday (int x);
    void  setmonth(int m);
   void setyear(int y);
     int getday ();
     int getmonth();
     int getyear();
     friend ostream &operator <<(ostream &out ,date d);
     friend istream &operator >>(istream &in , date &d );
     date operator ++ ();
     date operator --();
     bool operator ==(date d);
     bool operator != (date d );
     bool operator > (date d );
     bool operator < (date d );
     };

      date::date(){
      day =1 ;
      month=1 ;
      year =2000 ;

      }
      date ::~date (){


      }
     date::date(int d,int m ,int y){

     day= d;
     month=m ;
     year =y;

     }
     void date ::setdate( int d,int m ,int y){
         int x ;
  switch(m){

    case 1:case 3: case 5:case 7 :case 8:case 10 :case 12:x=31; break ;
     case 4:case 6 :case 9 :case 11:x=30 ;break ;
    case 2 :if (y%4==0){x=29 ;break;}
    else {x=28 ;break;}
    }
     if (d<=x){
   day= d;
   if (m<=12)  {this->month=m ;}
   else {cout<<"invalid month"<<endl;}
     this ->year =y;
    }
    else {cout<<"invalid day "<<endl ;}

     }
     void date ::setday(int x  ){
     this ->day=x ;
     }
     void date ::setmonth(int m){
     this ->month=m;
     }
     void date ::setyear (int u){
     this->year=u ;
     }
     int date::getday(){
     return day;

     }
     int date ::getmonth(){
     return month;
     }
int date ::getyear(){
return year ;

}
 ostream &operator <<(ostream &out ,date d){
  cout <<d.getyear()<<"-"<<d.getmonth()<<"-"<<d.getday()<<endl ;
  return out ;

  }
    istream &operator >>(istream &in , date &y ){

     cout<<"enter the day " ;
     in>> y.day;

     cout<<"\n";
     cout<<"enter the month";

     in >>y.month;

     cout<<"\n";
     cout<<"enter the year";
    in >>y.year;

return in;



     }
     bool date :: operator ==(date d){
     if (day==d.day&&month ==d.month&& year==d.year)return true  ;
     else return false ;



     }
     bool date :: operator !=(date d){
     if (day==d.day&&month ==d.month&& year==d.year)return false  ;
     else return true  ;



     }
     bool date ::operator >(date d){
     if(year>d.year)return true  ;
     else if (year ==d.year&&month>d.month)return true;
     else if (year==d.year&&month ==d.month&&day>d.day)return true ;
     else return false ;


     }
      bool date ::operator <(date d){
     if(year>d.year)return false  ;
     else if (year ==d.year&&month>d.month)return false ;
     else if (year==d.year&&month ==d.month&&day>d.day)return false  ;
     else return true  ;}


     date date ::operator++(){
          int x;

      switch(month){

    case 1:case 3: case 5:case 7 :case 8:case 10 :case 12:x=31; break ;
     case 4:case 6 :case 9 :case 11:x=30 ;break ;
    case 2 :if (year%4==0){x=29 ;break;}
    else x=28 ;break;
    }
    ++day ;
    if (day>x){day=1;month++ ;}
    if (month>12){day=1;month=1,++year;}




     }
     date date::operator--(){
         int q;
    if (day==1&&month==1){day=31; month=12;--year;}
    q=day-1 ;
    if (q ==0){
       int x;
        month--;
      switch(month){

    case 1:case 3: case 5:case 7 :case 8:case 10 :case 12:x=31; break ;
     case 4:case 6 :case 9 :case 11:x=30 ;break ;
    case 2 :if (year%4==0){x=29 ;break;}
    else x=28 ;break;
    }
    day=x ;
    }
else {--day;}


     }
int main()
{
   date date1(31 , 1, 2019);
date date2(1 , 3 , 2019);
date date3(15 , 4 , 2019);
date date4(15, 4, 2019);
date date5;
cout << "date1 :";
cout << "Day =" << date1.getday();
cout << " , Month = " << date1.getmonth();
cout << " , Year = " << date1.getyear() << endl;
cout << "date1 : " << date1 << endl;
cout << "date2 : " << date2 << endl;
cout << "date3 : " << date3 << endl;
cout << "date4 : " << date4 << endl;
if (date1 == date2)
cout << "date1 is equal to date2" << endl;
if (date1 != date2)
cout << "date1 is not equal to date2" << endl;
if (date3 == date4)
cout << "date3 is equal to date4" << endl;
if (date3 != date4)
cout << "date3 is not equal to date4" << endl;
if (date1 < date2)
cout << "date1 is before date2" << endl;
if (date3 > date1)
cout << "date3 is after date1" << endl;
cout << "date1 before auto-increment:" << date1 << endl;
++date1;
cout << "date1 after auto-increment:" << date1 << endl;
cout << "date2 before auto-decrement:" << date2 << endl;
--date2;
cout << "date2 after auto-decrement:" << date2 << endl;
cin >> date5;
cout << "date5 :" << date5 << endl;
date1.setdate(1, 12, 2020);
cout << "date1 : " << date1 << endl;
date1.setdate(29, 2, 2019); //invalid day
cout << "date1 : " << date1 << endl;

    return 0;
}
