//A program which checks to see if a word is a palindrome.
#include <iostream>
#include <cstring>

bool sanitise(int num, char word[])
{
    if (num==1 || strlen(word)<=1)
    {
        return false;
    }

    else { return true; }
}

int main(int argc, char* argv[])
{
    if(sanitise(argc, argv[1])==false)
    {
        std::cout << "Please enter a valid argument.";
    }
}