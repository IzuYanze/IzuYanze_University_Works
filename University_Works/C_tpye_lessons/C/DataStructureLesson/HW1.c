#include <stdio.h>

int main(){

    int null;
    //general statitics inputs
    int nodes, links, requests;
    scanf("%d %d %d", &nodes, &links, &requests);

    struct node{
        int node_id;
        int memory_space;
        int Channels[nodes];//to store the channels numbers, -1 if not connected
        int parent;//to record the parent node
    } Network[nodes];

    struct req{
        int request_id;
        int accept; // accept = 1, not accept = 0
        int source;
        int destiny;
        int points; // number of nodes in the route
        int Path[nodes]; 
    } Request[requests];

    //input node info
    for(int i=0; i<nodes; i++){
        scanf("%d %d", &Network[i].node_id, &Network[i].memory_space);
        for(int j=0; j<nodes; j++) // initialize the channels
            Network[i].Channels[j] = 0;
    }

    //input link info
    for(int i=0; i<links; i++){
        int node_a, node_b, channel;
        scanf("%d %d %d %d", &null, &node_a, &node_b, &channel);
        Network[node_a].Channels[node_b] = Network[node_b].Channels[node_a] = channel;
    }

    //BFS
    for(int now_request = 0; now_request < requests; now_request++){
        //initialization
        int Visit[nodes];
        for(int i=0;i<nodes;i++) //reset the visit map
            Visit[i] = -1;
        for(int i=0;i<nodes;i++)
            Network[i].parent = -1;

        int find_path = 0;
        scanf("%d %d %d", &Request[now_request].request_id, &Request[now_request].source, &Request[now_request].destiny);
        Visit[Request[now_request].source] = 0;
        Request[now_request].Path[0] = Request[now_request].source;
        Request[now_request].points = 0;

        /*
        //ck
        printf("src = %d, dst = %d",Request[now_request].source, Request[now_request].destiny);
        printf("==%d==\n",now_request);
        //*/

        while (!find_path){
            for(int now_node = 0; now_node < nodes; now_node++){
                if(Visit[now_node])
                    continue;
                for(int neighbor = 0; neighbor < nodes; neighbor++ ){
                    if(Visit[neighbor] != -1)//if visit, skip
                        continue;

                    Network[neighbor].parent = now_node;
                    Visit[neighbor] = nodes;
                    if(neighbor == Request[now_request].destiny){
                        find_path = 1;
                        break;
                    }
                }
                Visit[now_node] = 1;
                if(!find_path)
                    break;
            }
            for(int i=0;i<nodes;i++){
                if(Visit[i] == nodes)
                    Visit[i] = 0;
            }
            if(!find_path)
                break;
        }
        
            
        int node_ptr = Request[now_request].destiny ;
        for(; node_ptr != Request[now_request].source; Request[now_request].points++ )
            node_ptr = Network[node_ptr].parent;

        node_ptr = Request[now_request].destiny;

        for(int i = Request[now_request].points; i > 0; i-- ){
            Request[now_request].Path[i] = node_ptr;
            node_ptr = Network[node_ptr].parent;
        }
        Request[now_request].accept = 1;
        /*
        //ck
        for(int i=0;i<nodes;i++)
            printf("%d ",Request[now_request].Path[i]);
        //*/
    }


    //check the acception
    int accept_req = 0;
    for(int now_request = 0; now_request < requests; now_request++ ){

        //if src & dst memory not enough, no accept
        if( !Network[Request[now_request].source].memory_space || !Network[Request[now_request].destiny].memory_space )
            Request[now_request].accept = 0;

        //if middle memory not enough, no accept
        for(int i=1; i<Request[now_request].points; i++)
            if(Network[Request[now_request].Path[i]].memory_space < 2)
                Request[now_request].accept = 0;
        
        //if channel not enough, no accept
        for(int i=0; i<Request[now_request].points; i++)
            if( Network[Request[now_request].Path[i]].Channels[Request[now_request].Path[i+1]] < 1 )
                Request[now_request].accept = 0;

        if(Request[now_request].accept){
            accept_req ++;

            //src & dst memory -1
            Network[Request[now_request].source].memory_space --;
            Network[Request[now_request].destiny].memory_space --;

            //middle memory -2
            for(int i=1; i<Request[now_request].points; i++)
                Network[Request[now_request].Path[i]].memory_space -= 2;

            //channel -1
            for(int i=0; i<Request[now_request].points; i++){
                Network[Request[now_request].Path[i]].Channels[Request[now_request].Path[i+1]] --;
                Network[Request[now_request].Path[i+1]].Channels[Request[now_request].Path[i]] --;
            }
        }
        /* test
        printf("---request %d---\n",now_request);
        for(int i=0;i<nodes;i++){
            printf("At node %d:",i);
            for(int j=0;j<nodes;j++){
                printf(" {%d's mem: %d}",j,Network[i].Channels[j]);
            }
            printf("\n");
        }
        printf("Path :");
        for(int i=0;i<=Request[now_request].points;i++)
            printf(" %d",Request[now_request].Path[i]);
        printf("\n---request %d---\n",now_request);
        //*/
    }

    //Output
    printf("%d\n",accept_req);
    for(int now_request = 0; now_request < requests; now_request++ ){
        if(Request[now_request].accept){
            printf("%d",Request[now_request].request_id);
            for(int i=0; i<=Request[now_request].points;i++){
                printf(" %d",Request[now_request].Path[i]);
            }
            printf("\n");
        }
    }

    return 0;
}