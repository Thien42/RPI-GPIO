#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <wiringPi.h>
#include "GPIO.hh"

namespace RPI {
	GPIO::GPIO(int num) : gpionum(num)
	{
	}

	GPIO::~GPIO() {
	}

	bool GPIO::init(void) {
		if (getuid() != 0) {
			std::cerr << "You do not seem to have root privileges, please run this program as root user" << std::endl;
			return (false);
		} else if (wiringPiSetup() == -1) {
			std::cerr << "Failed to initialize GPIO" << std::endl;
			return (false);
		} else return (true);
	}

	void GPIO::setdir(GPIO::DIRECTION dir) const {
		if (dir == OUT) pinMode(this->gpionum, OUTPUT);
		else pinMode(this->gpionum, INPUT);
	}

	void GPIO::setstate(GPIO::STATE state) const {
		digitalWrite(this->gpionum, state);
	}

	GPIO::STATE GPIO::getstate(void) const {
		int ret = digitalRead(this->gpionum);
		if (ret == HIGH) return (OPEN);
		else return (CLOSED);
	}
}
