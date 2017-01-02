#include "ConcerteCommand.h"


void ConcerteCommand::Execute(){
    if((descs == "") && (names == "")){
        mediaBase->clear();
    }
    else{
        Concerte();
    }
}

void ConcerteCommand::Redo(){
    Execute();
}

void ConcerteCommand::Undo(){
    Execute();
}

void ConcerteCommand::Concerte(){
    std::vector<char> tempForAnalyzed(names.size()+1);
    std::vector<char*> analyzedName;
    strcpy(tempForAnalyzed.data(),names.c_str());
    char* tempWord = strtok(tempForAnalyzed.data(),"(){}=,.? \"");
    while(tempWord != NULL){
        analyzedName.push_back(tempWord);
        tempWord = strtok(NULL,"(){}=,.? \"");
    }
    stack<MediaBuilder *> mbs;
    mediaBase->clear();
    Analyze(&mbs,descs,analyzedName);
}

bool ConcerteCommand::IsMediaNameExist(string name){ // true is exist, false is the other
    for (Media *media : *mediaBase){
        if(media->getName() == name){
            return true;
        }
    }
    return false;
}

void ConcerteCommand::Analyze(std::stack<MediaBuilder*> *mb, string content, std::vector<char*> name){
    int nameCounter = 0;
    int comboCounter = 0;
    int currentComboSize = 0;
    /*vector<int> comboSizesToUse;
    for(int i=0; i < comboSizes.size; i++){
        comboSizesToUse[i] = comboSizes[i];
    }*/
    for(unsigned int i = 0; i < content.length(); i++){
        if(content[i] == 'c'){
            if(content[i+1] == 'o' && content[i+2] == 'm' && content[i+3] == 'b' && content[i+4] == 'o'){
                mb -> push(new ComboMediaBuilder());
                currentComboSize = comboSizes[comboCounter];
                comboCounter++;
                //std::cout << "currentComboSize : " << currentComboSize <<endl;
                mb -> top() -> buildComboMedia();
                mb -> top() -> getMedia()->setName(name[nameCounter]);
                //mediaBase.push_back(mb -> top() -> getMedia());
                nameCounter++;
            }
            else if(content[i+1] == '('){
                int endPosition = content.find_first_of(')', i);
                vector<double> value = getValues(content, i, endPosition);
                i = endPosition;
                Circle* circle = new Circle(value[0], value[1], value[2]);
                circle->setName(name[nameCounter]);
                if(!IsMediaNameExist(circle->getName())){
                    mediaBase->push_back(new ShapeMedia(circle));
                }
                if(comboCounter > 0 && currentComboSize > 0){
                    mb -> top() -> buildShapeMedia(circle);
                    currentComboSize--;
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
            if(!IsMediaNameExist(rectangle->getName())){
                mediaBase->push_back(new ShapeMedia(rectangle));
            }
            if(comboCounter > 0 && currentComboSize > 0){
                mb -> top() -> buildShapeMedia(rectangle);
                currentComboSize--;
            }
            nameCounter++;
        }
        else if(content[i] == 't'){
            int endPosition = content.find_first_of(')', i);
            vector<double> value = getValues(content, i, endPosition);
            i = endPosition;
            Triangle* triangle = new Triangle(value[0], value[1], value[2], value[3], value[4], value[5]);
            triangle->setName(name[nameCounter]);
            if(!IsMediaNameExist(triangle->getName())){
                mediaBase->push_back(new ShapeMedia(triangle));
            }
            if(comboCounter > 0 && currentComboSize > 0){
                mb -> top() -> buildShapeMedia(triangle);
                currentComboSize--;
            }
            nameCounter++;
        }
        else if(content[i] == ')'){
            mediaBase->push_back(mb -> top() -> getMedia());
            comboCounter--;
            if((mb -> size() >= 1) &&( comboCounter > 1 )) {
                Media *combo = mb -> top() -> getMedia();
                mb -> pop();
                ComboMediaBuilder* topCombo = dynamic_cast<ComboMediaBuilder*> (mb -> top());
                topCombo -> addComboMedia(combo);
            }
        }
    }
}

vector<double> ConcerteCommand::getValues(string content, int startPosition, int endPosition){
    vector<double> outputValues;
    double value;
    string desc = content.substr(startPosition + 2, endPosition - (startPosition + 2)); //2 means the shape title to first value's distance
    stringstream valueString(desc);
    while(valueString >> value) {
        outputValues.push_back(value);
    }
    return outputValues;
}
