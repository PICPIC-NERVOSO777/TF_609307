#ifndef jogo_h
#define jogo_h

#

//Botões interativos
typedef struct {
    float x, y;
    float largura, altura;
    char texto[50]; // Vetor de char para o texto
    int destinoTela;       // Para qual tela o botão aponta
    int bloqueado;         // 1 se estiver bloqueado, 0 se liberado
} Botao;
//Identificador de telas do programa
typedef enum {
    TELA_MENU = 0,
    TELA_MAPAS,
    TELA_JOGO,
    TELA_PERSONALIZAR,
    TELA_CONFIGURACOES,
} TipoTela;
#endif
