#include "e2eExample.h"
#include <emscripten/bind.h>
#include <emscripten.h>

using namespace emscripten;

EM_JS(void, messageSentAlert, (), {
    alert("The message has been sent");
  console.log(message);
    document.getElementById("return").value = "The message has been sent";
});

Message::Message() {
}

Message::~Message() {
}

void Message::newMessage(MessageComposition messageComposition) {
    try {
        std::cout << "Name: " << messageComposition.name << std::endl;
        std::cout << "Last name: " << messageComposition.lastName<< std::endl;
        std::cout << "Mail: " << messageComposition.mail << std::endl;
        std::cout << "Message: " << messageComposition.message << std::endl;
        if (messageComposition.mail.find('@') >= messageComposition.mail.length()) {
            throw "Error in mail";
        }
        messageSentAlert();
    }catch(...) {
        EM_ASM(
            alert("Wrong Mail");
            throw "Wrong Mail";);
    }
}



EMSCRIPTEN_BINDINGS(message) {
  class_<Message>("Message")
    .constructor<>()
    .function("newMessage", &Message::newMessage);

    value_object<MessageComposition>("MessageComposition")
      .field("name", &MessageComposition::name)
      .field("lastName", &MessageComposition::lastName)
      .field("mail", &MessageComposition::mail)
      .field("message", &MessageComposition::message);
}
