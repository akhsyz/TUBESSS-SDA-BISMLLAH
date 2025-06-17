/*
PIC : akhsya 
NIM : 241524039
*/

#ifndef FILEIO_H
#define FILEIO_H

#include "tournament.h"

// Struktur untuk menyimpan semua data turnamen
typedef struct {
    char tournament_name[100];
    addressList head;           // Linked list tim
    addressTree root;           // Tournament tree
    Stack* history;             // Match history
} TournamentData;

void saveTournamentToJSON(addressList head, addressTree root, Stack* history, const char* tournament_name, const char* filename);
void saveTournamentToJSONQuiet(addressList head, addressTree root, Stack* history, const char* tournament_name, const char* filename, bool show_output);
TournamentData* loadTournamentFromJSON(const char* filename);

// Helper functions untuk JSON
void escapeJsonString(const char* input, char* output);
void getCurrentTimestamp(char* timestamp);
void saveBracketToJSON(FILE* file, addressTree treeNode, int indent);

void createDataFolder(void);
void createJSONPath(const char* tournament_name, char* output_path, size_t max_len);

// JSON Parsing functions
void parseJsonString(const char* json, const char* key, char* output, int max_len);
addressList parseJsonTeams(const char* json);
void parseJsonMatches(const char* json, Stack* history);

void rebuildMatchResultsFromHistory(addressTree root, Stack* history, addressList head);

#endif