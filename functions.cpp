/*functions-logical set of code performing a specific taskinput passed to a function are called parameters Types of functions :1.user defined2.standard library functions function should always be defined above the main() functionFUNCTION PROTOTYPE-if we wanna define function after function call we need to use function prototypeEg-int add(int,int)Standard library in <cmath> library functions present are 1.pow(a,b)=a^b   2.sqrt(a)*//*scope of variables-part of the program from where variable is accessible local variables-declared inside the function or blockglobal variables-exist throughout the wholle program and can be used in any part of the programlocal variable takes precedence over global i.e. local>>globalto access global variable in function where a same name local variable is present we use sope resolution operator(::)Eg-cout<<::p;pass by value-when we call a function and parameter values are copied to another variable then it is called pass by valuepass by reference-when we call a function and parameter values are passed then it is pass by reference.in this variable itself is passed using (& ampersand) operator.*/