# calculator
this is a code to calculate the addition,substract,multiply and divide of any two rational numbers to give a rational number

This console application is based on storing rational numbers in char arrays so that size limitation of float or any data type which is used to store rational numbers is escaped and also the limitation of accuracy ,in other words it gives answer with infinite accuracy 

add,sub,multiplication and division functions are now complete .
the present add ,sub, multiplication and division functions are only disignned to take only those rational numbers whose decimal part is not reapeting.for example "6.57(9086)" now in this number's decimal part there is a pair of brackets which means that ,the "9086" in the bracket keeps on reapeating to infinity.
that is  6.57908690869086908690869086 and so on.
such numbers are not yet designned in understandstrings() function.

note if division function is given an input numbers such that the answer is like given in the example given above then it will be caught in an infinite loop and also the answers for all these functions come in a weird manner like '0000000.00001232000000'. even that is left to be corrected.A simple '0.00001232' would be enough.

please if you want to try to run this code then run it and check if you find any errors in excetution of application .If there are any errors then please report.

still the problem of this code is the division may never work or if any number gets very complex the answer may take infinite time to appear by increasing retardation ,also I do not know because i have not taken time complexcity into consideration at all while writing the code for this.And also i had no idea that this can take place.so to say the actual truth i do not know the code is correct or wrong at all,because i forgot about time complexcity completely.it might also be like exponential graph in which if you keep moving towards -ve infinity with constant velocity the functional value will never become zero at all even after the end of world. 
note:don't put the second number entry equal to zero while using division.


