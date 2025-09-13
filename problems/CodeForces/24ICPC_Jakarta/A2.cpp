#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main() {
    string S;
    cin >> S;

    unordered_map<char, int> freq;
    for (char c : S) {
        freq[c]++;
    }

    int vowels = freq['A'] + freq['E'] + freq['I'] + freq['O'] + freq['U'];
    int consonants = 0;
    int y_count = freq['Y'];
    int ng_count = 0;

    // Count consonants and NG combinations
    for (char c = 'A'; c <= 'Z'; ++c) {
        if (c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U' && c != 'Y') {
            consonants += freq[c];
        }
    }

    // Count the number of NG combinations that can be used as a consonant
    ng_count = min(freq['N'], freq['G']);

    // Now try to form as many syllables as possible
    int syllables = 0;
    int word_length = 0;

    // Each syllable needs: 1 consonant, 1 vowel, and 1 consonant
    while ((consonants + ng_count) >= 2 && vowels >= 1) {
        if (ng_count > 0) {
            // Use NG as one of the consonants
            syllables++;
            word_length += 3; // NG (2 letters) + vowel + consonant
            ng_count--;
            consonants--;
            vowels--;
        } else if (consonants >= 2) {
            // Use two regular consonants
            syllables++;
            word_length += 3;
            consonants -= 2;
            vowels--;
        } else {
            break;
        }
    }

    // If we have Y's, we can try to use them as vowels or consonants
    while (y_count > 0 && syllables > 0) {
        // Use Y to replace a missing vowel or consonant
        if (vowels == 0) {
            y_count--;
            vowels++;
        } else if (consonants < 2) {
            y_count--;
            consonants++;
        } else {
            break;
        }
    }

    cout << word_length << endl;

    return 0;
}
