/*
 * Name: Jake Eklund
 * Date Submitted: October 18
 * Lab Section: 007
 * Assignment Name: Spell Checker Using a Hash Table
 */

#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string> > Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

void Stringset::insert(string word)
{
    //Implement this function
    if (!find(word)) {
        int loc;
        string Word1;
        std::hash<std::string> str_hash;
        if (num_elems >= size) {
            size = size * 2;
            vector<list<string> > newTable(size);
            for (int i = 0; i < size / 2; i++) {
                for(list<string>::const_iterator it = table[i].begin(); it != table[i].end(); ++it) {
                    Word1 = *it;
                    loc = str_hash(Word1) % size;
                    newTable[loc].push_back(Word1);
                    table[i].remove(word);
                }
            }
            table = newTable;
        }

        loc = str_hash(word) % size;
        table[loc].push_back(word);
        num_elems++;
    }
}

bool Stringset::find(string word) const
{
    //Implement this function
    std::hash<std::string> str_hash;
    int loc = str_hash(word) % size;
    for(list<string>::const_iterator it = table[loc].begin(); it != table[loc].end(); ++it) {
        if (*it == word) {
            return true;
        }
    }
    return false;
}

void Stringset::remove(string word)
{
    //Implement this function
    if (find(word)) {
        hash<std::string> str_hash;
        int loc = str_hash(word) % size;
        table[loc].remove(word);
        num_elems--;
    }
}