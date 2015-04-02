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

	int GPIO::read_action(const std::string &path, std::string &ret) {
		std::ifstream import_stream(path.c_str());
		if (import_stream.is_open()) {
			import_stream >> ret;
			if (ret != "0") ret = "1";
			import_stream.close();
			return (0);
		} else {
			std::cerr << "Unable to read from " << path << std::endl;
			return (-1);
		}
	}

	int GPIO::_export() const {
		return (GPIO::write_action("/sys/class/gpio/export", this->gpionum));
	}

	int GPIO::_unexport() const {
		return (GPIO::write_action("/sys/class/gpio/unexport", this->gpionum));
	}

	int GPIO::setdir(const std::string &dir) const {
		return (GPIO::write_action("/sys/class/gpio/gpio" + this->gpionum + "/direction", dir));
	}

	int GPIO::setval(const std::string &value) const {
		return (GPIO::write_action("/sys/class/gpio/gpio" + this->gpionum + "/value", value));
	}

	int GPIO::getval(std::string &val) const {
		return (GPIO::read_action("/sys/class/gpio/gpio" + this->gpionum + "/value", val));
	}
}
