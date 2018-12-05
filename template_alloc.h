#ifndef EXCELLENTEAM_ELLA_CPP_OVERLOADING_NEW_AND_DELETE_HODAYAMAR_TEMPLATE_ALLOC_H
#define EXCELLENTEAM_ELLA_CPP_OVERLOADING_NEW_AND_DELETE_HODAYAMAR_TEMPLATE_ALLOC_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>//cout

template <typename T, unsigned int size_of_pool>
class template_allocator : public T
{

public:

    void *operator new(size_t size);
    void operator delete(void *ptr);

private:

    static void* s_pool;
    static void* s_firstFree;
    static void* init_memory_pool();

};

template<typename T, unsigned int size_of_pool>
void* template_allocator<T, size_of_pool>::s_pool = NULL;

template<typename T, unsigned int size_of_pool>
void * template_allocator<T, size_of_pool>::init_memory_pool() {

    template_allocator<T, size_of_pool>::s_pool = new char[size_of_pool * sizeof(T)];

    T * iterator = (T *)s_pool;

    for (unsigned int i = 0; i < size_of_pool; ++i,++iterator) {

        *((T**)iterator) = (iterator + 1);
    }

    *(void**)iterator = NULL;

    return s_pool;
}

template<typename T, unsigned int size_of_pool>
void * template_allocator<T, size_of_pool>::s_firstFree = init_memory_pool();


template<typename T, unsigned int size_of_pool>
void * template_allocator<T, size_of_pool>::operator new(size_t size)
{
    void * temp = template_allocator<T, size_of_pool>::s_firstFree;

    if(template_allocator<T, size_of_pool>::s_firstFree)
    {
        template_allocator<T, size_of_pool>::s_firstFree = *((void**)template_allocator<T, size_of_pool>::s_firstFree);
        return  temp;
    }
    else
        throw  std::bad_alloc();

}

template<typename T, unsigned int size_of_pool>
void template_allocator<T, size_of_pool>::operator delete(void * ptr)
{
//    TEST_PRINT("operator new", Person::s_firstFree);
    *((void**)ptr) = s_firstFree;
   s_firstFree = ptr;
}

#endif //EXCELLENTEAM_ELLA_CPP_OVERLOADING_NEW_AND_DELETE_HODAYAMAR_TEMPLATE_ALLOC_H
