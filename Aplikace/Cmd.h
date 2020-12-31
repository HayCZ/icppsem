#pragma once
#include "Fleet.h"
class Cmd
{
public:
	Cmd(Fleet* fleet);
	~Cmd();
	//P�idat auto
	void addCar();
	//Odebere auto
	void removeCar();
	//Updatuje auto
	void updateCar();
	//Zobraz� auto
	void showCar(int index);
	//Zobraz� v�echny auta
	void showAllCars();
	//Zobraz� menu
	void displayMenu();
	//Na�te soubor
	void readFile();
	//Ulo�� soubor
	void saveFile();
	//Provede akci dle vstupu
	void doIt();
	//pomocn� promn�n�
	bool run;
private:
	int _selectedIndex;
	Fleet* _fleet;
	int getIntFromConsole();

};

