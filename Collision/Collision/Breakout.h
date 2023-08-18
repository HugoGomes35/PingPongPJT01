/**********************************************************************************
// Breakout (Arquivo de Cabe�alho)
//
// Cria��o:     26 Mar 2012
// Atualiza��o: 01 Dez 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Uso da classe Scene para gerenciar objetos e tratar colis�o
//
**********************************************************************************/

#include "Game.h"
#include "Sprite.h"
#include "Scene.h"
#include "Resources.h"

// ------------------------------------------------------------------------------
// Tipos dos objetos do jogo

enum ObjTypes
{
    PLAYER,                             // jogador
    BALL,                               // bola
    BLOCK                               // bloco
};

// ------------------------------------------------------------------------------

class Breakout : public Game
{
private:
    Sprite * backg = nullptr;           // plano de fundo
    Image * tile1  = nullptr;           // bloco verde
    Image * tile2  = nullptr;           // bloco cinza
    Image * tile3  = nullptr;           // bloco vermelho
    Image * tile4  = nullptr;           // bloco roxo
    Image * tile5  = nullptr;           // bloco amarelo

    bool viewScene = true;              // visualiza sprites da cena
    bool viewBBox  = false;             // visualiza bounding box
    
public:
    static Scene * scene;               // cena do jogo

    void Init();                        // inicializa��o
    void Update();                      // atualiza��o
    void Draw();                        // desenho
    void Finalize();                    // finaliza��o
};

// ------------------------------------------------------------------------------