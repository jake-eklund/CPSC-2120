/*
 * Name: Jake Eklund
 * Date Submitted: September 11, 2023
 * Lab Section: 007
 * Assignment Name: Lab 1: Linked List Based Stacks and Queues
 */

#pragma once
#include "List.h"

//This class represents a Queue implemented via Linked List
//Do not modify anything in the class interface
template <class T>
class ListQueue{

 private:
  List<T> queue;

 public:
  ListQueue();
  ~ListQueue();
  int size();
  bool empty();
  void enqueue(T);
  T dequeue();
  //Print the name and this ListQueue's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    queue.print(name);
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below

//Construct an empty ListQueue by initializing this ListQueue's instance variables
template <class T>
ListQueue<T>::ListQueue(){
  List<T> queue;
}

//Destroy all nodes in this ListQueue to prevent memory leaks
template <class T>
ListQueue<T>::~ListQueue(){
  for(int i = 1; i < queue.size(); i++)	{
		queue.removeEnd();
	}
}

//Return the size of this ListQueue
template <class T>
int ListQueue<T>::size(){
  return queue.size();
}

//Return true if this ListQueue is empty
//Otherwise, return false
template <class T>
bool ListQueue<T>::empty(){
  if (queue.size() == 0) {
    return queue.empty();
  }
  else {
    return false;
  }
}

//Create a new node with value, and insert that new node
//into this ListQueue in its correct position
template <class T>
void ListQueue<T>::enqueue(T value){
  queue.insertEnd(value);
}

//Dequeue an element from the queue.
//Note that here that means both removing it from the list
//AND returning the value
template <class T>
T ListQueue<T>::dequeue(){
  T top = queue.getFirst();
  queue.removeStart();
  return top;
}
