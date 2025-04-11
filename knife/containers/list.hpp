#pragma once
#include <iostream>
#include <stdexcept>

namespace knife {
    template<typename T>

    class List {
    public:
        class Node {
        public:
            T val;
            Node* next;
            Node* prev;

            Node( T value = nullptr) : val(value), next(nullptr), prev(nullptr) {}
        };
        Node *head;
        Node *tail;
    public:


        List (){
            head = nullptr;
            tail = nullptr;
        }
        void addFront(T val) {
            Node *newNode = new Node (val);
            if (head==nullptr) {

                head = newNode;
                tail = newNode;
            }
            else {
                newNode->next = head;
                head->prev = newNode;
                head = newNode;
            }
        }
        void addBack(T val) {
            Node *newNode = new Node (val);
            if (head==nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                newNode->prev= tail;
                tail->next = newNode;
                tail = newNode;
            }

        }

        T getFront() {
            if (head==nullptr) throw std::runtime_error("Empty list");
            return head->val;
        }


        void display() {
            Node* temp=head;
            while (temp!=nullptr) {
                std::cout<<temp->val<<" ";
                temp= temp ->next;
            }
        }

        void removeFront() {
            if (head==nullptr) throw std::runtime_error("Empty list, cant delete the front");
            Node *temp=head;
            head= head->next;
            delete temp;
            if ( head==nullptr) {
                tail=nullptr;
            }
            else {
                head->prev=nullptr;
            }
        }
        void removeTail() {
            if (tail==nullptr) throw std::runtime_error("the lsit is empthy, cant remove tail");
            Node *temp=tail;
            tail= tail -> prev;
            delete temp;
            if (tail == nullptr )
                head=nullptr;
            else {
                tail -> next = nullptr;
            }
        }

        T getAt(int index) {
            Node *temp=head;
            int i=0;
            while (temp!=nullptr) {
                if (i==index) return temp->val;
                temp=temp->next;
                i++;


            }
            throw std::out_of_range("The index is out of range");

        }

        void removeAt(int index) {

            if (head == nullptr || index < 0) {
                throw std::out_of_range("The index is out of range");
            }

            Node *temp = head;
            int i = 0;


            while (temp != nullptr && i < index) {
                temp = temp->next;
                i++;
            }


            if (temp == nullptr) {
                throw std::out_of_range("The index is out of range");
            }


            if (temp == head) {
                head = head->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                }
            } else if (temp == tail) {
                tail = tail->prev;
                if (tail != nullptr) {
                    tail->next = nullptr;
                }
            } else {
                temp->prev->next = temp->next;
                if (temp->next != nullptr) {
                    temp->next->prev = temp->prev;
                }
            }


            delete temp;
        }




        void insertAd(int val, int index) {
            if (index < 0) {
                throw std::out_of_range("The index is out of range");
            }

            Node *newNode = new Node(val);
            Node *temp = head;
            int i = 0;

            // if head
            if (index == 0) {
                addFront(val);
                return;
            }


            while (temp != nullptr && i < index) {
                temp = temp->next;
                i++;
            }

            if (temp == nullptr) {
                throw std::out_of_range("The index is out of range");
            }


            newNode->next = temp;
            newNode->prev = temp->prev;
            if (temp->prev != nullptr) {
                temp->prev->next = newNode;
            }
            temp->prev = newNode;
        }


    };
}



//when head==nullptr empty