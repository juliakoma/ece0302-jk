#include "dynamic_bag.hpp"

// Default constructor
template<typename T>
DynamicBag<T>::DynamicBag() {
  // initializing size to 0
  size = 0;
  array = new T[size];
}
  
//Copy constructor
template<typename T>
DynamicBag<T>::DynamicBag(const DynamicBag<T>& x){
    // setting set size equal to new size array
    size = x.size;
    array = new T[size];

    for (int i = 0; i < size; i++){
      array[i] = x.array[i];
    }
}
    
template<typename T>
DynamicBag<T>::~DynamicBag(){
  //destructor that deallocates memory
  delete [] array;
  array = nullptr;
}
  
// Overloaded operator method
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T> x)
{  
  // check to make sure x is not the same as this
  if (this != &x){
    // deallocating memory of array
    delete [] array;
    // setting size equal to 0
    size = 0;
  
    // setting size equal to size of x
    size = x.size;
    array = new T[size];

    // copying x array into the new array called array
    for (int i = 0; i < size; i++){
      array[i] = x.array[i];
    }    
  }

  // returns correct pointer object
  return *this;
}

// swap method that swaps values of x and array
template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x){
  // new template called temp
  T* tempArray = array;
  array = x.array;
  std::size_t tempSize = size;
  size = x.size;
  x.size = tempSize;
}

// add method
template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  // creates new template array with size plus one 
  T* oldArray = new T[size + 1];

  // copies old array into new array 
  for (int i = 0; i < size; i++){
    oldArray[i] = array[i];
  }

  // setting last element of array equal to item added
  oldArray[size] = item;
  size++;

  // deallocating memory of array 
  delete [] array;
  // setting array equal to the old array
  array = oldArray;

  // if item was added correctly returns true, if not, returns false
  if (array[size - 1] == item){
    return true;
  } else {
    return false;
  }
}

//Remove method to remove an item
template<typename T>
bool DynamicBag<T>::remove(const T& item)
{
  // checking to make sure bag isn't empty
  if (size == 0){
    return false;
  }

  // decreasing size of the array 
  T* temp = new T[size - 1];

  int index = 0;
  bool remove = false;
  // loop to remove instance of item
  for (int i = 0; i < size; i++){
    if (array[i] == item || remove){
      temp[index++] = array[i];
    }else{
      remove = true;
    }
  }

  // deallocate old array
  delete [] array;
  // set pointer to new array
  array = temp;
  // delete pointer of temp
  temp = nullptr;

  size--;
  return true;
}

template<typename T>
bool DynamicBag<T>::isEmpty() const
{
  // returning true if size == 0 and false if not
  return (size == 0);
}

// method to return size
template<typename T>
std::size_t DynamicBag<T>::getCurrentSize() const
{
  return size;
}

template<typename T>
bool DynamicBag<T>::contains(const T& item) const
{  
  for (int i = 0; i < size; i++){
    if (array[i] == item){
      return true; // item is found
    }
  }
  //item is not found
  return false;
}

//removes all items in bag
template<typename T>
void DynamicBag<T>::clear(){
  size = 0;
}

//returns frequency of a specific item in bag
template<typename T>
std::size_t DynamicBag<T>::getFrequencyOf(const T & item) const
{
  int freq = 0;
  for (int i = 0; i < size; i++)
  {
    if (array[i] == item)
    {
      freq++;
    }
  }
  return freq;
}
