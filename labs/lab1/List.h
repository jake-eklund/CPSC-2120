/*
 * Name: Jake Eklund
 * Date Submitted: 
 * Lab Section: 007
 * Assignment Name: Lab 1: Linked List Based Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List() {
  start = nullptr;
  mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
  Node<T> * new_node;
  while(start) {
    new_node = start->next;
    start = new_node;
    delete start;
  }
}

//Return the size of this list
template <class T>
int List<T>::size(){
  return mySize;
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
  return start == nullptr;
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
  Node<T> * n = new Node<T>(value);
  n->next = start;
  start = n;
  
  mySize++;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
  Node<T> * new_node = new Node<T>(value);
  new_node->next = start;
  
  if (empty() == true) {
    start = new_node;
    return;
  }
  else {
    while (new_node->next != nullptr) {
      new_node = new_node-> next;
    }
    new_node->next = new Node<T>(value);
  }
  
  mySize++;
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
  Node<T> * new_node = start;

  if (j == 0) {
      insertStart(value);
  }
  else {
    for (int i = 1; i < j; i++) {
      new_node = new_node->next;
    }

    Node<T> * node2 = new Node<T>(value);
    node2->next = new_node->next;
    new_node->next = node2;
  }
  
  mySize++;
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
  Node<T> * new_node = start;
  start = start->next;
  delete new_node;
  mySize--;
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
  Node<T> * new_node = start;

  while (new_node->next != nullptr) {
    new_node = new_node->next;
  }

  delete new_node;
  mySize--;
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
  Node<T> * new_node = start;

  for (int i = 0; i < j - 1; i++) {
    new_node = new_node->next;
  }

  Node<T> * node2 = new_node->next;
  new_node->next = new_node->next->next;
  delete node2;
  mySize--;
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
  return start->value;
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
  Node<T> * new_node = start;
  
  if (start == nullptr) {
      return T();
  }
  else {
    while (new_node-> next != nullptr) {
      new_node = new_node->next;
    }

    return new_node->value;
  }
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
  Node<T> * new_node = start;

  if (mySize == 0) {
    return T();
  }
  else {
    for (int i = 0; i < j; i++) {
      new_node = new_node->next;
    }

    return new_node->value;
  }
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
  Node<T> * new_node = start;

  for (int i = 0; i < mySize; i++) {
    if (key == new_node->value) {
      return i;
    }
    new_node = new_node->next;
  }
  
  return -1;
}