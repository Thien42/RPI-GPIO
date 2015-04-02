#include "Factory.hh"
#include "exercise_1.hh"
#include "exercise_2.hh"

Test::Exercise *Factory::create(const std::string &name) {
	if (name == "1") return (new exercise_1());
	else if (name == "2") return (new exercise_2());
	else return (NULL);
}
