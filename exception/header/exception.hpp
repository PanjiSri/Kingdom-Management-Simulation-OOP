#include <iostream>
#include <exception>
using namespace std;

class FilePathTidakValid : public exception
{
public:
    const char *what() const throw()
    {
        return "File Path Tidak Valid";
    }
};