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
        DefineNewMedia(analyzedCommand);
    }
    else if(strcmp(analyzedCommand[0], "add") == 0 && (analyzedCommand.size() == 4)){
        AddMediaToCombo(analyzedCommand);
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
    cout << "def ˇ§mediaNameˇ¨ = ˇ§ShapeTypeˇ¨(value)  --  can create media." << endl;
    cout << "def ˇ§comboMediaNameˇ¨ = combo {ˇ§mediaName1ˇ¨, ˇ§mediaName2ˇ¨}  --  can create comboMedia." << endl;
    cout << "ˇ§mediaNameˇ¨.area?  --  can get area of mediaName." << endl;
    cout << "ˇ§mediaNameˇ¨.perimeter?  -- can get perimeter of mediaName." << endl;
    cout << "save ˇ§mediaNameˇ¨ to ˇ§fileNameˇ¨ --  can save mediaName to fileName." << endl;
    cout << "load ˇ§fileNameˇ¨ --  can load from fileName." << endl;
    cout << "add ˇ§mediaNameˇ¨ to ˇ§comboMediaNameˇ¨ --  can add mediaName to comboMediaName." << endl;
    cout << "show  --  can display all Media." << endl;
    cout << "delete ˇ§mediaNameˇ¨ --  can delete mediaName." << endl;
    cout << "delete ˇ§mediaNameˇ¨ in ˇ§comboMediaNameˇ¨ --  can delete all relationships of mediaName in comboMediaName." << endl;
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

void GeometryController::DefineNewMedia(std::vector<char*> command){
    string mediaName = command[1];
    char* mediaShapeType = command[2];
    if(GetMediaByName(mediaName) != nullptr){
        cout<< ">> " << mediaName << " is already existed!" << endl;
    }
    else{
        if (strcmp(mediaShapeType, "combo") == 0)
        {
            Media* temp;
            ComboMedia *cm = new ComboMedia();
            cm -> setName(mediaName);
            //cout << cm -> getName() << endl;
            for (unsigned int cmdCounter = 3 ; cmdCounter < command.size(); cmdCounter++)
            {
                temp = GetMediaByName(command[cmdCounter]);
                if(temp == nullptr)
                {
                    cout << ">> " << command[cmdCounter] << " is not exist!" << endl;
                }
                else
                {
                    //cout << ">> " << command[cmdCounter] << " was found" << endl;
                    cm->add(temp);
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
            cout << ">> Rectangle(" << x << "," << y << "," << l << "," << w << ")" <<endl;
        }
        else if((strcmp(mediaShapeType, "Circle") == 0)  && (command.size() == 6))
        {
            double x = atof(command[3]);
            double y = atof(command[4]);
            double r = atof(command[5]);
            ShapeMedia* sm = new ShapeMedia(new Circle(x, y, r));
            sm->setName(mediaName);
            mediaBase.push_back(sm);
            cout << ">> Circle(" << x << "," << y << "," << r << ")" <<endl;
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
            cout << ">> Triangle(" << x1 << "," << y1 << "," << x2 << "," << y2 << "," << x3 << "," << y3 << ")" << endl;
        }
        else {
            cout<< ">> This is an illegal command!" << endl;
        }
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
    char* temp = strtok(command[3],"ˇ§");
    char* temp2 = strtok(command[4],"ˇ¨");
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

void GeometryController::LoadFromFile(std::vector<char*> command){
    char* temp = strtok(command[1],"ˇ§");
    char* temp2 = strtok(command[2],"ˇ¨");
    string fileName = temp;
    fileName += ".";
    fileName += temp2;
    cout<< fileName << endl;
    ifstream ifs(fileName, ios::in);
    string desc;
    string name;
    if(ifs){
        if(!ifs.eof()){
            getline(ifs,desc);
            getline(ifs,name);
            cout << ">> loading " << fileName << " ˇK" << endl;
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
        cout << ">> " << fileName << " is not exist!" <<endl;
    }
}

vector<double> GeometryController::getValues(string content, int startPosition, int endPosition){
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
