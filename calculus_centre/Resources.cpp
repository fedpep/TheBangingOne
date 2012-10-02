#include "Resources.h"

/* Resource - base class method implementation BEGIN */

int Resource::id_abs=1;

Resource::Resource()
{
}

Resource::Resource(string& date_bought , int table , int room)
{
	this->date_bought=date_bought;
	this->table=table;
	this->room=room;

	this->id=Resource::id_abs++;
}

void Resource::Relocate(int table, int room)
{
	this->table=table;
	this->room=room;
}

void Resource::ToString(void) const
{
	cout << id << ") "<< date_bought << " " << table << " " << room <<endl;
}

/* Resource - base class method implementation END */

/* Cartridge - base class method implementation BEGIN */

Cartridge::Cartridge()
{
}

Cartridge::Cartridge(string& color)
{
	this->color=color;
	this->inkQuantity=100;
}

string Cartridge::GetColor(void)
{
	return this->color;
}

int Cartridge::GetInkQuantity(void)
{
	return this->inkQuantity;
}

void Cartridge::RefillInk(void)
{
	this->inkQuantity=100;
}

void Cartridge::ToString(void)
{
	cout<<"cart color " << color << " ink:" << inkQuantity << endl;
}

void Cartridge::ToString(int index)
{
	cout<<"cart "<< index <<" " << color << " ink:" << inkQuantity << endl;
}

/* Cartridge - base class method implementation END */

/* Plotter - base class method implementation BEGIN */

Plotter::Plotter(string& date_bought , int table , int room, string& max_format):Resource(date_bought,table,room)
{
	this->max_format = max_format;
	string colours[] = {"red","green","cyan","magenta"};

	for(int i=0;i<4;i++)
		this->cartridge[i] = new Cartridge(colours[i]);

}

void Plotter::ToString(void) const
{
	Resource::ToString();
	cout<<" max format" << max_format << endl;

	for(int i=0;i<4;i++)
		cartridge[i]->ToString(i);

}

bool Plotter::isAvailable(void) const
{
	int n_avail=0;
	bool is_avail=true;

	for(int i=0;i<4;i++)
		if(this->cartridge[i]->GetInkQuantity()>0)
			n_avail++;

	if(n_avail<3)
		is_avail=false;

	return is_avail;
}

/* Plotter - base class method implementation END */



