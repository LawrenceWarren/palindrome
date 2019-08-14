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

bool check(char word[])
{
    char* backwards;

    //Some code

    return false;
}


int main(int argc, char* argv[])
{
    if(sanitise(argc, argv[1])==false)
    {
        std::cout << "Please enter a valid argument.";
        return 1;
    }

    if (check(argv[1])==true) { std::cout << "\"" << argv[1] << "\" is a palindrome"; }

    else { std::cout << "\""<< argv[1] << "\" is not a palindrome."; }
    
    return 0;
}