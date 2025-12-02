#ifndef PARTB_H 
#define PARTB_H

#include <stdint.h> 
#include <stdbool.h> 
#include "chord.pb-c.h" // Combined protobuf definition of msgs in chord.proto

typedef struct ChordNode { 
    uint64_t id; 
    uint32_t ip;
    uint32_t port; 
    Node predecessor;
    Node successor;
    int num_successors; 
    Node *all_successors; 
    int num_fing; 
    Node *fingers;
} ChordNode; 

ChordNode *create_chord(uint64_t id, uint32_t ip, uint32_t port, int fingers, int num_successors); 
void destroy_chord(ChordNode *node); 
bool in_between(uint64_t key, uint64_t x, uint64_t y); 
Node find_successor_of_chord(ChordNode *self, uint64_t key); 
Node closest_preceding_node(ChordNode *self, uint64_t key);
void stabilize_chord(ChordNode *self); // --sp Arg  
void notify_chord(ChordNode *self, Node pred); 
void fix_fingers(ChordNode *self); // --ffp Arg
void check_predecessor_of_chord(ChordNode *self); // --cpp Arg 
void update_successor_list(ChordNode *self);
void print_state(ChordNode *self); 

#endif