#pragma once

#include <iostream>

using std::cout;
using std::endl;

class Mammal
{
public:
	Mammal(void);
	~Mammal(void);

	virtual void Move() const;
	virtual void Speak() const;

protected:
	int itsAge;
};

class Dog :public Mammal {
public:
	Dog();
	~Dog();

	void Move() const;
	void Speak() const;


private:
};

class Cat :public Mammal {
public:
	Cat();
	~Cat();

	void Move() const;
	void Speak() const;


private:
};

class Horse :public Mammal {
public:
	Horse();
	~Horse();

	void Move() const;
	void Speak() const;


private:
};

class GuineaPig :public Mammal {
public:
	GuineaPig();
	~GuineaPig();

	void Move() const;
	void Speak() const;


private:
};
