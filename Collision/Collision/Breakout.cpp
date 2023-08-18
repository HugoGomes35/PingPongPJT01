/**********************************************************************************
// Breakout (C�digo Fonte)
// 
// Cria��o:     26 Mar 2012
// Atualiza��o: 01 Dez 2022
// Compilador:  Visual C++ 2022
//
// Descri��o:   Uso da classe Scene para gerenciar objetos e tratar colis�o
//
**********************************************************************************/

#include "Engine.h"
#include "Breakout.h"
#include "Resources.h"
#include "playerRed.h"
#include "Block.h"
#include "Ball.h"

// ------------------------------------------------------------------------------
// Inicializa��o de membros est�ticos da classe

Scene * Breakout::scene = nullptr;

// ------------------------------------------------------------------------------

void Breakout::Init()
{
    // cena do jogo
    scene = new Scene();

    // carrega background
    backg = new Sprite("Resources/Background.png");
    
    // ---------------------------
    // cria jogador
    playerRed * player = new playerRed();
    scene->Add(player, MOVING);

    // ---------------------------
    // cria bola

    Ball * ball = new Ball(player);
    scene->Add(ball, MOVING);

 
}


void Breakout::Update()
{
    // sai com o pressionamento do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();
    
    // habilita/desabilita visualiza��o de sprites
    if (window->KeyPress('S'))
        viewScene = !viewScene;
 
    // habilita/desabilita visualiza��o da bounding box
    if (window->KeyPress('B'))
        viewBBox = !viewBBox;

    // atualiza objetos da cena
    scene->Update();

    // detec��o e resolu��o de colis�o
    scene->CollisionDetection();
}

// ------------------------------------------------------------------------------

void Breakout::Draw()
{
    // desenha a cena
    if (viewScene)
    {
        backg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
        scene->Draw();
    }

    // desenha a bounding box de todos os objetos
    if (viewBBox)
    {
        scene->DrawBBox();
    }
} 

// ------------------------------------------------------------------------------

void Breakout::Finalize()
{
    // apaga sprite
    delete backg;

    // apaga imagens
    delete tile1;
    delete tile2;
    delete tile3;
    delete tile4;
    delete tile5;

    delete scene;
}

// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    // cria engine
    Engine * engine = new Engine();

    // configura a janela
    engine->window->Mode(WINDOWED);
    engine->window->Size(640, 360);
    engine->window->Color(0, 0, 0);
    engine->window->Title("Breakout");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);

    // configura dispositivo gr�fico
    //engine->graphics->VSync(true);
    
    // inicia jogo
    engine->Start(new Breakout());

    // destr�i engine e jogo
    delete engine;
}

// ----------------------------------------------------------------------------

