#ifndef GENERATOR_H
#define GENERATOR_H

/* Verifica se o tamanho > 0 */
bool TamanhoValido(int tamanho);

/* Retorna um vetor aleatório com tamanho elementos */
int* VetorAleatorio(int tamanho, int seed);
/* Retorna um vetor em ordem crescente com tamanho elementos */
int* VetorCrescente(int tamanho);
/* Retorna um vetor em ordem decrescente com tamanho elementos */
int* VetorDecrescente(int tamanho);

#endif /* GENERATOR_H */