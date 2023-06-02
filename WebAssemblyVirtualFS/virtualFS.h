#ifndef WEBASSEMBLYVIRTUALFS_VIRTUALFS_H_
#define WEBASSEMBLYVIRTUALFS_VIRTUALFS_H_
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct MessageComposition{
  std::string name;
  std::string lastName;
  std::string mail;
  std::string message;
};

enum Tribalyte{
  tribalyteTech,
  tribalyteIdeas
};

std::vector<std::string> vec;
std::vector<std::vector<std::string>> vector_2d;

class Message {
 public:
    Message();
    ~Message();

  bool addNewVector(std::vector<std::string> newVec);
  std::string readFromFile(const std::string& filename);
  void writeToFile(const std::string& filename, const std::string& content);
  void processStringVector(const std::vector<std::string>& strings);
};
#endif  // WEBASSEMBLYVIRTUALFS_VIRTUALFS_H_"
