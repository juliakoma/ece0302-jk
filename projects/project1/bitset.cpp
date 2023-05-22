#include "bitset.hpp"

Bitset::Bitset() {
    // TODO
    // Default constructor : loop that will set all bits to 0
    N = 8;
    valid = true;

    bits = new bool[8];
    for (intmax_t i = 0; i < N; i++)
    {
        bits[i] = false;
    }

}

Bitset::Bitset(intmax_t size) {
    // TODO
    // Constructor with size N parameter
    // Error check if bitset is valid, will exit code if invalid
    if (size <= 0)
    {
        valid = false;
        return;
    }

    //If bitset is valid, will set parameter size to N and create bits array of size N
    N = size;
    bits = new bool[N];
    valid = true;

    for (intmax_t i = 0; i < N; i++)
    {
        bits[i] = false;
    }
}

Bitset::Bitset(const std::string & value) {
    // TODO        
    valid = true;
    N = value.length();
    
    // initalizing valid bitset and error checking for only 0 or 1
    for (intmax_t i = 0; i < N; i++)
    {
        if (value[i] != '0' && value[i] != '1'){
            valid = false;
            return;
        }
    }

    // If bitset is valid, then will iterate through string parameter and fill the bits array
    if (valid){
        N = value.length();
        bits = new bool[N];
        for (intmax_t i = 0; i < N; i++)
        {
            if(value[i] == '0'){
                bits[i] = 0;
            }
            else{
                bits[i] = 1;
            }
        }
    }
}

Bitset::~Bitset() {
    // TODO
    //Destructor
    delete [] bits;
}

// TODO: other methods

//Function to return the bit size
intmax_t Bitset::size() const{
    return N;
}

//method to determine if bitset is valid
bool Bitset::good() const{
    return valid;
}

//Method to set nth bit to 1
void Bitset::set(intmax_t index){
    //if index is not between 0 and N-1 then code will exit
    if (index < 0 || index >= N){
        valid = false;
        return;
    }
    //if index is in the range, nth value is set to 1
    bits[index] = true;

}

//Method to reset the nth bit to 0
void Bitset::reset(intmax_t index){
    if (index < 0 || index >= N)
    {
        valid = false;
        return;
    }
    else{
        bits[index] = false;
    }
}

//Method to toggle the nth bit (1 to 0 or 0 to 1)
void Bitset::toggle(intmax_t index){
    if (index < 0 || index >= N){
        valid = false;
        return;
    }
    else
    {
        bits[index] = !bits[index];
    }
}

//Method to check if nth bit is set
bool Bitset::test(intmax_t index){
    if (index < 0 || index >= N){
        valid = false; 
        return false; 
    }
   return bits[index] == true;
}

//Method to return bitset as a string of characters
std::string Bitset::asString() const{
    std::string result;

    for (intmax_t i = 0; i < N; i++)
    {        
        result += bits[i] ? '1' : '0';
    }

    return result;
}