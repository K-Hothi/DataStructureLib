//This is a Vector <dynamic array> class that uses an array implimentation
//The backend array both Increases and Decreases in size when space is needed or not being used
//The expansion saves time by doubling the array, making sure this O(n) operation does not need run often
//The decreaseSize method saves memory, avoiding a situation where the array is large for a small # of elements

#include <iostream>

template <typename T>
class Vector{

    private:
        T* arr;
        int elements;
        int capacity;

        const int static ORIGINAL_CAPACITY = 1;

        void increaseCapacity(){
            T* newArr = new T[capacity * 2];
            for(int i = 0; i < elements; i++){
                newArr[i] = arr[i];
            }

            delete arr;
            arr = newArr;

            capacity *= 2;
        }

        void decreaseCapacity(){
            T* newArr = new T[capacity/2];

            for(int i = 0; i < elements; i++){
                newArr[i] = arr[i];
            }

            delete arr;
            arr = newArr;

            capacity /= 2;
        }

    public:
        //constrcutors
        Vector(){
            arr = new T[ORIGINAL_CAPACITY];
            elements = 0;
            capacity = ORIGINAL_CAPACITY;
        }

        //Vector getter and setters
        int getElementCount(){
            return this->elements;
        }
        int getCapacity(){
            return this->capacity;
        }

        //Vector methods
        void insert(T data){
            if(elements >= capacity){
                increaseCapacity();
            }

            arr[elements] = data;
            elements++;
        }

        int search(T data){
            for(int i = 0; i < elements; i++){
                if(arr[i] == data){
                    return i;
                }
            }

            return -1;
        }

        void remove(int index){
            if(index >= elements || index < 0){
                return;
            }

            T* newArr = new T[capacity];
            int j = 0;

            for(int i = 0; i < elements; i++){
                if(i != index){
                    newArr[j] = arr[i];
                    j++;
                }
            }
            delete arr;
            arr = newArr;

            elements--;

            if(elements < capacity/2){
                decreaseCapacity();
            }
        }

        void print(){
            for(int i = 0; i < elements; i++){
                std::cout << arr[i] << ", ";
            }

            std::cout << std::endl;
        }


};