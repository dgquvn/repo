// This is for FizzBuzz program
// Print numbers from 1-100
// where the multiple of 3 print "Fizz"
// the multiple of 5 print "Buzz"
// and the multiple of 3 and 5 print "FizzBuzz"

#include <iostream>
using namespace std;

int main(){
	for (int i = 1; i <= 100; i++){
		if (i % 15 == 0)
			cout << "FizzBuzz" << endl;
		else if (i % 3 == 0)
			cout << "Fizz" << endl;
		else if (i % 5 == 0)
			cout << "Buzz" << endl;
	}
	return 0;
}
