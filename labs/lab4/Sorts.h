/*
 * Name: Jake Eklund
 * Date Submitted: October 2, 2023
 * Lab Section: 007
 * Assignment Name: Lab 4: Searching and Sorting
 */

#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

template <class T>
std::vector<T> mergeSort(std::vector<T> lst, int end, int start) {
    std::vector<T> myVec;

    if (end == start) {
        myVec.push_back(lst[end]);
        return myVec;
    }

    int index = (end + start) / 2;
    
    std::vector<T> num1 = mergeSort(lst, end, index);
    std::vector<T> num2 = mergeSort(lst, index + 1, start);

    int index1 = 0;
    int index2 = 0;

    while (index1 < num1.size() && index2 < num2.size()) {
        if (num1[index1] < num2[index2]) {
            myVec.push_back(num1[index1]);
            index1++;
        }
        else {
            myVec.push_back(num2[index2]);
            index2++;
        }
    }

    while (index1 < num1.size()) {
        myVec.push_back(num1[index1]);
        index1++;
    }

    while (index2 < num2.size()) {
        myVec.push_back(num2[index2]);
        index2++;
    }

    return myVec;
}

template <class T>
std::vector<T> mergeSort(std::vector<T> lst) {
    int end = 0;
    int start = lst.size() - 1;
    return mergeSort(lst, end, start);
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst) {
    if (lst.size() <= 1) {
        return lst;
    }

    srand(time(0));
    
    int perm = rand() % lst.size();
    T temp = lst[perm];
    vector<T> end, mid, start;

    lst.erase(lst.begin() + perm);

    for (int i = 0; i < lst.size(); i++) {
        if (lst[i] < temp) {
            start.push_back(lst[i]);
        }
        else if (lst[i] == temp) {
            mid.push_back(lst[i]);
        }
        else {
            end.push_back(lst[i]);
        }
    }

    start = quickSort(start);
    end = quickSort(end);
    lst.clear();

    for (int i = 0; i < start.size(); i++) {
        lst.push_back(start[i]);
    }

    lst.push_back(temp);

    for (int i = 0; i < mid.size(); i++) {
        lst.push_back(mid[i]);
    }

    for (int i = 0; i < end.size(); i++) {
        lst.push_back(end[i]);
    }

    return lst;
}