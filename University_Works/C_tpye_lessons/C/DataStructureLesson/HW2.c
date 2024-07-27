#include <stdio.h>
#include <string.h>

int resource_x, resource_y, users;

const char* Shape_name(int x){//to output the text of shape of the input
    switch (x){
    case 0:
        return "16x1";
    case 1:
        return "8x2";
    case 2:
        return "4x4";
    case 3:
        return "2x8";
    case 4:
        return "1x16";

    default:
        return "ㄐㄐ";
    }
}

int Shape_input(char *s, int list[5]){//to store the shape kinds
    int id;
    sscanf( s, "%d ", &id);
    if(strstr(s,"16x1")!= NULL)
        list[0] = 1;
    if(strstr(s,"8x2")!= NULL)
        list[1] = 1;
    if(strstr(s,"4x4")!= NULL)
        list[2] = 1;
    if(strstr(s,"2x8")!= NULL)
        list[3] = 1;
    if(strstr(s,"1x16")!= NULL)
        list[4] = 1;
    return id;
}

int Check_if_valid(int anchor_x, int anchor_y, int shape_kind){//check if the shape can put it at the anchor point
    switch (shape_kind){
    case 0:
        anchor_x += 0;
        anchor_y +=15;
        break;
    case 1:
        anchor_x += 1;
        anchor_y += 7;
        break;
    case 2:
        anchor_x += 3;
        anchor_y += 3;
        break;
    case 3:
        anchor_x += 7;
        anchor_y += 1;
        break;
    case 4:
        anchor_x +=15;
        anchor_y += 0;
        break;
    default:
        break;
    }
    if( anchor_x < resource_x && anchor_y < resource_y )
        return 1;
    return 0;
}

int main(){

    //input general data
    char temp[32];
    fgets( temp, 32, stdin);
    sscanf( temp, "%d %d %d", &resource_y, &resource_x, &users );

    struct shapes{
        int user_id;
        int accepted;
        int Shape[5];      // /1*16\ /2*8 \ /4*4 \ /8*2 \ /16*1\ //
        int chosen_shape;  // \0   / \1   / \2   / \3   / \4   / //
        int position_x;
        int position_y;
    } User[users];
    

    //input user data
    for( int i = 0; i < users; i++ ){ 

        //initializations
        User[i].accepted = 0;
        for(int j = 0; j < 5; j++)
            User[i].Shape[j] = 0;

        fgets( temp, 32, stdin ); //read one line to temp
        User[i].user_id = Shape_input( temp, User[i].Shape );
        
    }

    /*check
    for(int i=0;i<users;i++)
        printf("%d:[%d,%d,%d,%d,%d]\n",User[i].user_id,User[i].Shape[0],User[i].Shape[1],User[i].Shape[2],User[i].Shape[3],User[i].Shape[4]);
    
    //*/
    //check finished

    int anchor_x = 0, anchor_y = 0, accept_users = 0;//start from the left-lower point
    for(int now_user = 0; now_user < users; now_user ++){//from first user to last one
        int shape_width = 1;//to record the width of the shape in order to move anchor point
        for(int now_shape = 0; now_shape < 5; now_shape++){//from thinnest shape the fattest shape
            if(User[now_user].Shape[now_shape]){//if this user has this shape 
                if(Check_if_valid(anchor_x, anchor_y, now_shape)){//if this shape can put inside
                    accept_users++; //increase the nums of accepted user
                    User[now_user].accepted = 1;//accept this user
                    User[now_user].chosen_shape = now_shape; //this user use this shape
                    User[now_user].position_x = anchor_x; //record the anchor
                    User[now_user].position_y = anchor_y;
                    anchor_x += shape_width; //move anchor
                    break; //jump out the choosing loop to next user
                }
            }
            shape_width *= 2;
        }
        if(anchor_x >= resource_x && !User[now_user].accepted){//if reach the max of resourse width, jump upper 16 px and start from 0 again.
            anchor_y += 16;
            anchor_x = 0;
        }
    }

    //output data
    printf( "%d\n", accept_users );
    for(int i = 0; i < users; i++){
        if(User[i].accepted)
            printf("%d %s %d %d\n", User[i].user_id, Shape_name(User[i].chosen_shape), User[i].position_y, User[i].position_x);
    }

    return 0;
}