#include "virtualFS.h"
#include <emscripten/bind.h>
#include <emscripten.h>

using namespace emscripten;

EM_JS(void, saveUser, (), {
    alert("User saved successfully");
});

Message::Message() {
}

Message::~Message() {
}

int main() {
EM_ASM(
      const info = FS.analyzePath('/data/file.txt', true);
      if (!info.exists) {
        FS.mkdir('/data');
        FS.mount(IDBFS, {}, '/data');
        FS.syncfs(true, function(err) {
        if (err) {
          throw err;
          console.log('File system initialized with persistent data');
          }
        });
        });
}

bool addNewVector(std::vector<std::string> newVec) {
    auto it = std::find(vector_2d.begin(), vector_2d.end(), newVec);
    if (it == vector_2d.end()) {
        vector_2d.push_back(newVec);
        saveUser();
        return true;
    }
      return false;
}

std::string readFromFile(const std::string& filename) {
  std::ifstream file(filename);
  std::string content, contentf;
  if (file.is_open()) {
    while (std::getline(file, content)) {
    contentf = contentf+content+"\n";
  }
    file.close();
  } else {
    std::cout << "Error opening file" << std::endl;
  }
  return contentf;
}

void writeToFile(const std::string& filename, const std::string& content) {
  std::ofstream file(filename);
  if (file.is_open()) {
    file << content;
    file.close();
  } else {
    std::cout << "Error opening file" << std::endl;
  }
}

void processStringVector(const std::vector<std::string>& strings) {
    addNewVector(strings);
    std::string content;
    for (const auto& str2 : vector_2d) {
      for (const auto& str : str2) {
        content = content +str+"\n";
      }
    }
    writeToFile("/data/file.txt", content);
}

EMSCRIPTEN_BINDINGS(virtualFS) {
  emscripten::function("readFromFile", &readFromFile);
  register_vector<std::string>("StringVector");
  function("processStringVector", &processStringVector);
}
