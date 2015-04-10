#include "Exercise.hh"
#include "exercise_0.hh"
#include "GPIO.hh"
#include <iostream>

exercise_0::exercise_0() : Test::Exercise() {
	this->button1 = new RPI::GPIO(8);
	this->button1->setdir(RPI::GPIO::IN);
	this->button2 = new RPI::GPIO(9);
	this->button2->setdir(RPI::GPIO::IN);
	this->button3 = new RPI::GPIO(7);
	this->button3->setdir(RPI::GPIO::IN);
}

exercise_0::~exercise_0() {
	delete this->button1;
	delete this->button2;
	delete this->button3;
}

void exercise_0::run() {
	while (true) {
		usleep(500000);
		if (button1->getstate() == RPI::GPIO::CLOSED) {
			std::cout << "Button 1 pressed" << std::endl;
		}
		if (button2->getstate() == RPI::GPIO::CLOSED) {
			std::cout << "Button 2 pressed" << std::endl;
		}
		if (button3->getstate() == RPI::GPIO::CLOSED) {
			std::cout << "Button 3 pressed" << std::endl;
		}
	}
}
