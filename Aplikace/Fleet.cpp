
#include "Fleet.h"
#include <api.h>
#include <iostream>
#include <fstream>
#include <iostream>

//Destruktor
Fleet::~Fleet()
{
	for (int i = 0; i < cars.getSize(); i++) {
		Car* car = cars.getElementAt(i);
		delete(car);
	}
}

//Metoda pro pøidání vozu do vozového parku
void Fleet::add(Car* car)
{
	cars.append(car);
}

//Metoda pro získání velikosti vozového parku
int Fleet::getSize()
{
	return cars.getSize();
}

//Metoda pro získání vozu
Car* Fleet::get(int index)
{
	return cars.getElementAt(index);
}

//Metoda pro odebrání vozu
void Fleet::remove(int index)
{
	if (index < cars.getSize() && index >= 0) {
		Car* car = cars.getElementAt(index);
		cars.removeElementAt(index);
		delete(car);
	}
	else {
		throw std::exception("Car not found!");
	}
}

//Metoda pro uložení do soboru
void Fleet::save(std::string filename)
{
	if (cars.getSize() > 0) {
		ArrayValue jsonCars;

		for (int i = 0; i < cars.getSize(); i++) {
			Car* car = cars.getElementAt(i);
			ObjectValue* jsonCar = new ObjectValue{};
			jsonCar->append(KeyValuePair{ "manufacturer", new StringValue(car->getManufacturer()) });
			jsonCar->append(KeyValuePair{ "model", new StringValue(car->getModel()) });
			jsonCar->append(KeyValuePair{ "colour", new StringValue(car->getColour()) });
			jsonCar->append(KeyValuePair{ "price", new NumberValue(car->getPrice()) });

			auto wheelTypes = car->getWheelTypes();
			auto wheelTypesJson = new ArrayValue();
			for (int wheelId = 0; wheelId < wheelTypes->getSize(); wheelId++) {
				std::string wheelType = wheelTypes->getElementAt(wheelId);
				wheelTypesJson->append(new StringValue(wheelType));
			}
			jsonCar->append(KeyValuePair{ "wheelTypes", wheelTypesJson });

			auto weights = new ObjectValue();
			weights->append(KeyValuePair{ "allowed", new NumberValue(car->getWeights().allowed) });
			weights->append(KeyValuePair{ "operating", new NumberValue(car->getWeights().operating) });

			jsonCar->append(KeyValuePair{ "weights", weights });
			jsonCar->append(KeyValuePair{ "active", new BoolValue(car->getActive()) });
			jsonCars.append(jsonCar);
		}

		std::ofstream fl{};
		fl.open(filename);

		if (fl.is_open())
		{
			fl << JSON::serialize(&jsonCars);
		}
		else
		{
			throw std::exception("Cant't open the file!");
			return;
		}

		fl.close();

		std::cout << "Saved." << std::endl;
	}
	else {
		throw std::exception("Fleet is empty. Exiting....");
	}
}

//Metoda pro naètení ze souboru
void Fleet::load(std::string filename)
{
	try
	{
		//Delete before load
		if (cars.getSize() > 0) {
			while (cars.getSize() != 0)
			{
				this->remove(0);
			}
		}

		std::ifstream ifstr{};

		ifstr.open(filename);

		std::string value;

		ArrayValue* jsonCars;

		if (ifstr.fail())
		{
			ifstr.close();
			throw std::exception("Error ocured! Exiting...");
			return;
		}

		ifstr >> value;

		jsonCars = (ArrayValue*)JSON::deserialize(value);

		for (int i = 0; i < jsonCars->getSize(); i++) {
			ObjectValue* jsonCar = (ObjectValue*)jsonCars->getElementAt(i);

			Car* car = new Car();
			car->setManufacturer(jsonCar->get<StringValue>("manufacturer")->get());
			car->setModel(jsonCar->get<StringValue>("model")->get());
			car->setColour(jsonCar->get<StringValue>("colour")->get());
			car->setPrice((int)jsonCar->get<NumberValue>("price")->get());


			car->setWeights({
				(int)jsonCar->get<ObjectValue>("weights")->get<NumberValue>("allowed")->get(),
				(int)jsonCar->get<ObjectValue>("weights")->get<NumberValue>("operating")->get()
				});

			auto wheelJson = jsonCar->get<ArrayValue>("wheelTypes");
			auto wheelTypes = new DynamicArray<std::string>();

			for (int wheelId = 0; wheelId < wheelJson->getSize(); wheelId++) {
				wheelTypes->append(((StringValue*)wheelJson->getElementAt(wheelId))->get());
			}

			car->setWheelTypes(wheelTypes);

			car->setActive(jsonCar->get<BoolValue>("active")->get());

			add(car);
		}

		ifstr.close();

		std::cout << "Loaded." << std::endl;

		delete(jsonCars);
	}
	catch (const std::exception& ex)
	{
		throw std::exception(ex);
	}
}
