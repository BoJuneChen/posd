#include "..\cppunitlite\TestHarness.h"
//#include "utShapes.h"
#include "GeometryController.h"
#include <iostream>
#include <string>
#include <stdio.h>

int main()
{
    //TestResult tr;
    //TestRegistry::runAllTests(tr);
    string command;
    GeometryController gc;
    gc.DisplayCommandIndex();
    while (command != "Exit" && command != "exit"){
        gc.ClearResult();
        std::cout<< ":- " ;
        getline(cin,command);
        if(cin.eof()){
            //cout << "call undo" << endl;
            cin.clear();
            gc.ExecuteCommand("Undo");
        }
        if(command != ""){
            gc.ExecuteCommand(command);
        }
        if( gc.GetResult() != ""){
            cout << gc.GetResult();
        }
    }
    return 0;
}

