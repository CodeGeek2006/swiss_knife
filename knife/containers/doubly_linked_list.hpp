#pragma once
#include <iostream>
#include <stdexcept>
#include "../../knife/graph/list_node.hpp"

namespace knife::containers {
    template<typename T>

    class list {
    private:
        using list_node = knife::graph::list_node<T>;
        list_node *head;
        list_node *tail;
    public:
        list (){
            head = nullptr;
            tail = nullptr;
        }
        void push_front(T val) {
            list_node *new_list_node = new list_node (val);
            if (head==nullptr) {

                head = new_list_node;
                tail = new_list_node;
            }
            else {
                new_list_node->next = head;
                head->prev = new_list_node;
                head = new_list_node;
            }
        }
        void push_back(T val) {
            list_node *new_list_node = new list_node (val);
            if (head==nullptr) {
                head = new_list_node;
                tail = new_list_node;
            }
            else {
                new_list_node->prev= tail;
                tail->next = new_list_node;
                tail = new_list_node;
            }

        }

        T front() {
            if (head==nullptr) throw std::runtime_error("Empty list");
            return head->val;
        }




        void remove_front() {
            if (head==nullptr) throw std::runtime_error("Empty list, cant delete the front");
            list_node *temp=head;
            head= head->next;
            delete temp;
            if ( head==nullptr) {
                tail=nullptr;
            }
            else {
                head->prev=nullptr;
            }
        }
        void pop_back() {
            if (tail==nullptr) throw std::runtime_error("the lsit is empthy, cant remove tail");
            list_node *temp=tail;
            tail= tail -> prev;
            delete temp;
            if (tail == nullptr )
                head=nullptr;
            else {
                tail -> next = nullptr;
            }
        }

        T at(int index) {
            list_node *temp=head;
            int i=0;
            while (temp!=nullptr) {
                if (i==index) return temp->val;
                temp=temp->next;
                i++;


            }
            throw std::out_of_range("The index is out of range");

        }

        void pop_at(int index) {

            if (head == nullptr || index < 0) {
                throw std::out_of_range("The index is out of range");
            }

            list_node *temp = head;
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




        void insert(int val, int index) {
            if (index < 0) {
                throw std::out_of_range("The index is out of range");
            }

            list_node *new_list_node = new list_node(val);
            list_node *temp = head;
            int i = 0;

            if (index == 0) {
                push_front(val);
                return;
            }


            while (temp != nullptr && i < index) {
                temp = temp->next;
                i++;
            }

            if (temp == nullptr) {
                throw std::out_of_range("The index is out of range");
            }


            new_list_node->next = temp;
            new_list_node->prev = temp->prev;
            if (temp->prev != nullptr) {
                temp->prev->next = new_list_node;
            }
            temp->prev = new_list_node;
        }


    };
} // namespace knife::containers


