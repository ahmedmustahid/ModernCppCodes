#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::istringstream;

void badWelcomeProgram();
void goodWelcomeProgram();
int getInteger(const string& prompt);
void printStateBits(const std::istream& iss);
string breakingGetline(const string& input_string_with_newline);
string fixBrokenGetline(const string& input_string_with_newline);
int main(){

    //badWelcomeProgram();
    //goodWelcomeProgram();
    //getInteger("enter an integer: ");
    
    //cout << breakingGetline("16.9 \n 24")<<endl;
    cout << fixBrokenGetline("16.9\n 24")<<endl;
    return 0;

}

string breakingGetline(const string& input_string_with_newline){

    cout<<"input string: "<<input_string_with_newline<<"\n";
    istringstream iss(input_string_with_newline);
    double my_number;
    iss >> my_number;
    cout <<"number before newline "<<my_number<<"\n";
   
    string my_string;
    getline(iss, my_string);
    cout<<"number after newline \n";
    return my_string;
    //int my_another_number;
    //iss>> my_another_number;

}
string fixBrokenGetline(const string& input_string_with_newline){
    
    cout<<"fix broken string\n "<<"\n";
    cout<<"input string: "<<input_string_with_newline<<"\n";
    istringstream iss(input_string_with_newline);
    double my_number;
    iss >> my_number;
    cout <<"number before newline "<<my_number<<"\n";
   
    string my_string;
    iss.ignore();
    getline(iss, my_string);//my_string== ""
    //getline(iss, my_string);//my_string== " 24"
    cout<<"number after newline \n";
    return my_string;

}

void printStateBits(const std::istream& iss){


    std::cout << (iss.good() ? "G" : "-");
    std::cout << (iss.fail() ? "F" : "-");
    std::cout << (iss.eof() ? "E" : "-");
    std::cout << (iss.bad() ? "B" : "-");

    std::cout<<"\n";
}

void badWelcomeProgram(){
    
    string name, response;
    int age;

    cout << "What is your name? ";
    cin >> name;


    cout << "What is your age? ";
    cin >> age;

    cout<< "name "<<name << " age "<<age<<"\n";

    cout<<"try again? ";
    cin >> response;

    cout << "You said: "<<response << endl;
}

int getInteger(const string& prompt){
    
    while (true) {
        
        cout<< prompt;

        string input_string;
        if (!(getline(cin,input_string))){
            throw std::domain_error("insert a valid integer");
        }
   
        istringstream iss(input_string);
        cout<<"after calling iss \n";
        printStateBits(iss);
        int input_integer; char trash;
      
        //check the bits
        /*
        iss >> input_integer;
        cout << "input_integer: "<<input_integer<<"\n";
        printStateBits(iss);

        iss >> trash;
        cout << "trash: "<<trash<<"\n";
        printStateBits(iss);
        */ 
        
        
            
        if(iss >> input_integer && !(iss >> trash)){
            cout << "inside valid integer logic\n";
            printStateBits(iss);
            return input_integer;
        }
    }
}

void goodWelcomeProgram(){
    
    string name, response;
    int age;

    cout << "What is your name? ";
    getline(cin,name);


    //cout << "What is your age? ";
    //cin >> age;
    age = getInteger("What is your age? ");


    cout<< "name "<<name << " age "<<age<<"\n";

    cout<<"try again? ";
    getline(cin,response);

    cout << "You said: "<<response << endl;
}
