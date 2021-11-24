#ifndef OPERATION_ID_h
#define OPERATION_ID_h

/*
 * GIM-Code (p-code)
 * Ops-Notations ->
 *      I -> Integer
 *      UI -> Unsigned integer
 *      SI -> Signed integer
 *      F -> Floating point number
 *      CMPLX -> Complex type
*/
typedef enum
{
    OP_NOP,
    OP_HINT,

    // Load & Store

    OP_LOAD_ABS_N8,
    OP_LOAD_ABS_N16,
    OP_LOAD_ABS_N32,
    OP_LOAD_ABS_N64,
    OP_LOAD_ABS_CMPLX,

    OP_LOAD_LOC_N8,
    OP_LOAD_LOC_N16,
    OP_LOAD_LOC_N32,
    OP_LOAD_LOC_N64,
    OP_LOAD_LOC_CMPLX,

    OP_STORE_ABS_N8,
    OP_STORE_ABS_N16,
    OP_STORE_ABS_N32,
    OP_STORE_ABS_N64,
    OP_STORE_ABS_CMPLX,

    OP_STORE_LOC_N8,
    OP_STORE_LOC_N16,
    OP_STORE_LOC_N32,
    OP_STORE_LOC_N64,
    OP_STORE_LOC_CMPLX,

    // Arithmetic
    OP_ADD_I,
    OP_ADD_F,
    
    OP_SUB_I,
    OP_SUB_F,

    OP_MUL_UI,
    OP_MUL_SI,
    OP_MUL_F,

    OP_DIV_UI,
    OP_DIV_SI,
    OP_DIV_F,

    OP_MOD_SI,
    OP_MOD_UI,

    OP_INC_I,
    OP_INC_F,

    OP_DEC_I,
    OP_DEC_F,

    OP_AND,
    OP_OR,
    OP_NOT,
    OP_BWAND,
    OP_BWOR,
    OP_BWNOT,

    // CMP Operations

    OP_EQ,
    OP_NEQ,

    OP_GEQ_SI,
    OP_GEQ_UI,
    OP_GEQ_F,

    OP_LEQ_SI,
    OP_LEQ_UI,
    OP_LEQ_F,

    OP_LES_SI,
    OP_LES_UI,
    OP_LES_F,

    OP_GTR_SI,
    OP_GTR_UI,
    OP_GTR_F,

    // Stack Operations
    OP_POP,
    OP_RET,
    OP_ROT,

    // Procedures

    OP_PROC_RET,
    OP_SYNC_CALL,
    OP_ASYN_CALL,

    // Operations for complex types
    OP_CMPLX_CREATE,
    OP_CMPLX_UPDATE,
    OP_CMPLX_DELETE,

    // Controll Flow

    OP_CMPLX_USE_N8,    // JMP ADDRESS IF NONE
    OP_CMPLX_USE_N16,   // JMP ADDRESS IF NONE
    OP_CMPLX_USE_N32,   // JMP ADDRESS IF NONE
    OP_CMPLX_USE_N64,   // JMP ADDRESS IF NONE
    OP_CMPLX_USE_CMPLX, // JMP ADDRESS IF NONE

    OP_JMP_ABS,
    OP_JMP_NEG,
    OP_JMP_POS,
    OP_IFJ_ABS,
    OP_IFJ_NEG,
    OP_IFJ_POS,

    // Channels

    OP_CHL_OPEN,
    OP_CHL_WRITE,
    OP_CHL_READ,
    OP_CHL_CLOSE,
    OP_CHL_LISTEN,
    OP_CHL_WAIT,

    // Type Convertions
    OP_I2U,
    OP_I2F,
    OP_U2I,
    OP_U2F,
    OP_F2I,
    OP_F2U,

    // Size Convertions
    OP_RESIZE_N8,
    OP_RESIZE_N16,
    OP_RESIZE_N32,
    OP_RESIZE_N64
} operationID_t;

#endif