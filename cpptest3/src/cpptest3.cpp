//============================================================================
// Name        : cpptest3.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : conversion constructor in C++
//============================================================================

#include<iostream>
using namespace std;
class my_class{
   private:
      int my_var;
   public:
      my_class(int x) {		//using parameterized constructor
         this->my_var = x; 	//set the value of my_var
      }
      void display() {
         cout << "The value of my_var is: " << my_var <<endl;
      }
};
int main() {
   my_class my_obj(10);	// equivalent to my_class my_obj = 10 or my_class my_obj = my_class(10)
   my_obj.display();
   my_obj = 50; //here the conversion constructor is called
   my_obj.display();
}
