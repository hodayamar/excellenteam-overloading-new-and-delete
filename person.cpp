#include "person.h"

#define BLOCK_SIZE sizeof(Person)
#define SIZE_OF_POOL_MEMORY 100 * BLOCK_SIZE

//init static members s_pool
void *Person::i_pool()
{
    void ** pool_ptr = (void **)malloc(SIZE_OF_POOL_MEMORY);

    //init internal ptrs
    void* temp = pool_ptr;
    nit_s
    for(unsigned  int i = 0; i < SIZE_OF_POOL_MEMORY; ++i)
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


//new(size_t size):

    //temp = *s_firstFree

    //check if *s_firstFree is null
        //*s_firstFree = **s_firstFree

    //return temp

//delete(ptr):

    //set ptr to *s_firstFree
    //set *s_firstFree to ptr

