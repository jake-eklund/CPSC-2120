/*
 * Name: Jake Eklund
 * Date Submitted: October 2, 2023
 * Lab Section: 007
 * Assignment Name: Lab 4: Searching and Sorting
 */

#pragma once

#include <vector>

template <class T>
int linearSearch(std::vector<T> data, T target){
    for (int i = 0; i < data.size(); i++) {
            if (data[i] == target) {
                return i;
            }
    }

    return -1;
}


template <class T>
int binarySearch(std::vector<T> data, T target){
    int index = 0;
    int index2 = data.size() - 1;
    int index3 = (index + index2) / 2;


    while (index <= index2) {
            if (data[index3] == target) {
                return index3;
            }
            else if (data[index3] < target) {
                index = index3 + 1;
            }
            else {
                index2 = index3 - 1;
            }
        index3 = (index + index2) / 2;
    }

    return -1;
}