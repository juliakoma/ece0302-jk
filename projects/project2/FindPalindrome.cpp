#include <string>
#include <vector>
#include <iostream>
#include "FindPalindrome.hpp"

using namespace std;

//------------------- HELPER FUNCTIONS -----------------------------------------

// non-class helper functions go here, should be declared as "static" so that
// their scope is limited

// helper function to convert string to lower case
static void convertToLowerCase(string & value)
{
	for (int i=0; i<value.size(); i++) {
		value[i] = tolower(value[i]);
	}
}

//------------------- PRIVATE CLASS METHODS ------------------------------------

// private recursive function. Must use this signature!
void FindPalindrome::recursiveFindPalindromes(vector<string>
        candidateStringVector, vector<string> currentStringVector)
{    
	// candidate string vector is the current possible sentence
	// current string vector is the vector of all the words
	// current string vector should not change, then add one word to candidate

	// palindrome sentence contains all palindromes
	// current string is WordList
	// candidate is candSent

	// checking to see if string is empty
	if (currentStringVector.empty())
	{
		std::string string1;

		for (int i = 0; i < candidateStringVector.size(); i++) 
		{
        	string1 += candidateStringVector[i];
   		}

		convertToLowerCase(string1);

		if (isPalindrome(string1) == true)
		{
            palindromeSentence.push_back(candidateStringVector);
		}
	}

	else{
		// looping through all values of current string vector
		for (int k = 0; k < currentStringVector.size(); k++)
		{
			// temp vector
			std::vector<std::string> newVector = currentStringVector;

			// removing word at index i to create a new recursive call
			candidateStringVector.push_back(currentStringVector[k]);			
			newVector.erase(newVector.begin() + k);

			if (cutTest2(currentStringVector, candidateStringVector))
			{
				recursiveFindPalindromes(candidateStringVector, newVector);
			}

			candidateStringVector.pop_back();
		}
	}
	return;
}

// private function to determine if a string is a palindrome (given, you
// may change this if you want)
bool FindPalindrome::isPalindrome(string currentString) const
{
	locale loc;
	// make sure that the string is lower case...
	convertToLowerCase(currentString);
	// see if the characters are symmetric...
	int stringLength = currentString.size();
	for (int i=0; i<stringLength/2; i++) {
		if (currentString[i] != currentString[stringLength - i - 1]) {
			return false;
		}
	}
	return true;
}

//------------------- PUBLIC CLASS METHODS -------------------------------------

FindPalindrome::FindPalindrome()
{
	// initializing empty sentence
	//palindromeSentence = {};
	//num = 0;
}

FindPalindrome::~FindPalindrome()
{
	// destructor
	clear();
}

// returns current number of sentence palindromes
int FindPalindrome::number() const
{
	return palindromeSentence.size();
}

// clears vector
void FindPalindrome::clear()
{
	// TODO need to implement this...
	//num = 0;
	palindromeSentence.clear();
	wordList.clear();
}

bool FindPalindrome::cutTest1(const vector<string> & stringVector)
{
	// creating array with alphabet size
	const int alphaSize = 26;
	int charArray[alphaSize] = {0};
	
	// looping through each char of string to count the frequency of each char
	for (size_t i = 0; i < stringVector.size(); ++i)
	{
		const std::string& str = stringVector[i];
		for (size_t j = 0; j < str.length(); ++j)
		{
			char c = str[j];
            if (std::isalpha(c))
            {
                int index = std::tolower(c) - 'a';
                charArray[index]++;
            }

		}
	}

	// odd number count
	int oddNum = 0;

	// looping through alphabet and counting if a char appears an odd num of times
	for (int i = 0; i < alphaSize; i++)
	{
		if (charArray[i] % 2 != 0)
		{
			oddNum++;

			// if odd numbers is greater than 1, returns false
			if (oddNum > 1)
			{
				return false;
			}
		}
	}
	// if correct number of odd numbers, returns true
	return true;
}

bool FindPalindrome::cutTest2(const vector<string> & stringVector1,
                              const vector<string> & stringVector2)
{
	// TODO need to implement this...
	std::vector<std::string> left;
	std::vector<std::string> right;

	// copying contents of parameters in temp strings
	for (size_t i = 0; i < stringVector1.size(); ++i)
	{
		const std::string& str = stringVector1[i];
		left.push_back(str);
	}

	for (size_t i = 0; i < stringVector2.size(); ++i)
	{
		const std::string& str = stringVector2[i];
		right.push_back(str);
	}

	const int alphaSize = 26;
	int charArray1[alphaSize] = {0};
	int charArray2[alphaSize] = {0};

	for (size_t i = 0; i < stringVector1.size(); ++i)
	{
		const std::string& str = stringVector1[i];
		for (size_t j = 0; j < str.length(); ++j)
		{
			char c = str[j];
			int index = c - 'a';
			charArray1[index]++;
		}
	}

	for (size_t i = 0; i < stringVector2.size(); ++i)
	{
		const std::string& str = stringVector2[i];
		for (size_t j = 0; j < str.length(); ++j)
		{
			char c = str[j];
			int index = c - 'a';
			charArray2[index]++;
		}
	}
	// checking if left cut has less characters than right
	if (left.size() < right.size())
	{
		for (int i = 0; i < alphaSize; i++)
		{
			// checking if char exists, and if it exists more in the left than right
			if (charArray1[i] > 0 && charArray1[i] > charArray2[i])
			{
				return false;
			}
		}
	}

	// checking right cut
	else if (right.size() < left.size())
	{
		for (int i = 0; i < alphaSize; i++)
		{
			// checking if char exists, and if it exists more in the right than left
			if (charArray2[i] > 0 && charArray2[i] > charArray1[i])
			{
				return false;
			}
		}
	}

	return true;
}

// Add string method
bool FindPalindrome::add(const string & value)
{
	// creating temp string to hold value
	std::string temp = value;
	convertToLowerCase(temp);

	for(int i = 0; i < temp.size(); i++)
	{
		if(!isalpha(temp[i]))
		{
			return false;
		}
		if (ispunct(temp[i]) || temp[i] == ' ')
        {
            temp.erase(i--, 1);
        }
	}

	// checking to see if value is unique
	for (int i = 0; i < wordList.size(); i++)
	{
		convertToLowerCase(wordList[i]);
		if (temp == wordList[i])
		{
			return false;
		}
	}

	// adding value to vector
	//valueString.push_back(value);

	// adding value to full sentence
	wordList.push_back(temp);

	std::vector<std::string> temp1;

	if (cutTest1(wordList))
	{
		palindromeSentence.clear();
		recursiveFindPalindromes(temp1, wordList);
	}

	// two values sent to recursive call function to update palindromes
	//recursiveFindPalindromes(candidateSent, wordList);

	return true;
}

// add vector method
bool FindPalindrome::add(const vector<string> & stringVector)
{
	if (stringVector.empty())
	{
		return false;
	}

	for (int i = 0; i < stringVector.size(); i++)
	{
		// Creating a temporary string to hold the value
		std::string temp = stringVector[i];
		bool containsNonLetter = false;
		for (char c : temp)
		{
			if (!std::isalpha(c))
			{
				containsNonLetter = true;
				break;
			}
		}

		if (containsNonLetter)
		{
			continue; // Skip the word if it contains non-letter characters
		}

		for (int j = 0; j < wordList.size(); j++)
		{			
			convertToLowerCase(temp);

			if (!isalpha(temp[j]))
			{
				continue;
			}   
			if (ispunct(temp[j]) || temp[j] == ' ')
			{
				temp.erase(i--, 1);
			}
		}
	
		for (int j = 0; j < wordList.size(); j++)
		{
			convertToLowerCase(wordList[j]);
			if (temp == wordList[j])
			{
				return false;
			}
		}
		
		wordList.push_back(stringVector[i]);

	}
	

	std::vector<std::string> temp;

	if (cutTest1(wordList) == true)
	{
		recursiveFindPalindromes(temp, wordList);
	}

	return true;
}

vector< vector<string> > FindPalindrome::toVector() const
{
	// TODO need to implement this...
	return palindromeSentence;
}