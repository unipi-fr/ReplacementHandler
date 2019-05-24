#include <exception>
using namespace std;

class NWayException : public exception{
public:
    virtual const char* what() const throw()
    {
        return "nWayException: Invalid associative level (At the moment the maximum associative level must not be greater than 32).";
    }
};

class InvalidParametersException : public exception{
public:
    virtual const char* what() const throw()
    {
        return "InvalidParameters: Parameters of the function are not valid and they could cause errors.";
    }
};

class PolicyNotValidException : public exception{
public:
    virtual const char* what() const throw()
    {
        return "PolicyNotValidException: Policy chosen does not exists.";
    }
};