#pragma once
#include <allegro.h>
#include "lib.h"

int cont;
// tempo movimento
int  tem_mov;
void tem_direita();
void tem_esquerda();

void verifica();
void desenha();
void inicializa();
void incrementa();

void tem_atakF();
void gravidade(int *alt,int *obj_y,int obj_tam,int obj_lar,int obj_x);
void plata();
void paredes();
void inimigoM();
void ini_tem();
int contato(int x1,int x2,int dir);
bool tomaDano(int ataqX1,int ataqX2,int ataqY1,int ataqY2,int defX1,int defX2,int defY1,int defY2,int *dano_lado);
BITMAP *buffer;
BITMAP *fundo;

BITMAP *heroi;
BITMAP *heroi2;

BITMAP *heroi_atak;
BITMAP *heroi_atak2;

BITMAP *inimigo;
BITMAP *inimigo2;


// posicionamento do heroi
int lado;
int her_x, her_y;
int her_lar, tam_her;
bool dano;
int dano_lado;

bool direita,esquerda;
// gravidade
int grav;
// bool pulo;
// ataque
// bool atak;
// int tem_atak;

// plataformas
int plat[20][3],pl;
// paredes
int pare[20][4],pa;

// inimigo
int ini_x ,ini_y;
int ini_dir;
int ini_Tem;
int grav_ini = -20;
int ini_lar, ini_tam;
int dano_lado2;
bool danoIni;