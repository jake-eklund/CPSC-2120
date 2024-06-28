/*
 * Name: Jake Eklund
 * Date Submitted: October 18
 * Lab Section: 007
 * Assignment Name: Spell Checker Using a Hash Table
 */

#pragma once

#include <string>
#include <vector>
#include <list>
using namespace std;

//Stringset class, do not modify definitions for existing members
class Stringset
{
    private:
        vector<list<string> > table;
        int num_elems;
        int size;
    public:
        Stringset();
        vector<list<string> > getTable() const;
        int getNumElems() const;
        int getSize() const;
        void insert(string word);
        bool find(string word) const;
        void remove(string word);
};