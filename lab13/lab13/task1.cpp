#include "task1.h"

Mammal::Mammal(void) :itsAge(1)
{
	cout << "Mammal constructor..." << endl;
}

Mammal::~Mammal(void)
{
	cout << "Mammal destructor..." << endl;
}

void Mammal::Move() const
{
	cout << "Mammal moves a step!" << endl;
}

void Mammal::Speak() const
{
	cout << "What does a mammal speak? Mammilian!" << endl;
}

Dog::Dog() {
	cout << "Dog constructor" << endl;
}

Dog::~Dog() {
	cout << "Dog Destroyer!" << endl;
}

void Dog::Move() const {
	cout << "Dog puts his best paw forward." << endl;
}

void Dog::Speak() const {
	cout << "Bork!" << endl;
}

Cat::Cat() {
	cout << "Cat constructor" << endl;
}

Cat::~Cat() {
	cout << "Cat destructor" << endl;
}

void Cat::Move() const {
	cout << "Cat moves forward" << endl;
}

void Cat::Speak() const {
	cout << "MEOW" << endl;
}

Horse::Horse() {
	cout << "Constructing a horse" << endl;
}

Horse::~Horse() {
	cout << "Sending to glue factory." << endl;
}

void Horse::Move() const {
	cout << "horse gallops once" << endl;
}

void Horse::Speak() const {
	cout << "neigh" << endl;
}

GuineaPig::GuineaPig() {
	cout << "Assembling guinea pig" << endl;
}

GuineaPig::~GuineaPig() {
	cout << "Sending guinea pig back to New Guinea." << endl;
}

void GuineaPig::Move() const {
	cout << "Guinea pig waddles forward" << endl;
}

void GuineaPig::Speak() const {
	cout << "*guinea pig noise*" << endl;
}
