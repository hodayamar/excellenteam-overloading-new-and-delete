#ifndef EXCELLENTEAM_ELLA_CPP_OVERLOADING_NEW_AND_DELETE_HODAYAMAR_PERSON_H
#define EXCELLENTEAM_ELLA_CPP_OVERLOADING_NEW_AND_DELETE_HODAYAMAR_PERSON_H


#include <stdlib.h>
#include <stdio.h>



class Person {

public:

    Person(unsigned int id, unsigned char age, const char * full_name);

    ~Person(){};

    void *operator new(size_t size);

    void operator delete(void *ptr);


private:

    static void* s_pool;
    static void* s_firstFree;
    static void* init_s_pool();

    char m_full_name[32];
    unsigned int m_id;
    unsigned char m_age;

    void* operator new[](size_t size);

    void operator delete[](void *ptr);
};

static const unsigned int BLOCK_SIZE = sizeof(Person);
static const unsigned int SIZE_OF_POOL_MEMORY = 100 * BLOCK_SIZE;


#endif //EXCELLENTEAM_ELLA_CPP_OVERLOADING_NEW_AND_DELETE_HODAYAMAR_PERSON_H
