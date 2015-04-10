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
		GPIO(int);
		~GPIO();
		void setdir(GPIO::DIRECTION) const;
		void setstate(GPIO::STATE) const;
		GPIO::STATE getstate(void) const;
		static bool init(void);
	private:
		const int gpionum;
	};
}
#endif /* __GPIO_HH_ */
