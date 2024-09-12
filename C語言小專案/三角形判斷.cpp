#include<iostream>
using namespace std;
int  main()
{int a,b,c,max;
cin>>a>>b>>c;
if(a<b)
{     
    b=max;
	a=b;
	a=max;
}
else if(a<c)
{    c=max;
     a=c;
     a=max;
}
if(a>=b+c)
   cout<<"���i��"<<endl;
else if(a==b&&b==c)
   cout<<"���T����"<<endl;
else 
    cout<<"�T����"<<endl;}
	 
	 
