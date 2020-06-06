#include"Group.h"
#include"Person.h"
#include"Payer.h"
#include"Organization.h"
#include<algorithm>
#include<cassert>

vector<Institution*> clear_institutions(vector<Institution*> input) {
	vector<Institution*> result = input;
	//erase-remove idiom
	result.erase(std::remove_if(result.begin(), result.end(), [](Institution* i) -> bool {
		return i->is_valid();
		}), result.end());
	return result;
}

Institution* find_most_popular_institution(vector<Institution*> input) {
	unsigned max_users_count = 0;
	unsigned index_of_most_popular = 0;
	for (size_t i = 0; i < input.size(); ++i) {
		if (input[i]->associated_users_count() > max_users_count) {
			index_of_most_popular = i;
			max_users_count = input[i]->associated_users_count();
		}
	}
	return input[index_of_most_popular];
}

bool alianzrule(unsigned id1, unsigned id2) {
	return (id1 + id2) % 10 == 0;
}
bool bulstradrule(unsigned id1, unsigned id2) {
	return (id1 - id2) % 10 == 0;
}

int main() {
	Payer alianz("Alianz", alianzrule);
	Payer bulstrad("Alianz", bulstradrule);

	Person ivan("Ivan Ivanov", 2046);
	Person mitko("Mitko Dimitrov", 3046);

	Group g1("g1", 2020);
	assert(g1.get_id() == 1); //institution_id != group_id
	assert(g1.associated_payer() == nullptr);
	Group g2("g2", 2021, &alianz);
	assert(g2.associated_payer() == &alianz);
	Group g3("g3", 2022, &bulstrad);
	Group g4("g4", 2023, &alianz);

	g1.add_member_by_id(2046);
	assert(g1.has_member(ivan));

	vector<Institution*> institutions;
	institutions.push_back(&g1);
	institutions.push_back(&g2);
	institutions.push_back(&g3);
	institutions.push_back(&g4);
	vector<Institution*> institutions2;

	Organization o1("o1", institutions, "Lulin 11");
	assert(o1.has_member(ivan)); //ivan is in g1 so he should be in o1
	assert(o1.associated_payer() == &alianz);
	assert(o1.get_id() == 5);

	Organization o2("o2", institutions2, "Mladost 6");
	o2.add_institution(&g1); //print message to console, g1 should not be added
	o2.toggle_invalid_institutions();
	o2.add_institution(&g1); //g1 should be added
	assert(o2.has_member(ivan));

	institutions.push_back(&o1);

	assert(o1.associated_payer() == &alianz);
	Organization o3("o3", institutions, "Drujba 7");
	assert(o3.associated_payer() == &alianz);

	return 0;
}

/*
Payer p1 = {name: "Bulstrad", rule: bulstrad_member_rule, other data...};
Payer p2 = {name: "Alianz", rule: alianz_member_rule, other data...};

Group g1 = {group_id: 12345, other data...}; 
Group g2 = {group_id: 878782, payer: p1, other data...};
Group g3 = {group_id: 5555, other data...}
Group g4 = {group_id: 19870, payer: p2, other data...}

Ogranization o1 = {institution_list: [g1,g3], address: "unknown address", other data...};

o1::payer -> p1; 
Organization o2 = {institution_list:[], address: "another address", other data...}

Person p1 = {name: "John Smith", insurance_id: 87545, other data...};
Person p2 = {name: "Jane Smith", insurance_id: 13645, other data...};
Person p3 = {name: "Erica Smith", insurance_id: 32445, other data...};
*/