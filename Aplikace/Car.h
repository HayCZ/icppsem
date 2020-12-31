#pragma once
#include <api.h>

struct Weights {
	int allowed;
	int operating;
};

class Car {
public:
	Car();
	Car(std::string manufacturer, std::string model, std::string colour, int price, DynamicArray<std::string>* whellTypes, Weights weights, bool active);
	~Car();

	//Serialize/deserialize
	Value* convertToObject();
	std::string serialize(Car* car);

	//GET
	std::string getManufacturer();
	std::string getModel();
	std::string getColour();
	int getPrice();
	DynamicArray<std::string>* getWheelTypes();
	Weights getWeights();
	int getAllowedWeight();
	int getOperatingWeight();
	bool getActive();

	//SET
	void setManufacturer(std::string manufacturer);
	void setModel(std::string model);
	void setColour(std::string colour);
	void setPrice(int price);
	void setWheelTypes(DynamicArray<std::string>* whellTypes);
	void setWeights(Weights weights);
	void setActive(bool state);

private:
	std::string _manufacturer;
	std::string _model;
	std::string _colour;

	int _price;

	DynamicArray<std::string>* _wheelTypes;
	Weights _weights;

	bool _active;
};