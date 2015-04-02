#include "Exercise.hh"
#include "exercise_2.hh"
#include "GPIO.hh"

exercise_2::exercise_2() : Test::Exercise() {
	/* LEDS initialization */
	this->led1 = new RPI::GPIO("4");
	this->led1->setdir("out");
	this->led2 = new RPI::GPIO("14");
	this->led2->setdir("out");
	this->led3 = new RPI::GPIO("18");
	this->led3->setdir("out");

	/* Buttons initialization */
	this->button = new RPI::GPIO("17");
	this->button->setdir("in");
}

exercise_2::~exercise_2() {
	delete this->led1;
	delete this->led2;
	delete this->led3;
	delete this->button;
}

void exercise_2::run() {
	std::string val;
	bool is_running = false;

	while (true) {
		usleep(50000);
		button->getval(val);
		if (val != "0") {
			is_running = !is_running;
			if (is_running == false) {
				led1->setval("0");
				led2->setval("0");
				led3->setval("0");
			}
		}
		if (is_running) {
			led1->setval("1");
			usleep(50000);
			led1->setval("0");
			led2->setval("1");
			usleep(50000);
			led2->setval("0");
			led3->setval("1");
			usleep(50000);
			led3->setval("0");
		}
	}
}
