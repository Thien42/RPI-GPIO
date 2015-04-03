#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "../include/GPIO.hh"

namespace RPI {
	GPIO::GPIO(std::string const &name) : gpionum(name)
	{
		this->_export();
	}

	GPIO::~GPIO() {
		this->_unexport();
	}

	bool GPIO::init(void) {
		if (getuid() != 0) {
			std::cout << "You do not seem to have root privileges, please run this program as root user" << std::endl;
			return (false);
		} else return (true);
	}

	int GPIO::write_action(const std::string &path, const std::string &value) {
		std::ofstream export_stream(path.c_str());
		if (export_stream.is_open()) {
			export_stream << value;
			export_stream.close();
			return (0);
		} else {
			std::cerr << "Unable to write value " << value << std::endl;
			return (-1);
		}
	}

	std::string GPIO::read_action(const std::string &path) {
		std::string ret;
		std::ifstream import_stream(path.c_str());
		if (import_stream.is_open()) {
			import_stream >> ret;
			if (ret != "0") ret = "1";
			import_stream.close();
			return (ret);
		} else {
			std::cerr << "Unable to read from " << path << std::endl;
			return ("");
		}
	}

	int GPIO::_export() const {
		return (GPIO::write_action("/sys/class/gpio/export", this->gpionum));
	}

	int GPIO::_unexport() const {
		return (GPIO::write_action("/sys/class/gpio/unexport", this->gpionum));
	}

	int GPIO::setdir(GPIO::DIRECTION dir) const {
		std::string val;
		if (dir == GPIO::OUT) val = "out";
		else val = "in";
		return (GPIO::write_action("/sys/class/gpio/gpio" + this->gpionum + "/direction", val));
	}

	int GPIO::setstate(GPIO::STATE state) const {
		std::string value;
		if (state == GPIO::CLOSED) value = "0";
		else value = "1";
		return (GPIO::write_action("/sys/class/gpio/gpio" + this->gpionum + "/value", value));
	}

	GPIO::STATE GPIO::getstate(void) const {
		std::string val = GPIO::read_action("/sys/class/gpio/gpio" + this->gpionum + "/value");
		if (val == "0") return (GPIO::CLOSED);
		else return (GPIO::OPEN);
	}
}
