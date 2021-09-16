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
