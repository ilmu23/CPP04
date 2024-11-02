// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<Cat.cpp>>

#include <iostream>
#include "Cat.hpp"

Cat::Cat(void): Animal(), _brain(new Brain())
{
	this->_type = "Cat";
	std::cout << "Cat constructor called\n";
}

Cat::Cat(const Cat &copy): Animal(copy)
{
	std::cout << "Cat copy constructor called\n";
	*this = copy;
}

Cat	&Cat::operator=(const Cat &copy)
{
	std::cout << "Cat copy assignment overload called\n";
	if (this != &copy) {
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);
		this->_type = copy._type;
	}
	return *this;
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called\n";
	delete this->_brain;
}

// get

const std::string	&Cat::getIdea(const size_t &i) const
{
	return this->_brain->getIdea(i);
}

const size_t	&Cat::getIdeaCount(void) const
{
	return this->_brain->getIdeaCount();
}

// misc

void	Cat::makeSound(void) const
{
	std::cout << "Cat noises\n";
}

void	Cat::addIdea(const std::string &idea)
{
	this->_brain->addIdea(idea);
}

void	Cat::removeIdea(void)
{
	this->_brain->removeIdea();
}

void	Cat::shareIdeas(void) const
{
	this->_brain->shareIdeas();
}
