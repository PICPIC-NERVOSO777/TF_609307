#ifndef jogo.h
#define jogo.h

#define MAX_TEXTO 50

// Identificadores das telas do programa
typedef enum {
    TELA_MENU = 0, 
    TELA_MAPAS, // 1
    TELA_JOGO, // 2
    TELA_CONFIGURACOES, // 3
    TELA_PERSONALIZAR, // 4
    TELA_VITORIA, // 5
    TELA_DERROTA, // 6
} TipoTela;

// Estrutura para os botões interativos
typedef struct {
    float x, y;
    float largura, altura;
    char texto[MAX_TEXTO]; // Vetor de char para o texto
    int destinoTela;       // Para qual tela o botão aponta
    int bloqueado;         // 1 se estiver bloqueado, 0 se liberado
} Botao;

#endif