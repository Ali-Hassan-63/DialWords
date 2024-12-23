#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class LetterMapper {
private:
    const char* letterMapping[10] = { " ", " ", "ABC", "DEF", "GHI", "JKL", "MNO", "PRS", "TUV", "WXY" };

public:
    LetterMapper() {}
    // Returns letters corresponding to the digit
    const char* getLetters(char digit) const {
        if (digit < '2' || digit > '9') {
            throw invalid_argument("Invalid digit.");
        }
        return letterMapping[digit - '0'];
    }
};
class PhoneNumber {
private:
    string number;

    // Ensures the phone number is valid
    void validate() {
        if (number.size() != 7) {
            throw invalid_argument("Phone number must be 7 digits.");
        }
         for (int i = 0; i < 7; ++i) { 
           if (number[i] == '0' || number[i] == '1') { 
                throw invalid_argument("Phone number can't contain 0's or 1's."); 
            }
        }
    }

public:
    // Constructor validates the number
    PhoneNumber(const string& num) : number(num) {
        validate();
    }

    string getNumber() const {
        return number;
    }
    // Generates word combinations for the number
    void generateCombinations(const LetterMapper& mapper, ofstream& outputFile) const {
        const char* letters[7];  // Array to store the possible letters for each digit
        for (int i = 0; i < 7; ++i) {
            letters[i] = mapper.getLetters(number[i]);  // Store the corresponding letter set for each digit
        }
        int indices[7] = { 0 };  // Array to track the current index for each letter set
        while (true) {
            // Build the current combination based on the current indices
            string combination;
            for (int i = 0; i < 7; ++i) {
                combination += letters[i][indices[i]];  // Get the current letter for each digit
            }

            // Write the combination to the output file
            outputFile << combination << endl;

            // Increment indices to generate the next combination
            int position = 6;  // Start from the last digit
            while (position >= 0) {
                indices[position]++;  // Move to the next letter for the current digit
                if (indices[position] < strlen(letters[position])) {  // If within the bounds of the current letter set
                    break;
                }
                indices[position] = 0;  // Reset the current digit to the first letter in the set
                position--;  // Move to the previous digit
            }
            // If we've carried over past the first digit, we're done
            if (position < 0) {
                break;
            }
        }
    }
};

int main() {
    try {
        string inputNumber;
        cout << "Enter phone number (7 digits, no 0's or 1's): ";
        cin >> inputNumber;
        PhoneNumber phoneNumber(inputNumber);  // Validate phone number
        LetterMapper mapper;

        ofstream outputFile("word_combinations.txt");  // Output file for word combos
        if (!outputFile) {
            cerr << "Error: Could not open file for writing." << endl;
            return 1;
        }

        outputFile << "Entered: " << phoneNumber.getNumber() << endl;
        outputFile << "Generating combinations: " << endl;
        phoneNumber.generateCombinations(mapper, outputFile);  // Generate and save combinations

        outputFile.close();
        cout << "Combinations saved to word_combinations.txt" << endl;

    }
    catch (const exception& ex) {
        cerr << "Error: " << ex.what() << endl;
    }

    return 0;
}
