# 📞 TelePhone Number Word Generator  

## 🌟 Overview  
The **Phone Word Generator** is a C++ program that generates all possible word combinations for a **7-digit phone number** based on the traditional telephone keypad mapping. This tool is perfect for creating **mnemonic phone numbers** for **marketing, branding, or easy recall**!  

---

## 🔥 Features  
✅ **Validates User Input** – Ensures the phone number is exactly **7 digits** and **excludes `0`s & `1`s**.  
🔢 **Keypad Mapping** – Converts digits into letter combinations based on a traditional phone keypad:  

```
  2 → ABC    3 → DEF    4 → GHI  
  5 → JKL    6 → MNO    7 → PRS  
  8 → TUV    9 → WXY
```

🔄 **Generates All Possible Word Combinations** – Iteratively finds every possible word for the given number.  
💾 **Saves Results to File** – Outputs combinations to a file named **`word_combinations.txt`**.  

---

## 🚀 How It Works  
1️⃣ **User Inputs** a 7-digit phone number (e.g., `2345678`).  
2️⃣ **Validation** – The program checks if the number is valid (**no `0`s or `1`s**, exactly **7 digits**).  
3️⃣ **Mapping & Generation** – The program **maps** digits to letters and **recursively generates** all possible words.  
4️⃣ **Saving Output** – All generated word combinations are stored in **`word_combinations.txt`**.  

---

## 🛠 Prerequisites  
🔹 A **C++ compiler** (e.g., Visual Studio, GCC, Clang).  
🔹 Basic knowledge of **compiling and running** C++ programs.  

---

## 📜 Example Output  
**Input:** `5672324`  
**Generated Words (Excerpt from `word_combinations.txt`):**  
```
JOSADAG
JOSADAH
JOSADAI
JOSADBG
...
```

---

## 🎯 How to Run  
1️⃣ **Clone the repository:**  
   ```sh
   git clone https://github.com/yourusername/PhoneWordGenerator.git
   cd PhoneWordGenerator
   ```

2️⃣ **Compile the C++ program:**  
   ```sh
   g++ phone_word_generator.cpp -o phone_word_generator
   ```

3️⃣ **Run the program:**  
   ```sh
   ./phone_word_generator
   ```

---

## 📌 License  
📜 This project is open-source and available under the **MIT License**.  

---

🚀 **Enjoy generating creative phone numbers!** 🔢✨  
