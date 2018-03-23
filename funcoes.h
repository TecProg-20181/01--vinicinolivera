#ifndef funcoes_h
#define funcoes_h

//Estruturas
typedef struct _pixel {
  unsigned short int r;
  unsigned short int g;
  unsigned short int b;
} Pixel;

typedef struct _image {
  unsigned short int pixel[512][512][3];
  unsigned int width;
  unsigned int height;
} Image;

//Funcoes
int menor(int a, int b){
  if(a > b)
  return b;
  return a;
}

Image filtro_sepia(Image img){
  for (unsigned int x = 0; x < img.height; ++x) {
    for (unsigned int j = 0; j < img.width; ++j) {
      unsigned short int pixel[3];
      pixel[0] = img.pixel[x][j][0];
      pixel[1] = img.pixel[x][j][1];
      pixel[2] = img.pixel[x][j][2];

      int p =  pixel[0] * .393 + pixel[1] * .769 + pixel[2] * .189;
      int menor_r;
      menor_r = menor(255, p);
      img.pixel[x][j][0] = menor_r;

      p =  pixel[0] * .349 + pixel[1] * .686 + pixel[2] * .168;
      menor_r = menor(255, p);
      img.pixel[x][j][1] = menor_r;

      p =  pixel[0] * .272 + pixel[1] * .534 + pixel[2] * .131;
      menor_r = menor(255, p);
      img.pixel[x][j][2] = menor_r;
    }
  }
  return img;
}

Image espelhamento(Image img){
  int horizontal = 0;
  scanf("%d", &horizontal);

  int width = img.width, height = img.height;

  if (horizontal == 1) width /= 2;
  else height /= 2;

  for (int i2 = 0; i2 < height; ++i2) {
    for (int j = 0; j < width; ++j) {
      int x = i2, y = j;

      if (horizontal == 1) y = img.width - 1 - j;
      else x = img.height - 1 - i2;

      Pixel aux1;
      aux1.r = img.pixel[i2][j][0];
      aux1.g = img.pixel[i2][j][1];
      aux1.b = img.pixel[i2][j][2];

      img.pixel[i2][j][0] = img.pixel[x][y][0];
      img.pixel[i2][j][1] = img.pixel[x][y][1];
      img.pixel[i2][j][2] = img.pixel[x][y][2];

      img.pixel[x][y][0] = aux1.r;
      img.pixel[x][y][1] = aux1.g;
      img.pixel[x][y][2] = aux1.b;
    }
  }
  return img;
}

Image escala_de_cinza(Image img) {

  for (unsigned int i = 0; i < img.height; ++i) {
    for (unsigned int j = 0; j < img.width; ++j) {
      int media = img.pixel[i][j][0] +
      img.pixel[i][j][1] +
      img.pixel[i][j][2];
      media /= 3;
      img.pixel[i][j][0] = media;
      img.pixel[i][j][1] = media;
      img.pixel[i][j][2] = media;
    }
  }

  return img;
}

Image blur(Image img) {
  int tamanho = 0;
  scanf("%d", &tamanho);

  Image blur = img;
  for (unsigned int i = 0; i < blur.height; ++i) {
    for (unsigned int j = 0; j < blur.width; ++j) {
      Pixel media = {0, 0, 0};

      int menor_h = menor(blur.height-1, (i + tamanho/2));
      int min_w = menor(blur.width-1, (j + tamanho/2));

      for(int x = (i - tamanho/2); x <= menor_h; ++x) {
        for(int y =  (j - tamanho/2) ; y <= min_w; ++y) {
          media.r += blur.pixel[x][y][0];
          media.g += blur.pixel[x][y][1];
          media.b += blur.pixel[x][y][2];
        }
      }

      media.r /= tamanho * tamanho;
      media.g /= tamanho * tamanho;
      media.b /= tamanho * tamanho;

      blur.pixel[i][j][0] = media.r;
      blur.pixel[i][j][1] = media.g;
      blur.pixel[i][j][2] = media.b;
    }
  }

  return blur;
}

Image rotacionar90direita(Image img) {

  int quantas_vezes = 0;
  scanf("%d", &quantas_vezes);
  quantas_vezes %= 4;
  Image rotacionada;

  for (int j = 0; j < quantas_vezes; ++j) {
    int height = img.height;
    int width = img.width;

    rotacionada.height = img.width;
    rotacionada.width = img.height;
    for (unsigned int i = 0, y = 0; i < width; ++i, ++y) {
      for (int j = height - 1, x = 0; j >= 0; --j, ++x) {
        rotacionada.pixel[i][j][0] = img.pixel[x][y][0];
        rotacionada.pixel[i][j][1] = img.pixel[x][y][1];
        rotacionada.pixel[i][j][2] = img.pixel[x][y][2];
      }
    }
  }

  return rotacionada;
}

Image inverter_cores(Image img) {
    Image invertida = img;
    for (unsigned int i = 0; i < invertida.height; ++i) {
      for (unsigned int j = 0; j < invertida.width; ++j) {
        invertida.pixel[i][j][0] = 255 - invertida.pixel[i][j][0];
        invertida.pixel[i][j][1] = 255 - invertida.pixel[i][j][1];
        invertida.pixel[i][j][2] = 255 - invertida.pixel[i][j][2];
      }
    }

    return invertida;
  }

  Image cortar_imagem(Image img) {
    int x, y;
    scanf("%d %d", &x, &y);
    int width, height;
    scanf("%d %d", &width, &height);

    img.width = width;
    img.height = height;
    for(int i = 0; i < height; ++i) {
      for(int j = 0; j < width; ++j) {
        img.pixel[i][j][0] = img.pixel[i + y][j + x][0];
        img.pixel[i][j][1] = img.pixel[i + y][j + x][1];
        img.pixel[i][j][2] = img.pixel[i + y][j + x][2];
      }
    }

    return img;
  }

  #endif
