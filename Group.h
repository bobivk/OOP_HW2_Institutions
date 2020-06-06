#pragma once
#include "Institution.h"
class Group :
	public Institution
{
private:
	unsigned group_id;
	vector<unsigned> person_id_list;
	Payer* payer;

public:
	Group(string name, unsigned in_group_id, Payer* p = nullptr);
	Group(const Group&);
	Group& operator=(const Group&);
	void add_member_by_id(unsigned id);
	bool has_member(const Person&) const override;
	Payer* associated_payer() const override;
	unsigned associated_users_count() const override;
	bool is_valid() const override;
};

