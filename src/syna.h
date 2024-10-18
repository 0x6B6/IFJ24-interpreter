/** 
 * Název projektu: Implementace překladače imperativního jazyka IFJ24.
 * 
 * @author xglosro00, Robert Glos
 * @author xukropj00, Jan Ukropec
 * @author xtomasp00, Patrik Tomasko
 * 
 * @file syna.h
 */
 
#include "token.h"
#include "symtable.h"

typedef enum fsm_state_syna {
    STATE_ROOT, //expecting either a function header or import
    STATE_identifier, //expecting identifier
    STATE_assig, //expecting =
    STATE_prolog, //expectin @import
    STATE_lr_bracket, //expecting (
    STATE_rr_bracket, //expecting )
    STATE_semicolon, //expecting ;
    STATE_identifier_prolog, //@import(this part)
    STATE_fn, //expecting keyword fn
    STATE_type, //data type
    STATE_open_body_check, //the beginning { of the body of function/if/else/while
    STATE_body,
    STATE_next_command, //expecting either next command or } end of body
    STATE_first_fn_param, //expecting either ) or the first param of fn
    STATE_colon, //expecting :
    STATE_ls_bracket, //expecting ]
    STATE_u8, //expecting u8
    STATE_coma //expectin ,
} Pfsm_state_syna;

 typedef struct parser{
  Pfsm_state_syna state;
  token_t current_token;
  TSymtable* global_symtable;
  TSymtable* local_symtable;
 } Tparser;
 
void init_parser(token_t token);
 
void root_code(Tparser* parser);
 
void import_func(Tparser* parser);

void function_header(Tparser* parser);
 
void function_params(Tparser* parser);
