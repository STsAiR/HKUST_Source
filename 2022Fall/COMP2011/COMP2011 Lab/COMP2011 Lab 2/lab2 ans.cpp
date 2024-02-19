#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    // get user input
    int inputNumber;
    while (true) {
        cout << "Enter a non-negative integer number: ";
        if(cin >> inputNumber){
            if (inputNumber >= 0){
                break;
            }
        }
        // use cin.clear() and cin.ignore() to recover and clean the current input to require user input again.
        // if you are interested you can refer to https://www.quora.com/Can-you-explain-cin-ignore-and-cin-clear-for-C-When-is-it-appropriate-to-use-these-How-do-they-affect-the-next-cin.
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input, it is either non-integer, negative, or out of int type boundary." << endl;
        cout << "please re-enter." << endl;
    }       

    // use a loop and '/' operator to get the number of digits of input number
    int numOfDigits = 0;
    int num = inputNumber;
    while(num > 0)
    {
        ++numOfDigits;
        num /= 10; 
    }

    // total number of substring of a string of length n: n*(n+1)/2
    int numOfTotalSubstr = (numOfDigits * (numOfDigits + 1)) / 2;

    // check divisibility, and log related information to terminal
    cout << inputNumber << " is divisible by its substrings:" << endl;
    cout << "---------------------------" << endl;


    /* TASK: 
        (1). Print the desired substrings following the order being described on the lab webpage.
        (2). Count the total number of desired substrings.
        (3). Check the lab webpage picture and algorithm descriptions together as hints.
    */
    // Please write your code below

    // Algorithm Step 1:
    // - Start the outer loop, which aims to loop substrings that starts from different digits.
    // - Variable "totalCount" is given to you, you should count and update this variable when checking divisibility.
    int totalCount = 0;
    for (int startIndex = 0; startIndex < numOfDigits; startIndex++){

    // Algorithm Step 2: 
    // - Inside the outer loop, use "%" operator to get the longest substring that starts from a certain digit, this longest substring will be use for the inner loop.
    //   eg. (number % 10^n) will keep the last n digits.
    //   eg. for 12345, 12345 % 100 will give 45, keeping the last two digits.
    //   eg. for 114, 114 % 1000 will give 114, keeping the last three digits.
    //   You may use pow() function here if you want, <cmath> library is already included for you.
    //   But please note that pow() function will return you a float type variable, you may use static_cast if encounter problem.
    //   eg. pow(a, b) returns you a^b as output.
        int cuttedNumber = inputNumber % static_cast<int>(pow(10, numOfDigits - startIndex));

    // Algorithm Step 3:
    // - Start the inner loop, use the longest substring that starts from a certain digit, get and check the substrings that ends at different digits.
    // - Inside the inner loop, use "/" operator to get rid of some last digits.
    //   eg. (number / 10^n) will get rid of the last n digits.
    //   eg. 556 / 10 will give 55, getting rid of the last one digit.
    //   eg. 556 / 100 will give 5, getting rid of the last two digits.
    // - Inside the inner loop, check divisibility, print out the desired substring, and count to total number "totalCount".
        for (int i = 0; i < numOfDigits - startIndex; i++){
            if (inputNumber % cuttedNumber == 0){
                cout << cuttedNumber << endl;
                ++totalCount;
            }
            cuttedNumber /= 10;
        }
    }
    // Your code ends here


    cout << "---------------------------" << endl;
    cout << inputNumber << " is divisible by " << totalCount << " of its total " << numOfTotalSubstr << " substrings." << endl;

    return 0;
}