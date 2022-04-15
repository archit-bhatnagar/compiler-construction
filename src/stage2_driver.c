#include "parser.h"
#include <time.h>
#include "ast.h"
#include "symbolTable.h"

int main(int argc, char *argv[]){
    int choice=0;
    while(1){
        printf("\nENTER CHOICE:\n");
        scanf("%d", &choice);

        switch(choice){
            case 0:{
                exit(1);
            }
            break;

            case 1:{
                // printing the token list generated by the lexer
                initialize();
                prettyPrint(argv[1]);
            }
            break;

            case 2:{
                // parsing to verify the syntactic correctness of the input source code and to produce parse tree
                initialize();
                char *file;
                file = "grammar.txt";
                grammar C;
                C = readGrammar(file);
                C.ff = ComputeFirstAndFollowSets(C);
                parseTable* T = intializeParseTable(C.numNonTerminals,C.numTerminals);
                createParseTable(C,C.ff,T);
                treeN rootNode; 
                rootNode = parseInputSourceCode(argv[1], C, T);
                
                int *count1 = (int *)malloc(sizeof(int));
    			*count1 = 0;
    			printParseTree(&rootNode, argv[2],C,count1);
            }
            break;

            case 3:{
                // printing the Abstract Syntax Tree

    			printf("Printing Abstract Syntax Tree in Inorder Traversal\n");

				char *file;
				file = "grammar.txt";
				grammar C;
				C = readGrammar(file);
				C.ff = ComputeFirstAndFollowSets(C);
				parseTable* T = intializeParseTable(C.numNonTerminals, C.numTerminals);
				createParseTable(C, C.ff, T);
				char *testCaseFile = argv[1];
				treeN rootNode;
				rootNode = parseInputSourceCode(testCaseFile, C, T);
				
				int *count1 = (int *)malloc(sizeof(int));
				*count1 = 0;
				printParseTree(&rootNode,"op.txt",C,count1);
				int *insertPrev = (int *)malloc(sizeof(int));
				*insertPrev = 0;
				int *count = (int *)malloc(sizeof(int));
				*count = 0;
				astNode *astroot = mknode(rootNode.elem,C);
				constructAst(astroot, &rootNode,C,insertPrev,astroot);
				printAST(astroot,C, count);

            }
            break;

            case 4:{
				
				char *file;
				file = "grammar.txt";
				grammar C;
				C = readGrammar(file);
				C.ff = ComputeFirstAndFollowSets(C);
				parseTable* T = intializeParseTable(C.numNonTerminals, C.numTerminals);
				createParseTable(C, C.ff, T);
				char *testCaseFile = argv[1];
				treeN rootNode;
				rootNode = parseInputSourceCode(testCaseFile, C, T);
				
				int *count1 = (int *)malloc(sizeof(int));
				*count1 = 0;
				printParseTree(&rootNode,"op.txt",C,count1);
				int *insertPrev = (int *)malloc(sizeof(int));
				*insertPrev = 0;
				int *count = (int *)malloc(sizeof(int));
				*count = 0;
				astNode *astroot = mknode(rootNode.elem,C);
				constructAst(astroot, &rootNode,C,insertPrev,astroot);
				
				printf("Parse Tree Number of nodes = %d. Allocated Memory = %lu bytes\n",*count1,sizeof(treeN)*(*count1));
				printf("AST Number of nodes = %d. Allocated Memory = %lu bytes\n\n",*count,sizeof(astNode)*(*count));

				float p1 = sizeof(treeN)*(*count1);
				float p2 = sizeof(astNode)*(*count);
				float compressionPercentage = ((p1 - p2)/p1)*100;
				printf("Compression percentage = ((%f - %f)/%f)*100 = %f\n", p1, p2, p1, compressionPercentage);
    
            }
            break;

			case 5:{
				// printing symbol table
				printf("\nPrinting Symbol Table\n");

				char *file;
				file = "grammar.txt";
				grammar C;
				C = readGrammar(file);
				C.ff = ComputeFirstAndFollowSets(C);
				parseTable* T = intializeParseTable(C.numNonTerminals, C.numTerminals);
				createParseTable(C, C.ff, T);
				char *testCaseFile = argv[1];
				treeN rootNode;
				rootNode = parseInputSourceCode(testCaseFile, C, T);
				
				int *count1 = (int *)malloc(sizeof(int));
				*count1 = 0;
				printParseTree(&rootNode,"op.txt",C,count1);
				int *insertPrev = (int *)malloc(sizeof(int));
				*insertPrev = 0;
				int *count = (int *)malloc(sizeof(int));
				*count = 0;
				astNode *astroot = mknode(rootNode.elem,C);
				constructAst(astroot, &rootNode,C,insertPrev,astroot);
				
				// printSymbolTable()
			}
			break;

			case 6:{
				// Print Global Variable
				printf("\nPrinting Global Variables\n");

				char *file;
				file = "grammar.txt";
				grammar C;
				C = readGrammar(file);
				C.ff = ComputeFirstAndFollowSets(C);
				parseTable* T = intializeParseTable(C.numNonTerminals, C.numTerminals);
				createParseTable(C, C.ff, T);
				char *testCaseFile = argv[1];
				treeN rootNode;
				rootNode = parseInputSourceCode(testCaseFile, C, T);
				
				int *count1 = (int *)malloc(sizeof(int));
				*count1 = 0;
				printParseTree(&rootNode,"op.txt",C,count1);
				int *insertPrev = (int *)malloc(sizeof(int));
				*insertPrev = 0;
				int *count = (int *)malloc(sizeof(int));
				*count = 0;
				astNode *astroot = mknode(rootNode.elem,C);
				constructAst(astroot, &rootNode,C,insertPrev,astroot);
				
				symbolTable *sTable = constructST(astroot, C);
				for (int i = 0; i < sTable->numEntries; i++){
					printf("%s\n", sTable->entries[i]->varName);
				}
			}
			break;

			case 7:{
				// Print Activation record sizes
				printf("\nPrinting Activation record sizes\n");

				char *file;
				file = "grammar.txt";
				grammar C;
				C = readGrammar(file);
				C.ff = ComputeFirstAndFollowSets(C);
				parseTable* T = intializeParseTable(C.numNonTerminals, C.numTerminals);
				createParseTable(C, C.ff, T);
				char *testCaseFile = argv[1];
				treeN rootNode;
				rootNode = parseInputSourceCode(testCaseFile, C, T);
				
				int *count1 = (int *)malloc(sizeof(int));
				*count1 = 0;
				printParseTree(&rootNode,"op.txt",C,count1);
				int *insertPrev = (int *)malloc(sizeof(int));
				*insertPrev = 0;
				int *count = (int *)malloc(sizeof(int));
				*count = 0;
				astNode *astroot = mknode(rootNode.elem,C);
				constructAst(astroot, &rootNode,C,insertPrev,astroot);
				
				symbolTable *sTable = constructST(astroot, C);
				for(int i=0; i<sTable->numF; i++){
					printf("%s \t %d\n", sTable->tables[i]->function->fId, sTable->tables[i]->currWidth);
				}	
			}
			break;

			case 8:{
				// Record types and sizes
				printf("\nPrinting Record types and sizes\n");

			}
			break;

			case 9:{
				// Type checking and semantic analysis
				printf("\nType checking and semantic analysis\n");
				

				// print syntactic errors if any
				initialize();
                char *file;
                file = "grammar.txt";
                grammar C;
                C = readGrammar(file);
                C.ff = ComputeFirstAndFollowSets(C);
                parseTable* T = intializeParseTable(C.numNonTerminals,C.numTerminals);
                createParseTable(C,C.ff,T);
                treeN rootNode; 
                rootNode = parseInputSourceCode(argv[1], C, T);

				// type checking and semantic analysis
				int *insertPrev = (int *)malloc(sizeof(int));
				*insertPrev = 0;
				int *count = (int *)malloc(sizeof(int));
				*count = 0;
				astNode *astroot = mknode(rootNode.elem,C);
				construct5Ast(astroot, &rootNode,C,insertPrev,astroot);
				
				symbolTable* sTable = constructST(astroot, C);
				printf("Type Checking \n"); 
   				// int tc = typeCheck(astroot, C, sTable, -1);
			}
			break;

			case 10:{
				// Code generation and dynamic type checking
				printf("\nCode generation and dynamic type checking\n");
                printf("<Not Implemented>\n");
				
			}			
			break;

            default:
                printf("ENTER CORRECT CHOICE\n");
            break;
        }
    }
}