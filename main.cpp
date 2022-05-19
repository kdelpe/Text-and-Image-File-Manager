#include "Image.h"
#include "Text.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void filesDataOutput(vector<File*> file, unsigned int fileIndex = 0)
{
    // Vector of file pointers to recursively output the properties
    if (fileIndex < file.size() - 1) //base case
    {
        file[fileIndex]->displayFile();
        filesDataOutput(file, ++fileIndex); //recursive case
    }
    else
    {
        file[fileIndex]->displayFile();
    }
}

void filesTypeFilter(vector<File*> vectorFile, string fileType, unsigned int fileLocation = 0)
{
    // Vector of file pointers to recursively filter out the files by type
    while ((fileType.compare("txt") != 0) && (fileType.compare("gif") != 0))
    {
        //while loop to throw error if file type is incorrect and re-input
        cout << "Error: Incorrect file type. Please enter correct file type (txt or gif): ";
        cin >> fileType;
    }

    if (vectorFile.size() > 0)
    {
        if (fileLocation < vectorFile.size()) //if vector file is not out of bounds
        {
            while (vectorFile[fileLocation]->getFileType().compare(fileType) != 0)
            {
                //go to the next index while the files are not of the same type
                ++fileLocation;
                if (fileLocation == vectorFile.size()) //base case
                {
                    return;
                }
            }
            vectorFile[fileLocation]->displayFile();

            filesTypeFilter(vectorFile, fileType, ++fileLocation);//recursive case to output files with same type
        }
    }
    else
    {
        return;
    }
}

int main()
{
    //vector pointer to input image and text files
    vector<File*> inputFileContent;

    int option = 1;

    cout << "*******Text and Image File Manager*******" << endl;;

    while (true) // menu options for user to choose from
    {
        cout << "----------------------------------------- " << endl;
        cout << "Menu" << endl;
        cout << "----------------------------------------- " << endl;
        cout << "1. Read data from a file\n"
             << "2. Create an Image file\n"
             << "3. Create a Text file\n"
             << "4. Print All Files\n"
             << "5. Print Image Files\n"
             << "6. Print Text Files\n"
             << "7. Delete a file by name and type\n"
             << "8. Quit" << endl <<endl;

        cout << "Enter Menu option (1-8): ";
        cin >> option;
        cout << endl;

        if (option > 8 || option < 1)
        {
            cout << "Error: Invalid option!" << endl << endl;
            continue;
        }

        else if (option == 1) //if user chooses to read data from a file
        { 
            ifstream inputFile;
            string line; 

            inputFile.open("file.txt"); //open the input .txt file
            while (!inputFile.eof()) 
            {
                getline(inputFile, line);
                if (line.empty())
                { // if the line is blank, continue
                    continue;
                }
                else if (line.compare("txt") == 0) 
                { //when txt is read from a line, create a new Text file
                    string newTextFileName;
                    getline(inputFile, newTextFileName); //get the name of the text file

                    int newTextFileCharacterCount;
                    inputFile >> newTextFileCharacterCount;
                    inputFileContent.push_back(new Text(newTextFileName, newTextFileCharacterCount));
                }
                else if (line.compare("gif") == 0) 
                { //when gif is read from a line, create a new Image file
                    string newImageFileName;
                    getline(inputFile, newImageFileName);

                    string nothing; //store the empty files from the input file 

                    int newImagePixelRows, newImagePixelColumns, newImagePixelColorDepth;
                    inputFile >> newImagePixelRows;
                    inputFile >> nothing;
                    inputFile >> newImagePixelColumns;
                    inputFile >> newImagePixelColorDepth;
                    inputFileContent.push_back(new Image(newImageFileName, newImagePixelRows, newImagePixelColumns, newImagePixelColorDepth));
                }
                else 
                {
                    cout << "Error: Broken input file" << endl << endl;
                    exit(1);
                }
            } 
            cout << "Input file data read successfully"! << endl << endl;
            continue; 
        }

        else if (option == 2) //if user chooses to create an image file
        { 
            string imageName;
            int pixelValues; 
            cout << "Enter new image file name: ";
            cin.ignore();
            getline(cin, imageName);

            Image* createdImage = new Image(imageName); //image object pointer to push into the vector of files
            cout << "Enter the number of pixel rows: ";
            cin >> pixelValues;
            createdImage->setPixelRows(pixelValues);
            cout << "Enter the number of pixel columns: ";
            cin >> pixelValues;
            createdImage->setPixelColumns(pixelValues);
            cout << "Enter the pixels' color depth: ";
            cin >> pixelValues;
            createdImage->setPixelColorDepth(pixelValues);

            inputFileContent.push_back(createdImage);
            cout << "Image file created successfully!" << endl << endl;

            continue;
        }

        else if (option == 3) //if user chooses to create a text file
        { 
            string textName;
            int newCharacterCount;
            cout << "Enter the new text file name: ";
            cin.ignore();
            getline(cin, textName);
            cout << "Enter the character count of the new text file: ";
            cin >> newCharacterCount;

            inputFileContent.push_back(new Text(textName, newCharacterCount));
            cout << "Text file created successfully!" << endl << endl;

            continue;
        }

        else if (option == 4)  //if user chooses to print all files
        {
            if (inputFileContent.empty())
            {
                cout << "Error: Please create a new file or read data from an input file" << endl;
            }
            else
            {
                cout << "File properties details:" << endl;
                cout << "----------------------------------" << endl << endl;
                filesDataOutput(inputFileContent);
            }

            continue;
        }

        else if (option == 5) //if user chooses to only print image files 
        {
            cout << "Image files properties:" << endl;
            cout << "----------------------------------" << endl << endl;
            filesTypeFilter(inputFileContent, "gif");
            cout << endl;

            continue;
        }

        else if (option == 6) //if user chooses to only print text files
        { 
            cout << "Text files properties:" << endl;
            cout << "----------------------------------" << endl << endl;
            filesTypeFilter(inputFileContent, "txt");
            cout << endl;

            continue;
        }

        else if (option == 7) //if user chooses to delete a file by its name and type
        { 
            string name, type = "";
            cout << "Enter file name to delete: ";
            cin.ignore();
            getline(cin, name);

            while (type.compare("gif") != 0 && type.compare("txt") != 0) 
            {
                cout << "Enter file type to delete (txt or gif): ";
                cin >> type;
            }

            int i = 0;
            while (i < inputFileContent.size()) 
            { 
                if (inputFileContent[i]->getFileName().compare(name) == 0 && inputFileContent[i]->getFileType().compare(type) == 0)
                {
                    break;
                }
                ++i;
            }
            if (i >= inputFileContent.size())
            {
                cout << "Error: Unable to retrieve file" << endl << endl;

                continue;
            }
            else 
            {
                //delete the file pointer 
                File* temp = inputFileContent[i];
                while (i < inputFileContent.size() - 1) 
                {
                    inputFileContent[i] = inputFileContent[i + 1];
                    ++i;
                }
                inputFileContent.resize(inputFileContent.size() - 1); //shift the rest of the vector after deleting index
                cout << "File deleted successfully!" << endl << endl;

                continue;
            }
        }

        else if (option == 8) //if user chooses to quit the program
        {
            break;
        }

    }
    cout << endl;
    cout << "Thank you for using the text& image file manager!" << endl << endl;

    return 0;

} 

