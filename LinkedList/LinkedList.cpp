//LinkedList class implimented using a Node class
//This is a Doubly Headed Double Linked List implimentation
#include <iostream>
template <typename T>
class LinkedList{
    private:
        class Node{
            public:
                T data;
                Node* next;
                Node* prev;

                Node(){
                    data = T();
                    next = nullptr;
                    prev = nullptr;
                }

                Node(T value){
                    data = value;
                    next = nullptr;
                    prev = nullptr;
                }
        };
        Node* head;
        Node* tail;
        int length;

    public:
        //Constructor
        LinkedList(){
            head = nullptr;
            tail = nullptr;
            length = 0;
        }

        ~LinkedList(){
            Node* current = head;
            while(current != nullptr){
                Node* nextNode = current->next;
                delete current;
                current = nextNode;
            }
        }

        LinkedList(const LinkedList& ll){
            Node* current = ll.head;

            while(current != nullptr){
                this->insert(current->data);
                current = current->next;
            }

            this->length = ll.length;
        }



        //Setter & Getter
        void setHead(Node* n){
            this->head = n;
        }
        Node* getHead(){
            return this->head;
        }

        void setTail(Node* n){
            this->tail = n;
        }
        Node* getTail(){
            return this->tail;
        }

        //LinkedList get length methods
        int len(){
            return length;
        }
        int size(){
            return length;
        }

        //LinkedList Operation Methods
        Node* search(T targetValue){
            Node* current = head;

            while(current != nullptr){
                if(current->data == targetValue){
                    return current;
                }
                current = current->next;
            }

            return nullptr;
        }

        void removeHead(){
            if(head != nullptr){
                Node* oldHead = head;
                head = head->next;
                if(head != nullptr){
                    head->prev = nullptr;
                }else{
                    tail = nullptr;
                }
                delete oldHead;
                length--;
            }
        }

        void removeTail(){
            if(tail != nullptr){
                Node* oldTail = tail;
                tail = tail->prev;
                if(tail != nullptr){
                    tail->next = nullptr;
                }else{
                    head = nullptr;
                }
                delete oldTail;
                length--;
            }
        }

        Node* remove(T targetValue){
            if(this->getHead()->data == targetValue){
                Node* toReturn = head;
                this->removeHead();
                return toReturn;
            }
            if(this->getTail()->data == targetValue){
                Node* toReturn = tail;
                this->removeTail();
                return toReturn;
            }

            Node* toRemove = this->search(targetValue);
            if(toRemove == nullptr){
                return nullptr;
            }

            toRemove->prev->next = toRemove->next;
            toRemove->next->prev = toRemove->prev;

            return toRemove;
        }


        void insert(T value){
            Node* newNode = new Node(value);
            if(head == nullptr){
                head = newNode;
                tail = head;
            }else{
                Node* oldTail = tail;
                oldTail->next = newNode;
                tail = newNode;
                newNode->prev = oldTail;

            }
            length++;
        }

        void print(){
            Node* current = head;
            while(current->next != nullptr){
                std::cout << current->data << ", ";
                current = current->next;
            }
            std::cout << current->data << std::endl;
        }

        //Operator Overloading
        LinkedList& operator=(const LinkedList& ll){
            if(this == &ll){
                return *this;  // Handle self-assignment
            }

            // Clear the current list
            while(head != nullptr){
                removeHead();
            }

            // Copy elements from the other list
            Node* current = ll.head;
            while(current != nullptr){
                insert(current->data);
                current = current->next;
            }

            return *this;
        }


};