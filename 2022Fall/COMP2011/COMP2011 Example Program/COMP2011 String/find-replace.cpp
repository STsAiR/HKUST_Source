#include <iostream>     /* File: find-replace.cpp */
using namespace std;

void print_words(const string word[], int num_words) {
    for (int j = 0; j < num_words; j++)
        cout << word[j] << endl;
}

int main() {
    string s1("et"); // substring to be replaced
    string s2("ad"); // replacing string 
    const int num_words = 5;
    string word[num_words] = { "met", "deet", "pets", "eta", "set" };
    cout << "Before replacement" << endl; print_words(word, num_words);

    // Replace the first occurrence of "et" by "ad" in each word
    for (int j = 0; j < num_words; j++)
    {
        int index = word[j].find(s1, 0);
        word[j].replace(index, s1.length(), s2);
    }

    cout << "After replacement" << endl; print_words(word, num_words);
    return 0;
}
