Text and Image File Manager:
----------------------------
*Text and Image File Manager was completed as an assignment to practice polymorphism/inheritance with recursive functions for my object oriented programming course in C++.*

File Overview
-----------------------------------------------------------
* **Design a hierarchy of Files including two different kinds of Files, Text File and an Image File. The files are identified by their name and type, which is identified by either txt or gif extension. You should provide a function getSize that returns size of a file in bytes.**
    * An Image file has dimensions of pixel rows and pixel columns. Each pixel has a color depth that can be represented by number of bits. (8 bits is one byte). 
    * A Text file is a plain ASCII file that contains characters. Each character is represented by 8 bits. The size of an Image file is calculated by finding how many pixels are needed to store the file multiplied by number of bits to color a single bit divided by 8. The size of a Text file is calculated by counting number of ASCII characters stored in the file. 
* **Provide a function to display properties of a File. Properties include: type, name, size, dimensions and color depth for an Image File, characters for a Text File. Provide functions to return type and names of files. Provide function to retrieve character count for a Text file. Provide functions to retrieve dimensions and color depth of an Image File.** 

* Write two recursive functions: 
    - The first one receives a vector of File pointers and recursively outputs properties of every file stored inside this vector. 
    - The second function receives a vector of File pointers and a string which represents a type of the file (gif or txt). The function should return another vector of File pointers containing only Image files or Text files, depending on the second parameter. The function should be recursive. 
* **Write a menu driven application that will keep track of the collection of Files in a vector (File pointers, since File is an abstract class). The menu should contain the following options:** 
    1.	Read from a file (Read descriptions of Files from "files.txt" creating appropriate File object and putting it inside your vector. The file.txt is provided) 
    2.	Create an Image File (Creates a single Image File asking the user for its properties) 
    3.	Create a Text File (Creates a single Text File asking the user for its properties) 
    4.	Print All Files (You must use functions written for homework 9) 
    5.	Print Image Files (You must use functions written for homework 9) 
    6.	Print Text Files (You must use functions written for homework 9) 
    7.	Delete a file by file name and type (Removes a file from a vector) 
    8.	Quit (Terminate the program) 



Content Info
-------
### File list:
<!-- list files with brief descriptions -->
- **File.h**
    - Header file of base class, File, including two different kinds of files identified by name and type, a virtual function for the file size, and a virtual function to display files properties.
- **File.cpp**
    - Implementation of the header file, File.h, class constructors, getters and virtual functions.
- **Text.h**
    - Header file of derived class, Text, from super class File including the variable holding characters, constructors, a function that returns the number of characters in the file, overlading virtual functions to modify size and text file properties.
- **Text.cpp**
    - Implementation of the header file, Text.h, class constructors, getters and overlading virtual functions to modify size and file properties.
- **Image.h**
    - Header file of derived class, Image, from super class File including the variables holding pixel rows, columns and color depth, constructors, a function that returns the dimensions of the file, overlading virtual functions to modify size and text file properties.
- **Image.cpp**
    - Implementation of the header file, Image.h, class constructors, getters, setters and overlading virtual functions to modify size and image file properties.
- **file.txt**
    - Text file to read and input data from in the program
- **main.cpp**
    - main() function responsible for program starts and ends. It gives the status of the program to the Parent process, informing the success or failure of the program.
    




