#ifndef _ABSTRACT_BAG_HPP_
#define _ABSTRACT_BAG_HPP_

#include <cstdlib>

//TODO

#include "abstract_bag.hpp"

template<typename T> class Bag{
public:
  virtual Bag() = 0;
  
  virtual ~Bag() = 0;

  virtual std::size_t getCurrentSize() const = 0;

  virtual bool isEmpty() const = 0;

  virtual bool add(const T& entry) = 0;

  virtual bool remove(const T& entry) = 0;

  virtual void clear() = 0;

  virtual std::size_t getFrequencyOf(const T& entry) const = 0;

  virtual bool contains(const T& entry) const = 0;

  virtual static const std::size_t MAXSIZE = 100 = 0;
  
private:
  // implementation using fixed automatic storage
  std::size_t size;
  
  T data[MAXSIZE];
};

#include "bag_simple.tpp"



#endif