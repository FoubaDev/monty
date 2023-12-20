#include "monty.h"

/*
 * initializeGlobal - init global variable
 *@global - pointer to stack global
 *
 * Reurn - nothing
 */

void initializeGlobal(global_t *global)
{
	global->arg = NULL;
	global->file = NULL;
	global->content = NULL;
	global->flag = 0;
}
