#pragma once
#include <iostream>
#include <stdexcept>
#include "../../knife/graph/list_node.hpp"

namespace knife {
    template<typename T>

    class list {
    public:
        class node {
        public:
            T val;
            node* next;
            node* prev;

            node( T value = nullptr) : val(value), next(nullptr), prev(nullptr) {}
        };
        node *head;
        node *tail;
    public:


        list (){
            head = nullptr;
            tail = nullptr;
        }
        void add_front(T val) {
            node *new_node = new node (val);
            if (head==nullptr) {

                head = new_node;
                tail = new_node;
            }
            else {
                new_node->next = head;
                head->prev = new_node;
                head = new_node;
            }
        }
        void add_back(T val) {
            node *new_node = new node (val);
            if (head==nullptr) {
                head = new_node;
                tail = new_node;
            }
            else {
                new_node->prev= tail;
                tail->next = new_node;
                tail = new_node;
            }

        }

        T get_front() {
            if (head==nullptr) throw std::runtime_error("Empty list");
            return head->val;
        }


        void display() {
            node* temp=head;
            while (temp!=nullptr) {
                std::cout<<temp->val<<" ";
                temp= temp ->next;
            }
        }

        void remove_front() {
            if (head==nullptr) throw std::runtime_error("Empty list, cant delete the front");
            node *temp=head;
            head= head->next;
            delete temp;
            if ( head==nullptr) {
                tail=nullptr;
            }
            else {
                head->prev=nullptr;
            }
        }
        void remove_tail() {
            if (tail==nullptr) throw std::runtime_error("the lsit is empthy, cant remove tail");
            node *temp=tail;
            tail= tail -> prev;
            delete temp;
            if (tail == nullptr )
                head=nullptr;
            else {
                tail -> next = nullptr;
            }
        }

        T get_at(int index) {
            node *temp=head;
            int i=0;
            while (temp!=nullptr) {
                if (i==index) return temp->val;
                temp=temp->next;
                i++;


            }
            throw std::out_of_range("The index is out of range");

        }

        void remove_at(int index) {

            if (head == nullptr || index < 0) {
                throw std::out_of_range("The index is out of range");
            }

            node *temp = head;
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




        void insert_at(int val, int index) {
            if (index < 0) {
                throw std::out_of_range("The index is out of range");
            }

            node *new_node = new node(val);
            node *temp = head;
            int i = 0;

            if (index == 0) {
                add_front(val);
                return;
            }


            while (temp != nullptr && i < index) {
                temp = temp->next;
                i++;
            }

            if (temp == nullptr) {
                throw std::out_of_range("The index is out of range");
            }


            new_node->next = temp;
            new_node->prev = temp->prev;
            if (temp->prev != nullptr) {
                temp->prev->next = new_node;
            }
            temp->prev = new_node;
        }


    };
}


