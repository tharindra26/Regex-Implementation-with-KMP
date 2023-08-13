******String Pattern Matching Program******

This program helps you search for specific string patterns in a text file.

**Instructions**
1)Input text file: Place the text file you want to search through in the String_Matching_Code folder.

2)Open IDE: Open your preferred C++ Integrated Development Environment (IDE) that supports C++ programming and can compile/run code.

3)Configure stringMatchingMain.cpp: In the stringMatchingMain.cpp file, configure the following variables in the main function:

4)inputTextFile: Set the variable to the name of the input text file that you placed in the String_Matching_Code folder.
pattern: Set the variable to the string pattern you want to search for in the text file.
Example:

inputTextFile = "input.txt"
pattern = "examplepattern"

5)Compile and run: Compile and run the stringMatchingMain.cpp code in your IDE. This will execute the program and search for the specified pattern in the input text file.

6)Check results: After successful compilation and running, the program will generate an output text file named output.txt in the String_Matching_Code folder. This file will contain the search results.

7)Review output: Open the output.txt file to see the search results. It will display information about where the specified pattern was found in the input text file.

**Note**
If you need to search for different patterns, make sure to clear the output.txt file before running the program again.

**Searching Pattern Constraints**
This program supports the following regex patterns:

Plain text: Matches any word without special regex characters.
`. (dot):** Matches any single character except a newline.
`*:** Matches zero or more occurrences of the preceding character or group.
`+:** Matches one or more occurrences of the preceding character or group.
`?:** Matches zero or one occurrence of the preceding character or group.
**At a time, you can use only one special regex character.**

Example:

cre*k is valid.
c.e*k is not valid within this program, as it contains both . and * in the same pattern.