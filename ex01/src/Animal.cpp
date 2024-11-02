// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<Animal.cpp>>

#include <iostream>
#include "Animal.hpp"

Animal::Animal(void): _type("Animal")
{
	std::cout << "Animal constructor called\n";
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor called\n";
	*this = copy;
}

Animal	&Animal::operator=(const Animal &copy)
{
	std::cout << "Animal copy assignment overload called\n";
	this->_type = copy._type;
	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called\n";
}

const std::string	&Animal::getType(void) const
{
	return this->_type;
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal noises\n";
}
