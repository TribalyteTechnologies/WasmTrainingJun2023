#ifndef ADVANCEDEMBINDEXAMPLE_ADVANCEDEMBINDEXAMPLE_H_
#define ADVANCEDEMBINDEXAMPLE_ADVANCEDEMBINDEXAMPLE_H_
#include <iostream>
#include <string>
#include <map>
#include <vector>

struct PersonalData {
    std::string name;
    std::string lastName;
    int   age;
};

std::vector<std::map<std::string, std::map<std::string, PersonalData>>> tribaIdeas;
std::vector<std::map<std::string, std::map<std::string, PersonalData>>> tribaTech;

class MyMap {
public:
    MyMap();
    ~MyMap();
    void set(std::string key1, std::string key2, PersonalData value);

    PersonalData get(const std::string key1, const std::string key2) {
        return data[key1][key2];
    }

private:
    PersonalData person;
    std::map<std::string, std::map<std::string, PersonalData>> data;
};
#endif  // ADVANCEDEMBINDEXAMPLE_ADVANCEDEMBINDEXAMPLE_H_
