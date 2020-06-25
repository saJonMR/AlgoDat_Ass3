#include "GraphTemplate.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {
    NodeTemplate Berlin("Berlin");
    NodeTemplate Hamburg("Hamburg");
    NodeTemplate Frankfurt("Frankfurt");
    NodeTemplate Weimar("Weimar");
    NodeTemplate Muenchen("Muenchen");

    Berlin.add_connection(Hamburg, -200);
    Berlin.add_connection(Frankfurt, 550);
    Berlin.add_connection(Weimar, 300);
    Berlin.add_connection(Muenchen, 2000);
    Hamburg.add_connection(Frankfurt, 250);
    Frankfurt.add_connection(Muenchen, 650);

    GraphTemplate Map(Berlin);

    Map.add(Hamburg);
    Map.add(Frankfurt);
    Map.add(Weimar);
    Map.add(Muenchen);
       
    std::cout << Berlin.dist() << std::endl;
    std::cout << Hamburg.dist() << std::endl;
    std::cout << Frankfurt.dist() << std::endl;
    std::cout << Weimar.dist() << std::endl;
    std::cout << Muenchen.dist() << std::endl;

    //std::cout << Map.listNode(2);
    std::cout << Map.find("Hamburg");

    std::cout << Map.bellman_fort(Berlin) << std::endl;

   
    std::cout << Berlin.dist() << std::endl;
    std::cout << Hamburg.dist() << std::endl;
    std::cout << Frankfurt.dist() << std::endl;
    std::cout << Weimar.dist() << std::endl;
    std::cout << Muenchen.dist() << std::endl;
    
}