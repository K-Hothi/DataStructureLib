#include <iostream>

using namespace std;


//An exandable array with easy access to items via []
template <typename T>
class List{
    private:
        T* arr;
        int capacity;
        int numberOfItems;
};