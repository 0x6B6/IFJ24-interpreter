/**
 * Název projektu: Implementace překladače imperativního jazyka IFJ24.
 *
 * @author xukropj00, Jan Ukropec
 *
 * @file codegen.h
 */

#ifndef CODEGEN_H
#define CODEGEN_H

typedef enum frame{
    GLOBAL = 0,
    LOCAL = 1,
    TEMPORARY = 2,
} Frame;

typedef struct term{
    enum _term_type{
        VARIABLE_T,
        INTEGER_T,
        FLOAT_T,
        BOOLEAN_T,
        STRING_T,
        NULL_T
    } type;
    union _term_value{
        char *var_name;
        int int_val;
        double float_val;
        bool bool_val;
        char *string;
    } value;
    Frame frame; // In case of VARIABLE_T (otherwise can be left uninitialized)
} TTerm;

typedef unsigned long long ull;

// Constants
extern const TTerm cg_var_retval;
// Global terms
extern const TTerm cg_null_term;
extern const TTerm cg_true_term;
extern const TTerm cg_zero_int_term;

void cg_term(TTerm term);

/**
 * Sets interpreted language to IFJcode24
 */
void cg_init(void);

/**
 * Creates variable
 * \param var
 */
void cg_create_var(TTerm var);

/**
 * Creates temporary memory frame and deletes the current one
 */
void cg_create_frame(void);

/**
 * Pushes temporary memory frame to a local frame stack
 */
void cg_push_frame(void);

/**
 * Pops the active local memory frame and replaces the current temporary frame with it
 */
void cg_pop_frame(void);

/**
 * Copies value to a variable
 * \param dest Variable
 * \param src Variable or constant
 */
void cg_move(TTerm dest, TTerm src);

// IFJ BUILT-IN

/**
 * Reads a string from stdin and saves it into a variable GF@retval (cg_var_retval)
 */
void cg_ifj_readstr(void);

/**
 * Reads an integer from stdin and saves it into a variable GF@retval (cg_var_retval)
 */
void cg_ifj_readi32(void);

/**
 * Reads a float from stdin and saves it into a variable GF@retval (cg_var_retval)
 */
void cg_ifj_readf64(void);

/**
 * Writes term to stdoiut
 * \param term
 */
void cg_ifj_write(TTerm term);

/**
 * Convers integer value to float and saves it into GF@retval (cg_var_retval)
 * \param term Integer value
 */
void cg_ifj_i2f(TTerm term);

/**
 * Convers float value to integer and saves it into GF@retval (cg_var_retval)
 * \param term Float value
 */
void cg_ifj_f2i(TTerm term);

/**
 *
 * \param term
 */
void cg_ifj_string(TTerm term);

/**
 *
 * \param term
 */
void cg_ifj_length(TTerm s);

/**
 *
 * \param s1
 * \param s2
 */
void cg_ifj_concat(TTerm s1, TTerm s2);

#endif
