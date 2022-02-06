/*
C++ provides a class hierarchy  of exception classes

*std::Exception is the base class
all subclasses implement the what() virtual function
we can create our own user-defined exception subclasses

///virtual const char* what() const noexcept;
*/

/*
The exception::what() used to get string identifying exception. This function returns a null terminated 
character sequence that may be used to identify the 
exception

virtual const char* what() const throw();
Return: The function std::what() return a null terminated character sequence that is used to identify the exception.

Note: To make use of std::what(), one should set up the appropriate try and catch blocks.




*/