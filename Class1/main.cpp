#include <iostream>
using namespace std;
class A{
 private:
 double a;
 double b;
public:
   double c(double,double);
   };

double A::c(double a,double b)
{
 double t=0;
 a/=b;
  a--;
   t=a*b;
 return t;
}
int main()
{
 A z;
 double x=0,y=0;
 cout<<"a: ";cin>>x;
 cout<<"b: ";cin>>y;
 cout<<"c: "<<z.c(x,y)<<endl;
 return 0;
}
