#include "results.h"

void tampilkanStatistik (Stack* s, StackNode* head) {
  StatistikTim tim[MAX_TIM];
  int teamCount = 0;

  // Inisialisasi array tim
  for (int i = 0; i < MAX_TIM; i++)
  {
    tim[i].namaTim[0] = '\0';
    tim[i].laga = 0;
    tim[i].menang = 0;
    tim[i].kalah = 0;
  }

  // Kumpulkan data dari linked list 
  StackNode* current = head;
  while (current != NULL && teamCount < MAX_TIM){
    // Proses tim1
    int foundTim1 = 0;
    for (int i = 0; i < teamCount; i++) {
      if (strcmp(tim[i].namaTim, current->data.namaTim1) == 0){
        tim[i].laga++;
        if (strcmp(current->data.namaTimPemenang, current->data.namaTim1) == 0) {
          tim[i].menang++;
        } else {
          tim[i].kalah++;
        }
        foundTim1 = 1;
        break;
      }
    }
    if (!foundTim1) {
      strcpy(tim[teamCount].namaTim, current->data.namaTim1);
      tim[teamCount].laga = 1;
    } else {
      tim[teamCount].kalah = 1;
    }
    teamCount++;
  }

  // Proses tim2
    int foundTim2 = 0;
    for (int i = 0; i < teamCount; i++) {
      if (strcmp(tim[i].namaTim, current->data.namaTim2) == 0){
        tim[i].laga++;
        if (strcmp(current->data.namaTimPemenang, current->data.namaTim2) == 0) {
          tim[i].menang++;
        } else {
          tim[i].kalah++;
        }
        foundTim2 = 1;
        break;
      }
    }
    if (!foundTim2) {
      strcpy(tim[teamCount].namaTim, current->data.namaTim2);
      tim[teamCount].laga = 1;
    } else {
      tim[teamCount].kalah = 1;
    }
    teamCount++;
  }

  current = current->next

  
