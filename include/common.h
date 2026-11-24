#ifndef COMMON_H
#define COMMON_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

#define IPC_PERMS 0600


#define MASS_P1 1
#define MASS_P2 2
#define MASS_P3 3
#define MASS_P4 3

#define MAX_BELT_SIZE 1000

typedef struct {
    int station_id;
    int mass;
} BeltItem;

typedef struct {
    int cap_P;
    int belt_K;
    int belt_M;

    int truck_L;
    int trucks_N;

    int count_p1;
    int count_p2;
    int count_p3;
    int count_p4;
    int mag_used_units;

    BeltItem belt[MAX_BELT_SIZE];
    int belt_count;
    int belt_current_mass;
    int belt_head;
    int belt_tail;

    bool stop_warehouse;     
    bool stop_s1;        
    bool stop_s2;      
    bool force_truck_leave;
    int total_produced;      
} FactoryState;



#endif