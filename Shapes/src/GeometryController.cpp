#include "GeometryController.h"

GeometryController::GeometryController(){
    //ctor
}

void GeometryController::ExecuteCommand(string command){
    std::vector<char> tempForAnalyzed(command.size()+1);
    std::vector<char*> analyzedCommand;
    strcpy(tempForAnalyzed.data(),command.c_str());
    char* tempWord = strtok(tempForAnalyzed.data(),"(){}=,.? \"");
    while(tempWord != NULL){
        //cout << tempWord <<endl;
        analyzedCommand.push_back(tempWord);
        tempWord = strtok(NULL,"(){}=,.? \"");
    }
    //cout << "analyzedCommand's size = " << analyzedCommand.size() <<endl;
    if(strcmp(analyzedCommand[0], "def") == 0 && (analyzedCommand.size() >= 4)){
        //cout<< "AAAAA"<<endl;
        DefineNewMedia(analyzedCommand);
    }
    else if(strcmp(analyzedCommand[0], "add") == 0 && (analyzedCommand.size() == 4)){
        //cout<< "CCCCCC"<<endl;
        AddMediaToCombo(analyzedCommand);
    }
    else if(strcmp(analyzedCommand[0], "show") == 0 && (analyzedCommand.size() == 1)){
        //cout<< "EEEEEE"<<endl;
        Show();
    }
    else if(strcmp(analyzedCommand[0], "delete") == 0){
        //cout<< "DDDDDD"<<endl;
        if(analyzedCommand.size() == 2){
            DeleteMediaByName(analyzedCommand[1]);
        }
        else if(analyzedCommand.size() == 4){
            DeleteMediaFromCombo(analyzedCommand);
        }
    }
    else if(strcmp(analyzedCommand[0], "save") == 0 && (analyzedCommand.size() == 5)) {
        //cout<< "FFFFFF"<<endl;
        SaveFile(analyzedCommand);
    }
    else if(strcmp(analyzedCommand[0], "load") == 0){
        //cout<< "GGGGGG"<<endl;
    }
    else if(strcmp(analyzedCommand[1], "area") == 0 && (analyzedCommand.size() == 2)){
        GetArea(analyzedCommand[0]);
    }
    else if(strcmp(analyzedCommand[1], "perimeter")== 0 &&(analyzedCommand.size() == 2)){
        GetPerimeter(analyzedCommand[0]);
    }
    else{
        cout<< ">> This is an illegal command!" << endl;
    }
}

Media* GeometryController::GetMediaByName(string name){
    for (Media *media : mediaBase){
        if(media->getName() == name){
            return media;
        }
    }
    return nullptr;
}

void GeometryController::DefineNewMedia(std::vector<char*> command){
    string mediaName = command[1];
    char* mediaShapeType = command[2];
    if (strcmp(mediaShapeType, "combo") == 0){//  && (command.size() >= 3 )){
        //cout<< "BBBBBB"<<endl;
        Media* temp;
        ComboMedia *cm = new ComboMedia();
        cm -> setName(mediaName);
        //cout << cm -> getName() << endl;
        for (unsigned int cmdCounter = 3 ; cmdCounter < command.size(); cmdCounter++){
            temp = GetMediaByName(command[cmdCounter]);
            if(temp == nullptr){
                cout << ">> " << command[cmdCounter] << " is not exist!" << endl;
            }
            else {
                //cout << ">> " << command[cmdCounter] << " was found" << endl;
                cm->add(temp);

            }
        }
        mediaBase.push_back(cm);
    }
    else if((strcmp(mediaShapeType, "Rectangle") == 0) && (command.size() == 7)){
        double x = atof(command[3]);
        double y = atof(command[4]);
        double l = atof(command[5]);
        double w = atof(command[6]);
        ShapeMedia* sm = new ShapeMedia(new Rectangle(x, y, l, w));
        sm->setName(mediaName);
        mediaBase.push_back(sm);
        cout << ">> Rectangle(" << x << "," << y << "," << l << "," << w << ")" <<endl;
    }
    else if((strcmp(mediaShapeType, "Circle") == 0)  && (command.size() == 6)){
        double x = atof(command[3]);
        double y = atof(command[4]);
        double r = atof(command[5]);
        ShapeMedia* sm = new ShapeMedia(new Circle(x, y, r));
        sm->setName(mediaName);
        mediaBase.push_back(sm);
        cout << ">> Circle(" << x << "," << y << "," << r << ")" <<endl;
    }
    else if((strcmp(mediaShapeType, "Triangle") == 0)  && (command.size() == 9)){
        double x1 = atof(command[3]);
        double y1 = atof(command[4]);
        double x2 = atof(command[5]);
        double y2 = atof(command[6]);
        double x3 = atof(command[7]);
        double y3 = atof(command[8]);
        ShapeMedia* sm = new ShapeMedia(new Triangle(x1, y1, x2, y2, x3, y3));
        sm -> setName(mediaName);
        mediaBase.push_back(sm);
        cout << ">> Triangle(" << x1 << "," << y1 << "," << x2 << "," << y2 << "," << x3 << "," << y3 << ")" << endl;
    }
    else {
        cout<< ">> This is an illegal command!" << endl;
    }
}

void GeometryController::AddMediaToCombo(std::vector<char*> command){
    Media * shapeMedia = GetMediaByName(command[1]);
    Media * comboMedia = GetMediaByName(command[3]);
    if(shapeMedia != nullptr){
        if(comboMedia != nullptr){
            comboMedia->add(shapeMedia);
            DescriptionVisitor dv;
            NameVisitor nv;
            comboMedia->accept(&dv);
            comboMedia->accept(&nv);
            cout << ">> " << command[3] << " = " << nv.getNames() << "= " << dv.getDescription() << endl;
        }
        else {
            cout << ">> ComboMedia which named " << command[3] << " is not exist!" << endl;
        }
    }
    else {
        cout << ">> ShapeMedia which named " << command[1] << " is not exist!" << endl;
    }
}

void GeometryController::Show(){
    if(mediaBase.size()>0){
        for(Media *m :mediaBase){
            cout << m->getName() << endl;
        }
    }
    else {
        cout << "There is no any media." << endl;
    }
}

void GeometryController::GetArea(string name){
    Media *m = GetMediaByName(name);
    if(m != nullptr){
        cout << ">> " << m->area() << endl;
    }
    else{
        cout << ">> " << name << " is not exist!" << endl;
    }
 }

void GeometryController::GetPerimeter(string name){
    Media *m = GetMediaByName(name);
    if(m != nullptr){
        cout << ">> " << m->perimeter() << endl;
    }
    else{
        cout << ">> " << name << " is not exist!" << endl;
    }
}

void GeometryController::DeleteMediaByName(string name){
    int counter =0;
    for (Media *media : mediaBase){
        if(media->getName() == name){
            mediaBase.erase(mediaBase.begin()+counter);
        }
        counter++;
    }
}

void GeometryController::DeleteMediaFromCombo(std::vector<char*> command){
    Media * needToDeletesMedia = GetMediaByName(command[1]);
    Media * cm = GetMediaByName(command[3]);
    if(needToDeletesMedia != nullptr){
        if(cm->getType() == "ComboMedia"){
            cm->removeMedia(needToDeletesMedia);
        }
        else{
            cout<< ">> " << command[3] << " is not a ComboMedia" <<endl;
        }
    }
}

void GeometryController::SaveFile(std::vector<char*> command){
    Media *m = GetMediaByName(command[1]);
    char* temp = strtok(command[3],"¡§");
    char* temp2 = strtok(command[4],"¡¨");
    string fileName = temp;
    fileName += ".";
    fileName += temp2;
    //cout << fileName << endl;
    DescriptionVisitor dv;
    NameVisitor nv;
    if(m != nullptr){
        m->accept(&dv);
        m->accept(&nv);
        ofstream(fileName) << dv.getDescription() << "\n" << nv.getNames();
        cout << ">> " << m->getName() << " saved to " << fileName <<endl;
    }
    else{
        cout << ">> " << command[1] << " is not exist!" << endl;
    }
}
/*
GeometryController::~GeometryController()
{
    //dtor
}
*/
