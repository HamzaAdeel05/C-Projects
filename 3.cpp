#include <iostream>
using namespace std;
int main (){
int total_days=0,remaining_days=0,years=0,weeks=0,days=0;

cout<<"Enter the number of days:";
cin>>total_days;
years=total_days/365;
cout<<"Years:"<<years<<endl;
remaining_days=total_days-(years*365);
weeks=remaining_days/7;
cout<<"weeks:"<<weeks<<endl;
remaining_days=remaining_days-(weeks*7);
cout<<"days:"<<remaining_days<<endl;

return 0;
}