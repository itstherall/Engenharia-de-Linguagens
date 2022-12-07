/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     ID = 258,
     NUMBER_LITERAL = 259,
     STRING_LITERAL = 260,
     WHILE = 261,
     BLOCK_ENDWHILE = 262,
     FOR = 263,
     BLOCK_ENDFOR = 264,
     DO = 265,
     BLOCK_ENDDO = 266,
     BLOCK_END = 267,
     IF = 268,
     BLOCK_ENDIF = 269,
     THEN = 270,
     ELSE = 271,
     FUNCTION = 272,
     PROCEDURE = 273,
     RETURN = 274,
     PRINT = 275,
     DIMENSION = 276,
     NUMBER = 277,
     STRING = 278,
     BOOL = 279,
     MAP = 280,
     TRUE = 281,
     FALSE = 282,
     AND = 283,
     OR = 284,
     NOT = 285,
     OP_GEQ = 286,
     OP_LEQ = 287,
     OP_EQ = 288,
     OP_NEQ = 289,
     OP_INCREMENT = 290,
     OP_DECREMENT = 291,
     SUM_ASSIGN = 292,
     DIFFERENCE_ASSIGN = 293,
     PRODUCT_ASSIGN = 294,
     QUOTIENT_ASSIGN = 295,
     REMAINDER_ASSIGN = 296
   };
#endif
/* Tokens.  */
#define ID 258
#define NUMBER_LITERAL 259
#define STRING_LITERAL 260
#define WHILE 261
#define BLOCK_ENDWHILE 262
#define FOR 263
#define BLOCK_ENDFOR 264
#define DO 265
#define BLOCK_ENDDO 266
#define BLOCK_END 267
#define IF 268
#define BLOCK_ENDIF 269
#define THEN 270
#define ELSE 271
#define FUNCTION 272
#define PROCEDURE 273
#define RETURN 274
#define PRINT 275
#define DIMENSION 276
#define NUMBER 277
#define STRING 278
#define BOOL 279
#define MAP 280
#define TRUE 281
#define FALSE 282
#define AND 283
#define OR 284
#define NOT 285
#define OP_GEQ 286
#define OP_LEQ 287
#define OP_EQ 288
#define OP_NEQ 289
#define OP_INCREMENT 290
#define OP_DECREMENT 291
#define SUM_ASSIGN 292
#define DIFFERENCE_ASSIGN 293
#define PRODUCT_ASSIGN 294
#define QUOTIENT_ASSIGN 295
#define REMAINDER_ASSIGN 296




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 15 "parser.y"
{
	int    iValue; 	/* integer value */
	char   cValue; 	/* char value */
	char * sValue;  /* string value */
	struct node * nodeValue;  /* ??? */
	}
/* Line 1529 of yacc.c.  */
#line 138 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

