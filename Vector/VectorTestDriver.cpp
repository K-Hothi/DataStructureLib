#include <iostream>
#include "Vector.cpp"


void elementToCountRatio(Vector<int> v){
    std::cout << v.getElementCount() << ", ";
    std::cout << v.getCapacity() << std::endl;
}
int main(){

    Vector<int> v;
    v.insert(1);
    v.insert(2);
    v.insert(3);
    v.insert(4);

    v.print();
    elementToCountRatio(v);

    v.remove(v.search(4));
    elementToCountRatio(v);

    v.insert(4);
    v.insert(5);
    v.insert(6);
    v.insert(7);
    v.insert(8);
    v.print();
    elementToCountRatio(v);
    v.insert(9);
    v.insert(10);
    elementToCountRatio(v);
    v.remove(3);
    v.remove(4);
    v.remove(5);
    elementToCountRatio(v);
    v.remove(0);
    v.remove(0);
    v.remove(0);
    v.remove(0);
    elementToCountRatio(v);
    v.remove(0);
    v.remove(0);
    v.remove(0);
    elementToCountRatio(v);
    v.remove(0);
    elementToCountRatio(v);







    return 0;
}