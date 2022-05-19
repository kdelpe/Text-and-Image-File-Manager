#include "Text.h"
#include <iostream>

using namespace std;

Text::Text() : File("", "text")
{
	characterCount = 0;
}

Text::Text(string fileName, int characters) : File(fileName, "txt")
{
	this->characterCount = characters;
}

int Text::getSize() const
{
	return characterCount;
}

int Text::getCharacterCount() const
{
	return characterCount;
}

void Text::displayFile() const
{
	cout << "File Name: " << getFileName() << endl;
	cout << "File Type: " << getFileType() << endl;
	cout << "File Content: " << getCharacterCount() << " characters" << endl;
	cout << "File Size: " << getSize() << " bytes" << endl << endl;
}
