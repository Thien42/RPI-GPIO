#ifndef __GPIO_HH_
#define __GPIO_HH_

#include <string>

namespace RPI {
	class GPIO {
	
	public:
		GPIO(std::string const &name);
		~GPIO();
		int setdir(const std::string&) const;
		int setval(const std::string&) const;
		int getval(std::string&) const;
		static bool init(void);
	private:
		int _export() const;
		int _unexport() const;
		static int write_action(const std::string&, const std::string&);
		static int read_action(const std::string&, std::string&);
		const std::string gpionum;
	};
}
#endif /* __GPIO_HH_ */
