#include <stdio.h>

int NODES_NUM = 1, LEVELS = 0, incorrects = 0;

struct tree{
    int incorrect;
    int This_is_null;
    unsigned long hash_value;
};

unsigned long MurMurOAAT32( char * key );
void Generate_HashTree( struct tree *Tree, int now_level, int now_index  );
void Compare( struct tree *Tree, int now_level, int now_index );
int find_node( int level, int index );

int main(){

    
    #pragma region //input and initialize
    int strings, max_length;
    scanf("%d %d", &strings, &max_length );

    while (NODES_NUM < strings){
        NODES_NUM *= 2;
        LEVELS++;
    }
    
    
    struct tree Tree[NODES_NUM*2]; //skip Tree[0] due to level-index calculation
    char Data[NODES_NUM][max_length+1];

    //initialize
    for(int i=0; i<NODES_NUM*2;i++){
        Tree[i].incorrect = 0;
        Tree[i].This_is_null = 0;
        Tree[i].hash_value = 0;
    }
    for(int i = 0; i < strings; i++){
        scanf("%s",Data[i]);
        Tree[NODES_NUM+i].hash_value = MurMurOAAT32(Data[i]);
    }
    for(int i = NODES_NUM+strings; i< NODES_NUM*2; i++)
        Tree[i].This_is_null = 1;
    #pragma endregion

    #pragma region //generate and compare hash tree
    
    Generate_HashTree(Tree,0,0);

    Compare(Tree,0,0);

    #pragma endregion

    ///*
    #pragma region //outputs
    printf( "2 %d\n", incorrects );
    for(int i = 0; i < strings; i++){
        if(Tree[NODES_NUM+i].incorrect)
            printf("%s\n", Data[i] );
    }
    #pragma endregion //*/
    /*
    for(int i=0, row = 1; i<=LEVELS; i++){
        printf("%d:\t",i);
        for(int j=0; j<row; j++)
            printf("%d:[%10lu] ",j,Tree[find_node(i,j)].hash_value);
        printf("\n");
        row*=2;
    }
    //*/
    
    return 0;
}

unsigned long MurMurOAAT32( char * key ){
    //Divide the long hash value into 4 char variables to generate a new long hash value
    unsigned long h = 3323198485ul;
    for(; *key; ++key ){
        h ^= *key;
        h *= 0x5bd1e995;
        h ^= h >> 15;
    }
    return h;
}

void Generate_HashTree( struct tree *Tree, int now_level, int now_index  ){
    if(now_level == LEVELS)
        return;
    
    int now_node = find_node(now_level,now_index);

    Generate_HashTree(Tree,now_level+1,now_index*2);
    Generate_HashTree(Tree,now_level+1,now_index*2+1);

    int left_child = find_node(now_level+1,now_index*2);
    int right_child = find_node(now_level+1,now_index*2+1);

    if(Tree[left_child].This_is_null){
        Tree[now_node].This_is_null = 1;
        return;
    }
    
    char hash_string[50];
    unsigned long hash_value;
    if(Tree[right_child].This_is_null)
        hash_value = Tree[left_child].hash_value + Tree[left_child].hash_value;
    else
        hash_value = Tree[left_child].hash_value + Tree[right_child].hash_value;
    sprintf(hash_string,"%lu",hash_value);
    Tree[now_node].hash_value = MurMurOAAT32(hash_string);
}

void Compare( struct tree *Tree, int now_level, int now_index ){
    int now_node = find_node(now_level,now_index);
    if(Tree[now_node].This_is_null)
        return;
    
    printf("1 %d %d\n",now_level,now_index);
    fflush(NULL);
    unsigned long true_hash_value;
    scanf("%lu",&true_hash_value);


    if(Tree[now_node].hash_value != true_hash_value){
        Tree[now_node].incorrect = 1;
        if(now_level == LEVELS){
            incorrects++;
            return;
        }
        Compare( Tree, now_level+1, now_index*2);
        Compare( Tree, now_level+1, now_index*2+1 );
    }
    return;
}

int find_node( int level, int index ){
    int now_node = 1;
    while(level--)
        now_node *= 2;
    now_node += index;
    return now_node;
}