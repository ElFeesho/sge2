#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <string>

using std::string;

class Entity
{
public:
	Entity(const string &name);
	~Entity();

	void X(double x);
	void Y(double y);
	void W(double w);
	void H(double h);

	double X();
	double Y();
	double W();
	double H();

private:
	string name;
	double x, y;
	double w, h;
};

#endif