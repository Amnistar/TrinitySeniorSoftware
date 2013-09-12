//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//                                 Part.hpp                                     //
//                                                                              //
//  Purpose    : House includes, defines, class definitions, function           //
//               prototypes, and all template methods.                          //
//                                                                              //
//  Written By : Thomas E. Hicks         Environment : Windows 2003 Server      //
//  Date ......: xx/xx/xxxx              Compiler ...: Visual Studio Net 2005   // 
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////

# ifndef PART_CLASS //============================================================

// ----------------------------------- Includes ----------------------------------
# include "Utilities.hpp"

// ----------------------------------- Defines -----------------------------------
//////////////////////////////////////////////////////////////////////////////////
//  If PART_DIAGNOSTIC_LEVEL is commented out, then the Display methods         //
//  and the TestDLHeader cease to exist; as a result, the testing               //
//  functionality may be reactivated by removing the comment. I have chosen to  //
//  use increasing values for the PART_DIAGNOSTIC_LEVEL to represent the        //
//  complexity of what I am testing --> starting with 1. I Generally set the    //
//  PART_DIAGNOSTIC_LEVEL to 99 when I am finished testing, but wish to         //
//  maintain the Display functionality.                                         //
//////////////////////////////////////////////////////////////////////////////////
# define PART_DIAGNOSTIC_LEVEL 99
# define PART_CLASS

//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//                                     Class Part                               //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
class Part
{
public:
	Part (char NewName[] = "", long int NewNo = 0, long int NewDeptNo = 1, 
		  long int NewQuantity = 0, double NewCost = 0.0);
	~Part (void);
	void Set (char NewName[] = "", long int NewNo = 0, long int NewDeptNo = 1, 
		      long int NewQuantity = 0, double NewCost = 0.0);
	bool Get(void);
	long int Key(void);
	long int No_(void);
	double Cost_(void);
	long int Quantity_(void);
	long int DeptNo_(void);
# ifdef PART_DIAGNOSTIC_LEVEL //---------------------------------------------------
	void Display(char Message[] = "");
	void Display50(void);
# endif // PART_DIAGNOSTIC_LEVEL --------------------------------------------------

	friend ostream & operator << (ostream & OutputStream, Part P);

// I have decided that Name is to be the Primary Character Key for this record type.   
	bool operator == (const char Key[]);
	bool operator >  (const char Key[]);
	bool operator >= (const char Key[]);
	bool operator <  (const char Key[]);
	bool operator <= (const char Key[]);
	bool operator != (const char Key[]);
	void operator =  (const char Key[]);

// I have decided that No is to be the Primary Integer Key for this record type.   
	bool operator == (const long int Key);
	bool operator >  (const long int Key);
	bool operator >= (const long int Key);
	bool operator <  (const long int Key);
	bool operator <= (const long int Key);
	bool operator != (const long int Key);
	void operator =  (const long int Key);

// I have decided that Name is to be the Primary Key for this record type.   
	bool operator == (const Part & P);
	bool operator >  (const Part & P);
	bool operator >= (const Part & P);
	bool operator <  (const Part & P);
	bool operator <= (const Part & P);
	bool operator != (const Part & P);
	void operator =  (const Part & P);

private:
	char 
		Name [26];
	long int
		No, 
		Quantity,
		DeptNo;
	double
		Cost;
	};

// ------------------------- Non-Class Functions Prototypes-----------------------

# ifdef PART_DIAGNOSTIC_LEVEL //---------------------------------------------------
	void TestPart(void);
# endif // PART_DIAGNOSTIC_LEVEL --------------------------------------------------


# endif // PART_CLASS ============================================================