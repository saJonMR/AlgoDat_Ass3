#include "GraphTemplate.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {
    NodeTemplate Berlin("Berlin");
    NodeTemplate Hamburg("Hamburg");

    Berlin.add_connection(Hamburg, 400);

    std::cout << Berlin.connected();
}