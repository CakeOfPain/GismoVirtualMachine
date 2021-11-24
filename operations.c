
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




static const OperationPTR operations[INSTRUCTION_RANGE] =
{
    [OP_NOP]             = OPERATION_NOP,
    [OP_HINT]            = OPERATION_HINT,
    
    // Load & Store
    [OP_LOAD_ABS_N8]     = OPERATION_NOP,
    [OP_LOAD_ABS_N16]    = OPERATION_NOP,
    [OP_LOAD_ABS_N32]    = OPERATION_NOP,
    [OP_LOAD_ABS_N64]    = OPERATION_NOP,
    [OP_LOAD_ABS_CMPLX]  = OPERATION_NOP,
    
    [OP_LOAD_LOC_N8]     = OPERATION_NOP,
    [OP_LOAD_LOC_N16]    = OPERATION_NOP,
    [OP_LOAD_LOC_N32]    = OPERATION_NOP,
    [OP_LOAD_LOC_N64]    = OPERATION_NOP,
    [OP_LOAD_LOC_CMPLX]  = OPERATION_NOP,
    
    [OP_STORE_ABS_N8]    = OPERATION_NOP,
    [OP_STORE_ABS_N16]   = OPERATION_NOP,
    [OP_STORE_ABS_N32]   = OPERATION_NOP,
    [OP_STORE_ABS_N64]   = OPERATION_NOP,
    [OP_STORE_ABS_CMPLX] = OPERATION_NOP,

    [OP_STORE_LOC_N8]    = OPERATION_NOP,
    [OP_STORE_LOC_N16]   = OPERATION_NOP,
    [OP_STORE_LOC_N32]   = OPERATION_NOP,
    [OP_STORE_LOC_N64]   = OPERATION_NOP,
    [OP_STORE_LOC_CMPLX] = OPERATION_NOP,

    // Arithmetic

    [OP_ADD_I]           = OPERATION_NOP,
    [OP_ADD_F]           = OPERATION_NOP,
    
    [OP_SUB_I]           = OPERATION_NOP,
    [OP_SUB_F]           = OPERATION_NOP,

    [OP_MUL_UI]          = OPERATION_NOP,
    [OP_MUL_SI]          = OPERATION_NOP,
    [OP_MUL_F]           = OPERATION_NOP,

    [OP_DIV_UI]          = OPERATION_NOP,
    [OP_DIV_SI]          = OPERATION_NOP,
    [OP_DIV_F]           = OPERATION_NOP,

    [OP_MOD_SI]          = OPERATION_NOP,
    [OP_MOD_UI]          = OPERATION_NOP,

    [OP_INC_I]           = OPERATION_NOP,
    [OP_INC_F]           = OPERATION_NOP,

    [OP_DEC_I]           = OPERATION_NOP,
    [OP_DEC_I]           = OPERATION_NOP,

    [OP_AND]             = OPERATION_NOP,
    [OP_OR]              = OPERATION_NOP,
    [OP_NOT]             = OPERATION_NOP,
    [OP_BWAND]           = OPERATION_NOP,
    [OP_BWOR]            = OPERATION_NOP,
    [OP_BWNOT]           = OPERATION_NOP,

    // CMP Operations
    [OP_EQ]              = OPERATION_NOP,
    [OP_NEQ]             = OPERATION_NOP,

    [OP_GEQ_SI]          = OPERATION_NOP,
    [OP_GEQ_UI]          = OPERATION_NOP,
    [OP_GEQ_F]           = OPERATION_NOP,

    [OP_LEQ_SI]          = OPERATION_NOP,
    [OP_LEQ_UI]          = OPERATION_NOP,
    [OP_LEQ_F]           = OPERATION_NOP,

    [OP_LES_SI]          = OPERATION_NOP,
    [OP_LES_UI]          = OPERATION_NOP,
    [OP_LES_F]           = OPERATION_NOP,

    [OP_GTR_SI]          = OPERATION_NOP,
    [OP_GTR_UI]          = OPERATION_NOP,
    [OP_GTR_F]           = OPERATION_NOP,

    // Stack Operations
    [OP_POP]             = OPERATION_NOP,
    [OP_RET]             = OPERATION_NOP,
    [OP_ROT]             = OPERATION_NOP,
    
    // Procedures

    [OP_PROC_RET]        = OPERATION_NOP,
    [OP_SYNC_CALL]       = OPERATION_NOP,
    [OP_ASYN_CALL]       = OPERATION_NOP,
    
    // Operations for complex types

    [OP_CMPLX_CREATE] = OPERATION_NOP,
    [OP_CMPLX_UPDATE] = OPERATION_NOP,
    [OP_CMPLX_DELETE] = OPERATION_NOP,
    
    // Controll Flow

    [OP_CMPLX_USE_N8]  = OPERATION_NOP,
    [OP_CMPLX_USE_N16] = OPERATION_NOP,
    [OP_CMPLX_USE_N32] = OPERATION_NOP,
    [OP_CMPLX_USE_N64] = OPERATION_NOP,
    [OP_CMPLX_USE_CMPLX] = OPERATION_NOP,

    [OP_JMP_ABS] = OPERATION_NOP,
    [OP_JMP_NEG] = OPERATION_NOP,
    [OP_JMP_POS] = OPERATION_NOP,
    [OP_IFJ_ABS] = OPERATION_NOP,
    [OP_IFJ_NEG] = OPERATION_NOP,
    [OP_IFJ_POS] = OPERATION_NOP,

    // Channels

    [OP_CHL_OPEN] = OPERATION_NOP,
    [OP_CHL_WRITE] = OPERATION_NOP,
    [OP_CHL_READ] = OPERATION_NOP,
    [OP_CHL_CLOSE] = OPERATION_NOP,
    [OP_CHL_LISTEN] = OPERATION_NOP,
    [OP_CHL_WAIT] = OPERATION_NOP,

    // Type Convertions
    [OP_I2U] = OPERATION_NOP,
    [OP_I2F] = OPERATION_NOP,
    [OP_U2I] = OPERATION_NOP,
    [OP_U2F] = OPERATION_NOP,
    [OP_F2I] = OPERATION_NOP,
    [OP_F2U] = OPERATION_NOP,

    // Size Convertions
    [OP_RESIZE_N8] = OPERATION_NOP,
    [OP_RESIZE_N16] = OPERATION_NOP,
    [OP_RESIZE_N32] = OPERATION_NOP,
    [OP_RESIZE_N64] = OPERATION_NOP
};

const OperationPTR* Operations_getSTDOperationImplementation()
{
    return operations;
}