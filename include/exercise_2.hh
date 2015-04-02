#ifndef __EXERCICE_2_HH_
#define __EXERCICE_2_HH_

#include "Exercise.hh"
#include "GPIO.hh"

class exercise_2 : public Test::Exercise {
public:
	exercise_2();
	virtual ~exercise_2();
	virtual void run(void);
private:
	RPI::GPIO *led1;
	RPI::GPIO *led2;
	RPI::GPIO *led3;
	RPI::GPIO *button;
};

#endif /* __EXERCICE_1_HH_ */
