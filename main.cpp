#include "person.h"
#include "template_alloc.h"

int main(){

    typedef template_allocator<Person, 2> APerson;
    APerson * P = new APerson;
    std::cout << P << std::endl;
    return 0;
}