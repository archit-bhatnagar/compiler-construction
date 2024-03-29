/*
ID  2019A7PS0064P					Name Siddharth Sharma
ID  2019A7PS0062P					Name Atharva Chandak
ID  2019A7PS0133P					Name Archit Bhatnagar 
ID  2019A7PS0554P					Name Suchismita Tripathy
ID  2019A7PS1139P 					Name Srujan Deolasee
*/

#pragma once
#include "lookuptable.h"
#include "lexerDef.h"
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

int dfa_state;
token_name actualToken(token_name expected, char *lexeme);
int range_match(char a, char start, char end);
char* accept(bool isLastUseful);
char * reject();
void populateToken(tokenInfo *TOK, token_name t, char * lexeme, int lineNo);
void initializeTwinBuffer();
char next_char(FILE *fp, bool isComment, bool isLengthExceeded);
void reset(int amt);
int char_match(char a, char b);
FILE *getStream(FILE *fp, int bufferNo);
tokenInfo getNextToken(FILE *fp);
void removeComments(char *testcaseFile, char *cleanFile);
void clearTwinBuffer();
void removeComments(char *testcaseFile, char *cleanFile);
void prettyPrint(char *testcaseFile); 
