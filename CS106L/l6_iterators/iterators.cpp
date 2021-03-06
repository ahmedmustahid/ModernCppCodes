#include <cstddef>
#include <iostream>
#include <map>
#include <ostream>
#include <set>
#include <typeinfo>
#include <vector>
void checkVector() {

  std::vector<int> my_vector{13, 5, 8, 9, 0};

  for (size_t i = 0; i < my_vector.size(); ++i) {

    const auto &elem = my_vector[i];
    std::cout << elem << std::endl;
  }
}

void checkMapIterType() {

  std::map<int, int> my_map{{1, 2}, {3, 4}, {5, 6}};

  auto iter = my_map.begin();
  // std::map<int, int>::iterator iter = my_map.begin();
  //
  std::cout << iter->first << std::endl;
  std::cout << iter->second << std::endl;
  std::cout << typeid(*iter).name() << std::endl;

  ++iter;
  std::cout << iter->first << std::endl;
  std::cout << iter->second << std::endl;
  std::cout << typeid(*iter).name() << std::endl;

  auto iter_copy = iter;

  // same syntax for all iterators
  for (auto iter = my_map.begin(); iter != my_map.end(); ++iter) {

    const auto &[key, value] = *iter;
    std::cout << key << " " << value << std::endl;
  }

  //ForEach
  for (auto& [key, value]: my_map ){

      std::cout <<"key "<<key<<" value "<<value<<"\n";
  }

}

void checkSet() {

  std::set<int> my_set{13, 5, 8, 9, 0};

  for (size_t i = 0; i < my_set.size(); ++i) {

    // const auto& elem = my_set[i]; //cannot index a set
    // const auto& elem = my_set[i];
    // std::cout << elem << std::endl;

    // Does not work on a set. Iterator brings all these under a unified
    // framework
  }

  // same syntax for all iterators
  for (auto iter = my_set.begin(); iter != my_set.end(); ++iter) {

    const auto &elem = *iter;
    std::cout << elem << std::endl;
  }

  //ForEach
  for (const auto& elem : my_set){

      std::cout<<"elem "<<elem<<"\n";
  }
}

void invalidIterator1(){

    std::vector<int> my_vector{1, 2, 3, 4, 5};

    std::cout << "printing vector elements " << std::endl;

    for (const auto& elements: my_vector){
        
        std::cout << elements << std::endl;
    }


    auto iter{ my_vector.begin()};
    
    ++iter;
    std::cout << "dereferenced begin iterator " << *iter << "\n";
    my_vector.emplace_back(10);
    
    std::cout << "dereferenced begin iterator after emplace_back  " << *iter << "\n";

}



int invalidIterator2()
{
	std::vector v{ 1, 2, 3, 4, 5, 6, 7 };

	auto it{ v.begin() };

	++it; // move to second element
	std::cout << *it << '\n'; // ok: prints 2

	v.erase(it); // erase the element currently being iterated over

	// erase() invalidates iterators to the erased element (and subsequent elements)
	// so iterator "it" is now invalidated

	++it; // undefined behavior
	std::cout << *it << '\n'; // undefined behavior

	return 0;
}

int main() {

  // checkVector();
  //checkMapIterType();
  //checkSet();
  invalidIterator1();
  //invalidIterator2();
  return 0;
}
