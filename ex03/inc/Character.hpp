// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<Character.hpp>>

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

# define _INVENTORY_SIZE 4
# define _FLOOR_SIZE 256

class Character: public ICharacter
{
	private:

		uint8_t		_i;
		std::string	_name;
		AMateria	*_inventory[_INVENTORY_SIZE];
		AMateria	*_floor[_FLOOR_SIZE];

		// misc

		void	cleanFloor(void);

	public:

		Character(void) = delete;
		Character(const std::string &name);
		Character(const Character &copy);
		Character &operator=(const Character &copy);
		~Character(void);

		// get

		const std::string	&getName(void) const;

		// misc

		void	equip(AMateria *m);
		void	unequip(uint8_t id);
		void	use(uint8_t id, ICharacter &target);
};

#endif
