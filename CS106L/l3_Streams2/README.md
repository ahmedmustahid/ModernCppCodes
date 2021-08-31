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


### `goodWelcomProgram()` output:   


            What is your name? yang avery
            What is your age? 20
            after calling iss 
            G---
            inside valid integer logic
            -FE-
            name yang avery age 20
            try again?


### `breakingGetline(const string& input_string_with_newline)` output

            input string: 16.9 
            24
            number before newline 16.9
            number after newline 


### `fixBrokenGetline(const string& input_string_with_newline)` 
`fixBrokenGetline("16.9\n 24")`
Use two `getline`s consecutively. 
            
            getline(iss, my_string);//my_string== ""
            getline(iss, my_string);//my_string== " 24" //second getline starts after the earlier newline
            
Or, ignore `\n` after the first `iss` using `iss.ignore()`
 
            iss.ignore();//pointer stops infront of the whitespace before 24
            getline(iss, my_string);//my_string== " 24" //second getline starts after the earlier newline       

`iss.ignore()` won't work if the input is `"16.9 \n 24"` instead of `"16.9\n 24"`. Because the after the previous call to `iss` which is `iss >> my_number;`,  `iss` will stop infront of the whitespace before the newline.



### Signed and unsigned int: 
While indexing the variable must be unisgned int. 
What is the bug in the following code:
            
            string chopBothEnds(const string& mystring){
                string result="";
                for (size_t i=0; i< mystring.size(); ++i){
                    result += mystring[i];
                }
                return result;
            }


### Everything in one example:

            pair<int, int> findPriceRange(int dist){
                int min = static_cast<int> (dist * 0.08);
                int max = static_cast<int> (dist * 10);
                return {min, max};
            }
            int main(){
                int dist = 645;
