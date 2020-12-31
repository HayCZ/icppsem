#pragma once
#include <iostream>
#include <limits>
#include "fleet.h"
#include "Cmd.h"

Cmd::Cmd(Fleet* fleet)
{
	this->_fleet = fleet;
	bool run = true;
}

Cmd::~Cmd()
{
}
// Slouží pro pøidání auta do seznamu Fleet
void Cmd::addCar()
{
	std::string manu;
	std::cout << "Manufacturer: ";
	std::cin >> manu;

	std::string model;
	std::cout << "Model: ";
	std::cin >> model;

	std::string colour;
	std::cout << "Colour: ";
	std::cin >> colour;

	int price;
	std::cout << "Price (int): ";
	price = this->getIntFromConsole();

	DynamicArray<std::string>* wheelTypes = new DynamicArray<std::string>();

	while (true)
	{
		std::cout << "Wheel type (0 = exit): ";
		std::string data;
		std::cin >> data;
		if (data == "0") {
			break;
		}
		else {
			wheelTypes->append(data);
			std::cout << "Added!" << std::endl;
		}
	}

	int allowed;
	std::cout << "Weight - Allowed (int): ";
	allowed = this->getIntFromConsole();

	int operating;
	std::cout << "Weight - Operating (int): ";
	operating = this->getIntFromConsole();

	bool active;
	int result;
	std::cout << "Active (0 - False , 1 - True): ";
	while (true)
	{
		result = this->getIntFromConsole();
		if (result == 1) {
			active = true;
			break;
		}
		else if (result == 0) {
			active = false;
			break;
		}
		else {
			std::cout << "Invalid number!" << std::endl;
		}
	}

	Car* car = new Car(manu, model, colour, price, wheelTypes, { allowed,operating }, active);
	_fleet->add(car);
	std::cout << "Car added to your fleet!" << std::endl;
}

//slouží pro update auta v seznamu Fleet
void Cmd::updateCar()
{
	int selected;
	std::cout << "Please type index of Car to edit:";
	selected = getIntFromConsole();

	if (selected >= 0 && selected <= _fleet->getSize()) {
		int choice;
		std::cout << "Do You want to update value \"Manufacturer\"? (1 -> Yes, Other -> No):" << std::endl;
		choice = getIntFromConsole();
		if (choice == 1)
		{
			std::string manu;
			std::cout << "Manufacturer(" << _fleet->get(selected)->getManufacturer() << "): ";
			std::cin >> manu;
			_fleet->get(selected)->setManufacturer(manu);
		}

		std::cout << "Do You want to update value \"Model\"? (1 -> Yes, Other -> No):" << std::endl;
		choice = getIntFromConsole();
		if (choice == 1)
		{
			std::string model;
			std::cout << "Model (" << _fleet->get(selected)->getModel() << "): ";
			std::cin >> model;
			_fleet->get(selected)->setModel(model);
		}

		std::cout << "Do You want to update value \"Colour\"? (1 -> Yes, Other -> No):" << std::endl;
		choice = getIntFromConsole();
		if (choice == 1)
		{
			std::string colour;
			std::cout << "Colour (" << _fleet->get(selected)->getColour() << "): ";
			std::cin >> colour;
			_fleet->get(selected)->setColour(colour);
		}

		std::cout << "Do You want to update value \"Price\"? (1 -> Yes, Other -> No):" << std::endl;
		choice = getIntFromConsole();
		if (choice == 1)
		{
			int price;
			std::cout << "Price (" << _fleet->get(selected)->getPrice() << "): ";
			price = getIntFromConsole();
			_fleet->get(selected)->setPrice(price);
		}

		std::cout << "Do You want to update array \"WheelType\"? (1 -> Yes, Other -> No):" << std::endl;
		choice = getIntFromConsole();
		if (choice == 1)
		{
			auto wheelTypes = _fleet->get(selected)->getWheelTypes();
			for (int wheelId = 0; wheelId < wheelTypes->getSize(); wheelId++) {
				std::cout << wheelId << " - " << wheelTypes->getElementAt(wheelId) << std::endl;
			}
			while (true)
			{
				std::cout << "Do You want to update or remove \"WheelType\" value? (1 -> Yes, Other -> No):" << std::endl;
				choice = getIntFromConsole();
				if (choice == 1)
				{
					int valueIndex;
					std::cout << "Please enter the index of value: ";
					valueIndex = getIntFromConsole();
					if (valueIndex >= 0 && valueIndex <= wheelTypes->getSize()) {
						std::cout << "Do You want to update value \"WheelType\"? (1 -> Yes, Other -> Remove):" << std::endl;
						choice = getIntFromConsole();
						if (choice == 1)
						{
							std::string data;
							std::cout << "WheelType (" << wheelTypes->getElementAt(valueIndex) << "): ";
							std::cin >> data;
							wheelTypes->removeElementAt(valueIndex);
							wheelTypes->append(data);
							break;
						}
						else {
							wheelTypes->removeElementAt(valueIndex);
							std::cout << "Value removed!" << std::endl;
						}
					}
					else {
						std::cout << "Value not found!" << std::endl;
					}
				}
				else {
					break;
				}
			}
		}

		std::cout << "Do You want to update value \"Weights\"? (1 -> Yes, Other -> No):" << std::endl;
		choice = getIntFromConsole();
		if (choice == 1)
		{
			int allowed;
			std::cout << "Allowed (" << _fleet->get(selected)->getWeights().allowed << "): ";
			allowed = getIntFromConsole();

			int operating;
			std::cout << "Operating (" << _fleet->get(selected)->getWeights().operating << "): ";
			operating = getIntFromConsole();

			_fleet->get(selected)->setWeights({ allowed, operating });
		}

		std::cout << "Do You want to update value \"Active\"? (1 -> Yes, Other -> No):" << std::endl;
		choice = getIntFromConsole();
		if (choice == 1)
		{
			std::cout << "Active (" << _fleet->get(selected)->getActive() << "): " << std::endl;
			bool active;
			int result;
			std::cout << "Active (0 - False , 1 - True)";
			while (true)
			{
				result = this->getIntFromConsole();
				if (result == 1) {
					active = true;
					break;
				}
				else if (result == 0) {
					active = false;
					break;
				}
				else {
					std::cout << "Invalid number!" << std::endl;
				}
			}

			_fleet->get(selected)->setActive(active);
		}

		std::cout << "Car has been updated!";

	}
	else {
		std::cout << "Car not found!";
	}
}

//Slouží pro odebrání auta ze seznamu Fleet
void Cmd::removeCar()
{
	std::cout << "<<DELETE>>" << std::endl << "Please insert index of car: (starting from 0)" << std::endl;
	int choice = this->getIntFromConsole();
	if (choice <= _fleet->getSize() && choice >= 0) {
		_fleet->remove(choice);
	}
	else {
		std::cout << "Out of range!" << std::endl;
	}
}

//Slouží pro zobrazení auta 
void Cmd::showCar(int index)
{
	int size = _fleet->getSize();
	if (index <= size && index >= 0) {
		Car* car = _fleet->get(index);
		std::cout << "-----------------------------" << std::endl;
		std::cout << "Manufacturer: " << car->getManufacturer() << std::endl;
		std::cout << "Model: " << car->getModel() << std::endl;
		std::cout << "Colour: " << car->getColour() << std::endl;
		std::cout << "Model year: " << car->getPrice() << std::endl;

		std::cout << "Wheel types: " << std::endl;
		auto wheelTypes = car->getWheelTypes();
		for (int wheelId = 0; wheelId < wheelTypes->getSize(); wheelId++) {
			std::cout << wheelTypes->getElementAt(wheelId) << std::endl;
		}

		Weights weights = car->getWeights();
		std::cout << "Weights:" << std::endl;
		std::cout << "Allowed:" << car->getAllowedWeight() << std::endl;
		std::cout << "Operating:" << car->getOperatingWeight() << std::endl;
		std::cout << "State:";
		if (car->getActive()) {
			std::cout << "true" << std::endl;
		}
		else {
			std::cout << "false" << std::endl;
		}
	}
	else {
		std::cout << "Car not found!";
	}
}

//Slouží pro zobrazení všech vozù
void Cmd::showAllCars()
{
	if (_fleet->getSize() > 0) {
		for (int i = 0; i < _fleet->getSize(); i++)
		{
			std::cout << "-----------------------------" << std::endl;
			std::cout << "Car no. " << i << std::endl;
			showCar(i);
		}
	}
	else {
		std::cout << "Your fleet is empty!" << std::endl;
	}
}

//Slouží pro zobrazení menu
void Cmd::displayMenu()
{
	std::cout << "--------------MENU---------------" << std::endl;
	std::cout << "Please select item:\n";
	std::cout << "1) Create car\n";
	std::cout << "2) Update car\n";
	std::cout << "3) Remove car\n";
	std::cout << "4) Show all cars\n";
	std::cout << "5) Read JSON\n";
	std::cout << "6) Save JSON\n";
	std::cout << "0) Close App\n";
	std::cout << "Please select: ";
	try
	{
		_selectedIndex = this->getIntFromConsole();
		std::cout << "---------------------------------" << std::endl;
		this->doIt();
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}
}

//Slouží pro naètení souboru
void Cmd::readFile()
{
	std::cout << "Reading JSON \"fleet.json\"" << std::endl;
	_fleet->load("fleet.json");
}

//Slouží pro uložení souboru
void Cmd::saveFile()
{
	std::cout << "Saving JSON \"fleet.json\"" << std::endl;
	_fleet->save("fleet.json");
}

//Slouží pro provedení akce
void Cmd::doIt()
{
	switch (this->_selectedIndex)
	{
	case 1:
		this->addCar();
		break;
	case 2:
		this->updateCar();
		break;
	case 3:
		this->removeCar();
		break;
	case 4:
		this->showAllCars();
		break;
	case 5:
		this->readFile();
		break;
	case 6:
		this->saveFile();
		break;
	case 0:
		this->run = false;
		break;
	default:
		std::cout << "Option not found!";
		break;
	}
}

//Pomocná mentoda pro naèítaní int z console
int Cmd::getIntFromConsole()
{
	int choice = 0;
	while (!(std::cin >> choice)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	return choice;
}

