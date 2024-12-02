// COMSC-210 | lab 36 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include "IntBinaryTree.h" //this is actually a string binary tree now
#include <fstream>         //for file input/output
using namespace std;

// function prototype
void readIn(IntBinaryTree &);
int printMenu();
void addValue(IntBinaryTree &);
void deleteValue(IntBinaryTree &);
void searchValue(IntBinaryTree &);
void modifyValue(IntBinaryTree &);


/************************************************
 * Function: Main
 ************************************************/
int main()
{
    // build binary tree
    IntBinaryTree myTree = IntBinaryTree();

    // logic to read in values to BST
    readIn(myTree);

    int choice = 0;

    while (choice != 5)
    {
        choice = printMenu();
        switch (choice)
        {
        case (1):
            addValue(myTree);
            break;

        case (2):
            deleteValue(myTree);
            break;

        case (3):
            searchValue(myTree);
            break;

        case (4):
            modifyValue(myTree); 
            break;

        default: // shouldn't be possible due to range handling in printMenu()
            break;
        }
    }

    // myTree.displayInOrder(); //doesn't require parameter, uses private root variable

    return 0;
}

void readIn(IntBinaryTree &myTree)
{
    string file = "codes.txt", buf;
    ifstream fin(file);

    while (getline(fin, buf)) // for each line
    {
        myTree.insertNode(buf); // insert into binary tree
    }
}

int printMenu()
{
    int choice = 0;
    cout << "BST MENU -----\n1) Add a Node\n2) Delete a Node\n3) Search for a Node\n4) Modify a Node\n5) Quit Program\nYour Choice: -----> ";
    cin >> choice;

    // validation loop
    while (choice < 0 || choice > 5)
    {
        cout << "ERROR: Value must be from 1-5!\n\n";
        cout << "BST MENU -----\n1) Add a Node\n2) Delete a Node\n3) Search for a Node\n4) Modify a Node\n5) Quit Program\nYour Choice: -----> ";
        cin >> choice;
    }
    cout << '\n';
    return (choice);
}

void addValue(IntBinaryTree &myTree)
{

}

void deleteValue(IntBinaryTree &myTree)
{

}

void searchValue(IntBinaryTree &myTree)
{

}

void modifyValue(IntBinaryTree &myTree)
{

}