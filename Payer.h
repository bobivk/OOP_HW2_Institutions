#pragma once
#include<string>
class Payer
{
private:
	std::string name;
	bool (*payer_member_rule)(unsigned group_id, unsigned insurance_id);

public:
	Payer(std::string name, bool (*payer_member_rule)(unsigned group_id, unsigned insurance_id));
	Payer(const Payer&) = delete;
	Payer& operator=(const Payer&) = delete;
	bool operator==(const Payer&) const;
	bool rule(unsigned group_id, unsigned insurance_id);
	std::string get_name() const;
};