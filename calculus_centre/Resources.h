#include<string>
#include<iostream>

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
	int GetInkQuantity(void);
	void RefillInk(void);
	void ToString(void);
	void ToString(int index);

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

