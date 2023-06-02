#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream file("test.txt");

    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::cout << line << std::endl;
        }
        file.close();
    } else {
        std::cerr << "Could not open the file\n";
        return 1;
    }
    return 0;
}
