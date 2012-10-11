#include<string>
#include<iostream>
#include<vector>

using namespace std;


class Resource
{
private:
	static int id_abs;
	int id;
	int table, room;
	string date_bought;

public:
	Resource();
	Resource(string& date_bought , int table , int room);
	void Relocate(int table, int room);
	virtual void ToString(void) const = 0;
	virtual bool isAvailable(void) const = 0;
};

class Cartridge
{
private:
	string color;
	int inkQuantity;

public:
	Cartridge();
	Cartridge(string& color);
	string GetColor(void);
	int GetInkQuantity(void) const;
	void RefillInk(void);
	void ToString(void) const;
	void ToString(int index) const;

};

class Plotter : public Resource
{
private:
	string max_format;
	Cartridge *cartridge[4];
public:
	Plotter(string& date_bought , int table , int room , string& max_format);
	void ToString(void) const;
	bool isAvailable(void) const;
};


class Printer : public Resource
{
private:
	string type;
	int sheets;
	Cartridge cartridge;
public:
	Printer(string& date_bought , int table , int room , string& type);
	void rechargePaper(int sheets);
	int getSheets(void) const;
	void ToString(void) const;
	bool isAvailable(void) const;
};


class Workstation : public Resource
{
private:
	string cpu;
	int ram_mb;
	int hdd_mb;
	vector<string> software_list;

public:
	Workstation(string& date_bought , int table , int room, string& cpu , int ram_mb , int hdd_mb);
	void addSoftware(string& sw_name);
	void ToString(void) const;
	bool isAvailable(void) const;

};
