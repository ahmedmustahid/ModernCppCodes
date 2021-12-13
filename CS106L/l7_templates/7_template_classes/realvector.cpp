//include the .h file!
#include "realvector.h"

template <typename vectype>
//constructors
RealVector<vectype>::RealVector():
    logicalSize(0), allocatedSize(initialSize)
{
    elems = new vectype[allocatedSize];
}

template <typename vectype>
RealVector<vectype>::RealVector(size_t n, const vectype& val):
    logicalSize(n), allocatedSize(2 * n)
{
    elems = new std::string[allocatedSize];
    std::fill(begin(), end(), val);

}

//destructor
template <typename vectype>
RealVector<vectype>::~RealVector() {
    delete[] elems;
}

template <typename vectype>
size_t RealVector<vectype>::size() const {
    return logicalSize;
}

//interface
template <typename vectype>
bool RealVector<vectype>::empty() const {
    return size()==0;
}

template <typename vectype>
typename RealVector<vectype>::iterator RealVector<vectype>::RealVector::begin() {
    return elems;
}


template <typename vectype>
typename RealVector<vectype>::constIterator RealVector<vectype>::RealVector::cbegin() const {
    return elems;
}


template <typename vectype>
typename RealVector<vectype>::constIterator RealVector<vectype>::RealVector::cend() const {
    return elems + size();
}

template <typename vectype>
typename RealVector<vectype>::iterator RealVector<vectype>::RealVector::end() {
    return elems + size();
} 


template <typename vectype>
vectype& RealVector<vectype>::at(size_t index) {
    //hint: use your iterator knowledge!
    return *(begin() + index);
}   



template <typename vectype>
//typename RealVector<vectype>::iterator RealVector<vectype>::insert(size_t pos, const vectype &elem) {
void RealVector<vectype>::insert(size_t pos, const vectype &elem) {
    if(logicalSize == size()){
        grow();
    }
    for(size_t i = logicalSize; i != pos; --i){
        elems[i] = elems[i-1];
    }
    elems[pos] = elem;
    logicalSize++;

}


template <typename vectype>
void RealVector<vectype>::push_back(const vectype &elem) {
    insert(size(),elem);
}


template <typename vectype>
void RealVector<vectype>::grow(){
    typename RealVector<vectype>::iterator new_elems = new vectype[2 * allocatedSize];
    std::copy(begin(), end(), elems);
    delete[] elems;
    elems = new_elems;
    allocatedSize *= 2;
}
