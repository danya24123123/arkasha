#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <time.h>


#include "queue.h"





int main(int argc, char *argv[]) {
    int n,i,i_file;
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("До всего время = %ld ms \n", clock());
    for(i=0;i<argc;i++){
     //   puts(argv[i]);
       if (strcmp(argv[i],"--file")==0){
         if (i + 1 < argc) {
             FILE *file = NULL;
             char str[50];

             file = fopen(argv[i+1],"r");
             if (file == NULL) {
                printf("Ошибка: не удалось открыть файл %s\n", argv[i + 1]);
                return 1;
             }
             fseek(file, 0, SEEK_SET);
             if(fgets(str,50,file)!=NULL){

                printf("Предыдущий ряд: %s\n", str);

             }
             if(fgets(str,50,file)!=NULL){

                printf("Предыдущий  отсортированный ряд: %s\n", str);
            }

        }
       }
    }

    printf("Введите ряд чисел.Чтобы закончить ввод ввведите end\n");
    FILE *file = NULL;
    file = fopen("sp.txt","w");
    if (file == NULL) {
                printf("Ошибка: не удалось открыть файл sp.txt\n");
                return 1;
             }
    Queue *q = (Queue *) calloc(1, sizeof(Queue));
    Queue *q_h = (Queue *) calloc(1, sizeof(Queue));
    while (scanf("%d",&n)==1){
        queue_put(q, n);
        queue_put(q_h, n);
    }



    queue_fprint(q,file);
    queue_print(q);
    printf("До сорт выбором время = %ld ms \n", clock());

    queue_sort(q);
    printf("После сорт выбором время = %ld ms \n", clock());
    fseek(file, 0, SEEK_END);
    queue_fprint(q,file);
    queue_print(q);

   // fclose(file);
    queue_delete(q);

    printf("\nХОР\n");
    queue_fprint(q_h,file);
    queue_print(q_h);
    printf("До сорт Хором время = %ld ms \n", clock());

    queue_quick_sort(q_h);
    printf("После сорт Хором время = %ld ms \n", clock());
    fseek(file, 0, SEEK_END);
    queue_fprint(q_h,file);
    queue_print(q_h);

    fclose(file);
    queue_delete(q_h);
    return 0;
}
