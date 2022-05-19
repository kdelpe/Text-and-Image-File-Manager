#ifndef FILE_H
#define FILE_H

#include <string>

class File
{
private:
	std::string fileName;
	std::string fileType;
public:
	//constructors
	File(); //empty
	File(std::string name, std::string type); //constructor with file name and type parameters.

	//getters
	std::string getFileName() const;
	std::string getFileType() const;

	//setters
	void setFileName(std::string);
	void setFileType(std::string);

	//virtual function to return file size
	virtual int getSize() const;

	//virtual function to display file properties
	virtual void displayFile() const;

};
#endif