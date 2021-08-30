#include <iostream>
#include <list>
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>
#include <chrono>

void tryOsStream(){

    std::ostringstream oss("Ito En green tea ");
    //std::ostringstream oss("Ito En green tea ",stringstream::bin);//read as binary
    //std::ostringstream oss("Ito En green tea ",stringstream::ate); //start at the end

    std::cout<<oss.str()<<std::endl;

    oss << 16.9 << " Ounce "; //this will overwrite the previous stream
    //pointer starts from the start of the buffer and ends at the end of" Ounce "
    
    std::cout << oss.str() << std::endl;
    //std::cout << oss.str() << "\n";

    oss << "(Pack of " << 12 << ")" ;//will start from after " Ounce "
                                    
    std::cout << oss.str() <<std::endl;
 

}


void tryIsStream(){

    std::istringstream iss("16.9 Ounces");

    //double amount;
    int amount;
    std::string unit;

    //std::string check;

    iss >> amount;
    iss >> unit;

    std::cout<< amount/2<<" "<<unit<<"\n";//8.45 Ounces if amount is double
                                        //if int, 8 .9 (here amount/2 (==8) is token 1 and unit(==.9) is token2)
                                        //because whitespaces are skipped
                                        //16.9 \n Ounces. . \t \n \n  -3827
                                        //iss will skip all whitespaces and will extract based on the token types
                                        //int token1, string token2, char token3, bool token4
                                        //iss>>token1>>token2>>token3>>token4;
                                        //16 .9 O u
    //std::cout << check<<"\n";



}

void printStateBits(const std::istream& iss){


    std::cout << (iss.good() ? "G" : "-");
    std::cout << (iss.fail() ? "F" : "-");
    std::cout << (iss.eof() ? "E" : "-");
    std::cout << (iss.bad() ? "B" : "-");

    std::cout<<"\n";
}

int stringToInteger(const std::string& mystring){
    
    std::istringstream iss(mystring);
    printStateBits(iss);


    int myInteger;
    iss >> myInteger;
    if (iss.fail()){
        throw std::domain_error("not a valid integer");
    }

    //failbit can also be checked by passing the stream 
    /*
    if (!(iss >> myInteger)){ //iss>>myInteger evaluates to true if fail bit is off
        throw std::domain_error("not a valid integer");
    }
    */

    char result;
    iss >> result;
    if (!iss.fail()){
        throw std::domain_error("invalid value after integer");
    }
    
    //failbit can also be checked by passing the stream 
    /*

    if (iss >> result){
        throw std::domain_error("invalid value after integer");
    }
     */

    /*
    //this is also valid
    if (!iss.eof()){
        throw std::domain_error("invalid value after integer");
     
    */


    printStateBits(iss);
    std::cout << myInteger << std::endl;
    return myInteger;
}


void stringToIntegerBetter(){

    while(true){

        std::cout<<"type an integer:";

        std::string mystring;
        if (!std::getline(std::cin,mystring)){
            std::__throw_domain_error("getline failed");
        }

        std::cout<<"you typed:"<<mystring<<"\n";
        int result = stringToInteger(mystring);

        std::cout<<"as an integer: "<<result<<"\n";
        std::cout<<"half of that: "<<result/2<<"\n";



    }

}
inline void mindlessWork(){
    std::this_thread::sleep_for (std::chrono::seconds(1));
}

void bufferedExperiment(std::ostream& oss){

    oss << "CS";
    mindlessWork();

    oss << "106";
    mindlessWork();

    //oss<<std::flush;
    //mindlessWork();

    oss << "L";
    mindlessWork();
    oss << std::endl;
    //mindlessWork();
}

int endlEachTime(){
    
    auto start_move =std::chrono::high_resolution_clock::now();

    for(int i=0; i< 100; i++){
        
        std::cout<<i<<std::endl; //endl == newline + flush
    }
    auto stop_move =std::chrono::high_resolution_clock::now();
    
    auto move_duration = std::chrono::duration_cast<std::chrono::microseconds>(stop_move - start_move);

    return move_duration.count();
}


int endlAtEnd(){
    
    auto start_move =std::chrono::high_resolution_clock::now();

    for(int i=0; i< 100; i++){
        
        std::cout<<i<<"\n"; //endl == newline + flush
    }

    std::cout << std::flush; // flush puts everything into console
    auto stop_move =std::chrono::high_resolution_clock::now();
    
    auto move_duration = std::chrono::duration_cast<std::chrono::microseconds>(stop_move - start_move);

    return move_duration.count();
}

int main(){

    //tryOsStream();
    //tryIsStream();
    //stringToInteger("16.9");//get 16
    //stringToInteger("16 4");//get 16
    //stringToInteger("anik");//get 0

    //stringToIntegerBetter();
    //
    //bufferedExperiment(std::cout); //waits until the buffer ends before putting to console
    //bufferedExperiment(std::cerr); //cerr has no buffer
    //
    
    int endlEachTime_time = endlEachTime();
    int endlAtEnd_time = endlAtEnd();
    
    std::cout << "endlEachTime_time: "<<endlEachTime_time<<"\n";
    std::cout << "endlAtEnd_time: "<<endlAtEnd_time<<"\n";
    


    return 0;
}




