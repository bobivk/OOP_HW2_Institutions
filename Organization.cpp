#include "Organization.h"

Organization::Organization(string name, vector<Institution*> in_institutions, string in_address) :
	Institution(name),
	institutions{ in_institutions },
	address{ in_address }{}

Organization::Organization(const Organization& other):
	Institution(other.name),
	institutions{ other.institutions },
	address{other.address}{}

Organization& Organization::operator=(const Organization& other) {
	Institution::operator=(other);
	institutions = other.institutions;
	address = other.address;
	return *this;
}


void Organization::add_institution(Institution* i) {
	if (invalid_institutions_enabled)
		institutions.push_back(i);
	else cout << "Adding invalid institutions is disabled! Use toggle_invalid_institutions to enable it.\n";
}
void Organization::toggle_invalid_institutions() {
	invalid_institutions_enabled = !invalid_institutions_enabled;
}
Payer* Organization::associated_payer() const {
	vector<Payer*> payers;
	//get all the payers of the institutions
	for (size_t i = 0; i < institutions.size(); ++i) {
		Payer* current = institutions[i]->associated_payer();
		if (current != nullptr) {
			payers.push_back(current);
		}
	}
	if (payers.size() == 0) return nullptr;

	//count how many times each payer comes up
	unsigned* payer_counts = new unsigned[payers.size()]{ 0 };
	for (size_t i = 0; i < payers.size(); ++i) {
		Payer* current = payers[i];
		for (size_t j = 0; j < payers.size(); ++j) {
			if (*payers[j] == *payers[i]) {
				++payer_counts[i];
			}
		}
	}
	
	//return the one with the maximum count
	unsigned max_count = 0;
	unsigned index_of_max = 0;
	for (size_t i = 0; i < payers.size(); ++i) {
		if (payer_counts[i] > max_count) {
			max_count = payer_counts[i];
			index_of_max = i;
		}
	}
	delete[] payer_counts;
	return payers[index_of_max];
}

unsigned Organization::associated_users_count() const {
	unsigned count = 0;
	for (size_t i = 0; i < institutions.size(); ++i)
		count += institutions[i]->associated_users_count();
	return count;
}

bool Organization::has_member(const Person& person) const {
	for (size_t i = 0; i < institutions.size(); ++i) {
		if (institutions[i]->has_member(person)) return true;
	}
	return false;
}
bool Organization::is_valid() const {
	for (size_t i = 0; i < institutions.size(); ++i) {
		if (dynamic_cast<Group*>(institutions[i])) return true;
	}
	return false;
}