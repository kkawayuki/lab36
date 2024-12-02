// COMSC-210 | lab 36 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include "IntBinaryTree.h" //this is actually a string binary tree now
#include <fstream> //for file input/output
using namespace std;

//function prototype
void readIn(IntBinaryTree &);
int printMenu();

/************************************************
 * Function: Main
 ************************************************/
int main()
{
    //add string functionality with values

    // add menu-driven functionality
    // add/delete/search/modify records

    IntBinaryTree myTree = IntBinaryTree(); //initalize root to locaiton of binary tree

    //logic to read in values to BST
    readIn(myTree); 
    
    int choice;

    while(choice != 5);
    {
        choice = printMenu();
        switch(choice)
        {
            case(1):
                break;

            case(2):
                break;

            case(3):
                break;
            
            case(4):
                break;

            default: //shouldn't be possible due to error handling in printMenu()
                break;
        }
    }
    
    
    //myTree.displayInOrder(); //doesn't require parameter, uses private root variable

    cout << myTree.searchNode("a");

    return 0;
}


void readIn(IntBinaryTree &myTree)
{
    string file = "codes.txt", buf;
    ifstream fin(file); 

    while(getline(fin,buf)) //for each line
    {
        myTree.insertNode(buf); //insert into binary tree
    }
}

int printMenu()
{
    int choice = 0;

    while(choice < 0 || choice > 5)
    {
        cout << "BST MENU -----\n1) Add a Node\n2)Delete a Node\n3)Search for a Node\n4)Modify a Node\nYour Choice: ----->"; 
        cin >> choice; 
    }
    cout << '\n';
    return(choice);
}