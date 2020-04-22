// Copyright 2020 Adam Tremblay

#include <iostream>
#include <string>
#include "MModel.hpp"

int main(int argc, char* argv[]) {
    int k = std::stoi(argv[1]);
    int L = std::stoi(argv[2]);

    std::string str = "";
    std::string line;

    while (std::getline(std::cin, line)) {
        str += line + "\n";
    }

    MModel mm(str, k);

    std::cout << mm.generate(str.substr(0, k), L) << std::endl;

    return 0;
}
