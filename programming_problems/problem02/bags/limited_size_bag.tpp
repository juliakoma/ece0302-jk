#include "limited_size_bag.hpp"

template <typename T>
LimitedSizeBag<T>::LimitedSizeBag()
{
  size = 0;
}

template <typename T>
bool LimitedSizeBag<T>::add(const T &item)
{
  if (size >= maxsize)
  {
    return false;
  }

  array[size] = item;
  size++;
  return true;
}

template <typename T>
bool LimitedSizeBag<T>::remove(const T &item)
{
  if (size == 0){
    return false;
  }

  T temp[maxsize - 1];

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
  //delete array;
  // set pointer to new array
  //array = temp;
  // delete pointer of temp
  //temp = nullptr;

  size--;

  return true;
}

template <typename T>
bool LimitedSizeBag<T>::isEmpty() const
{
  return size == 0;
}

template <typename T>
std::size_t LimitedSizeBag<T>::getCurrentSize() const
{
  return size;
}

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

template <typename T>
void LimitedSizeBag<T>::clear()
{
  size = 0;
}

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
