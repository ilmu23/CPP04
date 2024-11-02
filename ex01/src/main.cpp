// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<main.cpp>>

#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

#define ARRSIZE 4
#define SGR_FG42 "\e[38;5;42m"
#define SGR_RESET "\e[m"

int32_t	main(void)
{
	size_t	i;
	Animal	*arr[ARRSIZE];
	Cat		*catp;
	Cat		cat;
	Dog		dog;

	std::cout << SGR_FG42 << "Creating animal array" << SGR_RESET << "\n";
	for (i = 0; i < ARRSIZE; i++) {
		arr[i] = (i & 1) ? (Animal *)new Dog() : (Animal *)new Cat();
		arr[i]->makeSound();
	}

	std::cout << SGR_FG42 << "Freeing animal array" << SGR_RESET << "\n";
	for (i = 0; i < ARRSIZE; i++)
		delete arr[i];

	std::cout << SGR_FG42 << "Creating more animals" << SGR_RESET << "\n";
	catp = new Cat();
	catp->addIdea("neovim");
	cat = *catp;
	cat.addIdea("death to emacs");

	std::cout << SGR_FG42 << "Idea counts" << SGR_RESET << "\n";
	std::cout << "catp: " << catp->getIdeaCount() << "\n";
	std::cout << "cat: " << cat.getIdeaCount() << "\n";
	std::cout << "dog: " << dog.getIdeaCount() << "\n";

	std::cout << SGR_FG42 << "Ideas" << SGR_RESET << "\n";
	std::cout << "catp:\n";
	catp->shareIdeas();
	delete catp;
	std::cout << "cat:\n";
	cat.shareIdeas();
	std::cout << "dog:\n";
	dog.shareIdeas();

	return 0;
}
