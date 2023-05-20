#include "bitset.hpp"

Bitset::Bitset() {
    // TODO
    //Default constructor : loop that will set all bits to 0
    for (intmax_t i = 0; i < size; i++)
    {
        bits[i] = false;
    }

}

Bitset::Bitset(intmax_t size) {
    // TODO
}

Bitset::Bitset(const std::string & value) {
    // TODO
}

Bitset::~Bitset() {
    // TODO
}

// TODO: other methods
