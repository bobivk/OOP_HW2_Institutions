#pragma once
#include "Institution.h"
#include"Group.h"
#include<vector>
class Organization :
	public Institution
{
private:
	vector<Institution*> institutions;
	string address;
	
	bool invalid_institutions_enabled{ false };
public:
	Organization(string name, vector<Institution*> in_institutions, string address);
	Organization(const Organization&);
	Organization& operator=(const Organization&);

	void add_institution(Institution*);
	void toggle_invalid_institutions();

	Payer* associated_payer() const override;
	unsigned associated_users_count() const override;
	bool has_member(const Person&) const override;
	bool is_valid() const override;
};

