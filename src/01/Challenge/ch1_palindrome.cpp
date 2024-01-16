// C++ Code Challenges, LinkedIn Learning

// Challenge #1: Checking for Palindromes
// Write a function to check if a string is a palindrome or not.
// Examples: civic, radar, level.

#include <iostream>
#include <algorithm>

// is_palindrome()
// Summary: This function receives a string and returns true if the string is a palindrome, false otherwise.
// Arguments:
//           str: The string to analyze.
// Returns: A boolean value. True for palindromes, false otherwise.
bool is_palindrome(std::string str){

    // Write your code here
    int len = str.size();
    int halflen = len / 2;
    bool test = true;

    char cf;
    char cb;
    for (int i=0; i < halflen; i++){
        cf = tolower(str[i]);
        cb = tolower(str[len-1-i]);
        /*std::cout << i;
        std::cout << cf;
        std::cout << cb;*/
        if (cf != cb){
            test = false;
        }
    }

    return test;
}

// Main function
int main(){
    std::string s;
    std::cout << "Enter a string: " << std::flush;
    std::getline(std::cin,s);
    std::cout << "\n\"" << s << (is_palindrome(s) ? "\" is" : "\" is not" ) << " a palindrome.\n\n";
    return 0;
}
