#include "stack.h"

byteStack_t* ByteStack(size_t size)
{
    byteStack_t* stack = (byteStack_t*) malloc(sizeof(byteStack_t));
    if(!stack)
    {
        fprintf(stderr, "%s - at: %d:%s\n", "Out of Memory!", __LINE__, __FILE__);
        exit(EXIT_FAILURE);
    }

    *stack = (byteStack_t)
    {
        .size = size,
        .pointer = 0
    };

    stack->data = (uint8_t*) malloc(sizeof(uint8_t) * stack->size);
    if(!stack->data)
    {
        fprintf(stderr, "%s - at: %d:%s\n", "Out of Memory!", __LINE__, __FILE__);
        exit(EXIT_FAILURE);
    }

    return stack;
}

byteStack_t* ByteStack_delete(byteStack_t *stack)
{
    free(stack->data);
    free(stack);
    return NULL;
}

void ByteStack_grow(byteStack_t *stack)
{
    stack->size *= 2;
    stack->data = (uint8_t*) realloc(stack->data, sizeof(uint8_t) * stack->size);
    if(!stack->data)
    {
        fprintf(stderr, "%s - at: %d:%s\n", "Out of Memory!", __LINE__, __FILE__);
        exit(EXIT_FAILURE);
    }
}

uint8_t ByteStack_pop_uint8(byteStack_t *stack)
{
    const size_t sizeOfData = sizeof(uint8_t);
    if(stack->pointer < sizeOfData)
    {
        fprintf(stderr, "%s - at: %d:%s\n", "Stack-Index out of Bounds", __LINE__, __FILE__);
        exit(EXIT_FAILURE);
    }
    stack->pointer -= sizeOfData;
    return stack->data[stack->pointer];
}

uint16_t ByteStack_pop_uint16(byteStack_t *stack)
{
    return STACK_POP_WITH_BYTES(uint16_t);
}

uint32_t ByteStack_pop_uint32(byteStack_t *stack)
{
    return STACK_POP_WITH_BYTES(uint32_t);
}

uint64_t ByteStack_pop_uint64(byteStack_t *stack)
{
    return STACK_POP_WITH_BYTES(uint64_t);
}

void* ByteStack_pop_ptr(byteStack_t *stack)
{
    return STACK_POP_WITH_BYTES(void*);
}

void ByteStack_push_uint8(byteStack_t *stack, uint8_t value)
{
    if(stack->pointer <= stack->size)
        ByteStack_grow(stack);
    stack->data[stack->pointer++] = value;
}

void ByteStack_push_uint16(byteStack_t *stack, uint16_t value)
{
    STACK_PUSH_WITH_BYTES();
}

void ByteStack_push_uint32(byteStack_t *stack, uint32_t value)
{
    STACK_PUSH_WITH_BYTES();
}

void ByteStack_push_uint64(byteStack_t *stack, uint64_t value)
{
    STACK_PUSH_WITH_BYTES();
}

void ByteStack_push_ptr(byteStack_t *stack, void* value)
{
    STACK_PUSH_WITH_BYTES();
}