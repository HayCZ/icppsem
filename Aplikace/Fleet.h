#pragma once
#include <api.h>
#include "Car.h"

class Fleet
{
public:
	~Fleet();
	//Pøidání vozu do vozového parku
	void add(Car* car);
	//Získání velikosti vozového parku
	int getSize();
	//Získání vozidla z vozového parku
	Car* get(int index);
	//Odebrání vozdila z vozového parku
	void remove(int index);
	//Uložení do souboru
	void save(std::string filename);
	//Naètení ze souboru
	void load(std::string filename);

private:
	//Pole pro ukládání vozidel
	DynamicArray<Car*> cars;
};

