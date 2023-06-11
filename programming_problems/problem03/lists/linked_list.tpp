#include "linked_list.hpp"

// default constructor
template <typename T>
LinkedList<T>::LinkedList()
{
  // initializing length equal to 0
  length = 0;
}

// destructor method
template <typename T>
LinkedList<T>::~LinkedList()
{
  // clear array
  clear();
}

// copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& x)
{
  // setting length of x equal to variable length
  length = x.length;
  // creating a new local node
  Node<T>* newNode = x.head;
  // if x head is = 0 then length and head of new node is 0;
  if(x.head == 0)
  {
    head = 0;
    length = 0;
    return;
  }
  // if head is not 0, set head equal to x head
  else
  {
    head = x.head;
  }

  head = x.head;
  length = x.length;
}

// equal overloader
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> x)
{
  swap(x);

  // returns correct pointer object
  return *this;
}

// swap function
template <typename T>
void LinkedList<T>::swap(LinkedList& x) 
{
  std::swap(length, x.length);
  std::swap(head, x.head);
}

template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
  // returns true if length = 0 and false if not
  return (length == 0);
}

template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
  // returns length of linked list
  return length;
}

// insert method
template <typename T>
bool LinkedList<T>::insert(std::size_t position, const T& item)
{
  // checking position value
  if (position < 0 || position > length)
  {
    return false;
  }

  // creating new local node with item
  Node<T>* newNode = new Node<T>(item);

  //If position is at beginning, sets it as the head
  if (position == 0)
  {
    newNode -> setNext(head);
    head = newNode;
  }
  // if position is in middle or end
  else
  {
    // sets the node before the one changed to the head
    Node<T>* prevNode = head;

    // loop to traverse the list to insert in correct spot
    for (std::size_t i = 0; i < position - 1; i++)
    {
      prevNode = prevNode -> getNext();
    }

    newNode -> setNext(prevNode -> getNext());
    prevNode -> setNext(newNode);
  }

  length++;

  return true;
}

// remove method
template <typename T>
bool LinkedList<T>::remove(std::size_t position)
{
  // checking value of position
  if (position >= length)
  {
    return false;
  }

  // if position 0, sets a local node to null
  if (position == 0)
  {
    Node<T>* removeNode = head;
    head = head -> getNext();
    removeNode = nullptr;
    length--;
  }
  // if position is in middle or end
  else
  {
    // setting previous node 
    Node<T>* prevNode = head;
    for (std::size_t i = 0; i < position - 1; i++)
    {
      prevNode = prevNode -> getNext();
    }
    // setting local node to remove
    Node<T>* removeNode = prevNode -> getNext();
    // relisting nodes
    prevNode -> setNext(removeNode -> getNext());
    // deleting node
    delete removeNode;
    length--;
  }

  return true;
}

// clears list
template <typename T>
void LinkedList<T>::clear()
{
  length = 0;
}

template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{  
  // error checking position
  if (position < 0 || position >= length){
    return T();
  }

  // creating local node 
  Node<T>* node = head;

  // traverse through array to find node at position
  for (std::size_t i = 0; i < position; i++)
  {
    node = node -> getNext();
  }  
  
  // return value of node
  return node -> getItem();
}

template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
  // error checking position is in bounds
  if (position < 0 || position >= length)
  {
    return;
  }

  // local node
  Node<T>* node = head;
  
  // traverse through array to find node at position
  for (std::size_t i = 0; i < position; i++)
  {
    node = node -> getNext();
  }

  // set node to new value given
  node -> setItem(newValue);
}
