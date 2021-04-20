#include <iostream>
#include <sstream>
#include <stdexcept>
#include "doctest.h"
using namespace std;

#include "NumberWithUnits.hpp"
using namespace ariel;


TEST_CASE("TEST FOR OPERATORS: operator+=, operator-="){
		ifstream units_file{"units.txt"};
		NumberWithUnits::read_units(units_file);
		
		NumberWithUnits a{2, "cm"}; 
		NumberWithUnits b{2, "cm"};
		NumberWithUnits c{3, "cm"};
		NumberWithUnits d{3, "cm"};
		NumberWithUnits e{4, "cm"};
		NumberWithUnits f{6, "cm"};
		NumberWithUnits y{6, "ton"};
		
		//operator+=
		a+= b; // a = 4
		c+= d; // c = 6 
		CHECK(a == e);
		CHECK(c == f); 
		
		CHECK(a != b);
		CHECK(c != d);
		CHECK_THROWS( a+= y); //illegal
		
		//operator-=
		a -= b; // a =2
		c -= d;// c = 3
					
		CHECK(a == b);
		CHECK(c == d);
		
		CHECK(a != e);
		CHECK(c != f);
		CHECK_THROWS( a-= y); //ilegal
}

TEST_CASE("TEST FOR OPERATORS:operator+(), operator-()"){
		
		ifstream units_file{"units.txt"};
		NumberWithUnits::read_units(units_file);
		
		NumberWithUnits a{2, "cm"}; 
		NumberWithUnits b{3, "cm"};
		
		//operator+()
		NumberWithUnits z = +a; // z = 2
		NumberWithUnits y = +b; // y = 3
		
		CHECK(z == a);
		CHECK(y == b);
		
		//operator-()
		z = -a; // z = -2
		y = -b; // y = -3
		
		CHECK(z.getVal() == -2);
		CHECK(y.getVal() == -3);
		CHECK(z != a);
		CHECK(y != b);		
}

TEST_CASE("TEST FOR FUNCTIONS: operator++(), operator--() (prefix)"){
		ifstream units_file{"units.txt"};
		NumberWithUnits::read_units(units_file);
		
		NumberWithUnits a{2, "ton"}; 
		NumberWithUnits b{3, "ton"};
		NumberWithUnits c{2, "ton"};
		
		//operator++()
		NumberWithUnits z = ++a; //z = 3, a = 3
		
		CHECK(z.getVal() == 3);
		CHECK(a.getVal() == 3);
		CHECK(z == a);
		CHECK(z == b);
		CHECK(a == b);
		CHECK(a != c);
		
		//operator--()
		z = --b;// z = 2, b =2
		CHECK(z.getVal() == 2);
		CHECK(b.getVal() == 2);
		CHECK(z == b);
		CHECK(z == c);
		CHECK(a != b);		
}


TEST_CASE("TEST FOR FUNCTIONS: operator++(...), operator--(...) (postfix)"){
		ifstream units_file{"units.txt"};
		NumberWithUnits::read_units(units_file);
		
		NumberWithUnits a{2, "ton"}; 
		NumberWithUnits b{3, "ton"};
		NumberWithUnits c{2, "ton"};
		NumberWithUnits d{4, "ton"};
		
		//operator++(...)
		NumberWithUnits z = a++;// z = 2, a = 3
		CHECK(a != z);
		CHECK(z == c);
		CHECK(a == b);
		CHECK(a != c);
		
		z = b++; // z = 3, b = 4
		CHECK(z == a);
		CHECK(b == d);
		
		//operator--(...)
		z = b--; // z = 4, b = 3
		CHECK(z == d);
		CHECK(b.getVal() == 3);
		z = a--; //z = 3, a = 2
		CHECK(z == b);
		CHECK(a == c);		
}	

TEST_CASE("TEST FOR FUNCTIONS: operator== , operator!= "){
		ifstream units_file{"units.txt"};
		NumberWithUnits::read_units(units_file);
		bool ans;
		
		NumberWithUnits a{2, "kg"}; 
		NumberWithUnits b{3, "kg"};
		NumberWithUnits c{2, "kg"};
		NumberWithUnits d{5, "kg"};
		NumberWithUnits e{4, "kg"};
		NumberWithUnits f{4, "cm"};
		
		NumberWithUnits z = a + b; //z = 5
		
		//operator==
		CHECK(a == c);
		CHECK(z == d);
		CHECK_THROWS(ans = (e == f)); //illegal
		
		//operator!=
		CHECK(a != b);
		CHECK(b != d);
		CHECK_THROWS(ans = (b != f)); //illegal			
}

TEST_CASE("TEST FOR FUNCTIONS: operator<, operator>, operator<=, operator>="){
		ifstream units_file{"units.txt"};
		NumberWithUnits::read_units(units_file);
		
		NumberWithUnits a{2, "ton"}; 
		NumberWithUnits b{3, "ton"};
		NumberWithUnits c{2, "ton"};
		NumberWithUnits d{5, "ton"};
		NumberWithUnits e{4, "ton"};
		NumberWithUnits f{4, "cm"};
		NumberWithUnits z = a + b; //z = 5
		NumberWithUnits y = a + c; //y = 4
		bool ans;
		
		//operator<
		CHECK(a < b);
		CHECK(c < d);
		CHECK_THROWS(ans = (a < f)); //illegal
		
		//operator>
		CHECK(b > a);
		CHECK(d > e);
		CHECK_THROWS(ans = (d > f)); //illegal
		
		//operator<=
		CHECK(a <= c);
		CHECK(a <= e);
		CHECK_THROWS(ans = (a <= f)); //illegal
		
		//perator>=
		CHECK(a >= c);
		CHECK(d >= b);
		CHECK_THROWS(ans = (a >= f));
		
}

	
TEST_CASE("TEST FOR FUNCTIONS: operator-, operator+"){
		ifstream units_file{"units.txt"};
		NumberWithUnits::read_units(units_file);
		
		NumberWithUnits a{4, "km"}; 
		NumberWithUnits b{2, "km"};
		NumberWithUnits c{2, "km"};
		NumberWithUnits d{6, "km"};
		NumberWithUnits y{6, "ton"};
		
		//operator+
		CHECK(b == c);
		
		NumberWithUnits e = a + b; //e = 6
		NumberWithUnits f = b + c;//f = 4 
		CHECK(e == d);
		CHECK(f == a); 
		CHECK(a != b);
		CHECK(a != d);
		CHECK_THROWS(y + a); //illegal
		
		//operator-
		e = d - c; //e = 4 
		f = a - b ; // f = 2
		CHECK(e == a);
		CHECK(f == b); 
		
		CHECK(e != d);
		CHECK(f != a);
		
		CHECK(e.getVal() == 4);
		CHECK(f.getVal() == 2);		
		CHECK_THROWS(y - a); //illegal
}


TEST_CASE("TEST FOR FUNCTION: operator* "){
		ifstream units_file{"units.txt"};
		NumberWithUnits::read_units(units_file);
		
		NumberWithUnits a{2, "ton"}; 
		NumberWithUnits b{3, "ton"};
		NumberWithUnits e{4, "ton"};
		NumberWithUnits f{6, "ton"};
		NumberWithUnits z = a*2; //z = 4
		NumberWithUnits y = b*2; //y = 6
		
		CHECK(z == e);
		CHECK(y == f);
		
		z = 0.5*a; // z = 2
		y = 0.5*b; // b = 3
		
		CHECK(z == a);
		CHECK(y == b);
}

TEST_CASE("TEST FOR FUNCTION: operator>>"){
	 ifstream units_file{"units.txt"};
	 NumberWithUnits::read_units(units_file);
	 
	 istringstream sample_input1{"7 [m]"};
	 istringstream sample_input2{"7 [ m ]"};// with spaces
     NumberWithUnits a{6, "m"};
	 NumberWithUnits b{7, "m"};
	 CHECK(a != b);
	 sample_input1 >> a;
	 CHECK(a == b);
	 sample_input2 >> a;
	 CHECK( a == b);	 
}	


TEST_CASE("TEST FOR FUNCTION: operator<<"){
	ifstream units_file{"units.txt"};
	NumberWithUnits::read_units(units_file);
	 
    NumberWithUnits a(7, "m");
    NumberWithUnits b(6, "km");
    NumberWithUnits c(5, "kg");

    ostringstream str1, str2, str3;
    str1 << a;    
    str2 << b;    
    str3 << c;   

    CHECK(str1.str() == "7[m]");
    CHECK(str2.str() == "6[km]");
    CHECK(str3.str() == "5[kg]");	
}

TEST_CASE("TEST: Conversions"){
	ifstream units_file{"units.txt"};
	NumberWithUnits::read_units(units_file);
	
	NumberWithUnits a(1, "hour");
	NumberWithUnits b(60, "min");
    NumberWithUnits c(1800, "sec");
	NumberWithUnits d(2, "hour");
	NumberWithUnits e(1.5, "hour");
	NumberWithUnits f(90, "min");
	NumberWithUnits g(5400, "sec");
	
	NumberWithUnits z = a + b;// z = 2 hours
	CHECK(a == d);
	
	z = a + c; // z = 1.5 hours
	CHECK(a == e);
	
	z = b + c; // z = 90 minutes
	CHECK(z == f);
	
	z = c + b;// z = 5400 seconds
	CHECK(z == g);	
}
	
	
		






		
		
	
