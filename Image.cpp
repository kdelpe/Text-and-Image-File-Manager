#include "Image.h"
#include <iostream>

using namespace std;

//constructors
Image::Image() : File("", "gif")
{
	pixelRows = 0;
	pixelColumns = 0;
	pixelColorDepth = 0;
}

Image::Image(string fileName) : File(fileName, "gif")
{
	pixelRows = 0;
	pixelColumns = 0;
	pixelColorDepth = 0;
}

Image::Image(string fileName, int rows, int columns, int colorDepth) : File(fileName, "gif")
{
	pixelRows = rows;
	pixelColumns = columns;
	pixelColorDepth = colorDepth;
}

//getters
const int Image::getPixelRows() const
{
	return pixelRows;
}

const int Image::getPixelColumns() const
{
	return pixelColumns;
}

const int Image::getPixelColorDepth() const
{
	return pixelColorDepth;
}

//setters
void Image::setPixelRows(int pixelRows)
{
	this->pixelRows = pixelRows;
}

void Image::setPixelColumns(int pixelColumns)
{
	this->pixelColumns = pixelColumns;
}

void Image::setPixelColorDepth(int pixelColorDepth)
{
	this->pixelColorDepth = pixelColorDepth;
}

// return size of the image file
int Image::getSize() const
{
	return (pixelRows * pixelColumns * pixelColorDepth) / 8;
}

//display function to print the image file
void Image::displayFile() const
{
	cout << "File Name: "        << getFileName() << endl;
	cout << "File Type: "        << getFileType() << endl;
	cout << "File Dimensions: "  << getPixelRows() << " x " << getPixelColumns() << endl;
	cout << "File Color Depth: " << getPixelColorDepth() << " bits" << endl;
	cout << "File Size: "        << getSize() << " bytes" << endl << endl;
}
