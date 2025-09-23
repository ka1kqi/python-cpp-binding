#pragma once
#include <string>

class Person {
private:
    int age;
    std::string name;

public:
    Person();
    Person(std::string name, int age);
    int get_age();
    void increment_age();
    void change_name(std::string new_name);
    std::string get_person();
};