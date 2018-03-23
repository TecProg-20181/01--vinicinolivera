#include <stdio.h>
#include "funcoes.h"

int main() {
  Image img;

  char p3[4];
  scanf("%s", p3);
  int max_color;
  scanf("%u %u %d", &img.width, &img.height, &max_color);

  for (unsigned int i = 0; i < img.height; ++i) {
    for (unsigned int j = 0; j < img.width; ++j) {
      scanf("%hu %hu %hu", &img.pixel[i][j][0],
      &img.pixel[i][j][1],
      &img.pixel[i][j][2]);
    }
  }

  int n_opcoes;
  scanf("%d", &n_opcoes);

  for(int i = 0; i < n_opcoes; ++i) {
    int opcao;
    scanf("%d", &opcao);

    switch(opcao) {
      case 1: { //Escala de Cinza
        img = escala_de_cinza(img);
        break;
      }
      case 2: { // Filtro Sepia
        img = filtro_sepia(img);
        break;
      }
      case 3: { // Blur
        img = blur(img);
        break;
      }
      case 4: { // Rotacao
          img = rotacionar90direita(img);
        break;
      }
      case 5: { // Espelhamento
        img = espelhamento(img);
        break;
      }
      case 6: { // Inversao de Cores
        img = inverter_cores(img);
        break;
      }
      case 7: { // Cortar Imagem
        img = cortar_imagem(img);
        break;
      }
    }
  }

  printf("P3\n");
  printf("%u %u\n255\n", img.width, img.height);

  for (unsigned int i = 0; i < img.height; ++i) {
    for (unsigned int j = 0; j < img.width; ++j) {
      printf("%hu %hu %hu ", img.pixel[i][j][0],
      img.pixel[i][j][1],
      img.pixel[i][j][2]);
    }
    printf("\n");
  }

  return 0;
}
