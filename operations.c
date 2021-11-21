
#include "operations.h"

// Stack Pipe Language:
// <name> () =>    Function Declaration
// [..]         Reference to a Stack 
// (..)[..]     Access to a Position in a Stack
// <-           Pop Value
// ->           Push Top Value
// =            Assignment

// Operations:

/**
 * @brief Does nothing, just a placeholder...
 */
static void OPERATION_NOP(virtualMachine_t *vm)
{
    
}

/**
 * @brief Does nothing, jumps over some bytes
 */
static void OPERATION_HINT(virtualMachine_t *vm)
{
    uint16_t size = ByteStack_pop_uint16(vm->opstack);
    for (uint16_t i = 0; i < size; ++i)
    {
        ByteStack_pop_uint8(vm->opstack);
    }
}

/**
 * @brief (bytePos : num64) => [opstack] <- num64 <- [programstack] <- num8 = (bytePos)[callstack]
 */
static void OPERATION_LOAD_CONST_NUM8(virtualMachine_t *vm)
{
    uint64_t index = ByteStack_pop_uint64(vm->opstack);
    ByteStack_push_uint8(vm->callstack, STACK_POINTER_TO(vm->ownershipstack->data, index, uint8_t));
}

/**
 * @brief (bytePos : num64) => [opstack] <- num64 <- [programstack] <- num16 = (bytePos)[callstack]
 */
static void OPERATION_LOAD_CONST_NUM16(virtualMachine_t *vm)
{
    uint64_t index = ByteStack_pop_uint64(vm->opstack);
    ByteStack_push_uint16(vm->callstack, STACK_POINTER_TO(vm->ownershipstack->data, index, uint16_t));
}

/**
 * @brief (bytePos : num64) => [opstack] <- num64 <- [programstack] <- num32 = (bytePos)[callstack]
 */
static void OPERATION_LOAD_CONST_NUM32(virtualMachine_t *vm)
{
    uint64_t index = ByteStack_pop_uint64(vm->opstack);
    ByteStack_push_uint32(vm->callstack, STACK_POINTER_TO(vm->ownershipstack->data, index, uint32_t));
}

/**
 * @brief (bytePos : num64) => [opstack] <- num64 <- [programstack] <- num64 = (bytePos)[callstack]
 */
static void OPERATION_LOAD_CONST_NUM64(virtualMachine_t *vm)
{
    uint64_t index = ByteStack_pop_uint64(vm->opstack);
    ByteStack_push_uint64(vm->callstack, STACK_POINTER_TO(vm->ownershipstack->data, index, uint64_t));
}

/**
 * @brief (bytePos : num64) => [opstack] <- num64 <- [programstack] <- byteStack* = (bytePos)[callstack]
 */
static void OPERATION_LOAD_CONST_STACK(virtualMachine_t *vm)
{
    uint64_t index = ByteStack_pop_uint64(vm->opstack);
    ByteStack_push_ptr(vm->callstack, STACK_POINTER_TO(vm->ownershipstack->data, index, byteStack_t*));
}

/**
 * @brief (bytePos : num64) => [opstack] <- num64 <- [programstack] <- num8 = (bytePos)[callstack]
 */
static void OPERATION_LOAD_FAST_NUM8(virtualMachine_t *vm)
{
    uint64_t index = ByteStack_pop_uint64(vm->opstack);
    ByteStack_push_uint8(vm->callstack, STACK_POINTER_TO(vm->programstack, index, uint8_t));
}

/**
 * @brief (bytePos : num64) => [opstack] <- num64 <- [programstack] <- num16 = (bytePos)[callstack]
 */
static void OPERATION_LOAD_FAST_NUM16(virtualMachine_t *vm)
{
    uint64_t index = ByteStack_pop_uint64(vm->opstack);
    ByteStack_push_uint16(vm->callstack, STACK_POINTER_TO(vm->programstack, index, uint16_t));
}

/**
 * @brief (bytePos : num64) => [opstack] <- num64 <- [programstack] <- num32 = (bytePos)[callstack]
 */
static void OPERATION_LOAD_FAST_NUM32(virtualMachine_t *vm)
{
    uint64_t index = ByteStack_pop_uint64(vm->opstack);
    ByteStack_push_uint32(vm->callstack, STACK_POINTER_TO(vm->programstack, index, uint32_t));
}

/**
 * @brief (bytePos : num64) => [opstack] <- num64 <- [programstack] <- num64 = (bytePos)[callstack]
 */
static void OPERATION_LOAD_FAST_NUM64(virtualMachine_t *vm)
{
    uint64_t index = ByteStack_pop_uint64(vm->opstack);
    ByteStack_push_uint64(vm->callstack, STACK_POINTER_TO(vm->programstack, index, uint64_t));
}

/**
 * @brief (bytePos : num64) => [opstack] <- num64 <- [programstack] <- byteStack* = (bytePos)[callstack]
 */
static void OPERATION_LOAD_FAST_STACK(virtualMachine_t *vm)
{
    uint64_t index = ByteStack_pop_uint64(vm->opstack);
    ByteStack_push_ptr(vm->callstack, STACK_POINTER_TO(vm->programstack, index, byteStack_t*));
}

static OperationPTR operations[INSTRUCTION_RANGE] =
{
    [OP_NOP] = OPERATION_NOP,
    [OP_HINT] = OPERATION_HINT,
    [OP_LOAD_CONST_NUM8] = OPERATION_LOAD_CONST_NUM8,
    [OP_LOAD_CONST_NUM16] = OPERATION_LOAD_CONST_NUM16,
    [OP_LOAD_CONST_NUM32] = OPERATION_LOAD_CONST_NUM32,
    [OP_LOAD_CONST_NUM64] = OPERATION_LOAD_CONST_NUM64,
    [OP_LOAD_CONST_STACK] = OPERATION_LOAD_CONST_STACK,
    [OP_LOAD_FAST_NUM8] = OPERATION_LOAD_FAST_NUM8,
    [OP_LOAD_FAST_NUM16] = OPERATION_LOAD_FAST_NUM16,
    [OP_LOAD_FAST_NUM32] = OPERATION_LOAD_FAST_NUM32,
    [OP_LOAD_FAST_NUM64] = OPERATION_LOAD_FAST_NUM64,
    [OP_LOAD_FAST_STACK] = OPERATION_LOAD_FAST_STACK,

    
};

OperationPTR* Operations_getSTDOperationImplementation()
{
    return operations;
}