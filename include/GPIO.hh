#ifndef __GPIO_HH_
#define __GPIO_HH_

#include <string>

namespace RPI {
	class GPIO {
	public:
		enum DIRECTION {
			OUT = 0,
			IN = 1
		};
		enum STATE {
			CLOSED = 0,
			OPEN = 1
		};
		GPIO(std::string const &name);
		~GPIO();
		int setdir(GPIO::DIRECTION) const;
		int setstate(GPIO::STATE) const;
		GPIO::STATE getstate(void) const;
		static bool init(void);
	private:
		int _export() const;
		int _unexport() const;
		static int write_action(const std::string&, const std::string&);
		static std::string read_action(const std::string&);
		const std::string gpionum;
	};
}
#endif /* __GPIO_HH_ */
