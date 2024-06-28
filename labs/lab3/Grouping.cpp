/*
 * Name: Jake Eklund
 * Date Submitted: September 
 * Lab Section: 007
 * Assignment Name: Lab 3: Finding Groups Using Recursion
 */

#include "Grouping.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Implement the (parameterized) constructor and findGroup functions below
Grouping::Grouping(string file) {
    string fileInput;
    ifstream input(file);
    vector<GridSquare> myVec;

    for (int i = 0; i < 10; i++) {
        getline(input, fileInput);
        for (int x = 0; x < 10; x++) {
            if (fileInput[x] == 'X') {
                grid[i][x] = 1;
            }
            else {
                grid[i][x] = 0;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int x = 0; x < 10; x++) {
            if (grid[i][x] == 1) {
                groups.push_back(myVec);
                findGroup(i, x);
            }
        }
    }
}

void Grouping::findGroup(int row, int column) {
    if (grid[row][column] == 0) {
        return;
    }
    if (row < 0 || row >= 10 || column < 0 || column >= 10) {
        return;
    }

    grid[row][column] = 0;
    
    findGroup(row + 1, column);
    findGroup(row - 1, column);
    findGroup(row, column + 1);
    findGroup(row, column - 1);
    groups.back().push_back(GridSquare(row, column));
}


//Simple main function to test Grouping
//Be sure to comment out main() before submitting
/*
int main()
{
    Grouping input1("input1.txt");
    input1.printGroups();
    
    return 0;
}
*/

//Do not modify anything below

GridSquare::GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square

GridSquare::GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square

//Compare with == operator, used in test cases
bool GridSquare::operator== (const GridSquare r) const
{
    if ((row == r.row) && (col == r.col))
    {
        return true;
    }
    return false;
}

int GridSquare::getRow() //return row value
{
    return row;
}

int GridSquare::getCol() //return column value
{
    return col;
}

//Output using << operator, used in Grouping::printGroups()
//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

Grouping::Grouping() : grid(), groups() {} //Default constructor, no groups

void Grouping::printGroups() //Displays grid's groups of squares
{
    for(int g=0; g<groups.size(); g++)
    {
        cout << "Group " << g+1 << ": ";
        for(int s=0; s<groups[g].size(); s++)
        {
            cout << " " << groups[g][s];
        }
        cout << endl;
    }
}

vector<vector<GridSquare> > Grouping::getGroups() //Needed in unit tests
{
    return groups;
}