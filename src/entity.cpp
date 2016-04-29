#include "entity.hpp"

Entity::Entity(const string &name) : name(name)
{

}

Entity::~Entity()
{

}

string Entity::getName()
{
	return name;
}

void Entity::X(double x) 
{
	this->x = x;
}

void Entity::Y(double y)
{
	this->y = y;
}

void Entity::W(double w) 
{
	this->w = w;
}

void Entity::H(double h)
{
	this->h = h;
}

double Entity::X()
{
	return x;
}

double Entity::Y()
{
	return y;
}

double Entity::W()
{
	return w;
}

double Entity::H()
{
	return h;
}