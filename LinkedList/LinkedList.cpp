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
            if(head == nullptr){
                return;
            }
            else if(head->next == nullptr){
                delete head;
            }
            Node* left = head;
            Node* right = head->next;
            while(right != nullptr){
                delete left;
                left = right;
                right = right->next;
            }

            delete left;
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
                this->head = head->next;
                if(head != nullptr){
                    head->prev = nullptr;
                }
            }
        }
        Node* remove(T targetValue){
            return nullptr;
        }


        void insert(T value){
            Node* newNode = new Node(value);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
                return;
            }
            tail->next = newNode;
            tail = newNode;
            length++;
        }

        void print(){
            Node* current = head;
            while(current != nullptr){
                std::cout << current->data << ", ";
                current = current->next;
            }
        }

        //Operator Overloading
        LinkedList* operator=(LinkedList ll){
            Node* current = ll.head;
            LinkedList* newLL = new LinkedList();

            while(current != nullptr){
                newLL->insert(current->data);
                current = current->next;
            }

            return newLL;
        }

};