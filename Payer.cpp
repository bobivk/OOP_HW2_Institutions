#include "Payer.h"

Payer::Payer(std::string in_name,
    bool (*in_payer_member_rule)(unsigned group_id, unsigned insurance_id)):
        name{in_name},
        payer_member_rule{ in_payer_member_rule }{}

bool Payer::operator==(const Payer& other) const {
    return name == other.name;
}
bool Payer::rule(unsigned group_id, unsigned insurance_id) {
    return payer_member_rule(group_id, insurance_id);
}
std::string Payer::get_name() const {
    return name;
}