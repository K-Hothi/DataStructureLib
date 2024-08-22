#include <iostream>

class LinkedList{
    private:
        struct pair{
            public:
                std::string key;
                std::string value;
        };
        class node{
            public:
                pair data;
                node* next;

        };

    public:
        node* head;
        node* tail;

        LinkedList(){
            head = nullptr;
            tail = nullptr;
        }

        bool insert(std::string key,  std::string value){
            pair data; data.key = key; data.value = value;

            node* newNode = new node();
            newNode->data = data;
            newNode->next = nullptr;

            if(newNode == nullptr){
                return false;
            }

            if(head == nullptr){
                head = tail = newNode;
                return true;
            }
            node* current = head;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = newNode;
            tail = current->next;

            return true;
        }

        std::string search(std::string k){
            node* current = head;

            while(current != nullptr){
                if(current->data.key == k){
                    return current->data.value;
                }
                current = current->next;
            }

            return "NULL";
        }

};