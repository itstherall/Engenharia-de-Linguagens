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
     BLOCK_ENDFOR = 263,
     IF = 264,
     BLOCK_ENDIF = 265,
     BLOCK_END = 266,
     FOR = 267,
     DO = 268,
     THEN = 269,
     ELSE = 270,
     SEMI = 271,
     ASSIGN = 272,
     COL = 273,
     DP = 274,
     FUNCTION = 275,
     PROCEDURE = 276,
     RETURN = 277,
     AP = 278,
     FP = 279,
     AC = 280,
     FC = 281,
     ACC = 282,
     FCC = 283,
     DIMENSION = 284,
     OP_AD = 285,
     OP_DIV = 286,
     OP_SUB = 287,
     OP_MULT = 288,
     NUMBER = 289,
     STRING = 290,
     BOOL = 291,
     MAP = 292,
     TRUE = 293,
     FALSE = 294,
     AND = 295,
     OR = 296,
     NOT = 297,
     OP_LARGER = 298,
     OP_SMALLER = 299,
     OP_LEQ = 300,
     OP_SEQ = 301,
     OP_EQ = 302,
     OP_NEQ = 303,
     OP_INCREMENT = 304,
     OP_DECREMENT = 305,
     REST_DIV = 306
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
#define SEMI 271
#define ASSIGN 272
#define COL 273
#define DP 274
#define FUNCTION 275
#define PROCEDURE 276
#define RETURN 277
#define AP 278
#define FP 279
#define AC 280
#define FC 281
#define ACC 282
#define FCC 283
#define DIMENSION 284
#define OP_AD 285
#define OP_DIV 286
#define OP_SUB 287
#define OP_MULT 288
#define NUMBER 289
#define STRING 290
#define BOOL 291
#define MAP 292
#define TRUE 293
#define FALSE 294
#define AND 295
#define OR 296
#define NOT 297
#define OP_LARGER 298
#define OP_SMALLER 299
#define OP_LEQ 300
#define OP_SEQ 301
#define OP_EQ 302
#define OP_NEQ 303
#define OP_INCREMENT 304
#define OP_DECREMENT 305
#define REST_DIV 306




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 11 "parser.y"
{
	int    iValue; 	/* integer value */
	char   cValue; 	/* char value */
	char * sValue;  /* string value */
	}
/* Line 1529 of yacc.c.  */
#line 157 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

