// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<MateriaSource.hpp>>

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

# define _DEF_ARRSIZE 8

class MateriaSource: public IMateriaSource
{
	private:

		size_t		_arrsize;
		size_t		_materiacount;
		AMateria	**_arr;

	public:

		MateriaSource(void);
		MateriaSource(const MateriaSource &copy) = delete;
		MateriaSource &operator=(const MateriaSource &copy) = delete;
		~MateriaSource(void);

		// misc

		AMateria	*createMateria(const std::string &type);
		void		learnMateria(AMateria *m);
};

#endif
