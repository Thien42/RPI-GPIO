#include <iostream>
#include <signal.h>
#include "Exercise.hh"
#include "GPIO.hh"
#include "Factory.hh"

Test::Exercise *ex;

void sig_handler(int)
{
	std::cout << "Ctrl^C pressed in sig handler" << std::endl;
	delete ex;
}

void set_signal(void) {
	struct sigaction sig_struct;

	sig_struct.sa_handler = sig_handler;
	sig_struct.sa_flags = 0;
	sigemptyset(&sig_struct.sa_mask);
	if (sigaction(SIGINT, &sig_struct, NULL) == -1) std::cerr << "Problem with sigaction" << std::endl;
}

int main(int ac, char **av) {
	set_signal();
	if (RPI::GPIO::init() == false) return (1);
	if (ac >= 2) {
		ex = Factory::create(av[1]);
		if (ex) {
			std::cout << "Lancement de l'exercice" << av[1] << std::endl;
			ex->run();
			delete ex;
		} else std::cout << "L'exercice " << av[1] << " n'existe pas ! :(" << std::endl;
	} else std::cout << "Aucun exemple selectionne !" << std::endl;
	return (0);
}
