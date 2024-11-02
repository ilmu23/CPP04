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
#include "WrongCat.hpp"
#include <iostream>

int32_t	main(void)
{
	const Animal		*a = new Animal();
	const Animal		*c = new Cat();
	const Animal		*d = new Dog();
	const WrongAnimal	*wa = new WrongAnimal();
	const WrongAnimal	*wc = new WrongCat();

	std::cout << c->getType() << "\n";
	std::cout << d->getType() << "\n";

	a->makeSound();
	c->makeSound();
	d->makeSound();

	wa->makeSound();
	wc->makeSound();

	delete wc;
	delete wa;

	delete d;
	delete c;
	delete a;

	return 0;
}
