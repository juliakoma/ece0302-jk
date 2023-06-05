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
    size = x.size;
    array = new T[size];

    for (int i = 0; i < size; i++){
      array[i] = x.array[i];
    }
}
    
template<typename T>
DynamicBag<T>::~DynamicBag(){
  delete [] array;
  array = nullptr;
}
  
template<typename T>
DynamicBag<T>& DynamicBag<T>::operator=(DynamicBag<T> x)
{  
  if (this != &x){
    delete [] array;
    size = 0;
  
    size = x.size;
    array = new T[size];
    for (int i = 0; i < size; i++){
      array[i] = x.array[i];
    }    
  }

  return *this;
}

template<typename T>
void DynamicBag<T>::swap(DynamicBag<T>& x){
  T* tempArray = array;
  array = x.array;
  std::size_t tempSize = size;
  size = x.size;
  x.size = tempSize;
}

template<typename T>
bool DynamicBag<T>::add(const T& item)
{
  T* oldArray = new T[size + 1];

  for (int i = 0; i < size; i++){
    oldArray[i] = array[i];
  }
  oldArray[size] = item;
  size++;
  delete [] array;
  array = oldArray;

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
  if (size == 0){
    return false;
  }

  T* temp = new T[size - 1];

  int index = 0;
  bool remove = false;
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
  return (size == 0);
}

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
  for (int i = 0; i < size; i++){
    if (array[i] == item){
      freq++;
    }
  }
  return freq;
}
