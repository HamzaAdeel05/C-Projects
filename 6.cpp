#include <iostream>
using namespace std;
int main (){
int num1=0,num2=0,num3=0,num4=0,num5=0,number=0,total=0,remain=0;
cout<<"Enter a 5 digit number:";
cin>>number;
num1=number/10000;
cout<<num1<<endl;
total=num1*10000;
remain=number-total;
num2=remain/1000;
cout<<num2<<endl;
total=num2*1000;
remain=remain-total;
num3=remain/100;
cout<<num3<<endl;
total=num3*100;
remain=remain-total;
num4=remain/10;
cout<<num4<<endl;
total=num4*10;
remain=remain-total;
num5=remain;
cout<<num5<<endl;

return 0;
}