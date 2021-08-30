#include <iostream>
#include <sstream>


int main(){


    std::ostringstream oss("Ito En green tea ");
    std::cout<<oss.str()<<std::endl;

    oss << 16.9 << " Ounce ";
    std::cout << oss.str() << std::endl;

}
