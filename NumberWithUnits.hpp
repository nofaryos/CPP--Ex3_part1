#pragma once
#include <string>
#include <map>
#include <fstream>
namespace ariel{
	class NumberWithUnits{

		private:
			
			double value;
			std::string name;
			static std::map<std::string, std::map<std::string, int>> units;
		 
		public:
			NumberWithUnits(double value, std:: string name){
				this -> value = value;
				this -> name = name;
			}
			
			double getVal() const{
				return this->value;
			}
			
			std::string getName() const{
				return this->name;
			}
			
			static void read_units(std::ifstream& f){}
			
			
			NumberWithUnits& operator+=(const NumberWithUnits& other);
			NumberWithUnits& operator-=(const NumberWithUnits& other);
			
			const NumberWithUnits operator+() const;
			const NumberWithUnits operator-() const;
			
			NumberWithUnits& operator++();
			NumberWithUnits& operator--();
			
			const NumberWithUnits operator++(int dummy_flag_for_postfix_increment);
			const NumberWithUnits operator--(int dummy_flag_for_postfix_increment);		
			
			friend bool operator==(const NumberWithUnits& c1, const NumberWithUnits& c2);
			friend bool operator!=(const NumberWithUnits& c1, const NumberWithUnits& c2);
			
			friend bool operator<(const NumberWithUnits& c1, const NumberWithUnits& c2);
			friend bool operator>(const NumberWithUnits& c1, const NumberWithUnits& c2);
			friend bool operator<=(const NumberWithUnits& c1, const NumberWithUnits& c2);
			friend bool operator>=(const NumberWithUnits& c1, const NumberWithUnits& c2);
			
			friend const NumberWithUnits operator-(const NumberWithUnits& c1, const NumberWithUnits& c2);
			friend const NumberWithUnits operator+(const NumberWithUnits& c1, const NumberWithUnits& c2);
			
			friend const NumberWithUnits operator*(const NumberWithUnits& c1, double d);
			friend const NumberWithUnits operator*(double d, const NumberWithUnits& c1);
			
			friend std::ostream& operator<< (std::ostream& os, const NumberWithUnits& c);
			friend std::istream& operator>> (std::istream& is, NumberWithUnits& c);
			
	};
}
		
		