#pragma once
#include "Car.h"

Car::Car()
{
}

Car::Car(std::string manufacturer, std::string model, std::string colour, int price, DynamicArray<std::string>* whellTypes, Weights weights, bool active)
{
	this->_manufacturer = manufacturer;
	this->_model = model;
	this->_colour = colour;
	this->_price = price;
	this->_wheelTypes = whellTypes;
	this->_weights = weights;
	this->_active = active;
}

Car::~Car()
{
	delete(_wheelTypes);
}

Value* Car::convertToObject()
{
	return nullptr;
}

std::string Car::serialize(Car* car)
{
	return std::string();
}

std::string Car::getModel() {
	return _model;
}

std::string Car::getColour()
{
	return _colour;
}

int Car::getPrice()
{
	return _price;
}

DynamicArray<std::string>* Car::getWheelTypes()
{
	return _wheelTypes;
}

Weights Car::getWeights()
{
	return _weights;
}

int Car::getAllowedWeight()
{
	return 	this->getWeights().allowed;
}

int Car::getOperatingWeight()
{
	return this->getWeights().operating;
}

bool Car::getActive()
{
	return _active;
}

std::string Car::getManufacturer()
{
	return _manufacturer;
}

void Car::setManufacturer(std::string manufacturer)
{
	this->_manufacturer = manufacturer;
}

void Car::setModel(std::string model)
{
	this->_model = model;
}

void Car::setColour(std::string colour)
{
	this->_colour = colour;
}

void Car::setPrice(int price)
{
	this->_price = price;
}

void Car::setWheelTypes(DynamicArray<std::string>* wheelTypes)
{
	this->_wheelTypes = wheelTypes;
}

void Car::setWeights(Weights weights)
{
	this->_weights = weights;
}

void Car::setActive(bool state)
{
	this->_active = state;
}
