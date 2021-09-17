#ifndef VIRTUALMACHINE_h
#define VIRTUALMACHINE_h

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "operationID.h"

#define INSTRUCTION_RANGE 256

struct virtualMachine_t;

typedef struct virtualMachine_t
{
    byteStack_t *callstack;
    byteStack_t *variables;
    byteStack_t *constants;
    byteStack_t *opstack;
    void (**operations)(struct virtualMachine_t*);
} virtualMachine_t;

typedef void (*OperationPTR)(virtualMachine_t*);

/**
 * @brief      Allocates and constructs a VirtualMachine Object using malloc
 * @returns    Pointer holding the VirtualMachines address
 */
virtualMachine_t* VirtualMachine(void);

/**
 * @brief        Frees Memory that a VirtualMachine has been allocated
 * @param vm     Pointer to the VirtualMachine that should become freed
 * @returns      NULL
 */
virtualMachine_t* VirtualMachine_delete(virtualMachine_t *);

/**
 * @brief        Executes instructions
 * @param vm     Pointer to the VirtualMachine that should perform execution
 */
void VirtualMachine_execute(virtualMachine_t *);

#endif
