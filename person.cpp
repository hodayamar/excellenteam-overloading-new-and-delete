#include "person.h"

#define BLOCK_SIZE sizeof(Person)
#define SIZE_OF_POOL_MEMORY 100 * BLOCK_SIZE

//init static members s_pool
void *Person::init_s_pool()
{
    void ** pool_ptr = (void **)malloc(SIZE_OF_POOL_MEMORY);

    //init internal ptrs
    void* temp = pool_ptr;

    for(unsigned  int i = 0; i < SIZE_OF_POOL_MEMORY/BLOCK_SIZE; i += BLOCK_SIZE)
    {
        pool_ptr[i] = (char*)temp + BLOCK_SIZE;
        temp = (char*)temp + BLOCK_SIZE;
    }

    return *pool_ptr;
}



// init s_pool
void* Person::s_pool = Person::init_s_pool();

// init s_firstFree
void* Person::s_firstFree = s_pool;


void * operator new(size_t size)
{
    void * temp;

    temp = Person::s_firstFree;

    if(Person::s_firstFree)
    {
        Person::s_firstFree = (Person*)*(size_t*)Person::s_firstFree;
    }

    return  temp;
}


void operator delete(void * ptr)
{
    void * temp = ptr;
    ptr = Person::s_firstFree;
    Person::s_firstFree = temp;

}


