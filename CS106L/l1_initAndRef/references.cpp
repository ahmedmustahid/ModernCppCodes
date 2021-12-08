#include <iostream>
#include <vector>
using std::vector, std::cout, std::endl ;

void printVector(const vector<int> vec){
    for (const auto& element: vec){
        cout << element << endl;
    }
}

int main(){
    vector<int> original{1, 2};
    cout << original[0] << endl;

    vector<int> copy = original;
    vector<int>& ref = original;

    original.push_back(3);
    copy.push_back(3);
    ref.push_back(5);

    cout << "original"<<endl;
    printVector(original);

    cout << "copy"<<endl;
    printVector(copy);

    cout << "ref"<<endl;
    printVector(ref);

}