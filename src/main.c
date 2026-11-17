#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"

#define LARGURA 1600
#define ALTURA 800

int main(void) {
    //Inicialização
    InitWindow(LARGURA, ALTURA, "Maze Runner v1.0"); //Inicializa janela, com certo tamnho e título
    SetTargetFPS(60); // Define a taxa de quadros por segundo (FPS)

    TipoTela telaAtual = 0; // Começa na tela de menu
    int indiceBotaoSelecionado = 0; // Índice do botão atualmente selecionado
    int totalBotoesMenu = 4; // Total de botões no menu principal

    //Variável para controlar progresso dos mapas
    int mapa1Conluido = 0; // 0 = Bloquado, 1 = Desbloquado

    // Botões do Menu Principal
    Botao btnJogar = { 250, 200, 300, 50, "Jogar", TELA_MAPAS, 0 };
    Botao btnPersonalizar = { 250, 270, 300, 50, "Personalizar", TELA_PERSONALIZAR, 0 };
    Botao btnConfiguracoes = {250, 340, 300, 50, "Configurações", TELA_CONFIGURACOES, 0 };
    Botao btnSair = { 250, 410, 300, 50, "Sair", -1, 0 };
    Botao btnVoltar = { 250, 500, 300, 50, "Voltar", TELA_MENU, 0 };

    // Botões de Seleção de Mapas
    Botao btnMapa1 = { 250, 180, 300, 50, "Mapa 1", TELA_JOGO, 0 };
    // O Mapa 2 começa bloqueado dependendo de 'mapa1Concluido'
    Botao btnMapa2 = { 250, 250, 300, 50, "Mapa 2 (Bloqueado)", TELA_JOGO, 1 };


    // Loop principal do jogo
    while (!WindowShouldClose()) {// Detecta o botão de fechar ou ESC
        Vector2 mousePos = GetMousePosition();
        bool clicou = IsMouseButtonPressed(MOUSE_LEFT_BUTTON);



        if (telaAtual == TELA_MENU) {
            // Lógica para o Menu Principal
            if (clicou) {
                if (CheckCollisionPointRec(mousePos, (Rectangle){btnJogar.x, btnJogar.y, btnJogar.largura, btnJogar.altura})) {
                    telaAtual = btnJogar.destinoTela;
                } else if (CheckCollisionPointRec(mousePos, (Rectangle){btnPersonalizar.x, btnPersonalizar.y, btnPersonalizar.largura, btnPersonalizar.altura})) {
                    telaAtual = btnPersonalizar.destinoTela;
                } else if (CheckCollisionPointRec(mousePos, (Rectangle){btnConfiguracoes.x, btnConfiguracoes.y, btnConfiguracoes.largura, btnConfiguracoes.altura})) {
                    telaAtual = btnConfiguracoes.destinoTela;
                } else if (CheckCollisionPointRec(mousePos, (Rectangle){btnSair.x, btnSair.y, btnSair.largura, btnSair.altura})) {
                    CloseWindow(); // Fecha a janela e sai do jogo
                }
            }
        } else if (telaAtual == TELA_MAPAS) {
            // Lógica para a tela de seleção de mapas
            if (clicou) {
                if (!btnMapa1.bloqueado && CheckCollisionPointRec(mousePos, (Rectangle){btnMapa1.x, btnMapa1.y, btnMapa1.largura, btnMapa1.altura})) {
                    telaAtual = btnMapa1.destinoTela;
                } else if (!btnMapa2.bloqueado && CheckCollisionPointRec(mousePos, (Rectangle){btnMapa2.x, btnMapa2.y, btnMapa2.largura, btnMapa2.altura})) {
                    telaAtual = btnMapa2.destinoTela;
                } else if (CheckCollisionPointRec(mousePos, (Rectangle){btnVoltar.x, btnVoltar.y, btnVoltar.largura, btnVoltar.altura})) {
                    telaAtual = btnVoltar.destinoTela;
                }
            }
        }

        

        BeginDrawing();
        EndDrawing(); //Encerra o ambiente de desenho

    }

    CloseWindow(); // Fecha a janela e o contexto OpenGL
    return 0;
}