#ifndef __EXERCISE_HH_
#define __EXERCISE_HH_

namespace Test {
	class Exercise {
	public:
		virtual ~Exercise() {}
		virtual void run(void) = 0;
	};
}

#endif /* __EXERCISE_HH_ */
