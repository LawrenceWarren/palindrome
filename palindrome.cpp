// A program which checks to see if a word is a palindrome.
#include <cstring>
#include <iostream>

// Checks to see if the given argument is a valid word.
bool sanitise(int num, char* word) {
  if (num == 1 || strlen(word) <= 1) {
    return false;
  }

  // If the given word uses non-letter characters, fail
  for (int i = strlen(word) - 1; i >= 0; i--) {
    if (word[i] < 65 || word[i] > 122 || (word[i] >= 90 && word[i] <= 96)) {
      return false;
    }
  }

  return true;
}

char* caser(char* word)  // Converts all of the letters to lower case.
{
  char* temp = word;

  for (int i = strlen(word) - 1; i >= 0;
       i--)  // Loops through every char in the array.
  {
    if (temp[i] < 97) {
      temp[i] += 32;
    }  // Converts each char to lower case if it is upper case.
  }

  return temp;
}

bool check(char* word)  // Actually checks if the word is a palindrome.
{
  int length = strlen(word) - 1;

  for (int i = 0; length > i;
       length--, i++)  // One counter starts at the beginning of the word, one
                       // starts at the end, and they work inwards. The counters
                       // essentially represent the mirrored side of the word,
                       // and they are compared.
  {
    if (word[i] != word[length]) {
      return false;
    }  // if the value of counter 1 is different to counter 2, the word is not a
       // palindrome.
  }

  return true;
}

int main(int argc, char* argv[])  // Runs the above functions.
{
  if (sanitise(argc, argv[1]) == false)  // If the word is not sanitised, fail.
  {
    std::cout << "Please enter a valid word.";
    return 1;
  }

  if (check(caser(argv[1])) == true) {
    std::cout << "\"" << caser(argv[1]) << "\" is a palindrome";
  }

  else {
    std::cout << "\"" << caser(argv[1]) << "\" is not a palindrome.";
  }

  return 0;
}