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
    IntBinaryTree myTree = IntBinaryTree(); // not sure if I have to do like this but it works

    // logic to read in values to BST
    readIn(myTree);

    // loop control variable
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

    return 0;
}

/************************************************
 * Function: Reads in all values from specified
 * text file into BST
 *
 * Parameters:
 * &myTree, BST, passed by reference in order to
 * insert node values to it
 ************************************************/
void readIn(IntBinaryTree &myTree)
{
    string file = "codes.txt", buf;
    ifstream fin(file);

    while (getline(fin, buf)) // for each line
    {
        myTree.insertNode(buf); // insert into binary tree
    }
}

/************************************************
 * Function: Print driving menu, gather user response
 *
 * Return:
 * choice: int value corresponding to user preference
 ************************************************/
int printMenu()
{
    int choice = 0;
    cout << "\nBST MENU -----\n1) Add a Node\n2) Delete a Node\n3) Search for a Node\n4) Modify a Node\n5) Quit Program\nYour Choice: -----> ";
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

/************************************************
 * Function: Add a new Node to the BST with value
 * specified by user
 *
 * Parameters:
 * &myTree, BST, passed by reference in order to
 * insert node values to it
 ************************************************/
void addValue(IntBinaryTree &myTree)
{
    string buf;
    cin.ignore(); // clear cache
    cout << "String value to add to the BST: ";
    getline(cin, buf);

    // add node to BST
    myTree.insertNode(buf);

    cout << "Added! Verify if needed with Node Search.\n";
}

/************************************************
 * Function: Remove an existing Node from the BST,
 * verified using a search function.
 *
 * Parameters:
 * &myTree, BST, passed by reference in order to
 * delete node values to it
 ************************************************/
void deleteValue(IntBinaryTree &myTree)
{
    string buf;
    cin.ignore(); // clear cache
    cout << "String value to remove from BST: ";
    getline(cin, buf);

    if (myTree.searchNode(buf)) // if node with value == buf exists:
    {
        myTree.remove(buf);
        cout << "Removed! Verify if needed with Node Search.\n";
    }
    else
        cout << "Unable to find Node with that value!\n";
}

/************************************************
 * Function: Searches BST for specific value, lets
 * user know of existence.
 *
 * Parameters:
 * &myTree, BST to search
 ************************************************/
void searchValue(IntBinaryTree &myTree)
{
    string buf;
    cin.ignore(); // clear cache
    cout << "String value to find in BST: ";
    getline(cin, buf);

    if (myTree.searchNode(buf)) // found
        cout << "Found! Node with this value exists in BST!\n";
    else // not found
        cout << "Unable to find Node with that value!\n";
}

/************************************************
 * Function: Takes in user input regarding initial
 * and final values for a Node, changes value to
 * final if node exists.
 *
 * Parameters:
 * &myTree, BST, passed by reference in order to
 * modify node values in it
 ************************************************/
void modifyValue(IntBinaryTree &myTree)
{
    string buf, buf2;
    cin.ignore(); // clear cache
    cout << "String value to alter from BST: ";
    getline(cin, buf);
    cout << "New value to change to: ";
    getline(cin, buf2);

    if (myTree.modify(buf, buf2))
        cout << "Modified! Verify if needed with Node Search.\n"; // success
    else
        cout << "Unable to find Node with that value!\n"; // could not find
}