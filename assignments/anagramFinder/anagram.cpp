/*
 * Name: Jake Eklund
 * Date Submitted: October 22
 * Assignment Name: Single-Word Anagram Finder
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> loadWordlist(string filename);

/*Implement the following function:
  anagram() takes a word (string) and a wordlist of all words (vector of strings)
  and builds a dictionary/map where the key is a specific number of times each
  letter occurs in a word and the associated value is a vector of strings
  containing all words using those letters (anagrams).
  The value returned is a vector of strings containing the corresponding
  set of anagrams
*/
vector<string> anagram(string word, vector<string> wordlist);

/*
int main()
{
    vector<string> words;
    vector<string> anagrams;
    string inputWord;
    words=loadWordlist("wordlist.txt");
    cout << "Find single-word anagrams for the following word: ";
    cin >> inputWord;
    anagrams = anagram(inputWord, words);
    for (int i=0; i<anagrams.size(); i++)
    {
        cout << anagrams[i] << endl;
    }
    return 0;
}
*/

vector<string> loadWordlist(string filename)
{
    vector<string> words;
    ifstream inFile;
    string word;
    inFile.open(filename);
    if(inFile.is_open())
    {
        while(getline(inFile,word))
        {
            if(word.length() > 0)
            {
                words.push_back(word);
            }
        }
        inFile.close();
    }
    return words;
}

//Implement this function
vector<string> anagram(string word, vector<string> wordlist)
{
    vector<string> anagrams;

    for (int i = 0; i < wordlist.size(); i++) {
        if (wordlist[i].length() == word.length()) {
            unordered_map<char, int> wordMap;
            unordered_map<char, int> wordsMap;

            for (int x = 0; x < word.length(); x++) {
                wordMap[word[x]]++;
                wordsMap[wordlist[i][x]]++;
            }

            if (wordMap == wordsMap) {
                anagrams.push_back(wordlist[i]);
            }
        }
    }
    return anagrams;
}