#include "Group.h"

Group::Group(string in_name, unsigned in_group_id, Payer* in_payer) :
    Institution(in_name),
    group_id{ in_group_id },
    payer{ in_payer } {}

Group::Group(const Group& other) :
    Institution(other.name),
    group_id{other.group_id},
    payer{ other.payer },
    person_id_list{ other.person_id_list }{}

Group& Group::operator=(const Group& other) {
    Institution::operator=(other);
    group_id = other.group_id;
    payer = other.payer;
    person_id_list = other.person_id_list;
    return *this;
}

void Group::add_member_by_id(unsigned id) {
    person_id_list.push_back(id);
}

bool Group::has_member(const Person& person) const {
    for (size_t i = 0; i < person_id_list.size(); ++i) {
        if (person_id_list[i] == person.get_insurance_id()) {
            return true;
        }
    }
    return false;
}

Payer* Group::associated_payer() const {
    return payer;
}

bool Group::is_valid() const {
    return payer != nullptr;
}

unsigned Group::associated_users_count() const {
    return person_id_list.size();
}