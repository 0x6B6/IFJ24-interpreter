/**
 * Název projektu: Implementace překladače imperativního jazyka IFJ24.
 *
 * @author xpazurm00, Marek Pazúr
 * 
 * @file semantic.c
 */

#ifndef SEMANTIC_H
#define SEMANTIC_H

#include "token.h"
#include "syna.h"
#include "symtable.h"
#include "binary_tree.h"

// Struct with information about expressions
typedef struct {
    int type;	// result type
    TData data;	// data about variable/constant
    bool is_constant_exp; // is result of (sub)expression constant
    bool is_optional_null;
} expr_info;

void semantic_analysis(TBinaryTree* AST);

void FunctionSemantics(TNode* func);

void CommandSemantics(TNode* Command, scope_t* current_scope, TNode* func);

void FunctionCallSemantics(TNode *functionCall, scope_t* current_scope, int* type_out);

void main_function_semantics(TSymtable* globalSymTable);

void assig_check(TNode* command_instance);

void declaration_semantics(TNode* declaration, scope_t* current_scope);

void check_head_type(TNode* body);

void expression_semantics(TNode *expression, scope_t* scope, expr_info* info);

// Helper functions
TSymtable* declaration_var_check(struct TScope scope, char* identifier);

int formal_param_count(TNode *formal_param);
bool id_defined(struct TScope* scope, char* identifier,  TSymtable** out_sym);
char get_var_type(Type type);
char get_literal_type(int type);
void set_to_used(TSymtable* symtable, char* identifier);

void add_sub_mul_semantic(TNode* operator, scope_t* scope, int* type_out);

char *literal_convert_i32_to_f64(char *literal);

#endif
