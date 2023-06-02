#ifndef E2ETESTEXAMPLE_HTML_E2EEXAMPLE_H_
#define E2ETESTEXAMPLE_HTML_E2EEXAMPLE_H_
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
  void newMessage(MessageComposition messageComposition);
};
#endif  // E2ETESTEXAMPLE_HTML_E2EEXAMPLE_H_
