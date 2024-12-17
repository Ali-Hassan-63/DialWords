# TelePhone number Word Generator  

## Overview  
The **Phone Word Generator** is a C++ program that generates all possible word combinations for a 7-digit phone number based on the traditional telephone keypad mapping. This tool is perfect for exploring mnemonic or creative word representations of phone numbers, commonly used for marketing and memory aids.  

---

## Features  
- Validates user input to ensure it’s a 7-digit phone number containing no `0`s or `1`s.  
- Maps numbers to letters using the standard telephone keypad:  
  - `2` → `ABC`  
  - `3` → `DEF`  
  - `4` → `GHI`  
  - `5` → `JKL`  
  - `6` → `MNO`  
  - `7` → `PRS`  
  - `8` → `TUV`  
  - `9` → `WXY`  
- Recursively generates all possible letter combinations for the phone number.  
- Saves the results to a file named `word_combinations.txt`.  

---

## How It Works  
1. The user inputs a 7-digit phone number (e.g., `2345678`).  
2. The program validates the number to ensure it is valid (7 digits, no `0`s or `1`s).  
3. The program maps each digit to its corresponding letters and recursively generates all possible combinations.  
4. The combinations are saved to `word_combinations.txt` in the project directory.  

---

## Prerequisites  
- A C++ compiler (e.g., visual studio).  
- Basic knowledge of compiling and running C++ programs.  

