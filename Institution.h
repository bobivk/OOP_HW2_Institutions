#pragma once
#include<string>
#include<vector>
#include<iostream>
#include"Person.h"
#include"Payer.h"
using namespace std;

class Institution
{
protected:
	std::string name;
	unsigned id;
	unsigned get_new_id();
public:
	Institution(string name);
	Institution(const Institution&);
	Institution& operator=(const Institution&);
	unsigned get_id();
	static unsigned institution_last_id;
	
	virtual bool has_member(const Person&) const = 0;
	virtual Payer* associated_payer() const = 0;
	virtual unsigned associated_users_count() const = 0;
	virtual bool is_valid() const = 0;

	virtual ~Institution() = default;
};

