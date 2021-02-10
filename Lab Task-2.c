#include<stdio.h>
#include<string.h>

#define mxSize 50

struct symbolInfo{
    char symbol[20];
    char type[20];
};

struct symbolInfo* symbolTable[mxSize];
int index;


void insert(char* symbol, char* type){
    struct symbolInfo* dumyData = (struct symbolInfo*)malloc(sizeof(struct symbolInfo*));
    strcpy(dumyData->symbol, symbol);
    strcpy(dumyData->type, type);
    symbolTable[index] = dumyData;
    index++;
    printf("Item Inserted!\n");
    printf(" Inserted Items: Symbol = %s,  Type = %s\n",symbol,type);
}

void show(){
    for(int i=0; i<index; i++){
        printf("Symbol Type: %s, Symbol Value: %s\n", symbolTable[i]->type, symbolTable[i]->symbol);
    }
}

void search(char* symbol, char* type){
    for(int i=0; i<index; i++){
        if(strcmp(symbolTable[i]->symbol, symbol) == 0 && strcmp(symbolTable[i]->type, type) == 0){
            printf("The symbol is found!\n");
            printf(" Searched Item: Symbol = %s,  Type = %s\n",symbol,type);
            return;
        }
    }
}

void delete (char* symbol, char* type){
    for(int i=0; i<index; i++){
        if(strcmp(symbolTable[i]->symbol, symbol) == 0 && strcmp(symbolTable[i]->type, type) == 0){
            for(int j=i+1; j<index; j++){
                strcpy(symbolTable[i]->symbol, symbolTable[j]->symbol);
                strcpy(symbolTable[i]->type, symbolTable[j]->type);
            }
            index--;
            printf("The symbol is deleted!\n");
            printf("  Deleted Item: Symbol = %s,  Type = %s\n",symbol,type);
            return;
        }
    }
}

void update(char* existingSymbol, char* existingType, char* symbol, char* type){
    for(int i=0; i<index; i++){
        if(strcmp(symbolTable[i]->symbol, existingSymbol) == 0 && strcmp(symbolTable[i]->type, existingType) == 0){
            printf("The symbol is updated!\n");
            printf(" Old Item: Symbol = %s,  Type = %s\n",symbolTable[i]->symbol,symbolTable[i]->type);
            printf(" New Item: Symbol = %s,  Type = %s\n",symbol,type);
            strcpy(symbolTable[i]->symbol, symbol);
            strcpy(symbolTable[i]->type, type);
            return;
        }
    }
}

int getHashKey(char* symbol, char* type){
    for(int i=0; i<index; i++){
        if(strcmp(symbolTable[i]->symbol, symbol) == 0 && strcmp(symbolTable[i]->type, type) == 0){
            return i+1;
        }
    }
}
int main()
{
    insert("int", "INTEGER");
    search("int", "INTEGER");
    delete("int", "INTEGER");
    update("int","INTEGER","FLOAT","CHAR");
    int value = getHashKey("int", "INTEGER");
    printf(" hash key is : %d\n",value);

    show();

    return 0;
}
