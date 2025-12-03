#ifndef PARTA_H 
#define PARTA_H

#include <stdint.h> 
#include <stdbool.h> 
#include "chord.pb-c.h" // Combined protobuf definition of msgs in chord.proto

/* Added some basic Remote Procedure Call (RPC) headers bc i need to use these too */
Node find_successor(Node target, uint64_t key); 
int get_successor_list(Node target, Node *buf, int max_len); // Gets a node's successor list 

Node get_predecessor(Node target); // Gets the pred Node 
bool check_predecessor(Node target); // Check's if pred is alive 
void notify (Node target, Node self); // Sends a notify rpc to target

#endif 
