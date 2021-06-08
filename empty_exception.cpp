#include "Stack.h"

void empty_exception::empty_exception(void){
    throw exception();
}

void empty_exception::empty_exception(const char* msg){
    throw exception(msg);
}