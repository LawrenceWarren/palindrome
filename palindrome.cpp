// A program which checks to see if a word is a palindrome
#include <cstring>
#include <iostream>
#include <string>

// Checks to see if the given argument is a valid word
bool sanitise(int num, std::string word) {
  if (num == 1 || word.length() == 0) {
    return false;
  }

  // If the given word uses non-letter characters, fail
  for (int i = word.length(); i >= 0; i--) {
    if (word[i] < 65 || word[i] > 122 || (word[i] >= 90 && word[i] <= 96)) {
      return false;
    }
  }

  return true;
}

// Converts all of the letters to lower case
std::string caser(std::string word) {
  auto temp = word;

  // Loops through every char in the array
  for (int i = word.length(); i >= 0; i--) {
    if (temp[i] <= 96) {
      temp[i] += 32;
    }  // Converts each char to lower case if it is upper case.
  }

  return temp;
}

// Actually checks if the word is a palindrome
bool check(std::string word) {
  int length = word.length();

  // One counter starts at the beginning of the word, one starts at the end, and
  // they work inwards. The counters essentially represent the mirrored side of
  // the word, and they are compared.
  for (int i = 0; length > i; length--, i++) {
    // if counter 1 is different to counter 2, the word is not a palindrome
    if (word[i] != word[length]) {
      return false;
    }
  }

  return true;
}

int main(int argc, char* argv[]) {
  auto word = std::string(argv[1]);

  // If the word is not sanitised, fail
  if (!sanitise(argc, word)) {
    std::cout << "Please enter a valid word.";
    return 1;
  }

  if (check(caser(word))) {
    std::cout << "\"" << caser(argv[1]) << "\" is a palindrome";
  } else {
    std::cout << "\"" << caser(argv[1]) << "\" is not a palindrome.";
  }

  return 0;
}
