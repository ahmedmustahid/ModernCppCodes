# Lecture 3 Streams 2
## cin:
1. When does the program promt the user for input ?
    Ans: When there is nothing left in the buffer ie when the position reaches EOF, past the last token. 
2. Does the position pointer skip whitespace before the token or after the token ?
    Ans: After a token is extracted by cin, it stops at the start of a whitespace. When the next token is read, it jumps over the whitespace and starts from after the whitespace.
3. why does the cout immediately print the output into the console? When is the output printed?
    Ans: All input operations will [flush](https://stackoverflow.com/questions/14105650/how-does-stdflush-work/14107357#14107357) cout. 


### `badWelcomProgram()` output:
            What is your name? yang avery
            What is your age? name yang age 0
            try again? You said:

#### Reasons:
1. `cin >> name;` reads input `yang` from the total input `yang avery` and stops immediately before the whitespace. 
2. In the next `cin>>age;`, skips the whitespace and tries to read the integer `age` from the buffer. But what is left inside the buffer is the string `wang` and so, Fail bit is turned on.
3. Reading a string into an iteger results in garbage value (`0` in this case). 
4. Because of the Fail bit the consecutive `cin`s are frozen and no input is accepted even though buffer has not been extracted. 

**Solution:** 
    1. Read input string so that it can read whitespaces (except newline) between strings too. We need `getline(cin, my_string)`
    2. Read input integer using our implementation og `getInteger(const string& prompt)` which allows `istringstream iss` unless `iss >> my_integer` produces a Good bit and the next `iss >> trash` (where `trash` is `char` after `my_integer`), produces a Fail bit.
