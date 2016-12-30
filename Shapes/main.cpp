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
    gc.DisplayCommandIndex();
    while (command != "Exit" && command != "exit"){
        std::cout<< ":- " ;
        getline(cin,command);
        if(cin.eof()){
            gc.ExecuteCommand("Undo");
        }
        if(command != ""){
            gc.ExecuteCommand(command);
            if( gc.GetResult() !=""){
                cout << gc.GetResult();
            }
        }
        cin.clear();
    }
    return 0;
}

