#include"ExceptiaMea.h"
using namespace std;

myException::myException(const char* error): logic_error(error) {}
