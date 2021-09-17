#ifndef OPERATIONS_h
#define OPERATIONS_h

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "virtualmachine.h"
#include "operationID.h"

/**
 * @brief   For defining what the virtualMachine does
 * @returns Global Array to Functions
 */
OperationPTR* Operations_getSTDOperationImplementation(void);

#endif