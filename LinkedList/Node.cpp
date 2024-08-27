#include "LinkedList.cpp"

template <typename T>
class Node{
    T data;
    Node* next;
    Node* prev;

    Node(){
        data = NULL;
        next = nullptr;
        prev = nullptr;
    }

    Node(T value){
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};