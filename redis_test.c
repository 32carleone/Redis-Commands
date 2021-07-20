#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <hiredis/hiredis.h>
#include "redis.h"

/*
    Author  : Yunus Can
    Website : www.yunuscan.xyz
    Mail    : info@yunuscan.xyz
    Date    : 20/07/2021
*/

int i;
redisReply *redis_response;


int main (int argc, char *argv[]) {
   
    printf(" ***** REDİS ****\n");

    redis_connect("127.0.0.1",6379);


    redis_select(0);
    redis_set("yunus","CAN");
    redis_set("user1","Ahmet");
    redis_set("user2","Mehmet");

    printf(" --- GET ---\n");
    redis_response = redis_get("yunus");
    if(redis_response != NULL){
        if(redis_response->str != NULL){
            printf("yunus : %s \n", redis_response->str); 
            freeReplyObject(redis_response);
        }
    }


    printf("\n --- KEYS 'user*' ---\n");
    redis_response = redis_keys("user*");
    if(redis_response != NULL){
        for (i = 0; i < redis_response->elements;i++ ) {
            printf( "KEY : %s \n", redis_response->element[i]->str );
        }

        freeReplyObject(redis_response);
    }


    printf("\n --- GET ---\n");
    redis_select(1);
    redis_response = redis_get("yunus");
    if(redis_response != NULL){
        if(redis_response->str != NULL){
            printf("yunus : %s \n", redis_response->str); 
            freeReplyObject(redis_response);
        }else{
             printf("yunus redis db 2 is null \n");
        }
    }







    printf("\n\n ***** HASHES ****\n");
    redis_hset("users","user3","Yunus");
    redis_hset("users","user4","Ali");
    redis_hset("users","user5","Osman");


    printf(" --- HGET ---\n");
    redis_response = redis_hget("users","user3");
    if(redis_response != NULL){
        if(redis_response->str != NULL){
            printf("user3 : %s \n", redis_response->str); 
            freeReplyObject(redis_response);
        }
    }


    printf("\n --- HGETALL ---\n");
    redis_response = redis_hgetall("users");
    if(redis_response != NULL){
        for (i = 0; i < redis_response->elements;i++ ) {
            printf( "HGETALL : %s \n", redis_response->element[i]->str );
        }

        freeReplyObject(redis_response);
    }


    printf("\n --- HKEYS ---\n");
    redis_response = redis_hkeys("users");
    if(redis_response != NULL){
        for (i = 0; i < redis_response->elements;i++ ) {
            printf( "HKEYS : %s \n", redis_response->element[i]->str );
        }

        freeReplyObject(redis_response);
    }



    



   return(0);
}