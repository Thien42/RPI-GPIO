#include <iostream>
#include "../include/GPIO.hh"

int main(int ac, char **av) {
	if (RPI::GPIO::init() == false) return (1);
	return (0);
}
