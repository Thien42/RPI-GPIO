#include "Exercise.hh"
#include "exercise_2.hh"
#include "GPIO.hh"

exercise_2::exercise_2() : Test::Exercise() {
	/* LEDS initialization */
	this->led1 = new RPI::GPIO(4);
	this->led1->setdir(RPI::GPIO::OUT);
	this->led2 = new RPI::GPIO(14);
	this->led2->setdir(RPI::GPIO::OUT);
	this->led3 = new RPI::GPIO(18);
	this->led3->setdir(RPI::GPIO::OUT);

	/* Buttons initialization */
	this->button = new RPI::GPIO(17);
	this->button->setdir(RPI::GPIO::IN);
}

exercise_2::~exercise_2() {
	delete this->led1;
	delete this->led2;
	delete this->led3;
	delete this->button;
}

void exercise_2::run() {
	bool is_running = false;
	RPI::GPIO::STATE val;

	while (true) {
		usleep(50000);
		val = button->getstate();
		if (val == RPI::GPIO::OPEN) {
			is_running = !is_running;
			if (is_running == false) {
				led1->setstate(RPI::GPIO::CLOSED);
				led2->setstate(RPI::GPIO::CLOSED);
				led3->setstate(RPI::GPIO::CLOSED);
			}
		}
		if (is_running) {
			led1->setstate(RPI::GPIO::OPEN);
			usleep(50000);
			led1->setstate(RPI::GPIO::CLOSED);
			led2->setstate(RPI::GPIO::OPEN);
			usleep(50000);
			led2->setstate(RPI::GPIO::CLOSED);
			led3->setstate(RPI::GPIO::OPEN);
			usleep(50000);
			led3->setstate(RPI::GPIO::CLOSED);
		}
	}
}
