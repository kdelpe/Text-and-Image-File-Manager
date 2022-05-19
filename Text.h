#ifndef TEXT_H
#define TEXT_H

#include "File.h"

class Text : public File
{
private:
	int characterCount;

public:
	//constructors
	Text(); //empty
	Text(std::string fileName, int characters); // constructor with file name and type parameters

	//getters
	int getCharacterCount() const;

	//virtual function overload to return text file size
	virtual int getSize() const;

	//virtual function overload to display text file properties
	virtual void displayFile() const;

};
#endif
