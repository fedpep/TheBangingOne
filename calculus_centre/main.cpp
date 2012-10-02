#include "Resources.h"
#include<string>
#include<iostream>

using namespace std;



int main()
{
	string date_r="13-09-2012";
	string formt="A4";



	Plotter p(date_r,1,3,formt);


	p.ToString();

	return 0;

}
