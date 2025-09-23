#include <person.h>

Person::Person() {}

Person:: Person(std::string name_,int age_) : name{name_}, age{age_} {}

int Person::get_age() {return age;}

void Person::increment_age() {age++;}

void Person::change_name(std::string new_name) {
    name = new_name;
}

std::string Person::get_person() {
    return "Name: " + name + " age: " + std::to_string(age);
}