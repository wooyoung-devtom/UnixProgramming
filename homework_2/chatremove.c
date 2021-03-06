// chatremove.c -- CP33357 assignment 2, Spring 2020
// Choi Woo Young, id #201524600, section 059, TAK. SUNG WOO


#include "mychatheader.h"

void chat_remove() {
    int shm_id;         // Shared memory id

    /* get shared memory's id */
    shm_id = shmget((key_t) 20200406, sizeof(CHAT_INFO), SHM_RW_FLAG);

    /* If error is occured... */
    if (shm_id < 0) {
        printf("Cannot found Shared Memory\n");
        perror("shmget failed: ");
        exit(EXIT_STATUS);
    }

    /* If Failed to delete Shared Memory */
    if(shmctl(shm_id, IPC_RMID, 0) < 0) {
        printf("Failed to delete shared memory\n");
        exit(EXIT_STATUS);
    } else {
        printf("Successfully delete shared memory\n");
    }
}