#include  "NumberWithUnits.hpp"



namespace ariel{
		
		
		NumberWithUnits& NumberWithUnits::operator+=(const NumberWithUnits& other){return *this;}//^
		NumberWithUnits& NumberWithUnits::operator-=(const NumberWithUnits& other){return *this;}//^
		
		const NumberWithUnits NumberWithUnits::operator+() const{return *this;};//^
		const NumberWithUnits NumberWithUnits::operator-() const{return *this;}//^
		
		NumberWithUnits& NumberWithUnits::operator++(){return *this;}//^
		NumberWithUnits& NumberWithUnits::operator--(){return *this;};//^
		
		const NumberWithUnits NumberWithUnits::operator++(int dummy_flag_for_postfix_increment){
			return *this;
		}//^
		const NumberWithUnits NumberWithUnits::operator--(int dummy_flag_for_postfix_increment){
			return *this;
		}//^
		
		bool operator==(const NumberWithUnits& c1, const NumberWithUnits& c2){return false;}//^
		bool operator!=(const NumberWithUnits& c1, const NumberWithUnits& c2){return false;}//^
		
		bool operator<(const NumberWithUnits& c1, const NumberWithUnits& c2){return false;}
		bool operator>(const NumberWithUnits& c1, const NumberWithUnits& c2){return false;}
		bool operator<=(const NumberWithUnits& c1, const NumberWithUnits& c2){return false;}
		bool operator>=(const NumberWithUnits& c1, const NumberWithUnits& c2){return false;}
		
		const NumberWithUnits operator-(const NumberWithUnits& c1, const NumberWithUnits& c2){
			return NumberWithUnits(c1.value+c2.value, "l");//^
			}
		const NumberWithUnits operator+(const NumberWithUnits& c1, const NumberWithUnits& c2){
			return NumberWithUnits(c1.value+c2.value, "l");//^
		}
		
		const NumberWithUnits operator*(const NumberWithUnits& c1, double d){
			int i = c1.value *d ;
			return NumberWithUnits(i, "l");
			
		};
		const NumberWithUnits operator*(double d, const NumberWithUnits& c1){
			int i = c1.value *d ;
			return NumberWithUnits(i, "l");
			
		};
		
		std::ostream& operator<< (std::ostream& os, const NumberWithUnits& c){
			return os;
		}
		std::istream& operator>> (std::istream& is, NumberWithUnits& c){
			return is;
		}
};