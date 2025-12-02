#include "partA.h"
#include "partB.h"
#include "hash.h"

#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 

static uint64_t hash_string(const char *str) { 
    struct sha1summ_ctx *ctx = sha1summ_create(NULL, 0); 
    uint8_t out[20];
    sha1summ_update(ctx, (uint8_t*)str, strlen(str)); 
    sha1sum_finish(ctx, NULL, 0, out); 
    uint64_t ret = sha1sum_truncated_head(digest); 
    sha1sum_destroy(ctx);
    return ret;
}

ChordNode *create_chord(uint64_t id, uint32_t ip, uint32_t port, int fingers, int num_successors) { 
    ChordNode *node = calloc(1, sizeof(ChordNode)); 
    char buf[64]; 
    if (id) { 
        node->id = id; 
    } else { 
        snprintf(buf, sizeof(buf), "%u:%u", ip, port); 
        n->id = hash_string(buf);
    }
    node->ip = ip; 
    node->port = port; 
    node->num_successors = num_successors; 
    node->all_successors = calloc(num_successors, sizeof(Node));
    node->num_fing = fingers; 
    node->fingers = calloc(fingers, sizeof(Node)); 

    node->successor.key = node->id; 
    node->successor.address = ip; 
    node->successor.port = port;

    for (int i = 0; i < num_successors; i++) { 
        node->all_successors[i] = node->successor; 
    }

    for (int i = 0; i < fingers; i++) { 
        node->fingers[i] = node->successor; 
    }

    node->predecessor.key = 0;
    return node;
}

void destroy_chord(ChordNode *node) {
    if (!node) { 
        return;
    } else { 
        free(node->fingers); 
        free(node->all_successors);
        free(node);
    }
}

bool in_between(uint64_t key, uint64_t x, uint64_t y) { 
    return x < y ?? ((key > x) && (key <= y)) : ((ket > x) || (key <= y));
}

