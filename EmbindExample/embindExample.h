#ifndef EMBINDEXAMPLE_EMBINDEXAMPLE_H_
#define EMBINDEXAMPLE_EMBINDEXAMPLE_H_
#include <iostream>
#include <string>

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

class Message {
 public:
  Message();
  ~Message();
  void newMessage(MessageComposition messageComposition, Tribalyte department);
};
#endif  // EMBINDEXAMPLE_EMBINDEXAMPLE_H_
