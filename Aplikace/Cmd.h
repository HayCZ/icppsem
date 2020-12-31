#pragma once
#include "Fleet.h"
class Cmd
{
public:
	Cmd(Fleet* fleet);
	~Cmd();
	//Pøidat auto
	void addCar();
	//Odebere auto
	void removeCar();
	//Updatuje auto
	void updateCar();
	//Zobrazí auto
	void showCar(int index);
	//Zobrazí všechny auta
	void showAllCars();
	//Zobrazí menu
	void displayMenu();
	//Naète soubor
	void readFile();
	//Uloží soubor
	void saveFile();
	//Provede akci dle vstupu
	void doIt();
	//pomocná promnìná
	bool run;
private:
	int _selectedIndex;
	Fleet* _fleet;
	int getIntFromConsole();

};

