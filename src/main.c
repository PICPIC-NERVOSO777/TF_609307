#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"

#define LARGURA 1600
#define ALTURA 800

int main(void) {
    //Inicialização
    InitWindow(LARGURA, ALTURA, "Nome do programa"); //Inicializa janela, com certo tamnho e título
    SetTargetFPS(60); // Define a taxa de quadros por segundo (FPS)

    TipoTela telaatual = TELA_MENU;

    //Variável para controlar progresso dos mapas
    int mapa1Conluido = 0; // 0 = Bloquado, 1 = Desbloquado

    // Botões do Menu Principal
    Botao btnJogar = { 250, 200, 300, 50, "Jogar", TELA_MAPAS, 0 };
    Botao btnPersonalizar = { 250, 270, 300, 50, "Personalizar", TELA_PERSONALIZAR, 0 };
    Botao btnConfiguracoes = {250, 340, 300, 50, "Configurações", TELA_CONFIGURACOES, 0 };
    Botao btnSair = { 250, 410, 300, 50, "Sair", -1, 0 };

    // Botões de Seleção de Mapas
    Botao btnMapa1 = { 250, 180, 300, 50, "Mapa 1", TELA_JOGO, 0 };
    // O Mapa 2 começa bloqueado dependendo de 'mapa1Concluido'
    Botao btnMapa2 = { 250, 250, 300, 50, "Mapa 2 (Bloqueado)", TELA_JOGO, 1 };

    // Loop principal do jogo
    while (!WindowShouldClose()) {// Detecta o botão de fechar ou ESC
        Vector2 mousePos = GetMousePosition();

        

        BeginDrawing();
        EndDrawing(); //Encerra o ambiente de desenho

    }

    CloseWindow(); // Fecha a janela e o contexto OpenGL
    return 0;
}