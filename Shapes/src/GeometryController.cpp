#include "GeometryController.h"
#include <sstream>

GeometryController::GeometryController(){
    //ctor
    cmdManager.ExecuteCMD(new ConcerteCommand (GetDescs(),GetNames(),&mediaBase,GetComboSize()));
}

string GeometryController::GetResult(){
    return result;
}

string GeometryController::GetComboMediaDes(string comboName){
    Media* combo = GetMediaByName(comboName);
    if(combo != nullptr){
        if(combo->getType() == "ComboMedia"){
            DescriptionVisitor dv;
            combo->accept(&dv);
            return dv.getDescription();
        }
        else {
            return "It's not a ComboMedia";
        }
    }
    else{
        return "It's not Exist";
    }
}

string GeometryController::GetDescs(){
    stringstream ss;
    for(Media *m : mediaBase){
        DescriptionVisitor dv;
        m->accept(&dv);
        ss << dv.getDescription();
        if(m->getType() == "ComboMedia"){
            ss << " ";
        }
    }
    //cout << ss.str() << endl;
    return ss.str();
}

string GeometryController::GetNames(){
    stringstream ss;
    for(Media *m : mediaBase){
        NameVisitor nv;
        m->accept(&nv);
        ss << nv.getNames();
        if(m->getType() == "ComboMedia"){
            ss << " ";
        }
    }
    //cout << ss.str() << endl;
    return ss.str();
}

std::vector<int> GeometryController::GetComboSize(){
    vector<int> comboSizes;
    comboSizes.clear();
    for(Media *m : mediaBase){
        if(m->getType() == "ComboMedia"){
            comboSizes.push_back(m->getSize());
            //std::cout<<"m->getSize() = " << m->getSize() <<endl;
        }
    }
    return comboSizes;
}

void GeometryController::ExecuteCommand(string command){
    result = "";
    //cout <<command <<endl;
    std::vector<char> tempForAnalyzed(command.size()+1);
    std::vector<char*> analyzedCommand;
    strcpy(tempForAnalyzed.data(),command.c_str());
    char* tempWord = strtok(tempForAnalyzed.data(),"(){}=,.? \"");
    while(tempWord != NULL){
        //cout << tempWord <<endl;
        analyzedCommand.push_back(tempWord);
        tempWord = strtok(NULL,"(){}=,.? \"");
    }
    //cout << "nalyzedCommand's size = " << analyzedCommand.size() <<endl;
    if(strcmp(analyzedCommand[0], "Undo")== 0){
        cout << "Undo" <<endl;
        cmdManager.UndoCMD();
        //string a = GetDescs();
        //string b = GetNames();
    }
    else if(strcmp(analyzedCommand[0], "") ==0){
        cout << "Redo" <<endl;
        cmdManager.RedoCMD();
    }
    else if(strcmp(analyzedCommand[0], "def") == 0 && (analyzedCommand.size() >= 4)){
        DefineNewMedia(analyzedCommand);
        cmdManager.ExecuteCMD(new ConcerteCommand (GetDescs(),GetNames(),&mediaBase,GetComboSize()));
    }
    else if(strcmp(analyzedCommand[0], "add") == 0 && (analyzedCommand.size() == 4)){
        AddMediaToCombo(analyzedCommand);
        cmdManager.ExecuteCMD(new ConcerteCommand (GetDescs(),GetNames(),&mediaBase,GetComboSize()));
    }
    else if(strcmp(analyzedCommand[0], "show") == 0 && (analyzedCommand.size() == 1)){
        Show();
    }
    else if(strcmp(analyzedCommand[0], "delete") == 0){
        if(analyzedCommand.size() == 2){
            DeleteMediaByName(analyzedCommand[1]);
        }
        else if(analyzedCommand.size() == 4){
            DeleteMediaFromCombo(analyzedCommand);
        }
        cmdManager.ExecuteCMD(new ConcerteCommand (GetDescs(),GetNames(),&mediaBase,GetComboSize()));
    }
    else if(strcmp(analyzedCommand[0], "save") == 0 && (analyzedCommand.size() == 5)) {
        SaveFile(analyzedCommand);
    }
    else if(strcmp(analyzedCommand[0], "load") == 0 && (analyzedCommand.size() == 3)){
        LoadFromFile(analyzedCommand);
    }
    else if(strcmp(analyzedCommand[1], "area") == 0 && (analyzedCommand.size() == 2)){
        GetArea(analyzedCommand[0]);
    }
    else if(strcmp(analyzedCommand[1], "perimeter")== 0 &&(analyzedCommand.size() == 2)){
        GetPerimeter(analyzedCommand[0]);
    }
    else if((strcmp(analyzedCommand[0], "Exit")== 0) || (strcmp(analyzedCommand[0], "exit")== 0)){
        cout<< ">> Exiting system, Bye!" << endl;
    }
    else if((strcmp(analyzedCommand[0], "Help")== 0) || (strcmp(analyzedCommand[0], "help")== 0)){
        DisplayCommandIndex();
    }
    else{
        cout<< ">> This is an illegal command!" << endl;
    }
}

void GeometryController::DisplayCommandIndex(){
    cout << "---COMMAND INDEX---" << endl;
    cout << "def ¡§mediaName¡¨ = ¡§ShapeType¡¨(value)  --  can create media." << endl;
    cout << "def ¡§comboMediaName¡¨ = combo {¡§mediaName1¡¨, ¡§mediaName2¡¨}  --  can create comboMedia." << endl;
    cout << "¡§mediaName¡¨.area?  --  can get area of mediaName." << endl;
    cout << "¡§mediaName¡¨.perimeter?  -- can get perimeter of mediaName." << endl;
    cout << "save ¡§mediaName¡¨ to ¡§fileName¡¨ --  can save mediaName to fileName." << endl;
    cout << "load ¡§fileName¡¨ --  can load from fileName." << endl;
    cout << "add ¡§mediaName¡¨ to ¡§comboMediaName¡¨ --  can add mediaName to comboMediaName." << endl;
    cout << "show  --  can display all Media." << endl;
    cout << "delete ¡§mediaName¡¨ --  can delete mediaName." << endl;
    cout << "delete ¡§mediaName¡¨ in ¡§comboMediaName¡¨ --  can delete all relationships of mediaName in comboMediaName." << endl;
    cout << "help  --  can display this Index." << endl;
    cout << "exit  --  can exit this program." << endl;
    cout << "" <<endl;
}

Media* GeometryController::GetMediaByName(string name){
    for (Media *media : mediaBase){
        if(media->getName() == name){
            return media;
        }
    }
    return nullptr;
}

void GeometryController::DefineNewMedia(std::vector<char*> command){ //done
    stringstream tempSs ;
    string mediaName = command[1];
    char* mediaShapeType = command[2];
    if(GetMediaByName(mediaName) != nullptr){
        //cout<< ">> " << mediaName << " is already existed!" << endl;
        tempSs << ">> " << mediaName << " is already existed!"<< "\n";

    }
    else{
        if (strcmp(mediaShapeType, "combo") == 0)
        {
            Media* tempMedia;
            ComboMedia *cm = new ComboMedia();
            cm -> setName(mediaName);
            //cout << cm -> getName() << endl;
            for (unsigned int cmdCounter = 3 ; cmdCounter < command.size(); cmdCounter++)
            {
                tempMedia = GetMediaByName(command[cmdCounter]);
                if(tempMedia == nullptr)
                {
                    tempSs << ">> " << command[cmdCounter] << " is not exist!"<< "\n" ;
                }
                else
                {
                    //cout << ">> " << command[cmdCounter] << " was found" << endl;
                    cm->add(tempMedia);
                    tempSs.clear();
                }
            }
            mediaBase.push_back(cm);
        }
        else if((strcmp(mediaShapeType, "Rectangle") == 0) && (command.size() == 7))
        {
            double x = atof(command[3]);
            double y = atof(command[4]);
            double l = atof(command[5]);
            double w = atof(command[6]);
            ShapeMedia* sm = new ShapeMedia(new Rectangle(x, y, l, w));
            sm->setName(mediaName);
            mediaBase.push_back(sm);
            tempSs << ">> Rectangle(" << x << "," << y << "," << l << "," << w << ")"<< "\n";
        }
        else if((strcmp(mediaShapeType, "Circle") == 0)  && (command.size() == 6))
        {
            double x = atof(command[3]);
            double y = atof(command[4]);
            double r = atof(command[5]);
            ShapeMedia* sm = new ShapeMedia(new Circle(x, y, r));
            sm->setName(mediaName);
            mediaBase.push_back(sm);
            tempSs << ">> Circle(" << x << "," << y << "," << r << ")"<< "\n";
        }
        else if((strcmp(mediaShapeType, "Triangle") == 0)  && (command.size() == 9))
        {
            double x1 = atof(command[3]);
            double y1 = atof(command[4]);
            double x2 = atof(command[5]);
            double y2 = atof(command[6]);
            double x3 = atof(command[7]);
            double y3 = atof(command[8]);
            ShapeMedia* sm = new ShapeMedia(new Triangle(x1, y1, x2, y2, x3, y3));
            sm -> setName(mediaName);
            mediaBase.push_back(sm);
            tempSs << ">> Triangle(" << x1 << "," << y1 << "," << x2 << "," << y2 << "," << x3 << "," << y3 << ")" << "\n";
        }
        else {
            tempSs << ">> This is an illegal command!"<< "\n";
        }
    }
    result = tempSs.str();
}

void GeometryController::AddMediaToCombo(std::vector<char*> command){ //done
    stringstream tempSs ;
    Media* shapeMedia = GetMediaByName(command[1]);
    Media* comboMedia = GetMediaByName(command[3]);
    if(shapeMedia != nullptr){
        if(comboMedia != nullptr){
            comboMedia->add(shapeMedia);
            DescriptionVisitor dv;
            NameVisitor nv;
            comboMedia->accept(&dv);
            comboMedia->accept(&nv);
            tempSs << ">> " << command[3] << " = " << nv.getNames() << "= " << dv.getDescription() << "\n";
        }
        else {
            tempSs << ">> ComboMedia which named " << command[3] << " is not exist!" << "\n";
        }
    }
    else {
        tempSs << ">> ShapeMedia which named " << command[1] << " is not exist!" << "\n";
    }
    result = tempSs.str();
}

void GeometryController::Show(){ //done
    stringstream tempSs ;
    if(mediaBase.size()>0){
        for(Media *m :mediaBase){
            tempSs << m->getName() << "\n";
        }
    }
    else {
        tempSs << "There is no any media." << "\n";
    }
    result = tempSs.str();
}

void GeometryController::GetArea(string name){ //done
    stringstream tempSs ;
    Media *m = GetMediaByName(name);
    if(m != nullptr){
        tempSs << ">> " << m->area() << "\n";
    }
    else{
        tempSs << ">> " << name << " is not exist!" << "\n";
    }
    result = tempSs.str();
 }

void GeometryController::GetPerimeter(string name){ //done
    stringstream tempSs ;
    Media *m = GetMediaByName(name);
    if(m != nullptr){
        tempSs << ">> " << m->perimeter() << "\n";
    }
    else{
        tempSs << ">> " << name << " is not exist!" << "\n";
    }
    result = tempSs.str();
}

void GeometryController::DeleteMediaByName(string name){ //do not need to refactoring

    for (Media *media : mediaBase){
        if(media->getType() == "ComboMedia"){
            DeleteMediaFromCombo(media->getName(),name);
        }
    }
    int counter =0;
    for (Media *media : mediaBase){

        if(media->getName() == name){
            mediaBase.erase(mediaBase.begin()+counter);
        }
        counter++;
    }
    result = "";
}
void GeometryController::DeleteMediaFromCombo(string comboName, string deleteName){

    Media * needToDeletesMedia = GetMediaByName(deleteName);
    Media * cm = GetMediaByName(comboName);
    if(needToDeletesMedia != nullptr){
        if(cm->getType() == "ComboMedia"){
            cm->removeMedia(needToDeletesMedia);
        }
    }
}
void GeometryController::DeleteMediaFromCombo(std::vector<char*> command){ //done
    stringstream tempSs;
    Media * needToDeletesMedia = GetMediaByName(command[1]);
    Media * cm = GetMediaByName(command[3]);
    if(needToDeletesMedia != nullptr){
        if(cm->getType() == "ComboMedia"){
            cm->removeMedia(needToDeletesMedia);
            result = "";
        }
        else{
            tempSs<< ">> " << command[3] << " is not a ComboMedia" << "\n";
            result = tempSs.str();
        }
    }
}

void GeometryController::SaveFile(std::vector<char*> command){ //done
    stringstream tempSs ;
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
        tempSs << ">> " << m->getName() << " saved to " << fileName << "\n";
    }
    else{
        tempSs << ">> " << command[1] << " is not exist!" << "\n";
    }
    result = tempSs.str();
}

void GeometryController::LoadFromFile(std::vector<char*> command){
    stringstream tempSs ;
    char* temp = strtok(command[1],"¡§");
    char* temp2 = strtok(command[2],"¡¨");
    string fileName = temp;
    fileName += ".";
    fileName += temp2;
    //cout<< fileName << endl;
    ifstream ifs(fileName, ios::in);
    string desc;
    string name;
    if(ifs){
        if(!ifs.eof()){
            getline(ifs,desc);
            getline(ifs,name);
            tempSs << ">> loading " << fileName << " ¡K" << "\n";
            std::vector<char> tempForAnalyzed(name.size()+1);
            std::vector<char*> analyzedName;
            strcpy(tempForAnalyzed.data(),name.c_str());
            char* tempWord = strtok(tempForAnalyzed.data(),"(){}=,.? \"");
            while(tempWord != NULL){
                //cout << tempWord <<endl;
                analyzedName.push_back(tempWord);
                tempWord = strtok(NULL,"(){}=,.? \"");
            }
            stack<MediaBuilder *> mbs;
            mediaBase.clear();
            Concrete(&mbs,desc,analyzedName);
        }
    }
    else{
        tempSs << ">> " << fileName << " is not exist!" << "\n";
    }
    result = tempSs.str();
}

std::vector<double> GeometryController::getValues(string content, int startPosition, int endPosition){
    vector<double> outputValues;
    double value;
    string desc = content.substr(startPosition + 2, endPosition - (startPosition + 2)); //2 means the shape title to first value's distance
    stringstream valueString(desc);
    while(valueString >> value) {
        outputValues.push_back(value);
    }
    return outputValues;
}

void GeometryController::Concrete(std::stack<MediaBuilder*> *mb, string content, std::vector<char*> name){
    int nameCounter = 0;
    int comboCounter =0;
    for(unsigned int i = 0; i < content.length(); i++){
        if(content[i] == 'c'){
            if(content[i+1] == 'o' && content[i+2] == 'm' && content[i+3] == 'b' && content[i+4] == 'o'){
                mb -> push(new ComboMediaBuilder());
                comboCounter++;
                mb -> top() -> buildComboMedia();
                mb -> top() -> getMedia()->setName(name[nameCounter]);
                mediaBase.push_back(mb -> top() -> getMedia());
                nameCounter++;
            }
            else if(content[i+1] == '('){
                int endPosition = content.find_first_of(')', i);
                vector<double> value = getValues(content, i, endPosition);
                i = endPosition;
                Circle* circle = new Circle(value[0], value[1], value[2]);
                circle->setName(name[nameCounter]);
                mediaBase.push_back(new ShapeMedia(circle));
                if(comboCounter > 0){
                    mb -> top() -> buildShapeMedia(circle);
                }
                nameCounter++;
            }
        }
        else if(content[i] == 'r'){
            int endPosition = content.find_first_of(')', i);
            vector<double> value = getValues(content, i, endPosition);
            i = endPosition;
            Rectangle* rectangle = new Rectangle(value[0], value[1], value[2], value[3]);
            rectangle->setName(name[nameCounter]);
            mediaBase.push_back(new ShapeMedia(rectangle));
            if(comboCounter > 0){
                mb -> top() -> buildShapeMedia(rectangle);
            }
            nameCounter++;
        }
        else if(content[i] == 't'){
            int endPosition = content.find_first_of(')', i);
            vector<double> value = getValues(content, i, endPosition);
            i = endPosition;
            Triangle* triangle = new Triangle(value[0], value[1], value[2], value[3], value[4], value[5]);
            triangle->setName(name[nameCounter]);
            mediaBase.push_back(new ShapeMedia(triangle));
            if(comboCounter > 0){
                mb -> top() -> buildShapeMedia(triangle);
            }
            nameCounter++;
        }
        else if(content[i] == ')'){
            if((mb -> size() >= 1) &&( comboCounter > 1 )) {
                Media *combo = mb -> top() -> getMedia();
                mb -> pop();
                ComboMediaBuilder* topCombo = dynamic_cast<ComboMediaBuilder*> (mb -> top());
                topCombo -> addComboMedia(combo);
            }
        }
    }
}
