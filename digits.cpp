//Digit game programm
#include <stdlib.h>
#include <iostream>
#include <stdlib.h>     
#include <stdio.h>     
using namespace std;


    class answer {
        int right_digits;
        int digits_on_right_place;
        public:
		answer (void) { };
		answer (int right, int inplace) {
			right_digits=right;
            digits_on_right_place = inplace;
		};
		int operator == (const  answer & x) {
		   int res=1;
		   if (right_digits != x.right_digits) res = 0;
	       if ( digits_on_right_place != x.digits_on_right_place) res=0;
		   return res;
		}
		
        void print (void) {
            cout  << " |" << right_digits << ':' << digits_on_right_place;
        };        
    };
	
class digits {
private:
    int digit1; //-32767 to 32767
    int digit2; 
    int digit3; 
    int digit4;
public:
    digits () {
    digit1=0; 
    digit2=0; 
    digit3=0; 
    digit4=0;  
        
    };
    digits (int d1, int d2, int d3, int d4) {
    digit1=d1; 
    digit2=d2; 
    digit3=d3; 
    digit4=d4;  
    };
	answer operator *(const digits &test) {
		int right=0;
		int inplace=0;
		
		if (test.digit1 == this->digit1)  { right++; inplace++;} 
		else 
		if (test.digit1 == this->digit2) right++; 
	    else 
		if (test.digit1 == this->digit3) right++;
		else 
		if (test.digit1 == this->digit4) right++;
	
	    if (test.digit2 == this->digit1) right++; 
		else 
		if (test.digit2 == this->digit2) { right++; inplace++;} 
	    else 
		if (test.digit2 == this->digit3) right++;
		else 
		if (test.digit2 == this->digit4) right++;
	
	    if (test.digit3 == this->digit1) right++; 
		else 
		if (test.digit3 == this->digit2) right++; 
	    else 
		if (test.digit3 == this->digit3) { right++; inplace++;} 
		else 
		if (test.digit3 == this->digit4) right++;

	    if (test.digit4 == this->digit1) right++; 
		else 
		if (test.digit4 == this->digit2) right++; 
	    else 
		if (test.digit4 == this->digit3) right++;
		else 
		if (test.digit4 == this->digit4) { right++; inplace++;} 
	    
		answer res(right, inplace);
		return res;	
	}
	
    void generate (void) {
        int ok;
          /* initialize random seed: */
        srand (time(NULL));
        
        //first
        digit1 = rand() % 10;
        //second
        do {
            digit2 = rand() % 10;
            ok = 1;
            if (digit2 == digit1) ok = 0;
            } while (ok == 0);
        //third
        do {
            digit3 = rand() % 10;
            ok = 1;
            if (digit3 == digit1) ok = 0;
            if (digit3 == digit2) ok = 0;
            } while (ok == 0);
        //fourth    
        do {
            digit4 = rand() % 10;
            ok = 1;
            if (digit4 == digit1) ok = 0;
            if (digit4 == digit2) ok = 0;
            if (digit4 == digit3) ok = 0;
            } while (ok == 0);
    }; //end of generation methode  
    
    void enter(void) {
        int digit1234;
        int remainder;
        cout  << "\n Could You enter digits: ";
        cin >>  digit1234;
        digit1 = digit1234 / 1000;
        remainder = digit1234 % 1000;
        digit2 = remainder / 100;
        remainder = remainder % 100;
        digit3 = remainder / 10;
        digit4 = remainder % 10;        
        };
        
    int is_digits_ok(int print_result) {
        int ok=1;
        if (digit1 == digit2) ok = 0;
        if (digit1 == digit3) ok = 0;
        if (digit1 == digit4) ok = 0;
        if (digit2 == digit3) ok = 0;
        if (digit2 == digit4) ok = 0;
        if (digit3 == digit4) ok = 0;
        if (print_result == 1) cout << " Digits is " << (ok==1 ? "OK" : "WRONG");
        return ok;    
        };    
        
    void print(void) {
        cout  << digit1  << digit2 << digit3 << digit4 ;
        };
    
    };// end of class declaration
    
    
	class attempt {
		digits dig;
		answer ans;
		attempt(digits &d, answer &a) {
			dig = d;
			ans = a;
		};		
	};
	
	class digits_game {
		const int max_attempts=50;
		attempt att[50];
		int att_index;		
	};

    
    int main () {
	//Computer riddles digits	
    digits game1;
    game1.generate();
    //game1.print();
    game1.is_digits_ok(0);
 
   cout << "\n Lets guess my digits!!!";
  
   int attempt = 0;
   int leave=0;
  do {
    digits game2;
    int test;
	do {
       game2.enter();	   
	   test = game2.is_digits_ok(0);
	   if (test==0) {
	   cout << "WRONG digit: ";
	   game2.print(); 
	   cout << " Please enter correct digits!";
	   }	   
	} while (test==0);
    //cout << "\n ";
	game2.print();
    
	answer answer1 = game1 * game2;
 	answer1.print();
	if (answer1 == answer(4,4))  { 
	    cout << "\n YOU GUESS AND WIN!!!";	    
	    leave++;
	}	
	attempt++;
	if (attempt>10) { 
	    cout << "\n Too many attemps - you loose!";
	    leave++;
	}	
  } while (leave==0);
  
  cout << "\n Bye-Bye\n";
        
  } //main
