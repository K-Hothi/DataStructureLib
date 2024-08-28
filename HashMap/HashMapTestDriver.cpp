#include <iostream>
#include "HashMap.cpp"

int main(){
    HashMap map;
    HashMap map2;

    map.insert("a", "A");
    map.insert("A", "a");
    map.insert("NewYork", "Meta Internship");
    map.insert("b", "B");

    std::cout << map["a"] << std::endl;
    std::cout << map["NewYork"] << std::endl;
    std::cout << map["A"] << std::endl;
    std::cout << map["b"] << std::endl;
    std::cout << map + map2 << std::endl;



    return 0;
}