#include "Person.h"
Person::Person(std::string in_name, unsigned in_id) :
	name{ in_name },
	insurance_id{ in_id }{}

unsigned Person::get_insurance_id() const {
	return insurance_id;
}