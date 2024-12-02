// COMSC-210 | lab 36 | Kent Kawashima
// IDE used: Visual Studio Code
#include <iostream>
#include "IntBinaryTree.h" //this is actually a string binary tree now
#include <fstream> //for file input/output
using namespace std;

//function prototype
void readIn(IntBinaryTree &root);

/************************************************
 * Function: Main
 ************************************************/
int main()
{
    //add string functionality with values

    // add menu-driven functionality
    // add/delete/search/modify records

    IntBinaryTree root = IntBinaryTree(); //initalize root to locaiton of binary tree

    //readIn(root); 
    

    return 0;
}


void readIn(IntBinaryTree &root)
{
    string file = "text.txt", buf;
    ifstream fin(file); 

    while(getline(fin,buf)) //for each line
    {
        root.insertNode(buf); //insert into binary tree
    }
}