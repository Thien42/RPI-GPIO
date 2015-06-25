#include "Exercise.hh"
#include "exercise_1.hh"
#include "GPIO.hh"
#include <iostream>

exercise_1::exercise_1() : Test::Exercise() {
	/* LEDS ini00tialization */
	this->led1 = new RPI::GPIO(0);
	this->led1->setdir(RPI::GPIO::OUT);
	this->led2 = new RPI::GPIO(1);
	this->led2->setdir(RPI::GPIO::OUT);
	this->led3 = new RPI::GPIO(2);
	this->led3->setdir(RPI::GPIO::OUT);

	/* Buttons initialization */
	this->button = new RPI::GPIO(8);
	this->button->setdir(RPI::GPIO::IN);
}

exercise_1::~exercise_1() {
	delete this->led1;
	delete this->led2;
	delete this->led3;
	delete this->button;
}

void exercise_1::run() {
	bool is_running = false;
	RPI::GPIO::STATE val;
	while (true) {
		usleep(500000);
		val = button->getstate();
		if (val == RPI::GPIO::CLOSED) {
		  std::cout << "button pressed" << std::endl;
			is_running = !is_running;
			if (is_running) {
				led1->setstate(RPI::GPIO::OPEN);
				led2->setstate(RPI::GPIO::OPEN);
				led3->setstate(RPI::GPIO::OPEN);
			} else {
				led1->setstate(RPI::GPIO::CLOSED);
				led2->setstate(RPI::GPIO::CLOSED);
				led3->setstate(RPI::GPIO::CLOSED);
			}
		}
	}
}
