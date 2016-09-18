# RomanNumeralKata

## Usage
### Build and run Docker
Clone git repo to working dir path
```
docker build -t falconkata [working dir path]
docker run --rm -it -v [working dir path]:/falconkata --name falconkata_container falconkata
```

### Running the tests
```
cd falconkata/
make clean
make check
```
- The tests take about one minute to complete. 

### Compiling libromancal
```
cd falconkata/
make clean
make libromancal
```

### add_two_roman_numerals
```
bool add_two_roman_numerals(char * result, const char * lhs, const char * rhs);
```
- Passing in null pointer inputs will return false and result string "INVALID"
- Passing in invalid roman numerals will return false and result string "INVALID"
- Passing in roman numerals that sum over the max roman numeral value will return false and result string "INVALID"
- Otherwise, passing in valid roman numerals that add to be valid roman numeral will return true and correct roman numeral string.

### subtract_two_roman_numerals
```
bool subtract_two_roman_numerals(char * result, const char * lhs, const char * rhs);
```
- Passing in null pointer inputs will return false and result string "INVALID"
- Passing in invalid roman numerals will return false and result string "INVALID"
- Passing in roman numerals that subract to negative results will return false and result string "INVALID"
- Otherwise, passing in valid roman numerals that subtract to valid roman numeral will return true and correct roman numeral string.


## Roman Numeral Calculator
For this programming exercise, you will be creating a library which will allow the addition and subtraction of Roman numerals.

## The solution will be reviewed for
- Test coverage
- Test Driven Development
- Algorithm Usage
- Code structure
- Use of source control  
- Completeness of the overall solution

## The environment for this programming exercise  must  utilize
- Ubuntu Linux 14.04
- The C programming language
- GNU GCC compiler tool chain
- GNU Make
- Check unit testing framework ( https://libcheck.github.io/check/ )
- git

## Roman Numeral rules:
- Roman numerals consist of the following letters: I, V, X, L, C, D, and M which mean one, five, ten, fifty, hundred, five hundred and one thousand respectively.
- An example would be "XIV" + "LX" = "LXXIV"
- Numerals can be concatenated to form a larger numeral ("XX" + "II" = "XXII").
- If a lesser numeral is put before a bigger it means subtraction of the lesser from the bigger ("IV" means four, "CM" means ninehundred).
- If the numeral is I, X or C you can't have more than three ("II" + "II" = "IV" not “IIII”).
- If the numeral is V, L or D you can't have more than one ("D" + "D" = "M" not “DD”)
- The maximum roman numeral is 3999 (MMMCMXCIX)

## Stories
### User Story: Addition
As a Roman bookkeeper, I want to be able to add two numbers together. So that I can do my work faster with fewer mathematical errors.

### User Story: Subtraction
As a Roman bookkeeper, I want to be able to subtract one number from another. So that I can do my work faster and with fewer mathematical errors.
­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­­
This exercise is based on the Roman Numeral Calculator Kata at  http://bit.ly/1VfHqlj
