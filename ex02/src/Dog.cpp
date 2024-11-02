// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<Dog.cpp>>

#include <iostream>
#include "Dog.hpp"

Dog::Dog(void): Animal(), _brain(new Brain())
{
	this->_type = "Dog";
	std::cout << "Dog constructor called\n";
}

Dog::Dog(const Dog &copy): Animal(copy)
{
	std::cout << "Dog copy constructor called\n";
	*this = copy;
}

Dog	&Dog::operator=(const Dog &copy)
{
	std::cout << "Dog copy assignment overload called\n";
	if (this != &copy) {
		delete this->_brain;
		this->_brain = new Brain(*copy._brain);
		this->_type = copy._type;
	}
	return *this;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called\n";
	delete this->_brain;
}

// get

const std::string	&Dog::getIdea(const size_t &i) const
{
	return this->_brain->getIdea(i);
}

const size_t	&Dog::getIdeaCount(void) const
{
	return this->_brain->getIdeaCount();
}

// misc

void	Dog::makeSound(void) const
{
	std::cout << "Dog noises\n";
}

void	Dog::addIdea(const std::string &idea)
{
	this->_brain->addIdea(idea);
}

void	Dog::removeIdea(void)
{
	this->_brain->removeIdea();
}

void	Dog::shareIdeas(void) const
{
	this->_brain->shareIdeas();
}
