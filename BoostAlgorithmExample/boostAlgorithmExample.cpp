#include <iostream>
#include <boost/algorithm/string.hpp>

int main() {
    std::string input = "This is an example of an input string";
    std::vector<std::string> words;
    boost::split(words, input, boost::is_any_of(" "));

    for (const auto& word : words) {
        std::cout << word << std::endl;
    }

    return 0;
}
