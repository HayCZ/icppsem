#pragma once
#include <api.h>
#include "Car.h"

class Fleet
{
public:
	~Fleet();
	//P�id�n� vozu do vozov�ho parku
	void add(Car* car);
	//Z�sk�n� velikosti vozov�ho parku
	int getSize();
	//Z�sk�n� vozidla z vozov�ho parku
	Car* get(int index);
	//Odebr�n� vozdila z vozov�ho parku
	void remove(int index);
	//Ulo�en� do souboru
	void save(std::string filename);
	//Na�ten� ze souboru
	void load(std::string filename);

private:
	//Pole pro ukl�d�n� vozidel
	DynamicArray<Car*> cars;
};

