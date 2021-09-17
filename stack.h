#ifndef STACK_h
#define STACK_h

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define STACK_POP_WITH_BYTES(TYPE)({                                 \
    const size_t sizeOfData = sizeof(TYPE);                          \
    TYPE value = 0;                                                  \
    for (size_t i = 0; i < sizeOfData; ++i)                          \
    {                                                                \
        *((uint64_t*)&value) <<= 8;                                  \
        *((uint64_t*)&value) |= ByteStack_pop_uint8(stack);          \
    }                                                                \
    value;})

#define STACK_PUSH_WITH_BYTES() {                     \
    uint8_t *buffer = (uint8_t*) &value;              \
    for(size_t i = 0; i < sizeof(value); ++i)         \
    {                                                 \
        ByteStack_push_uint8(stack, buffer[i]);       \
    } }

#define STACK_POINTER_TO(X, Y, T) *((T*) (X+Y))

typedef struct
{
    uint8_t* data;
    size_t size;
    size_t pointer;
} byteStack_t;

/**
 * @brief      Allocates and constructs a ByteStack Object using malloc
 * @param size How much bytes the stack can hold without allocating new space
 * @returns    Pointer holding the stacks address
 */
byteStack_t* ByteStack(size_t);

/**
 * @brief        Frees Memory that a stack has been allocated
 * @param stack  Pointer to the stack that should become freed
 * @returns      NULL
 */
byteStack_t* ByteStack_delete(byteStack_t *);

void ByteStack_grow(byteStack_t *);

/**
 * @brief        Executes the stack operation 'pop'
 * @param stack  Pointer to the stack that should perform operation
 * @returns      8-bit unsigned integer
 */
uint8_t ByteStack_pop_uint8(byteStack_t *);

/**
 * @brief        Executes the stack operation 'pop'
 * @param stack  Pointer to the stack that should perform operation
 * @returns      16-bit unsigned integer
 */
uint16_t ByteStack_pop_uint16(byteStack_t *);

/**
 * @brief        Executes the stack operation 'pop'
 * @param stack  Pointer to the stack that should perform operation
 * @returns      32-bit unsigned integer
 */
uint32_t ByteStack_pop_uint32(byteStack_t *);

/**
 * @brief        Executes the stack operation 'pop'
 * @param stack  Pointer to the stack that should perform operation
 * @returns      64-bit unsigned integer
 */
uint64_t ByteStack_pop_uint64(byteStack_t *);

/**
 * @brief        Executes the stack operation 'pop'
 * @param stack  Pointer to the stack that should perform operation
 * @returns      Void-Pointer
 */
void* ByteStack_pop_ptr(byteStack_t *);

/**
 * @brief        Executes the stack operation 'push' (back)
 * @param stack  Pointer to the stack that should perform operation
 * @param value  uint8 Data that will be pushed onto the stack
 */
void ByteStack_push_uint8(byteStack_t *, uint8_t);

/**
 * @brief        Executes the stack operation 'push' (back)
 * @param stack  Pointer to the stack that should perform operation
 * @param value  uint16 Data that will be pushed onto the stack
 */
void ByteStack_push_uint16(byteStack_t *, uint16_t);

/**
 * @brief        Executes the stack operation 'push' (back)
 * @param stack  Pointer to the stack that should perform operation
 * @param value  uint32 Data that will be pushed onto the stack
 */
void ByteStack_push_uint32(byteStack_t *, uint32_t);

/**
 * @brief        Executes the stack operation 'push' (back)
 * @param stack  Pointer to the stack that should perform operation
 * @param value  uint64 Data that will be pushed onto the stack
 */
void ByteStack_push_uint64(byteStack_t *, uint64_t);

/**
 * @brief        Executes the stack operation 'push' (back)
 * @param stack  Pointer to the stack that should perform operation
 * @param value  Void-Pointer that will be pushed onto the stack
 */
void ByteStack_push_ptr(byteStack_t *stack, void* ptr);

#endif