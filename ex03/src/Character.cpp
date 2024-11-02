// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<Character.cpp>>

#include "Character.hpp"
#include "ICharacter.hpp"

Character::Character(const std::string &name): _i(0), _name(name)
{
	size_t	i;

	for (i = 0; i < _INVENTORY_SIZE; i++)
		this->_inventory[i] = nullptr;
	for (i = 0; i < _FLOOR_SIZE; i++)
		this->_floor[i] = nullptr;
}

Character::Character(const Character &copy)
{
	*this = copy;
}

Character	&Character::operator=(const Character &copy)
{
	size_t	i;

	if (this == &copy)
		return *this;
	this->cleanFloor();
	for (i = 0; i < _INVENTORY_SIZE; i++) {
		if (this->_inventory[i] != nullptr)
			delete this->_inventory[i];
		this->_inventory[i] = copy._inventory[i]->clone();
	}
	for (i = 0; i < copy._i; i++)
		this->_floor[i] = copy._floor[i]->clone();
	this->_name = copy._name;
	this->_i = copy._i;
	return *this;
}

Character::~Character(void)
{
	size_t	i;

	for (i = 0; i < _INVENTORY_SIZE; i++)
		if (this->_inventory[i] != nullptr)
			delete this->_inventory[i];
	for (i = 0; i < this->_i; i++)
		delete this->_floor[i];
}

// get

const std::string	&Character::getName(void) const
{
	return this->_name;
}

// misc

void	Character::cleanFloor(void)
{
	size_t	i;

	for (i = 0; i < _FLOOR_SIZE; i++) {
		delete this->_floor[i];
		this->_floor[i] = nullptr;
	}
	this->_i = 0;
}

void	Character::equip(AMateria *m)
{
	size_t	i;

	if (!m)
		return ;
	for (i = 0; i < _INVENTORY_SIZE; i++)
		if (this->_inventory[i] == nullptr)
			break ;
	if (i < _INVENTORY_SIZE)
		this->_inventory[i] = m;
	else
		delete m;
}

void	Character::unequip(uint8_t id)
{
	if (id < _INVENTORY_SIZE && this->_inventory[id] != nullptr) {
		this->_floor[this->_i++] = this->_inventory[id];
		this->_inventory[id] = nullptr;
	}
	if (this->_i == 0)
		this->cleanFloor();
}

void	Character::use(uint8_t id, ICharacter &target)
{
	if (id < _INVENTORY_SIZE && this->_inventory[id] != nullptr)
		this->_inventory[id]->use(target);
}
