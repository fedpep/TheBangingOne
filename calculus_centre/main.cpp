#include "Resources.h"
#include<string>
#include<iostream>
#include<vector>

using namespace std;

vector<Resource*> resources;

int main()
{
	string date_r="13-09-2012";
	string formt="A4";


	for(int i=0 ; i<3 ; i++)
	{
		resources.push_back(new Plotter(date_r,1+i,3+i,formt));
		resources.push_back(new Printer(date_r,1+i,3+i,formt));
		resources.push_back(new Workstation(date_r,1+i,3+i,formt,350,2000));
	}
	for(int i=0 ; i<9 ; i++)
		resources[i]->ToString();




	return 0;

}
