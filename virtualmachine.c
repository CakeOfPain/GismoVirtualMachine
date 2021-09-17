
#include "virtualmachine.h"
#include "operations.h"

#define STD_STACK_SIZE 1024

virtualMachine_t* VirtualMachine()
{
    virtualMachine_t* vm = (virtualMachine_t*) malloc(sizeof(virtualMachine_t));
    if(!vm)
    {
        fprintf(stderr, "%s - at: %d:%s\n", "Out of Memory!", __LINE__, __FILE__);
        exit(EXIT_FAILURE);
    }
    // Initzalisation
    vm->callstack = ByteStack(STD_STACK_SIZE);
    vm->variables = ByteStack(STD_STACK_SIZE);
    vm->constants = ByteStack(STD_STACK_SIZE);
    vm->opstack   = ByteStack(STD_STACK_SIZE);
    
    vm->operations = Operations_getSTDOperationImplementation();
    return vm;
}

virtualMachine_t* VirtualMachine_delete(virtualMachine_t *vm)
{
    if(!vm)
    {
        fprintf(stderr, "%s - at: %d:%s\n", "Out of Memory!", __LINE__, __FILE__);
        exit(EXIT_FAILURE);
    }

    ByteStack_delete(vm->callstack);
    ByteStack_delete(vm->variables);
    ByteStack_delete(vm->constants);
    ByteStack_delete(vm->opstack);
    free(vm);
    return NULL;
}

void VirtualMachine_execute(virtualMachine_t *vm)
{
    // Disclaimer: At the moment only testing...

    
    
}

int main(int argc, char const *argv[])
{
    virtualMachine_t *vm = VirtualMachine();

    VirtualMachine_execute(vm);

    VirtualMachine_delete(vm);
    return EXIT_SUCCESS;
}