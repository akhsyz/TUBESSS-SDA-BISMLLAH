#include <stdio.h>
#include <string.h>
#include "templatebagan.h"

void templatebagan4tim(char teams[][50], int scores[], char* winner) {
    printf("BIGETRON : %d\n", scores[0]);
    printf("\t\t|--> BIGETRON : %d\n", scores[0]);
    printf("ONIC     : %d\n", scores[1]);
    printf("\t\t\t\t|--> %s\n", winner);
    printf("AEROWOLF : %d\n", scores[2]);
    printf("\t\t|--> RRQ      : %d\n", scores[3]);
    printf("RRQ      : %d\n\n", scores[3]);

    printf("TIM 1 : %s\n", teams[0]);
    printf("TIM 2 : %s\n", teams[1]);
    printf("TIM 3 : %s\n", teams[2]);
    printf("TIM 4 : %s\n", teams[3]);

    printf("Pertandingan 1 : %s vs %s\n", teams[0], teams[1]);
    printf("Pertandingan 2 : %s vs %s\n", teams[2], teams[3]);
    printf("Pertandingan 3 : %s vs %s\n", winner, teams[3]);
    printf("Winner : %s\n", winner);
}

void templatebagan5tim(char teams[][50], int scores[], char* winner) {
    printf("BIGETRON : %d\n", scores[0]);
    printf("\t\t|--> BIGETRON : %d\n", scores[0]);
    printf("ONIC     : %d\n", scores[1]);
    printf("\t\t\t    |--> BIGETRON : %d\n", scores[0]);
    printf("\t\t     AEROWOLF : %d\n", scores[2]);
    printf("\t\t\t\t\t\t|--> %s\n", winner);
    printf("\t\t     RRQ      : %d\n", scores[3]);
    printf("\t\t\t    |--> RRQ      : %d\n", scores[3]);
    printf("\t\t     EVOS     : %d\n", scores[4]);

    printf("TIM 1 : %s\n", teams[0]);
    printf("TIM 2 : %s\n", teams[1]);
    printf("TIM 3 : %s\n", teams[2]);
    printf("TIM 4 : %s\n", teams[3]);
    printf("TIM 5 : %s\n", teams[4]);

    printf("Pertandingan 1 : %s vs %s\n", teams[0], teams[1]);
    printf("Pertandingan 2 : %s vs %s\n", teams[0], teams[2]);
    printf("Pertandingan 3 : %s vs %s\n", teams[3], teams[4]);
    printf("Pertandingan 4 : %s vs %s\n", teams[0], teams[3]);
    printf("Winner : %s\n", winner);
}

void templatebagan6tim(char teams[][50], int scores[], char* winner) {
    printf("BIGETRON : %d\n", scores[0]);
    printf("\t\t|--> BIGETRON : %d\n", scores[0]);
    printf("ONIC     : %d\n", scores[1]);
    printf("\t\t\t    |--> BIGETRON : %d\n", scores[0]);
    printf("\t\t     EVOS     : %d\n", scores[4]);
    printf("AEROWOLF : %d\n", scores[2]);
    printf("\t\t\t\t\t\t|--> %s\n", winner);
    printf("\t\t|--> RRQ      : %d\n", scores[3]);
    printf("RRQ      : %d\n", scores[3]);
    printf("\t\t\t    |--> BOOM     : %d\n", scores[5]);
    printf("\t\t     BOOM     : %d\n", scores[5]);

    printf("TIM 1 : %s\n", teams[0]);
    printf("TIM 2 : %s\n", teams[1]);
    printf("TIM 3 : %s\n", teams[2]);
    printf("TIM 4 : %s\n", teams[3]);
    printf("TIM 5 : %s\n", teams[4]);
    printf("TIM 6 : %s\n", teams[5]);

    printf("Pertandingan 1 : %s vs %s\n", teams[0], teams[1]);
    printf("Pertandingan 2 : %s vs %s\n", teams[2], teams[3]);
    printf("Pertandingan 3 : %s vs %s\n", teams[0], teams[4]);
    printf("Pertandingan 4 : %s vs %s\n", teams[3], teams[5]);
    printf("Pertandingan 5 : %s vs %s\n", teams[0], teams[5]);
    printf("Winner : %s\n", winner);
}

void templatebagan7tim(char teams[][50], int scores[], char* winner) {
    printf("BIGETRON : %d\n", scores[0]);
    printf("\t\t|--> BIGETRON : %d\n", scores[0]);
    printf("ONIC     : %d\n", scores[1]);
    printf("\t\t\t    |--> BIGETRON : %d\n", scores[0]);
    printf("\t\t     AURA     : %d\n", scores[6]);
    printf("AEROWOLF : %d\n", scores[2]);
    printf("\t\t\t\t\t\t|--> %s\n", winner);
    printf("\t\t|--> RRQ      : %d\n", scores[3]);
    printf("RRQ      : %d\n", scores[3]);
    printf("\t\t\t    |--> RRQ      : %d\n", scores[3]);
    printf("EVOS     : %d\n", scores[4]);
    printf("\t\t|--> BOOM     : %d\n", scores[5]);
    printf("BOOM     : %d\n", scores[5]);

    printf("TIM 1 : %s\n", teams[0]);
    printf("TIM 2 : %s\n", teams[1]);
    printf("TIM 3 : %s\n", teams[2]);
    printf("TIM 4 : %s\n", teams[3]);
    printf("TIM 5 : %s\n", teams[4]);
    printf("TIM 6 : %s\n", teams[5]);
    printf("TIM 7 : %s\n", teams[6]);

    printf("Pertandingan 1 : %s vs %s\n", teams[0], teams[1]);
    printf("Pertandingan 2 : %s vs %s\n", teams[2], teams[3]);
    printf("Pertandingan 3 : %s vs %s\n", teams[4], teams[5]);
    printf("Pertandingan 4 : %s vs %s\n", teams[0], teams[6]);
    printf("Pertandingan 5 : %s vs %s\n", teams[3], teams[5]);
    printf("Pertandingan 6 : %s vs %s\n", teams[0], teams[3]);
    printf("Winner : %s\n", winner);
}

void templatebagan8tim(char teams[][50], int scores[], char* winner) {
    printf("BIGETRON : %d\n", scores[0]);
    printf("\t\t|--> BIGETRON : %d\n", scores[0]);
    printf("ONIC     : %d\n", scores[1]);
    printf("\t\t\t\t    |--> BIGETRON : %d\n", scores[0]);
    printf("AEROWOLF : %d\n", scores[2]);
    printf("\t\t|--> AEROWOLF : %d\n", scores[2]);
    printf("RRQ      : %d\n", scores[3]);
    printf("\t\t\t\t\t\t    |--> %s\n", winner);
    printf("EVOS     : %d\n", scores[4]);
    printf("\t\t|--> EVOS     : %d\n", scores[4]);
    printf("BOOM     : %d\n", scores[5]);
    printf("\t\t\t\t    |--> EVOS     : %d\n", scores[4]);
    printf("AURA     : %d\n", scores[6]);
    printf("\t\t|--> GEEKFAM  : %d\n", scores[7]);
    printf("GEEKFAM  : %d\n", scores[7]);

    printf("TIM 1 : %s\n", teams[0]);
    printf("TIM 2 : %s\n", teams[1]);
    printf("TIM 3 : %s\n", teams[2]);
    printf("TIM 4 : %s\n", teams[3]);
    printf("TIM 5 : %s\n", teams[4]);
    printf("TIM 6 : %s\n", teams[5]);
    printf("TIM 7 : %s\n", teams[6]);
    printf("TIM 8 : %s\n", teams[7]);

    printf("Pertandingan 1 : %s vs %s\n", teams[0], teams[1]);
    printf("Pertandingan 2 : %s vs %s\n", teams[2], teams[3]);
    printf("Pertandingan 3 : %s vs %s\n", teams[4], teams[5]);
    printf("Pertandingan 4 : %s vs %s\n", teams[6], teams[7]);
    printf("Pertandingan 5 : %s vs %s\n", teams[0], teams[2]);
    printf("Pertandingan 6 : %s vs %s\n", teams[4], teams[7]);
    printf("Pertandingan 7 : %s vs %s\n", teams[0], teams[4]);
    printf("Winner : %s\n", winner);
}

void templatebagan9tim(char teams[][50], int scores[], char* winner) {
    printf("BIGETRON : %d\n", scores[0]);
    printf("\t\t|--> BIGETRON : %d\n", scores[0]);
    printf("ONIC     : %d\n", scores[1]);
    printf("\t\t\t    |--> BIGETRON : %d\n", scores[0]);
    printf("\t\t     AEROWOLF : %d\n", scores[2]);
    printf("\t\t\t\t\t\t|--> %s\n", winner);
    printf("\t\t     RRQ      : %d\n", scores[3]);
    printf("\t\t\t    |--> EVOS     : %d\n", scores[4]);
    printf("\t\t     EVOS     : %d\n", scores[4]);
    printf("\t\t\t\t\t\t    |--> BIGETRON\n");
    printf("\t\t     BOOM     : %d\n", scores[5]);
    printf("\t\t\t    |--> AURA     : %d\n", scores[6]);
    printf("\t\t     AURA     : %d\n", scores[6]);
    printf("\t\t\t\t\t\t    |--> GEEKFAM  : %d\n");
    printf("\t\t     GEEKFAM  : %d\n", scores[7]);
    printf("\t\t\t    |--> GEEKFAM  : %d\n", scores[7]);
    printf("\t\t     ALTEREGO : %d\n", scores[8]);

    printf("TIM 1 : %s\n", teams[0]);
    printf("TIM 2 : %s\n", teams[1]);
    printf("TIM 3 : %s\n", teams[2]);
    printf("TIM 4 : %s\n", teams[3]);
    printf("TIM 5 : %s\n", teams[4]);
    printf("TIM 6 : %s\n", teams[5]);
    printf("TIM 7 : %s\n", teams[6]);
    printf("TIM 8 : %s\n", teams[7]);
    printf("TIM 9 : %s\n", teams[8]);

    printf("Pertandingan 1 : %s vs %s\n", teams[0], teams[1]);
    printf("Pertandingan 2 : %s vs %s\n", teams[0], teams[2]);
    printf("Pertandingan 3 : %s vs %s\n", teams[3], teams[4]);
    printf("Pertandingan 4 : %s vs %s\n", teams[5], teams[6]);
    printf("Pertandingan 5 : %s vs %s\n", teams[7], teams[8]);
    printf("Pertandingan 6 : %s vs %s\n", teams[0], teams[4]);
    printf("Pertandingan 7 : %s vs %s\n", teams[6], teams[7]);
    printf("Pertandingan 8 : %s vs %s\n", teams[0], teams[7]);
    printf("Winner : %s\n", winner);
}

void templatebagan10tim(char teams[][50], int scores[], char* winner) {
    printf("BIGETRON : %d\n", scores[0]);
    printf("\t\t|--> BIGETRON : %d\n", scores[0]);
    printf("ONIC     : %d\n", scores[1]);
    printf("\t\t\t    |--> BIGETRON : %d\n", scores[0]);
    printf("\t\t     EVOS     : %d\n", scores[4]);
    printf("\t\t\t\t\t\t|--> %s\n", winner);
    printf("\t\t     BOOM     : %d\n", scores[5]);
    printf("\t\t\t    |--> AURA     : %d\n", scores[6]);
    printf("\t\t     AURA     : %d\n", scores[6]);
    printf("AEROWOLF : %d\n", scores[2]);
    printf("\t\t\t\t\t\t    |--> BIGETRON\n");
    printf("\t\t|--> AEROWOLF : %d\n", scores[2]);
    printf("RRQ      : %d\n", scores[3]);
    printf("\t\t\t    |--> AEROWOLF : %d\n", scores[2]);
    printf("\t\t     GEEKFAM  : %d\n", scores[7]);
    printf("\t\t\t\t\t\t    |--> SIREN    : %d\n");
    printf("\t\t     ALTEREGO : %d\n", scores[8]);
    printf("\t\t\t    |--> SIREN    : %d\n", scores[9]);
    printf("\t\t     SIREN    : %d\n", scores[9]);

    printf("TIM 1 : %s\n", teams[0]);
    printf("TIM 2 : %s\n", teams[1]);
    printf("TIM 3 : %s\n", teams[2]);
    printf("TIM 4 : %s\n", teams[3]);
    printf("TIM 5 : %s\n", teams[4]);
    printf("TIM 6 : %s\n", teams[5]);
    printf("TIM 7 : %s\n", teams[6]);
    printf("TIM 8 : %s\n", teams[7]);
    printf("TIM 9 : %s\n", teams[8]);
    printf("TIM 10 : %s\n", teams[9]);

    printf("Pertandingan 1 : %s vs %s\n", teams[0], teams[1]);
    printf("Pertandingan 2 : %s vs %s\n", teams[2], teams[3]);
    printf("Pertandingan 3 : %s vs %s\n", teams[0], teams[4]);
    printf("Pertandingan 4 : %s vs %s\n", teams[5], teams[6]);
    printf("Pertandingan 5 : %s vs %s\n", teams[2], teams[7]);
    printf("Pertandingan 6 : %s vs %s\n", teams[8], teams[9]);
    printf("Pertandingan 7 : %s vs %s\n", teams[0], teams[6]);
    printf("Pertandingan 8 : %s vs %s\n", teams[2], teams[9]);
    printf("Pertandingan 9 : %s vs %s\n", teams[0], teams[9]);
    printf("Winner : %s\n", winner);
}

void templatebagan11tim(char teams[][50], int scores[], char* winner) {
    printf("BIGETRON : %d\n", scores[0]);
    printf("\t\t|--> BIGETRON : %d\n", scores[0]);
    printf("ONIC     : %d\n", scores[1]);
    printf("\t\t\t    |--> BIGETRON : %d\n", scores[0]);
    printf("\t\t     AURA     : %d\n", scores[6]);
    printf("\t\t\t\t\t\t|--> %s\n", winner);
    printf("\t\t     GEEKFAM  : %d\n", scores[7]);
    printf("\t\t\t    |--> GEEKFAM  : %d\n", scores[7]);
    printf("\t\t     ALTEREGO : %d\n", scores[8]);
    printf("AEROWOLF : %d\n", scores[2]);
    printf("\t\t\t\t\t\t    |--> BIGETRON\n");
    printf("\t\t|--> AEROWOLF : %d\n", scores[2]);
    printf("RRQ      : %d\n", scores[3]);
    printf("\t\t\t    |--> AEROWOLF : %d\n", scores[2]);
    printf("\t\t     SIREN    : %d\n", scores[9]);
    printf("EVOS     : %d\n", scores[4]);
    printf("\t\t\t\t\t\t    |--> HFX      : %d\n");
    printf("\t\t|--> EVOS     : %d\n", scores[4]);
    printf("BOOM     : %d\n", scores[5]);
    printf("\t\t\t    |--> HFX      : %d\n", scores[10]);
    printf("\t\t     HFX      : %d\n", scores[10]);

    printf("TIM 1 : %s\n", teams[0]);
    printf("TIM 2 : %s\n", teams[1]);
    printf("TIM 3 : %s\n", teams[2]);
    printf("TIM 4 : %s\n", teams[3]);
    printf("TIM 5 : %s\n", teams[4]);
    printf("TIM 6 : %s\n", teams[5]);
    printf("TIM 7 : %s\n", teams[6]);
    printf("TIM 8 : %s\n", teams[7]);
    printf("TIM 9 : %s\n", teams[8]);
    printf("TIM 10 : %s\n", teams[9]);
    printf("TIM 11 : %s\n", teams[10]);

    printf("Pertandingan 1 : %s vs %s\n", teams[0], teams[1]);
    printf("Pertandingan 2 : %s vs %s\n", teams[2], teams[3]);
    printf("Pertandingan 3 : %s vs %s\n", teams[4], teams[5]);
    printf("Pertandingan 4 : %s vs %s\n", teams[0], teams[6]);
    printf("Pertandingan 5 : %s vs %s\n", teams[7], teams[8]);
    printf("Pertandingan 6 : %s vs %s\n", teams[2], teams[9]);
    printf("Pertandingan 7 : %s vs %s\n", teams[4], teams[10]);
    printf("Pertandingan 8 : %s vs %s\n", teams[0], teams[7]);
    printf("Pertandingan 9 : %s vs %s\n", teams[2], teams[10]);
    printf("Winner : %s\n", winner);
}

void templatebagan12tim(char teams[][50], int scores[], char* winner) {
    printf("BIGETRON : %d\n", scores[0]);
    printf("\t\t|--> BIGETRON : %d\n", scores[0]);
    printf("ONIC     : %d\n", scores[1]);
    printf("\t\t\t    |--> BIGETRON : %d\n", scores[0]);
    printf("\t\t     SIREN    : %d\n", scores[9]);
    printf("AEROWOLF : %d\n", scores[2]);
    printf("\t\t\t\t\t\t|--> %s\n", winner);
    printf("\t\t|--> AEROWOLF : %d\n", scores[2]);
    printf("RRQ      : %d\n", scores[3]);
    printf("\t\t\t    |--> ALTEREGO : %d\n", scores[8]);
    printf("\t\t     ALTEREGO : %d\n", scores[8]);
    printf("EVOS     : %d\n", scores[4]);
    printf("\t\t\t\t\t\t    |--> BIGETRON\n");
    printf("\t\t|--> BOOM     : %d\n", scores[5]);
    printf("BOOM     : %d\n", scores[5]);
    printf("\t\t\t    |--> BOOM     : %d\n", scores[5]);
    printf("\t\t     HFX      : %d\n", scores[10]);
    printf("AURA     : %d\n", scores[6]);
    printf("\t\t\t\t\t\t    |--> GLU      : %d\n");
    printf("\t\t|--> AURA     : %d\n", scores[6]);
    printf("GEEKFAM  : %d\n", scores[7]);
    printf("\t\t\t    |--> GLU      : %d\n", scores[11]);
    printf("\t\t     GLU      : %d\n", scores[11]);

    printf("TIM 1 : %s\n", teams[0]);
    printf("TIM 2 : %s\n", teams[1]);
    printf("TIM 3 : %s\n", teams[2]);
    printf("TIM 4 : %s\n", teams[3]);
    printf("TIM 5 : %s\n", teams[4]);
    printf("TIM 6 : %s\n", teams[5]);
    printf("TIM 7 : %s\n", teams[6]);
    printf("TIM 8 : %s\n", teams[7]);
    printf("TIM 9 : %s\n", teams[8]);
    printf("TIM 10 : %s\n", teams[9]);
    printf("TIM 11 : %s\n", teams[10]);
    printf("TIM 12 : %s\n", teams[11]);

    printf("Pertandingan 1 : %s vs %s\n", teams[0], teams[1]);
    printf("Pertandingan 2 : %s vs %s\n", teams[2], teams[3]);
    printf("Pertandingan 3 : %s vs %s\n", teams[4], teams[5]);
    printf("Pertandingan 4 : %s vs %s\n", teams[6], teams[7]);
    printf("Pertandingan 5 : %s vs %s\n", teams[0], teams[9]);
    printf("Pertandingan 6 : %s vs %s\n", teams[2], teams[8]);
    printf("Pertandingan 7 : %s vs %s\n", teams[5], teams[10]);
    printf("Pertandingan 8 : %s vs %s\n", teams[6], teams[11]);
    printf("Pertandingan 9 : %s vs %s\n", teams[0], teams[8]);
    printf("Pertandingan 10 : %s vs %s\n", teams[5], teams[11]);
    printf("Winner : %s\n", winner);
}

void templatebagan13tim(char teams[][50], int scores[], char* winner) {
    printf("BIGETRON : %d\n", scores[0]);
    printf("\t\t|--> BIGETRON : %d\n", scores[0]);
    printf("ONIC     : %d\n", scores[1]);
    printf("\t\t\t    |--> BIGETRON : %d\n", scores[0]);
    printf("\t\t     HFX      : %d\n", scores[10]);
    printf("AEROWOLF : %d\n", scores[2]);
    printf("\t\t\t\t\t\t|--> %s\n", winner);
    printf("\t\t|--> AEROWOLF : %d\n", scores[2]);
    printf("RRQ      : %d\n", scores[3]);
    printf("\t\t\t    |--> AEROWOLF : %d\n", scores[2]);
    printf("EVOS     : %d\n", scores[4]);
    printf("\t\t\t\t\t\t    |--> BIGETRON\n");
    printf("\t\t|--> EVOS     : %d\n", scores[4]);
    printf("BOOM     : %d\n", scores[5]);
    printf("\t\t\t    |--> AURA     : %d\n", scores[6]);
    printf("AURA     : %d\n", scores[6]);
    printf("\t\t\t\t\t\t    |--> PJEV     : %d\n");
    printf("\t\t|--> SIREN    : %d\n", scores[9]);
    printf("GEEKFAM  : %d\n", scores[7]);
    printf("\t\t\t    |--> PJEV     : %d\n", scores[12]);
    printf("ALTEREGO : %d\n", scores[8]);
    printf("\t\t     PJEV     : %d\n", scores[12]);

    printf("TIM 1 : %s\n", teams[0]);
    printf("TIM 2 : %s\n", teams[1]);
    printf("TIM 3 : %s\n", teams[2]);
    printf("TIM 4 : %s\n", teams[3]);
    printf("TIM 5 : %s\n", teams[4]);
    printf("TIM 6 : %s\n", teams[5]);
    printf("TIM 7 : %s\n", teams[6]);
    printf("TIM 8 : %s\n", teams[7]);
    printf("TIM 9 : %s\n", teams[8]);
    printf("TIM 10 : %s\n", teams[9]);
    printf("TIM 11 : %s\n", teams[10]);
    printf("TIM 12 : %s\n", teams[11]);
    printf("TIM 13 : %s\n", teams[12]);

    printf("Pertandingan 1 : %s vs %s\n", teams[0], teams[1]);
    printf("Pertandingan 2 : %s vs %s\n", teams[2], teams[3]);
    printf("Pertandingan 3 : %s vs %s\n", teams[4], teams[5]);
    printf("Pertandingan 4 : %s vs %s\n", teams[6], teams[7]);
    printf("Pertandingan 5 : %s vs %s\n", teams[8], teams[9]);
    printf("Pertandingan 6 : %s vs %s\n", teams[0], teams[10]);
    printf("Pertandingan 7 : %s vs %s\n", teams[8], teams[4]);
    printf("Pertandingan 8 : %s vs %s\n", teams[9], teams[12]);
    printf("Pertandingan 9 : %s vs %s\n", teams[0], teams[8]);
    printf("Pertandingan 10 : %s vs %s\n", teams[6], teams[12]);
    printf("Pertandingan 11 : %s vs %s\n", teams[0], teams[12]);
    printf("Winner : %s\n", winner);
}

void templatebagan14tim(char teams[][50], int scores[], char* winner) {
    printf("BIGETRON : %d\n", scores[0]);
    printf("\t\t|--> BIGETRON : %d\n", scores[0]);
    printf("ONIC     : %d\n", scores[1]);
    printf("\t\t\t    |--> BIGETRON : %d\n", scores[0]);
    printf("\t\t     PJEV     : %d\n", scores[12]);
    printf("AEROWOLF : %d\n", scores[2]);
    printf("\t\t\t\t\t\t|--> %s\n", winner);
    printf("\t\t|--> AEROWOLF : %d\n", scores[2]);
    printf("RRQ      : %d\n", scores[3]);
    printf("\t\t\t    |--> AEROWOLF : %d\n", scores[2]);
    printf("EVOS     : %d\n", scores[4]);
    printf("\t\t\t\t\t\t    |--> BIGETRON\n");
    printf("\t\t|--> EVOS     : %d\n", scores[4]);
    printf("BOOM     : %d\n", scores[5]);
    printf("\t\t\t    |--> AURA     : %d\n", scores[6]);
    printf("AURA     : %d\n", scores[6]);
    printf("\t\t\t\t\t\t    |--> ALTEREGO : %d\n");
    printf("\t\t|--> ALTEREGO : %d\n", scores[8]);
    printf("GEEKFAM  : %d\n", scores[7]);
    printf("\t\t\t    |--> ALTEREGO : %d\n", scores[8]);
    printf("ALTEREGO : %d\n", scores[8]);
    printf("\t\t     VOIN     : %d\n", scores[13]);
    printf("SIREN    : %d\n", scores[9]);
    printf("\t\t|--> EVOS     : %d\n", scores[4]);
    printf("HFX      : %d\n", scores[10]);
    printf("\t\t     GLU      : %d\n", scores[11]);

    printf("TIM 1 : %s\n", teams[0]);
    printf("TIM 2 : %s\n", teams[1]);
    printf("TIM 3 : %s\n", teams[2]);
    printf("TIM 4 : %s\n", teams[3]);
    printf("TIM 5 : %s\n", teams[4]);
    printf("TIM 6 : %s\n", teams[5]);
    printf("TIM 7 : %s\n", teams[6]);
    printf("TIM 8 : %s\n", teams[7]);
    printf("TIM 9 : %s\n", teams[8]);
    printf("TIM 10 : %s\n", teams[9]);
    printf("TIM 11 : %s\n", teams[10]);
    printf("TIM 12 : %s\n", teams[11]);
    printf("TIM 13 : %s\n", teams[12]);
    printf("TIM 14 : %s\n", teams[13]);

    printf("Pertandingan 1 : %s vs %s\n", teams[0], teams[1]);
    printf("Pertandingan 2 : %s vs %s\n", teams[2], teams[3]);
    printf("Pertandingan 3 : %s vs %s\n", teams[4], teams[5]);
    printf("Pertandingan 4 : %s vs %s\n", teams[6], teams[7]);
    printf("Pertandingan 5 : %s vs %s\n", teams[8], teams[9]);
    printf("Pertandingan 6 : %s vs %s\n", teams[10], teams[11]);
    printf("Pertandingan 7 : %s vs %s\n", teams[0], teams[12]);
    printf("Pertandingan 8 : %s vs %s\n", teams[2], teams[4]);
    printf("Pertandingan 9 : %s vs %s\n", teams[6], teams[13]);
    printf("Pertandingan 10 : %s vs %s\n", teams[8], teams[4]);
    printf("Pertandingan 11 : %s vs %s\n", teams[0], teams[2]);
    printf("Pertandingan 12 : %s vs %s\n", teams[6], teams[8]);
    printf("Winner : %s\n", winner);
}

void templatebagan15tim(char teams[][50], int scores[], char* winner) {
    printf("BIGETRON : %d\n", scores[0]);
    printf("\t\t|--> BIGETRON : %d\n", scores[0]);
    printf("ONIC     : %d\n", scores[1]);
    printf("\t\t\t    |--> BIGETRON : %d\n", scores[0]);
    printf("\t\t     LIQUID   : %d\n", scores[14]);
    printf("AEROWOLF : %d\n", scores[2]);
    printf("\t\t\t\t\t\t|--> %s\n", winner);
    printf("\t\t|--> AEROWOLF : %d\n", scores[2]);
    printf("RRQ      : %d\n", scores[3]);
    printf("\t\t\t    |--> AEROWOLF : %d\n", scores[2]);
    printf("EVOS     : %d\n", scores[4]);
    printf("\t\t\t\t\t\t    |--> BIGETRON\n");
    printf("\t\t|--> EVOS     : %d\n", scores[4]);
    printf("BOOM     : %d\n", scores[5]);
    printf("\t\t\t    |--> AURA     : %d\n", scores[6]);
    printf("AURA     : %d\n", scores[6]);
    printf("\t\t\t\t\t\t    |--> HFX      : %d\n");
    printf("\t\t|--> ALTEREGO : %d\n", scores[8]);
    printf("GEEKFAM  : %d\n", scores[7]);
    printf("\t\t\t    |--> HFX      : %d\n", scores[10]);
    printf("ALTEREGO : %d\n", scores[8]);
    printf("\t\t     SIREN    : %d\n", scores[9]);
    printf("SIREN    : %d\n", scores[9]);
    printf("\t\t|--> HFX      : %d\n", scores[10]);
    printf("HFX      : %d\n", scores[10]);
    printf("\t\t     GLU      : %d\n", scores[11]);
    printf("GLU      : %d\n", scores[11]);
    printf("\t\t|--> PJEV     : %d\n", scores[12]);
    printf("PJEV     : %d\n", scores[12]);
    printf("\t\t     VOIN     : %d\n", scores[13]);

    printf("TIM 1 : %s\n", teams[0]);
    printf("TIM 2 : %s\n", teams[1]);
    printf("TIM 3 : %s\n", teams[2]);
    printf("TIM 4 : %s\n", teams[3]);
    printf("TIM 5 : %s\n", teams[4]);
    printf("TIM 6 : %s\n", teams[5]);
    printf("TIM 7 : %s\n", teams[6]);
    printf("TIM 8 : %s\n", teams[7]);
    printf("TIM 9 : %s\n", teams[8]);
    printf("TIM 10 : %s\n", teams[9]);
    printf("TIM 11 : %s\n", teams[10]);
    printf("TIM 12 : %s\n", teams[11]);
    printf("TIM 13 : %s\n", teams[12]);
    printf("TIM 14 : %s\n", teams[13]);
    printf("TIM 15 : %s\n", teams[14]);

    printf("Pertandingan 1 : %s vs %s\n", teams[0], teams[1]);
    printf("Pertandingan 2 : %s vs %s\n", teams[2], teams[3]);
    printf("Pertandingan 3 : %s vs %s\n", teams[4], teams[5]);
    printf("Pertandingan 4 : %s vs %s\n", teams[6], teams[7]);
    printf("Pertandingan 5 : %s vs %s\n", teams[8], teams[9]);
    printf("Pertandingan 6 : %s vs %s\n", teams[10], teams[11]);
    printf("Pertandingan 7 : %s vs %s\n", teams[12], teams[13]);
    printf("Pertandingan 8 : %s vs %s\n", teams[0], teams[14]);
    printf("Pertandingan 9 : %s vs %s\n", teams[2], teams[4]);
    printf("Pertandingan 10 : %s vs %s\n", teams[6], teams[8]);
    printf("Pertandingan 11 : %s vs %s\n", teams[10], teams[12]);
    printf("Pertandingan 12 : %s vs %s\n", teams[0], teams[2]);
    printf("Pertandingan 13 : %s vs %s\n", teams[6], teams[10]);
    printf("Winner : %s\n", winner);
}

void templatebagan16tim(char teams[][50], int scores[], char* winner) {
    printf("BIGETRON : %d\n", scores[0]);
    printf("\t\t|--> BIGETRON : %d\n", scores[0]);
    printf("ONIC     : %d\n", scores[1]);
    printf("\t\t\t\t    |--> BIGETRON : %d\n", scores[0]);
    printf("AEROWOLF : %d\n", scores[2]);
    printf("\t\t|--> AEROWOLF : %d\n", scores[2]);
    printf("RRQ      : %d\n", scores[3]);
    printf("\t\t\t\t\t\t    |--> BIGETRON : %d\n", scores[0]);
    printf("EVOS     : %d\n", scores[4]);
    printf("\t\t|--> EVOS     : %d\n", scores[4]);
    printf("BOOM     : %d\n", scores[5]);
    printf("\t\t\t\t    |--> EVOS     : %d\n", scores[4]);
    printf("AURA     : %d\n", scores[6]);
    printf("\t\t|--> AURA     : %d\n", scores[6]);
    printf("GEEKFAM  : %d\n", scores[7]);
    printf("\t\t\t\t\t\t    |--> BIGETRON\n");
    printf("ALTEREGO : %d\n", scores[8]);
    printf("\t\t|--> ALTEREGO : %d\n", scores[8]);
    printf("SIREN    : %d\n", scores[9]);
    printf("\t\t\t\t    |--> HFX      : %d\n", scores[10]);
    printf("HFX      : %d\n", scores[10]);
    printf("\t\t|--> HFX      : %d\n", scores[10]);
    printf("GLU      : %d\n", scores[11]);
    printf("\t\t\t\t\t\t    |--> HFX      : %d\n", scores[10]);
    printf("PJEV     : %d\n", scores[12]);
    printf("\t\t|--> PJEV     : %d\n", scores[12]);
    printf("VOIN     : %d\n", scores[13]);
    printf("\t\t\t\t    |--> PJEV     : %d\n", scores[12]);
    printf("LIQUID   : %d\n", scores[14]);
    printf("\t\t|--> LIQUID   : %d\n", scores[14]);
    printf("MORPH    : %d\n", scores[15]);

    printf("TIM 1 : %s\n", teams[0]);
    printf("TIM 2 : %s\n", teams[1]);
    printf("TIM 3 : %s\n", teams[2]);
    printf("TIM 4 : %s\n", teams[3]);
    printf("TIM 5 : %s\n", teams[4]);
    printf("TIM 6 : %s\n", teams[5]);
    printf("TIM 7 : %s\n", teams[6]);
    printf("TIM 8 : %s\n", teams[7]);
    printf("TIM 9 : %s\n", teams[8]);
    printf("TIM 10 : %s\n", teams[9]);
    printf("TIM 11 : %s\n", teams[10]);
    printf("TIM 12 : %s\n", teams[11]);
    printf("TIM 13 : %s\n", teams[12]);
    printf("TIM 14 : %s\n", teams[13]);
    printf("TIM 15 : %s\n", teams[14]);
    printf("TIM 16 : %s\n", teams[15]);

    printf("Pertandingan 1 : %s vs %s\n", teams[0], teams[1]);
    printf("Pertandingan 2 : %s vs %s\n", teams[2], teams[3]);
    printf("Pertandingan 3 : %s vs %s\n", teams[4], teams[5]);
    printf("Pertandingan 4 : %s vs %s\n", teams[6], teams[7]);
    printf("Pertandingan 5 : %s vs %s\n", teams[8], teams[9]);
    printf("Pertandingan 6 : %s vs %s\n", teams[10], teams[11]);
    printf("Pertandingan 7 : %s vs %s\n", teams[12], teams[13]);
    printf("Pertandingan 8 : %s vs %s\n", teams[14], teams[15]);
    printf("Pertandingan 9 : %s vs %s\n", teams[0], teams[2]);
    printf("Pertandingan 10 : %s vs %s\n", teams[4], teams[6]);
    printf("Pertandingan 11 : %s vs %s\n", teams[8], teams[10]);
    printf("Pertandingan 12 : %s vs %s\n", teams[12], teams[14]);
    printf("Pertandingan 13 : %s vs %s\n", teams[0], teams[4]);
    printf("Pertandingan 14 : %s vs %s\n", teams[8], teams[12]);
    printf("Winner : %s\n", winner);
}
