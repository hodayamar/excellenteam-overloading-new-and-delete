#include "person.h"
#include "template_alloc.h"
#include <cstring>//strcpy
#include <iostream>

//#ifdef TESTING
//#define TEST_PRINT(str, p) std::cout << str " " << getindex(p) << std::endl;
//#else
//#define TEST_PRINT(str, p)
//#endif

//init static members s_pool
void *Person::init_s_pool()
{

//    void *placeHolder = malloc(SIZE_OF_POOL_MEMORY);
    s_pool = new char[SIZE_OF_POOL_MEMORY];

    Person *iterator = (Person*)s_pool;

    for (unsigned int i = 0; i < SIZE_OF_POOL_MEMORY; ++i,++iterator) {

        *((Person**)iterator) = (iterator + 1);
    }

    *(void**)iterator = NULL;

    return s_pool;
}


void * Person::s_pool;

void * Person::s_firstFree = Person::s_pool;

void * Person::operator new(size_t size)
{
    void * temp = Person::s_firstFree;

    if(Person::s_firstFree)
    {
        Person::s_firstFree = *((void**)Person::s_firstFree);
        return  temp;
    }
    else
        throw  std::bad_alloc();


}


void Person::operator delete(void * ptr)
{
//    TEST_PRINT("operator new", Person::s_firstFree);
    *((void**)ptr) = Person::s_firstFree;
    Person::s_firstFree = ptr;
}


Person::Person()
{
    std::cout << "im in ctor" << std::endl;
}

//#ifdef  TESTING
////TEESTING FUNC. need to add on header file.
// -DTESTING
//#else

