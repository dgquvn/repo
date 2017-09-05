# Programs
#
# 1. Program FizzBuzz/FizzBuzz_main.cpp
##     This is the first FizzBuzz problem print 1-100, where the multiples of 3 are print out as "Fizz", multiples of 5 are print out as "Buzz", and the multiples of 3 and 5 are print out as "FizzBuzz".
#
# 2. Program FizzBuzz_generic_v2
##     This is the second FizzBuzz problem print 1-max_int.  There are two types of input. The first one is for two divisors input, where it reads lower_divisor, upper_divisor, lower_divisor_label, and upper_divisor_label. First it check if it is the multiple of the product of lower_divisor and upper_divisor, then check if it is the multiple of upper_divisor, finally check if it is the multiple of lower_divisor. The input file format example is 

max_int = 100

lower_divisor = 2 

upper_divisor = 4 

lower_divisor_label = Fizz 

upper_divisor_label = Buzz 
#
The product of lower_divisor and upper_divisor is 8 and it will be checked first, and then upper_divisor (4) is checked, finally lower_divisor (2) is checked.

The corresponding output will be 1, Fizz, 3, Buzz, 5, Fizz, 7, FizzBuzz, ...
#

# Second one
## The second one accept any input parameters and output the labels if the number is divisible by the given divisor. The input format for max_Int is "max_int", "()", and the divisor input format is "_divisor", "value", "()", "label", "()", or "_divisor", "label", "()", "value", "()", where "()" denotes the corresponding value or label.  The input file format example is

max_int 100

_divisor value 2 label Fizz _divisor label Buzz

value 3 _divisor value 5 label Guzz#
#
The corresponding output will be 1, Fizz, Buzz, Fizz, Guzz, FizzBuzz, 7, Fizz, Buzz, FizzGuzz, 11, FizzBuzz, 13, Fizz, ... , 29, FizzBuzzGuzz, ...

