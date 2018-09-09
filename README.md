# calculator
this is a code to calculate the addition,substract,multiply and divide of any two rational numbers to give a rational number

This console application is based on storing rational numbers in char arrays so that size limitation of float or any data type which is used to store rational numbers is escaped and also the limitation of accuracy ,in other words it gives answer with infinite accuracy 

add,sub,multiplication and division functions are now complete .
the present add ,sub, multiplication and division functions are only disignned to take only those rational numbers whose decimal part is not reapeting.for example "6.57(9086)" now in this number's decimal part there is a pair of brackets which means that ,the "9086" in the bracket keeps on reapeating to infinity.
that is  6.57908690869086908690869086 and so on.
such numbers are not yet designned in understandstrings() function.

note if division function is given an input numbers such that the answer is like given in the example given above then it will be caught in an infinite loop and also the answers for all these functions come in a weird manner like '0000000.00001232000000'. even that is left to be corrected.A simple '0.00001232' would be enough.

please if you want try to run this code.If you find any errors in excetution of application then report.

note:while using this calculator make sure that you use division carefully.If you want to use division ,use it only for testing.use normal calculator to check weather the answer is correct or not.if the answer does not appear or the application is still for long time not even ending ,then don't wait for too long because the program will keep on using more and more memory of your computer so close the application and check weather the resulting number is having an infinetly reapeting group of decimal digits by using your knowledge of math.

and also you can rely on it while using other three operations because in that case the answer will be infinetly accurate.
