#ifndef BITSET_HPP
#define BITSET_HPP
#include <stdint.h>
#include <stdlib.h>
#include <string>

class Bitset{
public:

  // Default Constructor
  Bitset();

  // Constructor with parameter size, will set N equal to parameter size and then create bit array with N
  Bitset(intmax_t size);

  // Constructor with parameter string
  // Function includes an error check for a valid string and then size of the bitset will be allocated according to the length of the string 
  Bitset(const std::string & value);

  // Destructor
  ~Bitset();

  Bitset(const Bitset & ) = delete;
  Bitset & operator=(const Bitset &) = delete;

  // Getter function that returns size
  intmax_t size() const;

  // Method to return if bitset is valid
  bool good() const;

  // Method to set nth bit to 1
  void set(intmax_t index);

  // Method that will reset the nth bit to 0
  void reset(intmax_t index);

  // Method to toggle the nth bit (1 to 0 or 0 to 1)
  void toggle(intmax_t index);

  // Method to check if the nth bit is set
  bool test(intmax_t index);

  // Method to return bitset as a string of characters
  std::string asString() const;

private:
    //Creating intmax N value that will hold size or length of array
    intmax_t N;

    // Initializing pointer to a bool array bits
    bool* bits = new bool[8];

    // Bool value of valid 
    bool valid;
};

#endif
