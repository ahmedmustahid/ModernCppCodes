#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

template<typename T>
//T my_min(const T& a, const T& b){
auto my_min(const T& a, const T& b){

    return a > b ? a : b;
}

template<typename InputIterator, typename Datatype>
int count_occurences_generalized(InputIterator begin, InputIterator end, Datatype value){

    int count=0;
    
    for (auto iter = begin; iter != end; iter++){
        
        if (*iter == value){
            ++count;
        }
    }

    return count;
}
int count_occurences(const vector<int>& myvector, int value){

    int count=0;
    
    for (size_t i=0; i < myvector.size(); i++){
        
        if (myvector[i] == value){
            ++count;
        }
    }

    return count;
}

int main(){
    //explicit instantiation
    cout<< my_min<string>("lois", "clark")<<"\n";
    cout<< my_min<int>(3, 5) << "\n";
   
    //implicit instantiation
    //Generates error clang c++17
    //cout<< my_min("lois", "clark")<<"\n";//passing C strings ie char*
    //cout << my_min(3, 4.5);
    
    vector<int> myvector{1, 3, 4, 6, 7, 8, 8, 6, 8};
    cout << " using vector and int "<< count_occurences(myvector, 8) <<" times" << "\n";
    cout << " generalized version of count " << count_occurences_generalized(myvector
            .begin(), myvector.end(), 8) << "\n";


    vector<string> mystringvector{"lois", "clark"};
    cout << " generalized version of count " << count_occurences_generalized(mystringvector
            .begin(), mystringvector.end(), "clark") << "\n" ;

    //data structure can be generalized by means of template iterator
    //value type can be generalized by means of template datatype

    
    return 0;
}
