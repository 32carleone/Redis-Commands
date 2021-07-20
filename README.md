# Redis-Commands
**Language** : C\
**Os** : Freebsd 13\
**Compiler** : gcc
## * Install and Build
1- pkg install redis\
2- pkg install hiredis\
3- service redis onestart\
4- gcc redis_test.c -lhiredis -o redis_test\
5- ./redis_test
## * Redis Commands
```ruby
redis_connect(string server,int port)
redis_select(int db)
redis_set(string key,string value)
redis_get(string key)
redis_hset(string hashes,string key,string value)
redis_hget(string hashes,string key)
redis_hgetall(string hashes)
redis_hkeys(string hashes)
```
![alt text](http://yunuscan.xyz/images/github/redis-commands.png)
-

