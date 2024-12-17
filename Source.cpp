#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

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
        for (char digit : number) {
            if (digit == '0' || digit == '1') {
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
        string combination(7, ' ');
        generateCombinationsRecursive(mapper, 0, combination, outputFile);
    }

private:
    // Recursively generates combinations
    void generateCombinationsRecursive(const LetterMapper& mapper, int index, string& combination, ofstream& outputFile) const {
        if (index == 7) {
            outputFile << combination << endl;
            return;
        }
        const char* letters = mapper.getLetters(number[index]);
        for (int i = 0; letters[i] != '\0'; ++i) {
            combination[index] = letters[i];
            generateCombinationsRecursive(mapper, index + 1, combination, outputFile);
        }
    }
};

int main() {
    try {
        string inputNumber;
        cout << "Enter phone number (7 digits, no 0's or 1's): ";
        cin >> inputNumber;
        inputNumber.erase(remove(inputNumber.begin(), inputNumber.end(), '-'), inputNumber.end());

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
