#ifndef BORROW_HANDLER_h
#define BORROW_HANDLER_h

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct borrowHandler_t
{
    void* owner;
    uint64_t value;
} borrowHandler_t;

borrowHandler_t* BorrowHandler(void* owner, uint64_t value)
{
    borrowHandler_t *handler = (borrowHandler_t*) malloc(sizeof(borrowHandler_t));
    if(!handler)
    {
        fprintf(stderr, "%s\n", "Out of Memory");
        exit(EXIT_FAILURE);
    }

    handler->owner = owner;
    handler->value = value;

    return handler;
}

#define RETURN_BORROW(X, T) ({*owner = value})

#endif