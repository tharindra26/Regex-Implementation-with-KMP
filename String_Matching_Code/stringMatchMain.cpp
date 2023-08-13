#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

void createLpsArray(char *pattern, int *lps, int patLen);
void KMPSearch(char* pattern, char* txt, int lineNumber);
void KMPSearch_dot(char* pattern, char* txt, int dotIndex, int lineNumber);
void KMPSearch_astrix(char* pattern, char* txt,char precedigCharacter, char postAstrixCharacter, int astrixIndex, int lineNumber);
void normalSearch(string pattern, char *stringLine, int lineNum);
void dotSearch(string pattern, char *stringLine, int lineNum);
void astrixSearch(string pattern, char *stringLine, int lineNum);
void plusSearch(string pattern, char *stringLine, int lineNum);
void questionSearch(string pattern, char *stringLine, int lineNum);
void appendToFile(int lineNumber, int index);



int main(){
    cout<<"\n\033[32mMain function is running without compilation errors :)\nSee output.txt for search results. \033[0m \n"<<endl;
    
   
    //Enter the input text file name
    std::string inputTextFile = "testRun.txt";
    //Enter the pattern
    string pattern = "cre*k";



    std::string inputFilePath = "..\\" + inputTextFile;
    std::ifstream inputFile(inputFilePath);
 

    

    if (!inputFile) {
        std::cerr << "Error opening the file." << std::endl;
        return 1;
    }

    std::string line;
    int lineNum=1;

    while (std::getline(inputFile, line)) {

        char* stringLine = new char[line.length() + 1];
        strcpy(stringLine, line.c_str());

        if (pattern.find('.') != std::string::npos){ //f.x  ar.
            dotSearch(pattern, stringLine, lineNum);
        }
        else if (pattern.find('*') != std::string::npos){ //cre*k  cre*
            astrixSearch(pattern, stringLine, lineNum);
        }
        else if (pattern.find('+') != std::string::npos){ // cre+k bloo+m
            plusSearch(pattern, stringLine, lineNum);
        }
        else if (pattern.find('?') != std::string::npos){  //cre?k moo?n
            questionSearch(pattern, stringLine, lineNum);
        } else{
            normalSearch(pattern, stringLine, lineNum);
        }

        lineNum++;
        delete[] stringLine;
    }
    inputFile.close();
   

}

void createLpsArray(char *pattern, int *lps, int patLen){ //LongestPrefixSuffixArray
    lps[0]=0;
    int i=1;
    int pointer=0;
    while(i<patLen){
        if(pattern[i]==pattern[pointer]){
            pointer++;
            lps[i] = pointer;
            i++;
        }else{
            pointer=0;
            lps[i]=0;
            i++;
        }
    }
}


void KMPSearch(char* pattern, char* txt, int lineNumber)  //KMP Search Algorithm without mofification
{
    int M = strlen(pattern);
    int N = strlen(txt);

    int lps[M];
 
    createLpsArray(pattern, lps, M);
 
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j)) {
        
        if (pattern[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
                
            if(txt[i]==' '){
                appendToFile(lineNumber, i-j);
            }

            j = lps[j - 1];
        }
 
        else if (i < N && pattern[j] != txt[i]) {
            if (j != 0)
                j = lps[j-1];
            else
                i = i + 1;
        }
    }
}

void KMPSearch_dot(char* pattern, char* txt, int dotIndex, int lineNumber) //KMP Search Algorithm, modified for dot dearch
{
    int M = strlen(pattern);
    int N = strlen(txt);


    int lps[M];
 
    createLpsArray(pattern, lps, M);
 
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j)) {
        if (pattern[j] == txt[i]) {
            j++;
            i++;
        }

        if(j==(dotIndex)) {

            i++;
        }

        if (j == M) {
                
                if(txt[i]==' '){
                    appendToFile(lineNumber, i-j-1);
                }
            j = lps[j - 1];
        }
 
        else if (i < N && pattern[j] != txt[i]) {
            if (j != 0)
                j = lps[j-1];
            else
                i = i + 1;
        }
    }
}

void KMPSearch_astrix(char* pattern, char* txt,char precedigCharacter, char postAstrixCharacter, int astrixIndex, int lineNumber)//KMP algorithm modified for asterix search
{
    int M = strlen(pattern);
    int N = strlen(txt);
    int astrixIndexTemp=astrixIndex;
    

    int lps[M];
 
    createLpsArray(pattern, lps, M);
 
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    int numberOfPassings=0;
    while ((N - i) >= (M - j)) {
        if (pattern[j] == txt[i]) {
            j++;
            i++;
        }

        if(j== astrixIndexTemp){
            if(postAstrixCharacter==precedigCharacter){
                
                while(txt[i]==precedigCharacter && txt[i+1]==precedigCharacter && txt[i+2]==precedigCharacter){                    
                    i++;
                    numberOfPassings++;
                }
              
            }else{
                while(txt[i]==precedigCharacter && txt[i+1]==precedigCharacter){
                    i++;
                  
                    numberOfPassings++;
                }
              
            }
            if(numberOfPassings!=0){
                i++;
            }
        }
        

        if (j == M) {
                
                if(txt[i]==' '){
                    appendToFile(lineNumber, i-j-numberOfPassings);
                }
    
            j = lps[j - 1];
        }
 
        else if (i < N && pattern[j] != txt[i]) {
            if (j != 0)
                j = lps[j-1];
            else
                i = i + 1;
        }
    }
    
}

void normalSearch(string pattern, char *stringLine, int lineNum){  // Pattern without any special symbols
    char patternText[pattern.length() + 1];
    strcpy(patternText, pattern.c_str());
    KMPSearch(patternText, stringLine,lineNum);
    
}

void dotSearch(string pattern, char *stringLine, int lineNum){ //pattern with a dot
    std::string resultString = "";
    int flag=0;
    int dotIndex=0;
    

    for (char c : pattern) {
        if (c != '.') {
            resultString += c;
            flag++;
        }else{
            dotIndex=flag;
        }
    }

    char patternText[resultString.length() + 1];
    strcpy(patternText, resultString.c_str());

    KMPSearch_dot(patternText, stringLine, dotIndex, lineNum);
}

void astrixSearch(string pattern, char *stringLine, int lineNum){ //pattern with a asterix
    std::string resultString = "";
    int flag=0;
    int astrixIndex=0;
    char precedingCharacter;

    for (char c : pattern) {
        if (c != '*') {
            resultString += c;
            flag++;
        }else{
            astrixIndex=flag;
            precedingCharacter=pattern[astrixIndex-1];
        }
    }

    char postAstrixCharacter=pattern[astrixIndex+1];

    char patternText[resultString.length() + 1];
    strcpy(patternText, resultString.c_str());

    //for preceding character count=0
    std::string resultStringWithoutPreceding = "";
    for(int i=0; i<pattern.length(); i++) {
        if(i!=astrixIndex-1 && i!=astrixIndex){
            resultStringWithoutPreceding+=pattern[i];
        }
    }
    char patternTextWithoutPreceding[resultString.length()+1];
    strcpy(patternTextWithoutPreceding, resultStringWithoutPreceding.c_str());

    //for preceding character count=0
    KMPSearch(patternTextWithoutPreceding, stringLine,lineNum);
    //for preceding character count>=1
    KMPSearch_astrix(patternText, stringLine,precedingCharacter, postAstrixCharacter, astrixIndex, lineNum);

    //printWithHighlight(stringLine, highlightIndices);
    
    
}

void plusSearch(string pattern, char *stringLine, int lineNumber){ //pattern with a plus
    std::string resultString = "";
    int flag=0;
    int astrixIndex=0;
    char precedingCharacter;
    vector<size_t> highlightIndices;

    for (char c : pattern) {
        if (c != '+') {
            resultString += c;
            flag++;
        }else{
            astrixIndex=flag;
            precedingCharacter=pattern[astrixIndex-1];
        }
    }

    char postAstrixCharacter=pattern[astrixIndex+1];

    char patternText[resultString.length() + 1];
    strcpy(patternText, resultString.c_str());

    //for preceding character count>=1
    KMPSearch_astrix(patternText, stringLine,precedingCharacter, postAstrixCharacter, astrixIndex, lineNumber);

    //printWithHighlight(stringLine, highlightIndices);
    
}

void questionSearch(string pattern, char *stringLine, int lineNum){ //pattern with a question mark
    std::string resultString = "";
    int flag=0;
    int astrixIndex=0;
    char precedingCharacter;

    for (char c : pattern) {
        if (c != '?') {
            resultString += c;
            flag++;
        }else{
            astrixIndex=flag;
            precedingCharacter=pattern[astrixIndex-1];
        }
    }

    char patternText[resultString.length() + 1];
    strcpy(patternText, resultString.c_str());

    //for preceding character count=0
    std::string resultStringWithoutPreceding = "";
    for(int i=0; i<pattern.length(); i++) {
        if(i!=astrixIndex-1 && i!=astrixIndex){
            resultStringWithoutPreceding+=pattern[i];
        }
    }
    char patternTextWithoutPreceding[resultString.length()+1];
    strcpy(patternTextWithoutPreceding, resultStringWithoutPreceding.c_str());

    //for preceding character count=0
    KMPSearch(patternTextWithoutPreceding, stringLine,lineNum);
    //for preceding character count==1
    KMPSearch(patternText, stringLine,lineNum);
       
}

void appendToFile(int lineNumber, int index) {
    // Check if the file exists
    std::ifstream fileCheck("..\\output.txt");
    bool fileExists = fileCheck.good();
    fileCheck.close();

    if (!fileExists) {
        // If the file doesn't exist, create it
        std::ofstream createFile("..\\output.txt");
        createFile.close();
    }

    std::ofstream outFile("..\\output.txt", std::ios::app);

    if (!outFile.is_open()) {
        std::cerr << "Error opening the file." << std::endl;
        return;
    }

    std::ostringstream oss;
    oss << "Found pattern at line: " << lineNumber << " index: " << index << std::endl;

    outFile << oss.str();

    outFile.close();
}
