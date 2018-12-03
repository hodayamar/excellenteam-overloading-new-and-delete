#include "person.h"

//init static members s_pool

    //malloc
    //init internal ptrs

// init s_firstFree


//new(size_t size):

    //temp = *s_firstFree

    //check if *s_firstFree is null
        //*s_firstFree = **s_firstFree

    //return temp

//delete(ptr):

    //set ptr to *s_firstFree
    //set *s_firstFree to ptr

