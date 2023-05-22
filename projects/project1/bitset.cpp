#include "bitset.hpp"

Bitset::Bitset() {
    // TODO
    // Default constructor : loop that will set all bits to 0
    for (intmax_t i = 0; i < 8; i++)
    {
        bits[i] = false;
    }

}

Bitset::Bitset(intmax_t size) {
    // TODO
    // Constructor with size N parameter
    // sets all bits to 0 and will exit code if bitset is invalid
}

Bitset::Bitset(const std::string & value) {
    // TODO
}

Bitset::~Bitset() {
    // TODO
}

// TODO: other methods
