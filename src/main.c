/** 
 * Název projektu: Implementace překladače imperativního jazyka IFJ24.
 * 
 * @author xpazurm00, Marek Pazúr
 * 
 * @file main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "compiler_error.h"
#include "lexer.h"
#include "dynamic_array.h"

int main(void) {
	//TODO
	//lexical analyser
	//syntax analyser - rekurzivni sestup?
	//symtable
	//semantic analyser
	//code generator
	if(init_scanner())
		return error;
	//get_token();
	return 0;
}