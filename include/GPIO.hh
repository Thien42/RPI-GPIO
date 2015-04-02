#ifndef __GPIO_HH_
#define __GPIO_HH_

#include <string>

namespace RPI {
	class GPIO {
	public:
		GPIO(std::string const &name);
		~GPIO();
		int setdir(const std::string&);
		int setval(const std::string&);
		int getval(std::string&);
	private:
		int _export();
		int _unexport();
		static int write_action(const std::string&, const std::string&);
		static int read_action(const std::string&, std::string&);
		const std::string &gpionum;
	};
}
#endif /* __GPIO_HH_ */
