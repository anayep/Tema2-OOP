#ifndef EXCEPTIAMEA_H_INCLUDED
#define EXCEPTIAMEA_H_INCLUDED
#include<stdexcept>
using namespace std;

class myException : public logic_error {
public:
    myException(const char* error);
};

#endif // EXCEPTIAMEA_H_INCLUDED
