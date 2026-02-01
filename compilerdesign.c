#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 1. Function to check if a string is a Keyword
int isKeyword(char buffer[]) {
    char keywords[32][10] = {
        "auto","break","case","char","const","continue","default",
        "do","double","else","enum","extern","float","for","goto",
        "if","int","long","register","return","short","signed",
        "sizeof","static","struct","switch","typedef","union",
        "unsigned","void","volatile","while"
    };
    
    for(int i = 0; i < 32; ++i) {
        if(strcmp(keywords[i], buffer) == 0) {
            return 1;
        }
    }
    return 0;
}

// 2. Function to check if a character is an Operator
int isOperator(char ch) {
    char operators[] = "+-*/%=,;()[]{}";
    for(int i = 0; i < strlen(operators); ++i) {
        if(ch == operators[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    // --- INPUT DATA ---
    // We hardcode the source code here to keep everything in one file.
    // You can change this string to test different inputs.
    char input[] = "void main() { int a = b + 10; }";
    
    char buffer[20]; // Buffer to store the current word being built
    int j = 0;       // Index for the buffer
    int len = strlen(input);

    printf("--- Analyzing: \"%s\" ---\n\n", input);
    printf("TYPE\t\tVALUE\n");
    printf("----\t\t-----\n");

    for (int i = 0; i <= len; i++) {
        char ch = input[i];

        // CHECK 1: If current char is an Operator or Space or Null Terminator
        if (isOperator(ch) || isspace(ch) || ch == '\0') {
            
            // A. If buffer is not empty, we just finished a word (Keyword or Identifier)
            if (j != 0) {
                buffer[j] = '\0'; // Null terminate the buffer
                j = 0;            // Reset buffer index

                if (isKeyword(buffer))
                    printf("KEYWORD\t\t%s\n", buffer);
                else if (isdigit(buffer[0])) // Optional: Detect numbers
                    printf("CONSTANT\t%s\n", buffer);
                else
                    printf("IDENTIFIER\t%s\n", buffer);
            }

            // B. If the delimiter was actually an Operator, print it
            if (isOperator(ch)) {
                printf("OPERATOR\t%c\n", ch);
            }
        } 
        // CHECK 2: If it is alphanumeric, keep building the word
        else if (isalnum(ch)) {
            buffer[j++] = ch;
        }
    }

    return 0;
}