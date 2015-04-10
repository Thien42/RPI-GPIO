#ifndef __EXERCICE_0_HH_
#define __EXERCICE_0_HH_

#include "Exercise.hh"
#include "GPIO.hh"

class exercise_0 : public Test::Exercise {
public:
	exercise_0();
	virtual ~exercise_0();
	virtual void run(void);
private:
	RPI::GPIO *button1;
	RPI::GPIO *button2;
	RPI::GPIO *button3;
};

#endif /* __EXERCICE_1_HH_ */
