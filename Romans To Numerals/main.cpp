/*
 * ACM Hackathon 2025, Task 1: Romans to Numerals
 * In the most optimal way possible, convert Roman Numerals 
 * to Standard (i.e. Arabic) numerals.
 *
 * This is the main.cpp file, where the main function is written
 *
 * Team Members: (Write your names below, alphabetical by first name)
 * Kayvon Washington
 * Noah Boyd
*/

#include <stdio.h> // Basic C++ functionality
#include <stdlib> // Additional C++ functionality, including data structures
#include <string.h> // String manipulation

using namespace std; // Allows String Datatype

int main(String[] args) {
    // Define Variables
    char[] roman_value = {'I', 'V', 'X', 'L', 'C', 'D', 'M'}; // Roman Numerals
    int[] integer_value = {1 ,  5,  10,  50,  100,  500, 1000}; // values of Roman Numerals

    int total = 0; // Initialize to 0
    string roman_numeral_input = "" // Initialize to empty string
    bool isUppercase = false;

    // Get Input
    cout << "Enter a number in Roman Numerals: ";
    cin >> roman_numeral_input;

    // Check whether the input is uppercase
    if(roman_numeral_input[0].isupper()) {
        isUppercase = true;
    }

    // Make the input uppercase
    for(auto &c: roman_numeral_input) c = (char)toupper(c); 

    // Check Input for invalid characters
    for(int i = 0; i < length(roman_numeral_input); i++) {
        
        //Check whether the character was found
        bool found = false;

        // Check whether this character is in the array
        for(char c: roman_value) {
            if(roman_numeral_input[i] == c) {
                // This character is valid
                found = true;
                break;
            }
        }

        // If any character in the input isn't found in the array of valid Roman Numerals, 
        // then the whole input is invalid.
        if(!found) {
            cout << "\n ## Error: Invalid Character " << roman_numeral_input[i] << " ##" << endl;
            cout << "== Program ended unsuccessfully. ==" << endl;
            return 1;
        }

    } // endfor

    // Convert valid character input to an array of numbers
    int conv_roman_input[length(roman_numeral_input)];

    for(int i = 0; i < length(roman_numeral_input); i++) {
        // Find this character in the input string
        int result = roman_value.find(roman_numeral_input[i]);

        // Insert the corresponding numerical value into the converted input string
        conv_roman_input[i] = integer_value[result];
    }

    // Check each index against the next one in the sequence:
    // If this index is less than the following one, subtract it from the total.
    // If this index is more than or equal to the following one, add it to the total.
    // The last index is always added
    for(int i = 0; i < (sizeof(conv_roman_input)/sizeof(int))-1; i++) {
        if(conv_roman_input[i] < conv_roman_input[i+1]) {
            total -= conv_roman_input[i];
        }
        else {
            total += conv_roman_input[i];
        }
    }

    // Report Output
    if(!isUppercase) {

        // Make the input lowercase again
        for(auto &c: roman_numeral_input) c = (char)tolower(c); 
    }

    cout << roman_numeral_input << " --> " << total << endl;

    // Return 0
    cout << "\n== Program completed successfully. ==" << endl;
    return 0;
}