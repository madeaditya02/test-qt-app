#ifndef STRUCTDEFINITION_H
#define STRUCTDEFINITION_H
#include "QString"

using namespace std;

// struct Mahasiswa
// {
//     QString nama;
//     QString nim;
//     struct Mahasiswa *next;
//     Mahasiswa() {}
// };

// typedef struct {
//     struct Mahasiswa *data;
//     int count;
//     void update(int row, int col, QString value) {
//         struct Mahasiswa *temp = this->data;
//         int i = 0;
//         for (int i = 0; i < row; ++i)
//             temp = temp->next;
//         if (col == 0)
//             temp->nama = value;
//         else if (col == 1)
//             temp->nim = value;
//     }
// } mhsResult;

// mhsResult* getDataMahasiswa() {
//     struct Mahasiswa *head = new Mahasiswa(), *temp = new Mahasiswa();
//     // head = (struct Mahasiswa *)malloc(sizeof(struct Mahasiswa));
//     head->nama = "I Kadek Bisma Yoga";
//     head->nim = "2308561015";
//     // head->nama = QString::fromStdString(nama);
//     // head->nim = QString::fromStdString("2308561015");
//     temp = head;
//     int c = 1;
//     for (int i = 0; i<9; i++) {
//         struct Mahasiswa *node = new Mahasiswa();
//         // node = (struct Mahasiswa *)malloc(sizeof(struct Mahasiswa));
//         // node->nama = QString::fromStdString(i%2 == 0 ? "Made Aditya" : "I Kadek Bisma Yoga");
//         // node->nim = QString::fromStdString("2308561015");
//         node->nama = i%2 == 0 ? "Made Aditya" : "I Kadek Bisma Yoga";
//         node->nim = "2308561015";
//         node->next = NULL;
//         temp->next = node;
//         temp = node;
//         c++;
//     }
//     mhsResult *result;
//     result->data = head;
//     result->count = c;
//     return result;
// }

// mhsResult *dataMhs = getDataMahasiswa();


#endif // STRUCTDEFINITION_H
