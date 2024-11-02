// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<Brain.hpp>>

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

# define _MAX_IDEAS 100

class Brain
{
	private:

		std::string	_ideas[_MAX_IDEAS];
		size_t		_i;

	public:

		Brain(void);
		Brain(const Brain &copy);
		Brain &operator=(const Brain &copy);
		~Brain(void);

		// get

		const std::string	&getIdea(const size_t &i) const;
		const size_t		&getIdeaCount(void) const;

		// misc

		void	addIdea(const std::string &idea);
		void	removeIdea(void);
		void	shareIdeas(void) const;
};

#endif
