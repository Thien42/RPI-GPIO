#ifndef _FACTORY_HH_
#define _FACTORY_HH_

#include <string>
#include "Exercise.hh"

class Factory {
public:
	static Test::Exercise *create(std::string const&);
};

#endif /* _FACTORY_HH_ */
