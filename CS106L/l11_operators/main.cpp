#include <iostream>
#include <ostream>
#include <string>
#include <vector>


void printVector(){

    std::vector<std::string> mystrig_vector;

    mystrig_vector.emplace_back("Hello");
    mystrig_vector.emplace_back("World");

    for (const auto& element: mystrig_vector){

        std::cout << element << std::endl;

    }


}



int main(){

    printVector(); 
    return 0;
}
