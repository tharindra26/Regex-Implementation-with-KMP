# C++ Regex Implementation

This repository contains a C++ program that implements a simple regular expression search functionality. The program supports common regex elements like '.', '*', '+', and '?', allowing you to search for patterns in a given text file. The search results are then saved in an `output.txt` file.

## Features

- Implementation of regex-like pattern searching using C++.
- Supports '.' (dot), '*' (asterisk), '+' (plus), and '?' (question mark) regex elements.
- Provides options for various pattern searches, including normal, dot, asterisk, plus, and question mark searches.

## Getting Started

1. Clone the repository using the following command:
git clone https://github.com/your-username/CppRegexImplementation.git
2. Compile the C++ source code: g++ -o regex_search main.cpp
3. Run the program: ./regex_search

4. View the search results in the `output.txt` file.

## Usage

1. Edit the `testRun.txt` file to include the text in which you want to search for patterns.
2. Modify the `pattern` variable in the `main.cpp` file to set the regex pattern you want to search for.

## Pattern Types

- **Normal Search:** Search for a regular pattern without any special symbols.
- **Dot Search:** Search for a pattern containing a dot ('.') to match any character.
- **Asterisk Search:** Search for a pattern containing an asterisk ('*') to match zero or more occurrences of the preceding character.
- **Plus Search:** Search for a pattern containing a plus ('+') to match one or more occurrences of the preceding character.
- **Question Mark Search:** Search for a pattern containing a question mark ('?') to match zero or one occurrence of the preceding character.

## Contributions

Contributions are welcome! If you find bugs or want to enhance the program, feel free to open issues or pull requests.

## Acknowledgments

- This project was created to showcase the implementation of simple regex-like search functionality in C++.
 
