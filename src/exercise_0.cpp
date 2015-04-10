#include "Exercise.hh"
#include "exercise_0.hh"
#include "GPIO.hh"
#include <iostream>

exercise_0::exercise_0() : Test::Exercise() {
	this->button = new RPI::GPIO(8);
	this->button->setdir(RPI::GPIO::IN);
}

exercise_0::~exercise_0() {
	delete this->button;
}

void exercise_0::run() {
	RPI::GPIO::STATE val;

	while (true) {
		usleep(500000);
		val = button->getstate();
		if (val == RPI::GPIO::OPEN) {
			std::cout << "Button released" << std::endl;
		} else {
			std::cout << "Button pressed" << std::endl;
		}
	}
}
