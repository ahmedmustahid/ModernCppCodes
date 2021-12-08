#include <string>
#include <iostream>
#include <cmath> //gives us pow and sqrt!

using std::string; using std::cout;
using std::cin; using std::pow;
using std::sqrt; using std::endl;

std::pair<bool, std::pair<double, double>> quadratic(double a, double b, double c){
	//get radical, test if negative, return false if so
	double radical = pow(b, 2) - 4 * a * c ;

	if (radical < 0) {
		return std::make_pair(false,  std::make_pair(-1,-1));
	} else {
		double rootPos, rootNeg ;
		double denominator = 2 * a ;
		rootPos = (-b + sqrt(radical))/denominator ;
		rootNeg = (-b - sqrt(radical))/denominator ;
		
		return std::make_pair(true, std::make_pair(rootPos, rootNeg));
	}
	//otherwise get roots and return

	//return {false, {-1, -1}};
}

int main(){
	//get 3 doubles (ax^2 + bx + c)
	double a, b, c;

	cin >> a >> b >> c;
	auto [rootExists, roots] = quadratic(a, b, c);

	//get roots if they exist
	if (rootExists) {
		auto [rootPos, rootNeg] = roots;
		cout << "roots are " <<"\n"<<rootPos <<"\n" << rootNeg <<"\n";
	} else {
		cout << "root doesnt exist" << "\n";
	}
	
	//print accordingly
	

	return 0;
}