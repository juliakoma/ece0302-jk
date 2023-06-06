#include "limited_size_bag.hpp"

// default constructor setting size = 0
template <typename T>
LimitedSizeBag<T>::LimitedSizeBag()
{
  size = 0;
}

// add method
template <typename T>
bool LimitedSizeBag<T>::add(const T &item)
{
  // return false if size is greater than maxsize
  if (size >= maxsize)
  {
    return false;
  }

  // adding item as last value in array
  array[size] = item;
  size++;
  return true;
}

template <typename T>
bool LimitedSizeBag<T>::remove(const T &item)
{
  // checking to make sure bag isn't empty
  if (size == 0){
    return false;
  }

  // creating object of the maxsize minus 1
  T temp[maxsize - 1];

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

  size--;
  return true;
}

// returning true if size = 0 and false if not
template <typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  return size == 0;
}

// method to return size
template <typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return size;
}

// contains method
template <typename T>
bool LimitedSizeBag<T>::contains(const T &item) const
{
  for (int i = 0; i < size; i++)
  {
    if (array[i] == item)
    {
      return true; // item is found
    }
  }
  // item is not found
  return false;
}

// resets size to 0
template <typename T>
void LimitedSizeBag<T>::clear()
{
  size = 0;
}

//returns frequency of a specific item in bag
template <typename T>
std::size_t LimitedSizeBag<T>::getFrequencyOf(const T &item) const
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
