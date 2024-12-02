// COMSC-210 | lab 36 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include "IntBinaryTree.h" //this is actually a string binary tree now
#include <fstream> //for file input/output
using namespace std;

//function prototype
void readIn(IntBinaryTree &);

/************************************************
 * Function: Main
 ************************************************/
int main()
{
    //add string functionality with values

    // add menu-driven functionality
    // add/delete/search/modify records

    IntBinaryTree myTree = IntBinaryTree(); //initalize root to locaiton of binary tree
    //need pointer to root it owuld seem? 

    readIn(myTree); 
    
    cout << "test complete";

    myTree.displayInOrder(); //doesn't require parameter, uses private root variable

    return 0;
}


void readIn(IntBinaryTree &myTree)
{
    string file = "test.txt", buf;
    ifstream fin(file); 

    while(getline(fin,buf)) //for each line
    {
        myTree.insertNode(buf); //insert into binary tree
    }
}