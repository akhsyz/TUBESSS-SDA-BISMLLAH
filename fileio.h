#ifndef FILEIO_H
#define FILEIO_H

#include "templatebagan.h"

void saveTeamsToFile(addressList head, const char* filename);
void saveMatchHistoryToFile(Stack* history, const char* filename);
void saveTournamentTreeToFile(addressTree root, const char* filename);
addressList loadTeamsFromFile(const char* filename);
Stack* loadMatchHistoryFromFile(const char* filename);
addressTree loadTournamentTreeFromFile(const char* filename);

#endif
