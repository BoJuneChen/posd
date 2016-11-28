#ifndef MEDIADIRECTOR_H
#define MEDIADIRECTOR_H

#include "Media.h"
#include <string>
#include <stack>

using namespace std;

class MediaDirector {

public :
	void setMediaBuilder(std::stack<MediaBuilder *> *mbs);
	void concrete(string content);

private :
  	std::stack<MediaBuilder*> *mb;
};
#endif // MEDIADIRECTOR_H
