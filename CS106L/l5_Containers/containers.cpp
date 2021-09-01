#include <iostream>
#include <ostream>
#include <vector>

void failVector(){

    std::vector<int> vec{5, 6};
    vec[1] = 8 ;
    vec[2] = 9; //shows no error

}



void accessElemsVector(){

    std::vector<int> vec{5, 6};
    vec[1] = 8 ;
    //vec[2] = 9; //shows no error
    std::cout << vec.at(1) << std::endl;
    std::cout << vec.at(2) << std::endl;
}


int main(){
    
    accessElemsVector();
    return 0;
}
