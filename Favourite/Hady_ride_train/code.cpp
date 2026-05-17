
#include <iostream>
using namespace std;

int main() {
 long long n, x,sum;
 cin >>n;

//this part discover the column
 if ((n-6)%8 == 0 || (n-9)%8 == 0)
  {
   x=1;
  }
 else if ((n-5)%8 == 0 || (n-10)%8 == 0)
 {
  x=2;
 }
 else if ((n-8)%8 == 0 || (n-7)%8 == 0)
 {
  x=0;
 }
 else if ((n-4)%8 == 0 || (n-11)%8 == 0)
 {
  x=3;
 }

 //this part discover the row
 if (x==3|| x==0)
 {
  if ( (n +(n+1)+(n+2) + (n+3) - 6)%16 == 0)
  {
   cout << (n +(n+1)+(n+2) + (n+3) - 6)/16 << " "<< x;
  }
  else if ( (n +(n-1)+(n-2) + (n-3) - 6)%16 == 0)
  {
   cout << (n +(n-1)+(n-2) + (n-3) - 6)/16 << " "<< x;
  }
 }



 else if (x==1 || x==2)
 {
  if ( (n +(n+1)+(n-1) + (n-2) - 6)%16 == 0)
  {
   cout << (n +(n+1)+(n-1) + (n-2) - 6)/16 << " "<< x;
  }
  else if ( (n +(n+1)+(n+2) + (n-1) - 6)%16 == 0)
  {
   cout << (n +(n+1)+(n+2) + (n-1) - 6)/16 << " "<< x;
  }

 }











 }
