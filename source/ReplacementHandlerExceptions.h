#include <exception>
using namespace std;

class nWayException : public exception{
public:
    virtual const char* what() const throw()
    {
        return "nWayException: Invalid associative level (greater than 16).";
    }
};