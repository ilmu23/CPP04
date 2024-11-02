// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<Brain.cpp>>

#include <iostream>
#include "Brain.hpp"

static const std::string	_huh = "huh";

Brain::Brain(void): _i(0)
{
	std::cout << "Brain constructor called\n";
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor called\n";
	*this = copy;
}

Brain	&Brain::operator=(const Brain &copy)
{
	size_t	i;

	std::cout << "Brain copy assignment overload called\n";
	for (i = 0; i < _MAX_IDEAS && i < copy._i; i++)
		this->_ideas[i] = copy._ideas[i];
	this->_i = copy._i;
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called\n";
}

// get

const std::string	&Brain::getIdea(const size_t &i) const
{
	if (this->_i == 0)
		return _huh;
	return (i <= this->_i) ? this->_ideas[i] : this->_ideas[this->_i];
}

const size_t	&Brain::getIdeaCount(void) const
{
	return this->_i;
}

// misc

void	Brain::addIdea(const std::string &idea)
{
	this->_ideas[this->_i] = idea;
	if (this->_i < _MAX_IDEAS - 1)
		this->_i++;
}

void	Brain::removeIdea(void)
{
	if (this->_i > 0)
		this->_i--;
}

void	Brain::shareIdeas(void) const
{
	size_t	i;

	if (this->_i == 0)
		std::cout << "huh\n";
	else for (i = 0; i < _MAX_IDEAS && i < this->_i; i++)
		std::cout << "idea " << i << ": " << this->_ideas[i] << "\n";
}
