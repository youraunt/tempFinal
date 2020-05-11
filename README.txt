*******************************************************
*  Name      :	Brice Allen          
*  Student ID:	*****2188
*  Class     :  CSC 2421           
*  HW#       :  Final
*  Due Date  :  May 11, 2020
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program "2188Final" implements the an award database
to handle three csv files:
* actor-actress.csv
* pictures.csv
* nominations.csv

The program utilizes Vectors and Binary Search Trees as
its main data structures.


*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program.  This is the driver program that calls
   enter_program();

Name:  functions.h
   Contains the prototypes for the class function.

Name: function.cpp
   Defines and implements the functions class for implementing
   sorting, searching, deleting, adding, displaying, and writing
   to file.

Menus.h & Menus.cpp
    Menus.h contains the prototypes for the class.
    Menus.cpp implements the functions for handling user interfaces.

Read_From_File.h & Read_From_File.cpp
    Read_From_File.h contains the prototypes for the class.
    Read_From_File.cpp implements the functions related to reading in
    from the files.


Node.h, Binary_Search_Tree.hpp, & Binary_Search_Tree.h
    Provided, minimally altered.
   
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program runs successfully.  
   
   The program was developed and tested on QtCreator.  It was
   compiled, run, and tested on gcc csegrid.ucdenver.pvt.


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip 2188Final

   Now you should see a directory named homework with the files:
	main.cpp
	functions.h
	functions.cpp
	Read_From_File.h
	Read_From_File.cpp
	Menus.h
	Menus.cpp
	actor-actress.csv
	nominations.csv
	pictures.csv
	Binary_Search_Tree.h
	Binary_Search_Tree.hpp
    Node.h
	makefile
	Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd 2188Final

    Compile the program by:
    % make

3. Run the program by:
   % ./2188Final

4. Delete the obj files, executables, and core dump by
   %./make clean
