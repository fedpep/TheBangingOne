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

/* Cartridge - class method implementation BEGIN */

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

int Cartridge::GetInkQuantity(void) const
{
	return this->inkQuantity;
}

void Cartridge::RefillInk(void)
{
	this->inkQuantity=100;
}

void Cartridge::ToString(void) const
{
	cout<<"cart color " << color << " ink:" << inkQuantity << endl;
}

void Cartridge::ToString(int index) const
{
	cout<<"cart "<< index <<" " << color << " ink:" << inkQuantity << endl;
}

/* Cartridge - class method implementation END */

/* Plotter - class method implementation BEGIN */

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

/* Plotter - class method implementation END */


/* Printer - class method implementation BEGIN */

Printer::Printer(string& date_bought , int table , int room , string& type):Resource(date_bought,table,room),cartridge(*new string("black"))
{
	this->type=type;
	this->sheets=100;
}

void Printer::rechargePaper(int sheets)
{
	this->sheets=sheets;

}

int Printer::getSheets(void) const
{
	return this->sheets;

}

void Printer::ToString(void) const
{
	Resource::ToString();
	cout<<" type" << type << endl;

	this->cartridge.ToString();

}

bool Printer::isAvailable(void) const
{
	if(this->cartridge.GetInkQuantity()>0 && this->getSheets()>0)
		return true;

	return false;
}

/* Printer - class method implementation END */


/* Workstation - class method implementation BEGIN */

Workstation::Workstation(string& date_bought , int table , int room, string& cpu , int ram_mb , int hdd_mb):Resource(date_bought,table,room)
{
	this->cpu=cpu;
	this->ram_mb=ram_mb;
	this->hdd_mb=hdd_mb;
}

void Workstation::addSoftware(string& sw_name)
{
	this->software_list.push_back(sw_name);

}

void Workstation::ToString(void) const
{
	Resource::ToString();
	cout<<" HDD (MB):" << hdd_mb << endl;

}

bool Workstation::isAvailable(void) const
{
	if(this->software_list.size()!=0 && this->hdd_mb>0)
		return true;

	return false;
}

/* Workstation - class method implementation END */

