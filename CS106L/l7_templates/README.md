## Example of generalizing with template function
### ``count_occurences()`` :
1. The function counts the number of occurences of a particular element inside it.
                
                    int count_occurences(std::vector<int>& myvector, int value){
                        int count = 0;
                        for (size_t i=0; i < myvector.size(); ++i ){
                            if (myvector[i] == value) ++count;
                        }
                        return value;
                    }


2. The assumptions are:
a. The argument is a vector
b. The value to be matched is an integer
c. The data structure can be accessed by indexing (Sets/maps/lists can't be indexed)

3. Solution to this is to use a template function that will take any data structure and any ``value`` 
                
                    template <typename Collection, typename DataType>
                    int count_occurences(const Collection& my_collection, const DataType& my_data) {
                        int count = 0;
                        for (auto iter = my_collection.begin(); iter != my_collection.end() ; ++iter ){
                            if (*iter == my_data ) count++;
                        }
                        return count;
                    }
