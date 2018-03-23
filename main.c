#include <stdio.h>
#include "funcoes.h"

//Main principal da aplicacao
int main() {
  Image img;

  char p3[4];
  scanf("%s", p3);

  // read width height and color of image
  int max_color;
  scanf("%u %u %d", &img.width, &img.height, &max_color);

  // read all pixels of image
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
      case 1: { // Escala de Cinza
        img = escala_de_cinza(img);
        break;
      }
      case 2: { // Filtro Sepia
        img = filtro_sepia(img);
        break;
      }
      case 3: { // Blur
        int tamanho = 0;
        scanf("%d", &tamanho);
        blur(img.height, img.pixel, tamanho, img.width);
        break;
      }
      case 4: { // Rotacao
        int quantas_vezes = 0;
        scanf("%d", &quantas_vezes);
        quantas_vezes %= 4;
        for (int j = 0; j < quantas_vezes; ++j) {
          img = rotacionar90direita(img);
        }
        break;
      }
      case 5: { // Espelhamento
        int horizontal = 0;
        scanf("%d", &horizontal);

        int width = img.width, height = img.height;

        if (horizontal == 1) width /= 2;
        else height /= 2;

        img = espelhamento(img, horizontal, height, width);
        break;
      }
      case 6: { // Inversao de Cores
        inverter_cores(img.pixel, img.width, img.height);
        break;
      }
      case 7: { // Cortar Imagem
        int x, y;
        scanf("%d %d", &x, &y);
        int width, height;
        scanf("%d %d", &width, &height);

        img = cortar_imagem(img, x, y, width, height);
        break;
      }
    }

  }

  // print type of image
  printf("P3\n");
  // print width height and color of image
  printf("%u %u\n255\n", img.width, img.height);

  // print pixels of image
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
