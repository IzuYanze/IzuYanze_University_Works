#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DISTANCE_PAIR struct distance_pair
#define MCSTREE struct MCSTree
int nodes;

struct MCSTree{
    int node_id;
    int neighbor_count;
    int neighbors[10];
};

struct distance_pair{
    int first_node;
    int second_node;
    double distance;
};

int compare_func_of_distance_pair(const void *a, const void *b){//cmp for qsort
    DISTANCE_PAIR node_A = *(DISTANCE_PAIR *)a;
    DISTANCE_PAIR node_B = *(DISTANCE_PAIR *)b;
    if(node_A.distance > node_B.distance)
        return 1;
    return -1;
};

int now_legth;
void MCST_DFS(int Array[], MCSTREE NODES[], int now_node, int Map[]){
    if(Map[now_node])
        return;
    //printf("%d ",now_node);
    Array[now_legth++] = now_node;
    Map[now_node] = 1;

    for(int i = 0; i < NODES[now_node].neighbor_count ; i++){
        int next_node = NODES[now_node].neighbors[i];
        MCST_DFS(Array, NODES, next_node, Map);
    }
    return;
}

int find_the_nearest(double array[],int nodes){
    int nearest = 0;
    double dis = array[0];
    for(int i = 1; i < nodes; i++ ){
        if(array[i] < dis){
            dis = array[i];
            nearest = i;
        }
    }
    return nearest;
}

int cmp(const void *a, const void *b){
    int A = *(int *)a;
    int B = *(int *)b;
    return A-B;
}

int main(){

    double route_limit;

    scanf( "%d %lf", &nodes, &route_limit );

    struct networkofnode{
        int node_id;
        double cordinate_x, cordinate_y;
        double distance[nodes];
    };
    struct networkofnode Network[nodes];

    //for Minimum Cost Spanning Tree
    int PAIR_COUNT = nodes * (nodes-1)/2;
    DISTANCE_PAIR pairs[PAIR_COUNT];
    int now_pair = 0;

    for(int now_node = 0; now_node < nodes; now_node++ ){ //data input & calculate distance
        scanf("%d %lf %lf", &Network[now_node].node_id, &Network[now_node].cordinate_x, &Network[now_node].cordinate_y );

        for(int opponent_node = 0; opponent_node < now_node; opponent_node++ ){
            double distances = sqrt( pow((Network[now_node].cordinate_x - Network[opponent_node].cordinate_x),2) + pow((Network[now_node].cordinate_y - Network[opponent_node].cordinate_y),2) );
            pairs[now_pair].distance = Network[now_node].distance[opponent_node] = Network[opponent_node].distance[now_node] = distances;
            pairs[now_pair].first_node = now_node;
            pairs[now_pair].second_node = opponent_node;
            now_pair++;
            //printf("%d to %d: %lf\n",now_node,opponent_node,distances);
        }
    }

    //sort by distance for Minimum Cost Spanning Tree
    qsort(pairs,PAIR_COUNT,sizeof(DISTANCE_PAIR),compare_func_of_distance_pair);

    /*check for distance
    printf("pair\n");
    for(int i=0; i< PAIR_COUNT; i++){
        printf("[%d,%d]:[%lf]\n",pairs[i].first_node,pairs[i].second_node,pairs[i].distance);
    }
    //*/
    
    //construct Minimum Cost Spanning Tree
    //#pragma region
    
    struct MCSTree Node[nodes];
    int Field[nodes];

    for(int i = 0; i < nodes; i++){
        Node[i].node_id = i;
        Node[i].neighbor_count = 0;
        Field[i] = i;
    }
    //printf("Action\n");

    for(int i = 0; i < PAIR_COUNT; i++){
        int node_a = pairs[i].first_node;
        int node_b = pairs[i].second_node;
        if(Field[node_a] == Field[node_b])
            continue;
        Node[node_a].neighbors[Node[node_a].neighbor_count] = node_b;
        Node[node_b].neighbors[Node[node_b].neighbor_count] = node_a;
        //printf("now pair: %d %d\n",Node[node_a].neighbors[Node[node_a].neighbor_count],Node[node_b].neighbors[Node[node_b].neighbor_count]);
        Node[node_a].neighbor_count++;
        Node[node_b].neighbor_count++;
        int remove_field = Field[node_b];
        for(int i = 0; i < nodes; i++ ){
            //printf("%d ",Field[i]);
            if(Field[i] == remove_field)
                Field[i] = Field[node_a];
        }
        /*printf("\n");
        for(int k=0; k < nodes; k++){
            printf("%d",k);
            for(int j=0; j < Node[k].neighbor_count ; j++)
                printf(" %d",Node[k].neighbors[j]);
            printf("\n");
        }   */
    }
    /*
    printf("Tree\n");
    for(int i=0; i < nodes; i++){
        printf("%d",i);
        for(int j=0; j < 10; j++)
            printf(" %d",Node[i].neighbors[j]);
        printf("\n");
    }
    //*/
    //#pragma endregion

    for(int i=0;i<nodes;i++){
        qsort(Node[i].neighbors, Node[i].neighbor_count, sizeof(int) ,cmp);
    }


    //#pragma region //Traverse
    int groups = 0;
    int Traverse_List[nodes][2]; //[node_id : group_id]

        //#pragma region //DFS
        
        int List[nodes];
        now_legth = 0;
        int Map[nodes];
        for(int i=0; i<nodes;i++)
            Map[i] = 0;
        MCST_DFS( List, Node, 0, Map );

        /*
        printf("out dfs");
        for(int i=0;i<PAIR_COUNT;i++)
            printf("%d ",List[i]);
        //*/
        //#pragma endregion

    double now_distance = 0;
    Traverse_List[0][0] = List[0];
    Traverse_List[0][1] = 0 ;
    for(int i=1;i<nodes;i++){
        //printf("%d",List[i]);
        int now_node = List[i], last_node = List[i-1];
        now_distance += Network[now_node].distance[last_node];
        if( now_distance > route_limit/2){
            groups ++;
            now_distance = 0;
        }
        Traverse_List[i][0] = List[i];
        Traverse_List[i][1] = groups;
    }
    //#pragma endregion

    //Output
    printf("%d",groups+1);
    for(int i = 0, now_group = -1; i < nodes; i++){
        if(now_group != Traverse_List[i][1])
            printf("\n%d",++now_group);

        printf(" %d",Traverse_List[i][0]);
    }
    
    //*/
    return 0;
}