#include <iostream>

class Animal
{
public:
	Animal()
	{
		std::cout << "Animal::Animal()" << std::endl;
	}
	virtual void move() = 0
		// Virtual enables the function to be defiend by the base class' derived classes
		// TODO: Find out how virtual functions work
	{
	}
	virtual ~Animal()
	{
		std::cout << "Animal::~Animal()" << std::endl;
	}
private:
	uint16_t m_age;	//TODO: Find out the difference between types
};

class Dog 
	: public Animal
{
public:
	Dog()
	{
		std::cout << "Dog::Dog()" << std::endl;
	}
	virtual void move()
	{
		std::cout << ":::Dog::move()" << std::endl;
	}
	void bark()
	{
	}
	virtual ~Dog()
	{
		std::cout << "Dog::~Dog()" << std::endl;
	}
};

class Cat
	: public Animal
{
public:
	Cat()
	{
		std::cout << "Cat::Cat()" << std::endl;
	}
	virtual void move()
	{
		std::cout << ":::Cat::move()" << std::endl;
	}
	virtual ~Cat()
	{
		std::cout << "Cat::~Cat()" << std::endl;
	}
};

Animal* createAnimal()
	// creates animal depending on the user's choice 
	// returns a pointer to the created animal
{
	Animal* animal{ nullptr };
	char c = 'd';

	std::cout << "What animal?: " << std::endl;
	std::cin >> c;

	if (c == 'd')
		animal = new Dog();
	else
		animal = new Cat();

	return animal;
}
int main()
{
	Animal* a {nullptr};
	a = createAnimal();
	a->move();

	// std::cout << sizeof(a) << std::endl;	// returns a value of the object in bytes
	delete a;
	std::cin.get();
}