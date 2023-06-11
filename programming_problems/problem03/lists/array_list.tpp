#include "array_list.hpp"

// default constructor 
template <typename T>
ArrayList<T>::ArrayList() {
  // setting length equal to 0
  length = 0;
  array = new T[length];
}

// destructor
template <typename T>
ArrayList<T>::~ArrayList() {
  delete [] array;
  array = nullptr;
}

// copy constructor 
template <typename T>
ArrayList<T>::ArrayList(const ArrayList& rhs){
  // setting length and array equal to array parameter
  length = rhs.length;
  array = new T[length];

  // for loop to copy array contents of rhs into array
  for (int i = 0; i < length; i++){
    array[i] = rhs.array[i];
  }
}

// equal overloader
template <typename T>
ArrayList<T>& ArrayList<T>::operator=(ArrayList rhs){
    // check to make sure x is not the same as this
  if (this != &rhs){
    // deallocating memory of array
    delete [] array;
    // setting size equal to 0
    length = 0;
  
    // setting size equal to size of x
    length = rhs.length;
    array = new T[length];

    // copying x array into the new array called array
    for (int i = 0; i < length; i++){
      array[i] = rhs.array[i];
    }    
  }

  // returns correct pointer object
  return *this;
}

// swap function
template <typename T>
void ArrayList<T>::swap(ArrayList& rhs) {
  T* tempArray = array;
  delete [] array;
  array = rhs.array;
  std::size_t tempSize = length;
  length = rhs.length;
  rhs.length = tempSize;
}

// returns true if array is empty and false if not
template <typename T>
bool ArrayList<T>::isEmpty() const noexcept {
  return (length == 0);
}

// returns length of array
template <typename T>
std::size_t ArrayList<T>::getLength() const noexcept {
  return length;
}

// insert function
template <typename T>
bool ArrayList<T>::insert(std::size_t position, const T& item){
  
  // checking to see if position is in bounds
  if (position > length){
    return false;
  }
  
  // creates new template array with size plus one 
  T* oldArray = new T[length + 1];

  if (position <= length)
  {
    // copies old array into new array 
    for (int i = 0; i < position; i++){
      oldArray[i] = array[i];
    }

    // setting array of position to item
    oldArray[position] = item;
    
    // copies the rest of the array into the old array[i + 1]
    for (int i = position; i < length; i++)
    {
      oldArray[i+1] = array[i];
    }

    // incrementing length
    length++;

    // deallocating memory of array 
    delete [] array;
    // setting array equal to the old array
    array = oldArray;
  }

  // returning true if item was correctly added
  return (array[position] == item);
}

// remove method
template <typename T>
bool ArrayList<T>::remove(std::size_t position){
  // checking to make sure bag isn't empty and position is in bounds
  if (length == 0 || position > length){
    return false;
  }

  // decreasing size of the array 
  T* temp = new T[length - 1];

  // loop to remove instance of item
  for (int i = 0; i < length; i++)
  {
    if (i < position)
    {
      temp[i] = array[i];
    }
    else
    {
      temp[i] = array[i + 1];
    }
  }

  // deallocate old array
  delete [] array;
  // set pointer to new array
  array = temp;
  // delete pointer of temp
  temp = nullptr;
  // decreasing length variable
  length--;
  return true;
}

// setting length to 0 to clear the array
template <typename T>
void ArrayList<T>::clear() {
  length = 0;
}

// returns the value of array at position
template <typename T>
T ArrayList<T>::getEntry(std::size_t position) const {
  if (position >= length){
    return T();
  }

  return array[position];
}

// sets array of position to a specific value
template <typename T>
void ArrayList<T>::setEntry(std::size_t position, const T& newValue) {
  // making sure position is within bounds 
  if (position < 0 || position >= length){
    return;
  }

  array[position] = newValue;
}
