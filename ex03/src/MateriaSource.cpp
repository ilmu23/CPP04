// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<MateriaSource.cpp>>

#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(void): _arrsize(_DEF_ARRSIZE),
	_materiacount(0), _arr(new AMateria*[_DEF_ARRSIZE]) {}

MateriaSource::~MateriaSource()
{
	size_t	i;

	for (i = 0;  i < this->_materiacount; i++)
		delete this->_arr[i];
	delete[] this->_arr;
}

// misc

AMateria	*MateriaSource::createMateria(const std::string &type)
{
	size_t	i;

	for (i = 0; i < this->_materiacount; i++)
		if (this->_arr[i]->getType() == type)
			break ;
	return (i < this->_materiacount) ? this->_arr[i]->clone() : nullptr;
}

void	MateriaSource::learnMateria(AMateria *m)
{
	size_t		i;
	AMateria	**arr;

	for (i = 0; i < this->_materiacount; i++)
		if (this->_arr[i]->getType() == m->getType())
			return ;
	if (this->_materiacount == this->_arrsize) {
		arr = new AMateria*[this->_arrsize * 2];
		for (i = 0; i < this->_materiacount; i++)
			arr[i] = this->_arr[i];
		this->_arrsize *= 2;
		delete[] this->_arr;
		this->_arr = arr;
	}
	this->_arr[this->_materiacount++] = m;
}
