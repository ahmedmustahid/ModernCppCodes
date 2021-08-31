#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void badWelcomeProgram();


int main(){

    badWelcomeProgram();
    return 0;

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
