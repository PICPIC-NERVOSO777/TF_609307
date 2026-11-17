#include "raylib.h"
#include <strings.h>
#include "jogo.h"

void desenhaBotao(Botao *b) {

    Color corFundo = WHITE; // Cor padrão do botão
    Color corTexto = BLACK; // Cor padrão do texto

    Vector2 mousePos = GetMousePosition();
    
    bool mouseEmCima = (mousePos.x >= b->x && mousePos.x <= b->x + b->largura &&
                        mousePos.y >= b->y && mousePos.y <= b->y + b->altura);
                        
    bool SelecionadoPorTeclado = (b->selecionadoPorTeclado);
    
    if (mouseEmCima || SelecionadoPorTeclado) {
        corFundo = LIGHTGRAY; // Cor do botão quando o mouse está em cima ou selecionado por teclado
    }
    
    DrawRectangleRec((Rectangle){b->x, b->y, b->largura, b->altura}, corFundo); // Fundo do botão
    DrawRetangleLines(b->x, b->y, b->largura, b->altura, BLACK); // Borda do botão

    // Desenha o texto centralizado no botão

    int tamanhoFonte = 20;
    int larguraTexto = MeasureText(b->texto, tamanhoFonte);

    float textoX = b->x + (b->largura - larguraTexto) / 2.0f;
    float textoY = b->y + (b->altura - tamanhoFonte) / 2.0f;
    DrawText(b->texto, (int)textoX, (int)textoY, tamanhoFonte, corTexto);
}
