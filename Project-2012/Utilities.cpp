/////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////
//                              Utilities.cpp                                  //
//                                                                             //
// Purpose : Common utility applications used in lots of programs.             //
//                                                                             //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server     //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005  // 
/////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////// 

# include "Utilities.hpp"
# define _CRT_SECURE_NO_DEPRECATE 1
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                           StripLeadingBlanks                                 //
//                                                                              //
// Purpose : Remove all leading blanks from String[].                           //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 

void StripLeadingBlanks (char String[])
{
   long int 
      Pos2, // First Non-Blank Char
      Pos1;

   Pos2 = 0;

// Set Pos2 to the first non blank character.
   while (String [Pos2] == ' ')
      Pos2 ++;

// Copy valid characters to the beginning of the string..
   for (Pos1 = 0; String[Pos2] != '\0'; Pos1++, Pos2++)
      String[Pos1] = String[Pos2];

// Insert the End of String Marker..
      String[Pos1] = '\0';
}


//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                             StripTrailingBlanks                              //
//                                                                              //
//  Purpose : Remove all trailing blanks. String *Tom Hicks * becomes string    //
//  *Tom Hicks*                                                                 //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 

void StripTrailingBlanks (char String[])
{
  size_t 
      Pos;

   Pos = strlen(String)-1;

// Set Pos to the last non blank character.
   while (String [Pos] == ' ')
   {
      Pos --;
   }

// Insert the End of String Marker..
   String[Pos +1] = '\0';
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                ToLowerCase                                   //
//                                                                              //
//  Purpose : Convert String[] to all lower case characters. String *tOm HiCKs* //
//  becomes string *tom hicks*                                                  //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 

void ToLowerCase (char String[])
{
   unsigned long int 
      Pos;

   for (Pos = 0; Pos <= strlen(String); Pos ++)
   {
      if ((String[Pos] >= 'A') && (String[Pos] <= 'Z')) 
         String[Pos] = String[Pos] + ' ';
   }
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                   ToUpperCase                                //
//                                                                              //
// Purpose : Convert String[] to all upper case characters. String *tOm HiCKs*  //
// becomes string *TOM HICKS*                                                   //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 

void ToUpperCase (char String[])
{
   unsigned long int 
      Pos;

   for (Pos = 0; Pos <= strlen(String); Pos ++)
   {
      if ((String[Pos] >= 'a') && (String[Pos] <= 'z')) 
         String[Pos] = String[Pos] - ' ';
   }
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                           CompressMultipleBlanks                             //
//                                                                              //
// Purpose : Compress multiple blanks to a single blank. String *Tom Hicks*     //
// becomes string *Tom Hicks*                                                   //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 

void CompressMultipleBlanks (char String[])
{
// For you to do if you want it!
}



//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                           PrepareMatchString                                 //
//                                                                              //
// Purpose : Strip Leading Blanks, Strip Trailing Blanks, Compress Multiple     //
// Blanks and change to Lower Case. String * tOm HiCKs *                        //
// would be changed to *tom hicks* for more accurate pattern                    //
// matching.                                                                    //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 

void PrepareMatchString (char String[])
{
   StripLeadingBlanks (String);
   StripTrailingBlanks (String);
   ToLowerCase (String);
   CompressMultipleBlanks (String);
}



//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                        HitCarriageReturnToContinue                           //
//                                                                              //
// Purpose : Delay until the user strikes the return key.                       //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 

void HitCarriageReturnToContinue (void) 
{
   char
      JunkString[255];

// cin.flush();
   cout << " <Hit Carriage Return To Continue>\n";

   #ifdef INTERACTIVE //=============================================================
      cin.getline(JunkString,255);
   #endif // INTERACTIVE ============================================================
}

void TestSwap(void)
{
   int 
      A = 5, 
      B = 10;

   cout << "A = " << A << " B = " << B << endl;
   Swap (A, B);
   cout << "A = " << A << " B = " << B << endl;

   double 
      AA = 5.5, 
      BB = 5.6;

   cout << "AA = " << AA << " BB = " << BB << endl;
   Swap (AA, BB);
   cout << "AA = " << AA << " BB = " << BB << endl;

   char 
      AAA = 'X', 
      BBB = 'O';

   cout << "AAA = " << AAA << " BBB = " << BBB << endl;
   Swap (AAA, BBB);
   cout << "AAA = " << AAA << " BBB = " << BBB << endl;
}

void TestUtilities (void)
{
   TestSwap();
}


void TestPrepareMatchString(void) 
{ 
   char
      Name[] = " Now Is The TimE ";

   cout << "Original *" << Name << "*\n";
   StripLeadingBlanks (Name);
   cout << "Strip Leading *" << Name << "*\n";
   StripTrailingBlanks (Name);
   cout << "Strip Trailing *" << Name << "*\n";
   ToLowerCase (Name);
   cout << "ToLowerCase *" << Name << "*\n";
   ToUpperCase (Name);
   cout << "ToUpperCase *" << Name << "*\n";
   strcpy (Name, " Now Is The TimE ");
   PrepareMatchString(Name); 
   cout << "PrepareMatchString *" << Name << "*\n";

}

long int FileLength (FILE *FilePtr, long int NoBytesPerRecord)
{
	long int
		Bytes;

	return (Bytes / NoBytesPerRecord);    //Returns number of records in file
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                             Function RandomNo                                //
//                                                                              //
// Purpose : Test each and every method in class RebeccaMP3.                    //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

long int RandNo(long int Low, long int High)
{
	long int RandNo = long int(rand() / 32767.001 * (High - Low)) + Low;
	return RandNo;
}
