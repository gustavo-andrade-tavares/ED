#ifndef FIL_H
#define FIL_H

typedef int elem;
typedef struct fila_ Fila;

Fila* cria_fila();

int fila_pop(Fila* f, elem* e);

int fila_add(Fila* f, elem e);

int fila_destruir(Fila** f)

#endif
