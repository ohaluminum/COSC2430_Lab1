#include <iostream>
#include <fstream>
#include "ArgumentManager.h"
using namespace std;

int main(int argc, char* argv[])
{
    ArgumentManager am(argc, argv);

    //Get the filename of argument name "input" and "output"
    //string input = am.get("input");
    //string output = am.get("output");

    //Test
    string input = "input1.txt";
    string output = "output1.txt";

    ifstream inFS;
    ofstream outFS;

    //Open the input file and output file
    inFS.open(input);
    outFS.open(output);

    int operation;
    char A;
    char B;
    int result;

    try
    {
        if (!inFS.is_open())
        {
            throw runtime_error("File does not exist.");
        }

        if (inFS.peek() == EOF)
        {
            throw runtime_error("File is empty.");
        }
        

    }
    catch (runtime_error & e)
    {
        outFS << e.what() << endl;
    }


    //Read from input file
    inFS >> operation >> A >> B;

    if (operation == 1)
    {
        result = (int)A + (int)B;
    }
    else if (operation == 2)
    {
        result = (int)A - (int)B;
    }

    if (result > 0)
    {
        outFS << result;
    }
    else
    {

    }

    return 0;
}
