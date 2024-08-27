#include <iostream>
#include "LinkedList.cpp"

int main(){
    LinkedList<int>* ll = new LinkedList<int>();
    ll->insert(2);
    ll->insert(1);
    ll->insert(4);
    ll->insert(5);
    ll->insert(6);
    ll->insert(7);
    ll->insert(8);
    ll->print();
    std::cout << std::endl;
    ll->removeHead();
    ll->removeHead();
    ll->removeHead();
    ll->removeHead();
    ll->removeHead();
    ll->removeHead();
    ll->removeHead();
    ll->removeHead();
    ll->removeHead();
    ll->print();
   
    
    

    return 0;
}