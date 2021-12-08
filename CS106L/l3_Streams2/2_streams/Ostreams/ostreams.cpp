
//What do we need to include?
#include <iostream>
#include <string>
#include <fstream>

//No using namespace std;!!!!
using std::cout;
using std::endl;
using std::string;

//function to write num to any ostream
void writeToAnyOstream(std::ostream& myStream, int myInt){
    myStream << "Writing my int " << myInt;
}

int main() {
    // Write an int to the user's console.
    int myNum = 42;
    cout << myNum ;    

    // Write an int to a file.
    std::ofstream ofs ("out.txt", std::ofstream::out);
    ofs << myNum ; 

    // Write method to take any ostream
    writeToAnyOstream(cout, myNum);
    writeToAnyOstream(ofs, myNum);
   
    return 0;
}
