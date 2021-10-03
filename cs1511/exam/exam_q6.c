#include <stdio.h>
#include <stdlib.h>

struct station {
    int station_num;
    struct station *next;
    struct train *trains;
};

struct train {
    int train_num;
    int count;
    struct train *next;
};

struct station *create_station(int num, struct station *next);
struct train *create_train(int num, struct train *next);
void add_train_station(struct station *curr_station, int train_num, int sta_num);
void move_train(struct station *curr_station);
void print_list(struct station *head);

int main(void) {
    int sta_num = 0;
    int train_num = 0;
    struct station *station_head = create_station(3, NULL);
    station_head = create_station(2, station_head);
    station_head = create_station(1, station_head);
    struct station *curr_station = station_head;
    while (scanf("%d %d", &sta_num, &train_num) == 2) {
        add_train_station(curr_station, train_num, sta_num);
        // check muliple train nums then move them as needed
    }
    print_list(station_head);
    return 0;
}

struct station *create_station(int num, struct station *next) {
    struct station *new_station = malloc(sizeof(struct station));
    new_station->station_num = num;
    new_station->next = next;
    new_station->trains = NULL;
    return new_station;
}

struct train *create_train(int num, struct train *next) {
    struct train *new_train = malloc(sizeof(struct train));
    new_train->train_num = num;
    new_train->count = 0;
    new_train->next = next;
    return new_train;
}

void print_list(struct station *head) {
    struct station *curr = head;
    struct train *curr_t = curr->trains;
    while (curr != NULL) {
        curr_t = curr->trains;
        printf("STATION %d\n", curr->station_num);
        while (curr_t != NULL) {
            printf("Train num: %d\n", curr_t->train_num);
            curr_t = curr_t->next;
        }
        curr = curr->next;
    }
}

void add_train_station(struct station *curr_station, int train_num, int sta_num) {
    while (curr_station != NULL) {
        struct train *train_head = curr_station->trains;
        if (curr_station->station_num == sta_num) {
            if (train_head == NULL) {
                train_head = create_train(train_num, NULL);
                curr_station->trains = train_head;
            } else {
                train_head->next = create_train(train_num, NULL);
            }  
        }
        curr_station = curr_station->next;
    }
}

void move_train(struct station *curr_station) {
    
}




