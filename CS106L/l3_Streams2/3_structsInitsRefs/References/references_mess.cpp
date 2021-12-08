#include <iostream>
#include <vector>

using std::cout;    using std::endl;
using std::string; using std::cin; 
using std::vector;

void shift(vector<std::pair<int, int>>& nums) {
	for (size_t i = 0; i < nums.size(); ++i) {
		auto [num1, num2] = nums[i];
		num1++;
		num2++;
	}
}

void print_vector(vector<int> vec){
	cout << "{ ";
	for(int i = 0; i < vec.size() - 1; i++){
		cout << vec[i] << ", ";
	}

	cout << vec[vec.size() - 1] <<" }" << endl;
}

//utility function just pauses program to poll the class
void poll(string question){
	string fluff;
	cout << question << endl;
	getline(cin, fluff);
}

void ref_var_example(){
	//create vectors
	vector<int> original{1, 2};
	vector<int> copy = original;
	vector<int>& ref = original;
	cout << "executing: \n vector<int> original{1, 2}; \n vector<int> copy = original; \n vector<int>& ref = original;" << endl;

	//change vectors
	original.push_back(3);
	copy.push_back(4);
	ref.push_back(5);

	cout << "executing:\n original.push_back(3); \n copy.push_back(4); \nref.push_back(5);" << endl;

	poll("What is the state of each object?");

	cout << "original: ";
	print_vector(original);
	cout << "copy: ";
	print_vector(copy);
	cout << "ref: ";
	print_vector(ref);
}


int main(){
	ref_var_example();
}