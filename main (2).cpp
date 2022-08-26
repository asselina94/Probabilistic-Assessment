#include <iostream>
#include <math.h>
#include <cmath>
#include "stdafx.h"
#include <stdlib.h>
using namespace std;

int main()
{
    double E = 0,A=0,CF =0,d =0,D=0,T=0,X=0;
 cout << "Enter the SOURCE ACTIVITY:";
	 cin >>A;
	 cout << "Enter the CONVERSION FACTOR:";
	 cin>>CF;
	 cout<<"Enter the SHIELDING THICKNESS:";
	 cin>>d;
	 cout<<"Enter the HALF VALUE LAYER:";
	 cin>>D;
	 for(T = 10;T < 60;T++){
	     for(X = 1;X < 2.5;X++){
	         E = (A * CF * T * (pow(0.5,(d/(sqrt(D))))))/(X*X);
	        cout<<"Effective dose from a point source: "<<E<<endl;
	     }
	 }
	 system("pause");
    return 0;
}
