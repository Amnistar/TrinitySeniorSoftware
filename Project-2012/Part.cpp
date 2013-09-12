//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                               Part.cpp                                       //
//                                                                              //
// Purpose    : House all non-template methods for class Part.                  //
//              House function TestPart(void).                                  //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

# include "Part.hpp"

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 Method Part                                  //
//                                                                              //
// Purpose : Constructors for Class Part. Set Name to NewName and No to NewNo.  //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
Part::Part (char NewName[], long int NewNo, long int NewDeptNo, 
			long int NewQuantity, double NewCost)
{
# ifdef PART_DIAGNOSTIC_LEVEL //---------------------------------------------------
	if (PART_DIAGNOSTIC_LEVEL <= 1)
		puts("Evoking Constructor Part (NewName,NewNo,NewDeptNo,NewQuantity,NewCost)");
# endif // PART_DIAGNOSTIC_LEVEL --------------------------------------------------

	Set (NewName, NewNo, DeptNo, NewQuantity, NewCost);
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                   DeptNo_()                                  //
//                                                                              //
// Purpose : Explicitly Returns the Part No.                                    //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 

long int  Part::DeptNo_(void)
{
	return (DeptNo);
}


//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 Method ~Part                                 //
//                                                                              //
// Purpose : Destructor Class Part.                                             //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
Part::~Part (void)
{
# ifdef PART_DIAGNOSTIC_LEVEL //---------------------------------------------------
	if (PART_DIAGNOSTIC_LEVEL <= 1)
		puts("Evoking Destructor ~Part (void)");
# endif // PART_DIAGNOSTIC_LEVEL --------------------------------------------------

}

# ifdef PART_DIAGNOSTIC_LEVEL //---------------------------------------------------

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 Method Display                               //
//                                                                              //
// Purpose : Display Name on line 1, No on line 2, and blank on line 3.         //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void Part::Display (char Message[])
{
	if (strlen (Message) > 0)
		puts( Message);
	printf("Name     : %s\n", Name);
	printf("No       : %ld\n", No);
	printf("DeptNo   : %ld\n", DeptNo);
	printf("Cost     : %6.2f\n", Cost);
	printf("Quantity : %ld\n\n", Quantity);
}


//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 Method Display50                             //
//                                                                              //
// Purpose : Display the most important 50 characters of the structure.         //
//           No line feed.                                                      //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void Part::Display50(void)
{
	printf("%-22s %6ld %6ld %6ld %6.2f", Name, No, DeptNo, Quantity, Cost);
}

# endif // PART_DIAGNOSTIC_LEVEL --------------------------------------------------

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 Method Set                                   //
//                                                                              //
//Purpose : Set the value of Name to NewName. Set the value of No to NewNo.     //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void Part::Set(char NewName[], long int NewNo, long int NewDeptNo, 
			long int NewQuantity, double NewCost)
{
   strcpy (Name, NewName);
   No = NewNo;
   DeptNo = NewDeptNo;
   Cost = NewCost;
   Quantity = NewQuantity;
}


//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 Method Get                                   //
//                                                                              //
// Purpose : Interactively Prompt The User For Name, and No. If the Name is     //
//           Blank exit; do not prompt for No. Does No Error checking for No.   //
//           Explicitly returns INVALID if user chooses to exit prematurely by  //
//           enterning a Name = Blank. Otherwise return VALID.                  //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
bool Part::Get(void)
{
char
	Temp[200];

	fflush(stdin);
	printf ("\nEnter Part Name [Hit Return To Exit].....: ");
	gets(Temp);
	if (strlen(Temp) == 0)
		return (INVALID);
	strncpy(Name, Temp, 25);
	Name[25] = 0;

	fflush(stdin);
	printf ("\nEnter Part No ...........................: ");
	scanf ("%ld", &No);

	fflush(stdin);
	printf ("\nEnter Dept No ...........................: ");
	scanf ("%ld", &DeptNo);

	fflush(stdin);
	printf ("\nEnter Cost ..............................: ");
	scanf ("%f", &Cost);

	fflush(stdin);
	printf ("\nEnter Quantity ..........................: ");
	scanf ("%ld", &No);

	fflush(stdin);

	return (VALID);
}
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                        char operator Overloads                               //
//                                                                              //
// Purpose : Overload the operators in such a way that the Name becomes the     //
//           primary character key for the Part Class.                          //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
bool Part::operator == (const char Key[])   
{
   if (strcmp(Name, Key) == 0)
      return (true);
   else 
      return (false);
}
   
bool Part::operator > (const char Key[])   
{
   if (strcmp(Name, Key) > 0)
      return (true);
   else 
      return (false);
}

bool Part::operator >= (const char Key[])   
{
   if (strcmp(Name, Key) >= 0)
      return (true);
   else 
      return (false);
}

bool Part::operator < (const char Key[])   
{
   if (strcmp(Name, Key) < 0)
      return (true);
   else 
      return (false);
}

bool Part::operator <= (const char Key[])   
{
   if (strcmp(Name, Key) <= 0)
      return (true);
   else 
      return (false);
}

bool Part::operator != (const char Key[])   
{
   if (strcmp(Name, Key) != 0)
      return (true);
   else 
      return (false);
}

void Part::operator = (const char Key[])   
{
   strcpy(Name, Key);
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                      Part operator Overloads                                 //
//                                                                              //
// Purpose : Overload the operators in such a way that the Name becomes the     //
//           primary Part key for the Part Class.                               //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
bool Part::operator == (const Part & P)
{
   if (strcmp(Name, P.Name) == 0)
      return (true);
   else 
      return (false);
}

bool Part::operator > (const Part & P)
{
   if (strcmp(Name, P.Name) > 0)
      return (true);
   else 
      return (false);
}

bool Part::operator >= (const Part & P)
{
   if (strcmp(Name, P.Name) >= 0)
      return (true);
   else 
      return (false);
}

bool Part::operator < (const Part & P)
{
   if (strcmp(Name, P.Name) < 0)
      return (true);
   else 
      return (false);
}

bool Part::operator <= (const Part & P)
{
   if (strcmp(Name, P.Name) <= 0)
      return (true);
   else 
      return (false);
}


bool Part::operator != (const Part & P)
{
   if (strcmp(Name, P.Name) != 0)
      return (true);
   else 
      return (false);
}

void Part::operator = (const Part & P)
{
   strcpy (Name, P.Name);
   No = P.No;
   Cost = P.Cost;
   Quantity = P.Quantity;
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                        int operator Overloads                                //
//                                                                              //
// Purpose : Overload the operators in such a way that the No becomes the       //
//           primary integer key for the Part Class.                            //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
bool Part::operator == (const long int Key)
{
   if (No == Key) 
      return (true);
   else 
      return (false);
}

bool Part::operator > (const long int Key)
{
   if (No > Key) 
      return (true);
   else 
      return (false);
}

bool Part::operator >= (const long int Key) 
{
   if (No >= Key) 
      return (true);
   else 
      return (false);
}

bool Part::operator < (const long int Key)
{
   if (No < Key) 
      return (true);
   else 
      return (false);
}

bool Part::operator <= (const long int Key) 
{
   if (No <= Key) 
      return (true);
   else 
      return (false);
}

bool Part::operator != (const long int Key) 
{
   if (No != Key) 
      return (true);
   else 
      return (false);
}

void Part::operator = (const long int Key) 
{
   No = Key;
}


//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                          Overload << Operator                                //
//                                                                              //
//Purpose : Display the 50 characters that represent this Part datatype.        //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
ostream & operator << (ostream & OutputStream, Part P)
{
	OutputStream << setw(18) << left << P.Name; 
	OutputStream << " " << right << setw(6) << P.No;
	OutputStream << " " << setw(6) << P.No;
	OutputStream << " " << setw(6) << P.Quantity;
	OutputStream.setf(ios::fixed);
	OutputStream.precision(2);
	OutputStream << " " << setw(10) << P.Cost;
	return (OutputStream);

}


//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 Key()                                        //
//                                                                              //
// Purpose : Explicitly Return a long integer that represents this Part.        //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 
long int  Part::Key(void)
{
	return (No);
}


//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                   No_()                                      //
//                                                                              //
// Purpose : Explicitly Returns the Part No.                                    //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 

long int  Part::No_(void)
{
	return (No);
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                  Cost_()                                     //
//                                                                              //
// Purpose : Explicitly Returns the Part No.                                    //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 

double  Part::Cost_(void)
{
	return (Cost);
}

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                   Quantity_()                                //
//                                                                              //
// Purpose : Explicitly Returns the Part No.                                    //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////// 

long int  Part::Quantity_(void)
{
	return (Quantity);
}


# ifdef PART_DIAGNOSTIC_LEVEL //---------------------------------------------------

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                 Function TestPart                            //
//                                                                              //
//  Purpose : Test each and every method in class Part.                         //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
void TestPart(void)
{
	puts("\n\n*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("************************* Start TestPart **************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");

	if (PART_DIAGNOSTIC_LEVEL <= 1)
	{
	puts("\n\n===================================================================");
	puts("===================================================================");
	puts("================== Testing Constructor & Destructor ===============");
	puts("===================================================================");
	puts("===================================================================\n");

	Part
	   Part1,
	   Part2("Football", 22),
	   Inventory[4];   
	
	}
	
	if (PART_DIAGNOSTIC_LEVEL <= 2)
	{
	puts("\n\n===================================================================");
	puts("===================================================================");
	puts("=================== Testing Display Methods =======================");
	puts("===================================================================");
	puts("===================================================================\n");

	Part
	   Part1,
	   Part2("Football", 22, 1, 5, 1.5),
	   Part3( "Softball", 33, 1, 10, 3.30);   

	   Part1.Display("\nContents Of Part1");
	   Part2.Display("\nContents Of Part2");
	   Part3.Display("\nContents Of Part3");
	   

	   puts("\n\n\n| 12345678901234567890123456789012345678901234567890 |");
	   puts("-------------------------------------------------------");
	   printf("| ");
	   Part1.Display50();
	   puts(" |");
	   printf("| ");
	   Part2.Display50();
	   puts(" |");
	   printf("| ");
	   Part3.Display50();
	   puts(" |");
	   puts("-------------------------------------------------------");
	}

	if (PART_DIAGNOSTIC_LEVEL <= 3)
	{
	puts("\n\n===================================================================");
	puts("===================================================================");
	puts("====================== Testing Set Method =========================");
	puts("===================================================================");
	puts("===================================================================\n");

	Part
	   Part1,
	   Part2("Football", 22, 1, 10, 12.5),
	   Part3("Softball", 33, 1, 5, 5.50);   

 	   Part1.Display("\nContents Of Part1");
	   Part2.Display("\nContents Of Part2");
	   Part3.Display("\nContents Of Part3");

	   Part1.Set("Computer",111, 1, 2, 2.20);
	   Part2.Set("Monitor");
	   Part3.Set();

	   Part1.Display("\nNew Contents Of Part1");
	   Part2.Display("\nNew Contents Of Part2");
	   Part3.Display("\nNew Contents Of Part3");

	}

	if (PART_DIAGNOSTIC_LEVEL <= 4)
	{
	puts("\n\n===================================================================");
	puts("===================================================================");
	puts("======================= Testing < Overload ========================");
	puts("===================================================================");
	puts("===================================================================\n");

	Part
		Part1 ("BasketBall",11, 1, 4, 2.25);

		puts("\n\n\n| 12345678901234567890123456789012345678901234567890 |");
		puts("-------------------------------------------------------");
		printf("| ");
		fflush(stdout);
		cout << Part1;
		cout.flush();
		puts(" |\n");
	}


	if (PART_DIAGNOSTIC_LEVEL <= 5)
	{
	puts("\n\n===================================================================");
	puts("===================================================================");
	puts("=================== Testing Operator Overloads ====================");
	puts("===================================================================");
	puts("===================================================================\n");

	Part
	   Part3 ("SoccerBall",44),
	   Part5 ("FootBall", 55);
   
  
		Part5.Display("\nInfo Stored In Part5:");
		if (Part5 == "FootBall")
		  puts("Part.Name == 'FootBall'");
		else
		  puts("Part.Name != 'FootBall'");

		if (Part5 == "   FooTBAll   ")
		  puts("Part.Name == ' FooTBAll '");
		else
		  puts("Part.Name != '   FooTBAll   '");

		if (Part5 == "TennisBall")
		  puts("Part.Name == TennisBall");
		else
		  puts("Part.Name != TennisBall");


		Part5.Set ("CCC", 3);
		if (Part5 == "AAA")                   // Test = Char
		  puts("True ---> CCC = AAA");
		else
		  puts("False --> CCC = AAA");
		if (Part5 > "AAA")                   // Test > Char
		  puts("True ---> CCC > AAA");
		else
		  puts("False --> CCC > AAA");
		if (Part5 >= "AAA")                   // Test >= Char
		  puts("True ---> CCC >= AAA");
		else
		  puts("False --> CCC >= AAA");
		if (Part5 < "AAA")                   // Test < Char
		  puts("True ---> CCC < AAA");
		else
		  puts("False --> CCC < AAA");
		if (Part5 <= "AAA")                   // Test <= Char
		  puts("True ---> CCC <= AAA");
		else
		  puts("False --> CCC <= AAA");
		if (Part5 != "AAA")                   // Test != Char
		  puts("True ---> CCC != AAA");
		else
		  puts("False --> CCC != AAA");

		Part5.Display("\n\nContents of Part5"); // Test = Char
		Part5 = "GolfBall";
		Part5.Display("New Contents of Part5");

		puts("\n*************  int Overload operator *****************************\n");
		Part5.Set ("CCC", 3);
		if (Part5 == 5)                   // Test = Integer
		  puts("True ---> 3 == 5");
		else
		  puts("False --> 3 == 5");
		if (Part5 > 5)                   // Test > Integer
		  puts("True ---> 3 > 5");
		else
		  puts("False --> 3 > 5");
		if (Part5 >= 5)                   // Test >= Integer
		  puts("True ---> 3 >= 5");
		else
		  puts("False --> 3 >= 5");
		if (Part5 < 5)                   // Test < Integer
		  puts("True ---> 3 < 5");
		else
		  puts("False --> 3 < 5");
		if (Part5 <= 5)                   // Test <= Integer
		  puts("True ---> 3 <= 5");
		else
		  puts("False --> 3 <= 5");
		if (Part5 != 5)                   // Test != Integer
		  puts("True ---> 3 != 5");
		else
		  puts("False --> 3 != 5");
		Part5.Display("\n\nContents of Part5"); // Test = Integer
		Part5 = 21;
		Part5.Display("New Contents of Part5");


		puts("\n*************  Part Overload operator ***************************\n");
		Part5.Set ("BaseBall", 5);
		Part3.Set ("TennisBall", 21);

		if (Part5 == Part3)                 // Test == Part
		  puts("True ---> BaseBall = TennisBall");
		else
		  puts("False --> BaseBall = TennisBall");

		if (Part5 > Part3)                  // Test > Part
		  puts("True ---> BaseBall > TennisBall");
		else
		  puts("False --> BaseBall > TennisBall");

		if (Part5 >= Part3)                  // Test >= Part
		  puts("True ---> BaseBall >= TennisBall");
		else
		  puts("False --> BaseBall >= TennisBall");

		if (Part5 < Part3)                   // Test < Part
		  puts("True ---> BaseBall < TennisBall");
		else
		  puts("False --> BaseBall < TennisBall");

		if (Part5 <= Part3)                   // Test < Part
		  puts("True ---> BaseBall <= TennisBall");
		else
		  puts("False --> BaseBall <= TennisBall");

		if (Part5 != Part3)                   // Test != Part
		  puts("True ---> BaseBall != TennisBall");
		else
		  puts("False --> BaseBall != TennisBall");

		Part5.Display("\nNew Contents of Part5");
		Part3.Display("\nNew Contents of Part3");
		Part5 = Part3;                        // Test = Part
		Part5.Display("\nNew Contents of Part5");
		Part3.Display("\nNew Contents of Part3");
	}

	
	if (PART_DIAGNOSTIC_LEVEL <= 6)
	{
	puts("\n\n===================================================================");
	puts("===================================================================");
	puts("============================== Test Key ===========================");
	puts("===================================================================");
	puts("===================================================================\n");


	Part
		Part1,
		Part2("Football", 22, 1, 4, 22.50),
		Part3("Softball", 33, 1, 6, 10.10),
		Part5("GolfBall",44, 1, 5, 7.70),
		Part4("SoccerBall", 11, 1, 10, 15.15),
		Inventory[4];   

		printf ("Part1.Key() = %ld\n", Part1.Key());
		printf ("Part2.Key() = %ld\n", Part2.Key());
		printf ("Part3.Key() = %ld\n", Part3.Key());
		printf ("Part4.Key() = %ld\n", Part4.Key());
		printf ("Part5.Key() = %ld\n", Part5.Key());
		printf ("Inventory[1].Key() = %ld\n", Inventory[1].Key());
	}

	if (PART_DIAGNOSTIC_LEVEL <= 7)
	{
	puts("\n\n===================================================================");
	puts("===================================================================");
	puts("=========== Test Get If TestInterActivePart is True  ==============");
	puts("===================================================================");
	puts("===================================================================\n");
	
	Part
		Part1;   

	bool 
		TestInterActivePart = false;

		Part1.Display("Blank Part1");

		if (TestInterActivePart)
		{
			Part1.Display("Blank Part1");
			if (Part1.Get())
				Part1.Display("Newly Filled Part1");
			else
				puts ("Part Fill Was Aborted By Entering A Blank Description");
		}	
	}


	if (PART_DIAGNOSTIC_LEVEL <= 8)
	{
	puts("\n\n===================================================================");
	puts("===================================================================");
	puts("==================== Final Testing Of Array =======================");
	puts("===================================================================");
	puts("===================================================================\n");
	long int
		Counter;
	Part
		Inventory[30];

	Inventory[0].Set("SoftBall",      100, 1,  10,    5.50);
	Inventory[1].Set("FootBall",      101, 1, 100,   33.30);
	Inventory[2].Set("IBM",           102, 2,   1,  800.00);
	Inventory[3].Set("Oven",          103, 3,   1,  200.00);
	Inventory[4].Set("Microwave",     104, 3,  10,   75.50);
	Inventory[5].Set("Macintosh",     105, 2,   1, 2000.00);
	Inventory[6].Set("Dell",          106, 2,  500,1000.00);
	Inventory[7].Set("BasketBall",    107, 1,  10,   25.50);
	Inventory[8].Set("BaseBall",      108, 1,  10,    6.50);
	Inventory[9].Set("TennisBall",    109, 1,  10,    3.50);

	Inventory[10].Set("VolleyBall",   119, 1,  10,   25.50);
	Inventory[11].Set("Gateway",      118, 2,  10,  800.00);
	Inventory[12].Set("Micron",       117, 2,   1, 2500.00);
	Inventory[13].Set("HP",           116, 2,  10,  700.00);
	Inventory[14].Set("Mixer",        115, 3,  10,   25.50);
	Inventory[15].Set("NoBrand",      114, 2, 100,  350.00);
	Inventory[16].Set("HandBall",     113, 1,  10,    7.50);
	Inventory[17].Set("PingPongBall", 112, 1,  10,    2.50);
	Inventory[18].Set("TeatherBall",  111, 1,  10,   65.00);
	Inventory[19].Set("RoundBall",    110, 1,  10,    5.00);


		puts("\n\n\n      | 12345678901234567890123456789012345678901234567890 |");
		puts("      ------------------------------------------------------");
		for (Counter = 0; Counter <= 19; Counter ++)
		{
			printf("%5ld | ", Counter);
			fflush(stdout);
			cout << Inventory[Counter];
			cout.flush();
			puts(" |");
		}
		puts("      ------------------------------------------------------");





	}

	puts("\n\n*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*************************** End TestPart **************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************");
	puts("*******************************************************************\n\n");

}



# endif // PART_DIAGNOSTIC_LEVEL --------------------------------------------------
