#pragma once
#include<string>
class Person
{
private:
	std::string name;
	unsigned insurance_id;
public:
	Person(std::string name, unsigned id);
	unsigned get_insurance_id() const;
};

