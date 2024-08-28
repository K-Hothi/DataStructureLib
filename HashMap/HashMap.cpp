#include <iostream>
#include "LinkedList.cpp"

class HashMap{
    private:
        int hash(std::string key) {
            int hashValue = 0;
            for (int i = 0; i < key.size(); i++) {
                hashValue += key[i];
            }
            return hashValue % size;
        }
    public:
        int size;
        LinkedList* arr;

        HashMap(){
            size = 20;
            arr = new LinkedList[size];
        }

        void insert(std::string key,  std::string value){
            int index = hash(key);
            arr[index].insert(key, value);
        }

        std::string search(std::string key){
            return arr[hash(key)].search(key);
        }

        std::string operator[](std::string key){
            return this->search(key);
        }

        int operator+(HashMap b){
            return this->size + b.size;
        }

};