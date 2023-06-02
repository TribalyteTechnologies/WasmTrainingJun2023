
#include <map>
#include <string>
#include <emscripten/bind.h>
#include "advancedEmbindExample.h"

using namespace emscripten;

MyMap::MyMap() {
}

MyMap::~MyMap() {
}

void showVector(std::vector<std::map<std::string, std::map<std::string, PersonalData>>> workVector) {
    for (const auto& outer_map : workVector) {
        for (const auto& inner_map : outer_map) {
            for (const auto& inner_inner_map : inner_map.second) {
                std::cout << "Name: " << inner_inner_map.second.name
                << ", Last Name: " << inner_inner_map.second.lastName
                << ", Age: " << inner_inner_map.second.age << std::endl;
            }
        }
    }
}

void MyMap::set(const std::string key1, const std::string key2, const PersonalData value) {
    MyMap::data[key1][key2] = value;
    PersonalData person;
    if (key1 == "Tribalyte.Ideas") {
        tribaIdeas.push_back(data);
        std::cout  << "department: Tribalyte Ideas"<< std::endl;
        showVector(tribaIdeas);
    } else {
        tribaTech.push_back(data);
        std::cout << "department: Tribalyte Tech"<< std::endl;
        showVector(tribaTech);
    }
}


EMSCRIPTEN_BINDINGS(MyMap) {
    class_<MyMap>("MyMap")
        .constructor<>()
        .function("set", &MyMap::set)
        .function("get", &MyMap::get);
    value_object<PersonalData>("personalData")
        .field("name", &PersonalData::name)
        .field("lastName", &PersonalData::lastName)
        .field("age", &PersonalData::age);
}
