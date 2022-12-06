/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    NUMBER_LITERAL = 259,
    STRING_LITERAL = 260,
    WHILE = 261,
    BLOCK_ENDWHILE = 262,
    BLOCK_ENDFOR = 263,
    IF = 264,
    BLOCK_ENDIF = 265,
    BLOCK_END = 266,
    FOR = 267,
    DO = 268,
    THEN = 269,
    ELSE = 270,
    FUNCTION = 271,
    PROCEDURE = 272,
    RETURN = 273,
    DIMENSION = 274,
    NUMBER = 275,
    STRING = 276,
    BOOL = 277,
    MAP = 278,
    TRUE = 279,
    FALSE = 280,
    AND = 281,
    OR = 282,
    NOT = 283,
    OP_LEQ = 284,
    OP_SEQ = 285,
    OP_EQ = 286,
    OP_NEQ = 287,
    OP_INCREMENT = 288,
    OP_DECREMENT = 289
  };
#endif
/* Tokens.  */
#define ID 258
#define NUMBER_LITERAL 259
#define STRING_LITERAL 260
#define WHILE 261
#define BLOCK_ENDWHILE 262
#define BLOCK_ENDFOR 263
#define IF 264
#define BLOCK_ENDIF 265
#define BLOCK_END 266
#define FOR 267
#define DO 268
#define THEN 269
#define ELSE 270
#define FUNCTION 271
#define PROCEDURE 272
#define RETURN 273
#define DIMENSION 274
#define NUMBER 275
#define STRING 276
#define BOOL 277
#define MAP 278
#define TRUE 279
#define FALSE 280
#define AND 281
#define OR 282
#define NOT 283
#define OP_LEQ 284
#define OP_SEQ 285
#define OP_EQ 286
#define OP_NEQ 287
#define OP_INCREMENT 288
#define OP_DECREMENT 289

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 11 "parser.y"

	int    iValue; 	/* integer value */
	char   cValue; 	/* char value */
	char * sValue;  /* string value */
	

#line 132 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
