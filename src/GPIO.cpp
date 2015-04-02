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

	int GPIO::_export() {
		static const std::string export_str = "/sys/class/gpio/export";
		return (GPIO::write_action(export_str, this->gpionum));
	}

	int GPIO::_unexport() {
		static const std::string export_str = "/sys/class/gpio/unexport";
		return (GPIO::write_action(export_str, this->gpionum));
	}

	int GPIO::setdir(const std::string &dir) {
		static const std::string export_str = "/sys/class/gpio/gpio" + this->gpionum + "/direction";
		return (GPIO::write_action(export_str, dir));
	}

	int GPIO::setval(const std::string &value) {
		static const std::string export_str = "/sys/class/gpio/gpio" + this->gpionum + "/value";
		return (GPIO::write_action(export_str, value));
	}

	int GPIO::getval(std::string &val) {
		static const std::string getval_str = "/sys/class/gpio/gpio" + this->gpionum + "/value";
		return (GPIO::read_action(getval_str, val));
	}
}
