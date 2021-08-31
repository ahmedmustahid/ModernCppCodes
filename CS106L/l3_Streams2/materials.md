# Lecture 3 Streams 2
## cin:
1. When does the program promt the user for input ?
    Ans: When there is nothing left in the buffer ie when the position reaches EOF, past the last token. 
2. Does the position pointer skip whitespace before the token or after the token ?
    Ans: After a token is extracted by cin, it stops at the start of a whitespace. When the next token is read, it jumps over the whitespace and starts from after the whitespace.
3. why does the cout immediately print the output into the console? When is the output printed?
    Ans: All input operations will [flush](https://stackoverflow.com/questions/14105650/how-does-stdflush-work/14107357#14107357) cout. 


### `badWelcomProgram()` output:
            What is your name? yang yang
            What is your age? name yang age 0
            try again? You said:
