# complier-designCOMPANY: CODTECH IT SOLUTIONS

NAME: KABYATREE KAKATI

INTERN ID: CTIS1433

DOMAIN: C Programming

DURATION: 4 Weeks

MENTOR: Neela Santhosh Kumar

Description of the Task:-

The core objective of this project was to design and implement a Lexical Analyzer (also known as a scanner or tokenizer), which serves as the first phase of a compiler. In the context of computer science and compiler design, high-level source code—written by humans—appears to the machine as a meaningless stream of characters. The task of the lexical analyzer is to read this raw input stream and group characters into meaningful sequences called lexemes. These lexemes are then categorized into specific token types, such as Keywords, Identifiers, Operators, and Constants.

The Specific Implementation: The C program provided performs this task by simulating the behavior of a finite automata. It processes an input string (representing source code) character by character. The logic utilizes a buffer system to accumulate alphanumeric characters. When the program encounters a delimiter—such as a space, newline, or operator—it halts the accumulation process and analyzes the contents of the buffer.

The categorization logic functions as follows:

Keywords: The buffered string is compared against a pre-defined lookup table containing 32 standard C keywords (e.g., int, void, return). If a match is found, the token is flagged as a KEYWORD.

Identifiers: If the string is alphanumeric but not a keyword, it is classified as an IDENTIFIER (variable or function name).

Constants: By checking if the first character of the token is a digit, the program distinguishes numeric literals (CONSTANTS) from standard identifiers.

Operators: Special characters (like +, =, {, ;) are identified immediately via a dedicated lookup array and printed as OPERATORS.

This task demonstrates fundamental string manipulation, the use of standard libraries for character classification, and the logic required to parse structured text.

Tools Used To achieve this implementation, specific software tools and standard libraries were utilized to ensure efficiency and portability.
Programming Language: C C was chosen as the implementation language because of its proximity to the hardware and its historical significance in compiler construction (most early Unix compilers were written in C). It provides granular control over memory and string manipulation, which is essential for text parsing.

Standard Libraries:

<stdio.h>: Used for input/output operations, specifically printf to display the categorized tokens to the console.

<string.h>: Crucial for the strcmp() function, which compares the buffered string against the array of keywords, and strlen() for loop bounds.

<ctype.h>: This library simplified the logic significantly by providing functions like isalnum() (to check for letters/numbers) and isdigit() (to identify constants), removing the need for complex manual ASCII range checks.

Compiler: GCC (GNU Compiler Collection) The code is designed to be compiled with GCC. This is the industry-standard compiler for C/C++ on Linux and is widely available on Windows via MinGW. It ensures the code is compliant with ANSI C standards.

Editor Platform The development and testing of this lexical analyzer can be performed on any standard Integrated Development Environment (IDE) or text editor. The recommended platform for this specific task is Visual Studio Code (VS Code).
Visual Studio Code: As a lightweight yet powerful code editor, VS Code provides syntax highlighting, which helps in writing the initial C code. Its integrated terminal allows for immediate compilation (e.g., gcc lexer.c -o lexer) and execution, creating a seamless "edit-compile-debug" cycle.

Alternative Environments:

Code::Blocks: A more traditional IDE often used in academic settings. It handles the linking and compiling process automatically, which is helpful for beginners who are not comfortable with command-line interfaces.

Online Compilers: For quick testing without local setup, platforms like Programiz or OnlineGDB are sufficient, as the program relies on standard libraries and does not require external file I/O in the "hardcoded" version.

Applicability and Future Scope The concepts demonstrated in this simple lexical analyzer form the backbone of many critical software development tools. Understanding how to tokenize text is applicable in several domains:
Compiler Design: This is the foundational step for parsing. A parser cannot analyze the grammar of a program (Syntax Analysis) until the lexical analyzer has converted raw text into a stream of tokens.

Syntax Highlighting: The color-coding you see in editors like VS Code or Sublime Text is powered by a real-time lexical analyzer. It scans your code, identifies that int is a keyword and main is an identifier, and applies different colors to them accordingly to improve readability.

Code Minification: In web development, "minifiers" use lexical analysis to strip out unnecessary whitespace and comments from JavaScript or CSS files to reduce file size, while ensuring the tokens (logic) remain intact.

Static Analysis and Linters: Tools that check your code for bugs before you run it (like ESLint or SonarQube) first tokenize the code to understand its structure. They can then warn you if you have unused variables or syntax errors.

Next Steps (Future Scope): While this program serves as a strong educational model, a production-level lexer would need to handle more complex scenarios, such as detecting string literals (text inside quotes " "), handling comments (// or /* ... */), and tracking line numbers to provide useful error messages during compilation.
