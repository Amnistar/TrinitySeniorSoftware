//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//                               Utilities.hpp                                  //
//                                                                              //
// Purpose : Collection of often used utilities.                                //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
# ifndef UTILITIES //-------------------------------------------------------------
# define _CRT_SECURE_NO_DEPRECATE 1

# define VISUALC
//# define GNUC

// ----------------------------------- Includes ----------------------------------

// -------------- Add in Main/hpp's As You Need Stream Output ------------ 
#ifdef VISUALC  //===================================================
   # include <iostream>
   # include <fstream>   
   # include <iomanip>
   # define VISUALC
   using namespace std;
#endif// VISUALC  ===================================================

#ifdef GNUC  //======================================================
   # include <iostream.h>
   # include <iomanip.h>
   # include <fstream.h>
   # define GNUC
#endif// GNUC  ======================================================

# include <stdio.h> 
# include <string.h> 
# include <stdlib.h>


// ----------------------------------- Defines -----------------------------------
# define UTILITIES 
# define INTERACTIVE // Comment Out To Eliminate all Delays, Clears, etc.

// I/O is not standardized in C/C++ These defines will be used for I/0 processing
// such as clearing the screen, moving the cursor, etc. Select one of the following:

//# define BORLAND_IBM
//# define SYMANTEC_IBM
//# define SYMANTEC_MAC
//# define LINUX
//# define CODE_WARRIOR_IBM
//# define CODE_WARRIOR_MAC
# define MICROSOFT_VISUAL

# define SUCCESSFUL 1
# define UNSUCCESSFUL 0
# define VALID 1
# define INVALID 0

// Define Some Of The Commonly Used Keyboard Characters
# define ESC 27
# define CARRIAGE_RETURN 10
# define LINE_FEED 13

# define UP_ARROW 30
# define DOWN_ARROW 31
# define LEFT_ARROW 28
# define RIGHT_ARROW 29
# define DELETE_KEY 8
# define END_OF_STRING 0
# define BLANK 32
# define NILL 0



// ------------------------------ String Processing ----------------------------
void StripLeadingBlanks (char String[]);
void StripTrailingBlanks (char String[]);
void ToLowerCase (char String[]);
void ToUpperCase (char String[]);
void CompressMultipleBlanks (char String[]);
void PrepareMatchString (char String[]);
void TestPrepareMatchString(void);

// ------------------------------ Screen Processing -----------------------------
void ClearScreen(void);
void HitCarriageReturnToContinue (void);

// ------------------------------ String Processing ----------------------------
template <class T>
void Swap (T & Value1, T & Value2);

// ------------------------------- Non-Template Functions ------------------------
void TestSwap (void);
void TestUtilities (void);
long int FileLength (FILE *FilePtr, long int NoBytesPerRecord);
long int RandNo(long int Low, long int High);

// ------------------------------ Template Prototypes -----------------------------
template <class InfoType>
bool WriteRecord(InfoType *Info, long int RecordNo, FILE *fp);
template <class InfoType>
bool ReadRecord(InfoType *Info, long int RecordNo, FILE *fp);

// ------------------------------ Template Functions -----------------------------

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//                                      Swap                                    //
//                                                                              //
// Purpose : Exchange the values Value1 and Value2.                             //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 

template <class T>
void Swap (T & Value1, T & Value2)
{
   T
      Temp;

   Temp = Value1;
   Value1 = Value2;
   Value2 = Temp;
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//                                 ReadRecord                                   //
//                                                                              //
// Purpose : Read the direct access record RecordNo from file *fp into          //
//           container Info.  No error checking yet!                            //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
template <class InfoType>
bool ReadRecord(InfoType *Info, long int RecordNo, FILE *fp)
{
	return (SUCCESSFUL);
}


//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//                                WriteRecord                                   //
//                                                                              //
// Purpose : Write the direct access record RecordNo from file *fp from         //
//           container Info.  No error checking yet!                            //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
template <class InfoType>
bool WriteRecord(InfoType *Info, long int RecordNo, FILE *fp)
{
	return (SUCCESSFUL);
}



# endif