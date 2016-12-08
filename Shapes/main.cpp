#include "..\cppunitlite\TestHarness.h"
#include "utShapes.h"
#include "GeometryController.h"
#include <iostream>
#include <string>
#include <stdio.h>

int main()
{
    TestResult tr;
    TestRegistry::runAllTests(tr);
    string command;
    GeometryController gc;
    //string output;
    while (command != "Exit" && command != "exit"){
        std::cout<< ":- " ;
        getline(cin,command);
        //cout<< ">> " << command <<endl;
        if(command != ""){
            gc.ExecuteCommand(command);
        }
    }
    return 0;
}

