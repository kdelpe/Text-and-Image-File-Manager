#ifndef IMAGE_H
#define IMAGE_H

#include "File.h"

class Image : public File
{
private:
	//dimensions
	int pixelRows;
	int pixelColumns;

	//variable for color depth per pixel
	int pixelColorDepth;

public:
	//constructors
	Image(); //empty
	Image(std::string fileName); //constructor with file name and type as parameters
	Image(std::string fileName, int rows, int columns, int colorDepth); //constructor with file name, dimensions and color depth as parameters

	//getters
	const int getPixelRows() const;
	const int getPixelColumns() const;
	const int getPixelColorDepth() const;

	//setters
	void setPixelRows(int);
	void setPixelColumns(int);
	void setPixelColorDepth(int);

	// virtual function overload to return image file size
	virtual int getSize() const;

	// virtual function overload to display file properties
	virtual void displayFile() const;

};
#endif
