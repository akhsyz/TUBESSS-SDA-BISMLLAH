#ifndef FILEIO_H
#define FILEIO_H

#include "linkedlist.h"
#include "tree.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struktur untuk menyimpan semua data turnamen
typedef struct {
    char tournament_name[100];
    addressList head;           // Linked list tim
    addressTree root;           // Tournament tree
    Stack* history;             // Match history
} TournamentData;

// JSON Format
void saveTournamentToJSON(addressList head, addressTree root, Stack* history, const char* tournament_name, const char* filename);
void saveTournamentToJSONQuiet(addressList head, addressTree root, Stack* history, const char* tournament_name, const char* filename, bool show_output);
TournamentData* loadTournamentFromJSON(const char* filename);

// Helper functions untuk JSON
void escapeJsonString(const char* input, char* output);
void getCurrentTimestamp(char* timestamp);
void saveBracketToJSON(FILE* file, addressTree treeNode, int indent);

// Fungsi untuk manajemen folder
void createDataFolder(void);
void createJSONPath(const char* tournament_name, char* output_path, size_t max_len);

// JSON Parsing functions
void parseJsonString(const char* json, const char* key, char* output, int max_len);
addressList parseJsonTeams(const char* json);
void parseJsonMatches(const char* json, Stack* history);
addressTree parseJsonBracket(const char* json);

// Backward compatibility (sekarang menggunakan JSON di belakang layar)
void saveTeamsToFile(addressList head, const char* filename);
addressList loadTeamsFromFile(const char* filename);
void saveMatchHistoryToFile(Stack* history, const char* filename);
Stack* loadMatchHistoryFromFile(const char* filename);
void saveTournamentTreeToFile(addressTree root, const char* filename);
addressTree loadTournamentTreeFromFile(const char* filename);

// Fallback untuk format TXT lama
addressList loadTeamsFromFileTXT(const char* filename);

#endif