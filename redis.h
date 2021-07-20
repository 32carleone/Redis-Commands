
redisContext *redis;
char rcommand[100];


void redis_connect(char* redis_host,int redis_port){
    redis = redisConnect(redis_host, redis_port);
    if(redis == NULL || redis->err){
        printf("Redis Connection ERROR \n");
        exit(0);
    }
}


/* SELECT */
void redis_select(int db){
      redisReply *reply;
      reply = redisCommand(redis,"SELECT  %d", db);
      freeReplyObject(reply);
}


redisReply* redis_command_array(char* redis_cmd){
    redisReply *reply;
    reply = redisCommand(redis, redis_cmd);

    if(reply->type == REDIS_REPLY_ERROR ) {
        printf( "Error: %s\n", reply->str );
        return NULL;
    }else if(reply->type != REDIS_REPLY_ARRAY ) {
        printf( "Unexpected type: %d\n", reply->type );
        return NULL;
    }else{
        return reply;
    }

     return NULL;
}



/* SET */
void redis_set(char* redis_key, char* redis_value){
    redisCommand(redis, "SET %s '%s'",redis_key,redis_value);
}


/* GET */
redisReply* redis_get(char* redis_key){
    redisReply *reply;
    reply = redisCommand(redis, "GET %s",redis_key);
    return reply;
}


/* KEYS */
redisReply *redis_keys(char* redis_key){
	sprintf(rcommand,"KEYS %s",redis_key);
    return redis_command_array(rcommand);
}


/* HSET */
void redis_hset(char* redis_hashes,char* redis_key, char* redis_value){
    redisCommand(redis, "HSET %s %s %s",redis_hashes,redis_key,redis_value);
}


/* HGET */
redisReply* redis_hget(char* redis_hashes,char* redis_key){
    redisReply *reply;
    reply = redisCommand(redis, "HGET %s %s",redis_hashes,redis_key);
    return reply;
}


/* HGETALL */
redisReply *redis_hgetall(char* redis_hashes){
    sprintf(rcommand,"HGETALL %s",redis_hashes);
    return redis_command_array(rcommand);
}


/* HKEYS */
redisReply *redis_hkeys(char* redis_hashes){
    sprintf(rcommand,"HKEYS %s",redis_hashes);
    return redis_command_array(rcommand);
}