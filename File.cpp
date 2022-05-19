#include "File.h"
#include <string>
#include <iostream>

using namespace std;

File::File()
{
	fileName = "";
	fileType = "";
}

File::File(string fileName, string fileType)
{
	this->fileName = fileName;
	this->fileType = fileType;
}

string File::getFileName() const
{
	return fileName;
}

string File::getFileType() const
{
	return fileType;
}

void File::setFileName(string fileName)
{
	this->fileName = fileName;
}

void File::setFileType(string fileType)
{
	this->fileType = fileType;
}

// return size of the file
int File::getSize() const
{
	return 0;
}

//display function to print the file
void File::displayFile() const
{
	cout << "File Name: " << endl;
	cout << "File Type: " << endl;
	cout << "File Content: " << endl;
	cout << "File Size: " << endl << endl;
}


