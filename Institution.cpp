#include "Institution.h"
Institution::Institution(string in_name) :
	id{ get_new_id() },
	name{ in_name }{}

Institution::Institution(const Institution& other) : id{ other.id } {}

Institution& Institution::operator=(const Institution& other) {
	id = other.id;
	name = other.name;
	return *this;
}
unsigned Institution::get_id() {
	return id;
}

unsigned Institution::get_new_id() {
	return ++institution_last_id;
}
unsigned Institution::institution_last_id{ 0 };