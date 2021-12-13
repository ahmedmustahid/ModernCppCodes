//in case mutliple files in a project include strvector, 
//this instruction says only compile this file once!
#ifndef REALVECTOR_H
#define REALVECTOR_H

#include <string>
#include <algorithm>

template <typename vectype>
class RealVector {
    public:
        //type alias (this is how iterator types work!)
        using iterator = vectype* ;
        using constIterator = const vectype* ;
        //using iterator = std::string* ;
        using sizeType = size_t ;
        //define an initial size for your underlying array
        const sizeType initialSize = 2 ;
        //constructors and destructor
        RealVector();
        RealVector(sizeType vecSize, const vectype& vecReal);
        ~RealVector();

        //public interface: What can users of vectors do with the vector?
        sizeType size() const;
        bool empty() const;

        void insert(size_t index, const vectype& vecReal);
        void push_back(const vectype& vecReal);



        //we will learn how to define operators soon, for now lets make
        //at(index) instead of [index]
        vectype& at(size_t index);

        //dont forget about accessing iterators!
        iterator begin();
        iterator end();
        constIterator cbegin() const;
        constIterator cend() const;

    private:
        //all member variables should go here!
        void grow();
        vectype* elems;
        sizeType logicalSize, allocatedSize;

        //Any private helper functions we might need?

};


#include "realvector.cpp"


#endif // STRVECTOR_H


