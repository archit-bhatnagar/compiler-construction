/*
ID  2019A7PS0064P					Name Siddharth Sharma
ID  2019A7PS0062P					Name Atharva Chandak
ID  2019A7PS0133P					Name Archit Bhatnagar 
ID  2019A7PS0554P					Name Suchismita Tripathy
ID  2019A7PS1139P 					Name Srujan Deolasee
*/

#include "lookuptable.h"
#include "lookuptableDef.h"
// #include "lexerDef.h"
int maxLen(int a){
    int count =0;
    while(a>0){
        count++;
        a/=10;
    }
    return count;
}
int kmult(int a, int b){
    if(a<10 || b<10) return a*b;
    int n = maxLen(a>b?a:b);
    int ten_power_n_by_2 = binExpo(10,n/2);
    int a_high = a/ten_power_n_by_2;
    int a_low = a%ten_power_n_by_2;
    int b_high = b/ten_power_n_by_2;
    int b_low = b%ten_power_n_by_2;
    int a_high_b_high = kmult(a_high,b_high);
    int a_low_b_low = kmult(a_low, b_low);
    return a_high_b_high*binExpo(10,2*ten_power_n_by_2) + (kmult(a_high, b_low) + kmult(a_low, b_high))*ten_power_n_by_2+a_low_b_low;

}
int binExpo(int a, int b){
    if(!b) return 1;
    if(b%2) return a*binExpo(a,(b-1)/2);
    if(!(b%2)) return binExpo(a,b/2);
}

int h1(char *lexeme){
    int val=0;
    for(int i=0;i<strlen(lexeme);i++){
        val += (lexeme[i]*binExpo(PRIME,i));
        val%=HASH_SIZE;
    }
    return val;
}
int h2(int h1_hashvalue){
    return 1+(h1_hashvalue%(HASH_SIZE-1));
}
int hash(char *lexeme, int i){
    int x =h1(lexeme);
    return (x+i*h2(x))%HASH_SIZE;
}
int search(char * lexeme){
    int i =0;
    int j = hash(lexeme, i);
    while(lookup_table[j].present && i<HASH_SIZE){
        j=hash(lexeme,i);
        if(lookup_table[j].present && strcmp(lexeme,lookup_table[j].lexeme)==0)return j;
        i++;
    }
    return -1;
}
int insert(char *lexeme, token_name tkn){
    int i = 0;
    int j;
    while(i<HASH_SIZE){
        j = hash(lexeme, i);
        if(!lookup_table[j].present){
            for(int i=0;i<strlen(lexeme);i++){
                lookup_table[j].lexeme[i]=*(lexeme+i);
            }
            lookup_table[j].present = true;
            lookup_table[j].tkn=tkn;
            return j;
        }
        i++;
    }
}
void initialize(){
    FILE *fp = fopen("keywords_lexemes.txt","r");
    char str[20]="";
    int index;
    // printf("start\n");
    for(int i=0;i<HASH_SIZE;i++){
        lookup_table[i].present=false;
        lookup_table[i].lexeme=(char *)malloc(sizeof(char)*MAX_LEXEME);
    }
    while(!feof(fp)){
        fscanf(fp,"%d %20[^,^\n],",&index,str);
        // printf("%s\n",str);
        int j = search(str);
        if(j==-1){
            // printf("lexeme: %s enum: %d ",str,mapIndexToEnum[index]);   
            // printf("hashvalue: %d\n",insert(str, mapIndexToEnum[index]));  // index for the lexeme


            insert(str,mapIndexToEnum[index]);
        }
        fgetc(fp);
        
    }
    fclose(fp);
}
// int main(){
//     initialize();
//     // char * lex="Int";
//     // char *lex1="Real";
//     // printf("%d %d\n",hash(lex,0),hash(lex1,0));
//     return 0;
// }
