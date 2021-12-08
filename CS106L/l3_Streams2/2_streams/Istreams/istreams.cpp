
#include <iostream>
#include <fstream>

using std::cout;    using std::endl;
using std::string; using std::cin;

void printBits(std::ifstream& input) {
    string bitResult{""};
    if (input.good()) bitResult+="G" ;
    else bitResult+="-";

    if (input.eof()) bitResult+="E" ;
    else bitResult+="-";
    
    if (input.fail()) bitResult+="F" ;
    else bitResult+="-";

    if (input.bad()) bitResult+="B" ;
    else bitResult+="-";

    cout << "Bit result GEFB is " << bitResult <<"\n";
}

//read numbers from a file
void readNumbers() {
    // Create our ifstream and make it open the file
    std::ifstream inputFile("res/numbers.txt", std::ifstream::in);

    // Something to store values we get from the stream
    int myNumber;

    while(true){
        // Extract next number from input
        inputFile >> myNumber;

        // If input is in a fail state, either a value couldn't
        // be converted, or we are at the end of the file.

        printBits(inputFile);
        if (inputFile.fail()) {
            break;
        }
        //print whatever we read
        cout << "we read " << myNumber <<"\n";
    }  
}

//read a single word at a time from a file
void readHaikuWord() {
    // Create our ifstream and make it open the file
    std::ifstream inputFile("res/haiku.txt", std::ifstream::in);
     // Something to store values we get from the stream
    string word;

    while(true) {
        // Extract next word from input
        inputFile >> word;

        // If input is in a fail state, either a value couldn't
        // be converted, or we are at the end of the file.
        printBits(inputFile);
        if (inputFile.fail()) {
            break;
        }
        //print whatever we read
        cout << "we read " << word << "\n";
    }
}

void readHaikuLine() {
    // Create our ifstream and make it open the file

    std::ifstream inputFile("res/haiku.txt", std::ifstream::in);
    // Something to store the lines as we get them form the stream
    string myLine;

    while(true) {
        std::getline(inputFile, myLine);
        // If input is in a fail state, either a value couldn't
        // be converted, or we are at the end of the file.
        printBits(inputFile);
        if (inputFile.fail()) {
            break;
        }
        //print whatever we read
        cout << "myLine " << myLine <<"\n";
    }
}

//function for us to play around with cin
void playground(){


}

int main() {

    //playground();
    readNumbers() ;
    cout << "==================" <<"\n";
    readHaikuWord();
    cout << "==================" <<"\n";
    readHaikuLine();
    cout << "==================" <<"\n";

    // string goodBit{"goodbit"};
    // string badBit{"badbit"};

    // cout << goodBit + badBit << "\n";
    return 0;
}


