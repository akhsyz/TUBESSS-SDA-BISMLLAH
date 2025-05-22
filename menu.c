#include "menu.h"

void uiGreetings() {
    printf("***********************************************************************************\n");
    printf("*   W E L C O M E   T O   T O R N A M E N T   M A N A G E M E N T   S Y S T E M   *\n");
    printf("***********************************************************************************\n");
    printf("PLEASE ENTER YOUR EVENT NAME: ");
    scanf(" %[^\n]", namaEvent);
    printf("\n***************************************************************\n");
    printf("*                                                             *\n");
    printf("*                    WELCOME TO %s                        *\n", namaEvent);
    printf("*                                                             *\n");
    printf("***************************************************************\n");
}

void mainMenu() {
    int input = 0;
    while (input != 9) {
        printf("\n=== Manajemen Turnamen %s ===\n", namaEvent);
        printf("1. Tambah Tim\n");
        printf("2. Hapus Tim\n");
        printf("3. Tampilkan Daftar Tim\n");
        printf("4. Mulai Penjadwalan Pertandingan\n");
        printf("5. Input Hasil Pertandingan\n");
        printf("6. Undo Hasil Pertandingan\n");
        printf("7. Tampilkan Bagan Pertandingan\n");
        printf("8. Tampilkan Statistik Tim\n");
        printf("9. Keluar\n");
        printf("Pilih Opsi: ");
        scanf("%d", &input);
        switch (input) {
            case 1:
                showsTambahTim();
                break;
            case 2:
                showsHapusTim();
                break;
            case 3:
                showsDaftarTim();
                break;
            case 4:
                showsJadwalkanPertandingan();
                break;
            case 5:
                showsInputResult();
                break;
            case 6:
                showsUndoResult();
                break;
            case 7:
                showsBracket();
                break;
            case 8:
                showsStatistik();
                break;
            case 9:
                exitProgram();
                break;
            default:
                printf("Opsi tidak valid!\n");
        }
    }
}