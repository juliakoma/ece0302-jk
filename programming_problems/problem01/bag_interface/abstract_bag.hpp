/**
 * @file abstract_bag.hpp
 * @author Julia Koma 
 * @version 0.1
 * @date 2023-05-25
 */

#ifndef ABSTRACT_BAG_HPP
#define ABSTRACT_BAG_HPP

#include <cstdlib>

template<typename T> class AbstractBag{
public:

/**
 * @brief Returns current size of the bag
 * @return size
 * */
  virtual std::size_t getCurrentSize() const = 0;

/**
 * @brief Checks if bag is empty and returns true if bag is equal to 0
 * no arguments passed into function
 * @return true if bag is empty, false if not
 * */
  virtual bool isEmpty() const = 0;

/**
 * @brief adds parameter value as the next available element in the array
 * @param entry passed by reference that is a value that wants to be added to the array
 * @return bool of false if bag is full and true element was added
 * */
  virtual bool add(const T& entry) = 0;

/**
 * @brief Method to remove a specific element from the bag
 * @param entry passed by reference that is a value that needs to be removed from array
 * first loop will loop through all values of array and search for value equal to the parameter, if found, break loop and removes element
 * second loop will shift all values to the left after the value has been removed
 * @return bool of false if bag is empty or if value is not found in array
 * @return bool of true if value has been successfully removed
 * */
  virtual bool remove(const T& entry) = 0;

/**
 * @brief Empties bag by setting size equal to 0
 * void function
 * */
  virtual void clear() = 0;

/**
 * @brief Counts frequency of a number in the array through a for loop
 * @param value passed by reference that we will count the frequency of
 * @pre loops through array starting at 0 until i < size of array
 * if the element equals the value passed into the function, the freqeuncy is incremented
 * @return frequency value after the loop completes
 * */
  virtual std::size_t getFrequencyOf(const T& entry) const = 0;

/**
 * @brief This method allows you to see if a specific value exists somewhere in the bag
 * @param value that we are searching for
 * if the frequency is not 0 then true is returned
 * if the frequency is 0 then false is returned
 * */
  virtual bool contains(const T& entry) const = 0;

};


#endif


