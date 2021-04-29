#include "Game.h"
#include <iostream>
#include <random>
#include <time.h>

std::mt19937 rnd(19937);

void Game::next_step() {

}

void Game::init(size_t width, size_t height) {
    run = true;
    Graphics::instance()->createWindow(width, height);
    ImageController::instance()->loadImages();
    // Main Menu //

    this->mainMenu = (new Scene())
    ->add((new Button())
        ->setAction(new Action(openGameSpace))
        ->setPosition(Point2D(300, 200))
        ->setScale(Vector2D(200, 80))
        ->setAngle(0.f)
        ->setImage(ImageType::buttonImage1)
        )
    ->add((new Text())
        ->setString("Play")
        ->setPosition(Point2D(300, 200))
        ->setScale(Vector2D(200, 80))
        ->setAngle(0.f)
        )
    ->add((new Button())
        ->setAction(new Action(openMainSettings))
        ->setPosition(Point2D(300, 320))
        ->setScale(Vector2D(200, 80))
        ->setAngle(0.f)
        )
    ->add((new Text())
        ->setString("Settings")
        ->setPosition(Point2D(300, 320))
        ->setScale(Vector2D(200, 80))
        ->setAngle(0.f)
        )
    ->add((new Button())
        ->setAction(new Action(stopGame))
        ->setPosition(Point2D(300, 420))
        ->setScale(Vector2D(200, 80))
        ->setAngle(0.f)
        )
    ->add((new Text())
        ->setString("Exit")
        ->setPosition(Point2D(300, 420))
        ->setScale(Vector2D(200, 80))
        ->setAngle(0.f)
        )
    ->add((new Text())
        ->setString("Space")
        ->setPosition(Point2D(300, 100))
        ->setScale(Vector2D(200, 80))
        ->setAngle(0.f)
        );

    // Main Settings //
    
    this->mainSettings = (new Scene())
    ->add((new Button())
        ->setAction(new Action(openMainMenu))
        ->setPosition(Point2D(10, 10))
        ->setScale(Vector2D(100, 30))
        ->setAngle(0.f)
        )
    ->add((new Text())
        ->setString("Back to menu")
        ->setPosition(Point2D(10, 10))
        ->setScale(Vector2D(30, 20))
        ->setAngle(0.f)
        );

    // Game Space //
    
    this->gameSpace = (new GameScene())
    ->add((new UIBox())
        ->setPosition(Point2D(0, 500))
        ->setScale(Vector2D(800, 100))
        ->addItem((new Button())
            ->setAction(new Action(openMainMenu))
            ->setPosition(Point2D(10, 510))
            ->setScale(Vector2D(100, 30))
            ->setAngle(0.f)
            )
        )
    ->add((new Button())
        ->setAction(new Action(openMainMenu))
        ->setPosition(Point2D(10, 10))
        ->setScale(Vector2D(100, 30))
        ->setAngle(0.f)
        )
    ->add((new Text())
        ->setString("Go to menu")
        ->setPosition(Point2D(10, 10))
        ->setScale(Vector2D(30, 20))
        ->setAngle(0.f)
        );

    size_t xSize = GameScene::getWorldWidht();
    size_t ySize = GameScene::getWorldHieght();

    for(size_t i = 0; i < 100; ++i){
        reinterpret_cast<GameScene* >(this->gameSpace)->addUnit((new Parts())
        ->setImage(ImageType::starImage)
        ->setPosition(Point2D(rnd() % xSize, rnd() % ySize))    
        ->setScale(Vector2D(50, 50))
        ->setSign(false)
        );
    }

    for(size_t i = 0; i < 100; ++i){
        reinterpret_cast<GameScene* >(this->gameSpace)->addUnit((new Parts())
        ->setImage(ImageType::whiteStarImage)
        ->setPosition(Point2D(rnd() % xSize, rnd() % ySize))    
        ->setScale(Vector2D(50, 50))
        ->setSign(false)
        );
    }


    reinterpret_cast<GameScene* >(this->gameSpace)->addTarget((new SpaceShip())
        ->setGameController(PlayerController::instance())
        ->setPosition(Point2D(400, 300))
        ->setScale(Vector2D(150, 100))
        ->setSignColor(Color(150, 0, 0))
        ->setImage(ImageType::spaceship)
        );


    Graphics::Font f;
    f.loadFromFile("../src/font/sansation.ttf");
    Graphics::DrawObject::instance()->setFont(f.getFont());


    // bots

    reinterpret_cast<GameScene* >(this->gameSpace)
        ->addUnit((new SpaceShip())
            ->setPosition(Point2D(500, 500))
            ->setScale(Vector2D(100, 50))
            ->setSignColor(Color(0, 0, 150))
        )
        ->addUnit((new SpaceShip())
            ->setPosition(Point2D(150, 150))
            ->setScale(Vector2D(100, 50))
            ->setSignColor(Color(0, 0, 150))
        );

    //


    this->presentScene = scene::MainMenu;   
}

int Game::Execute(size_t width, size_t height) {

    init(width, height);

    Graphics::instance()->render();
    while(run){
        sf::sleep(sf::milliseconds(50));
        //auto t = clock();
        next_step();
        EventController::instance()->refresh(Graphics::instance()->getWindow());

        switch(this->presentScene){
            case scene::MainMenu: {
                this->mainMenu->listenEvent();
                this->mainMenu->draw();
                break;
            }
            case scene::MainSettings:{
                this->mainSettings->listenEvent();
                this->mainSettings->draw();
                break;
            }
            case scene::GameSpace: {
                this->gameSpace->listenEvent();
                this->gameSpace->draw();
                break;
                break;
            }
            default: {

                break;
            }
        }
        Graphics::instance()->render();

        if(EventController::instance()->isClosed())
            Exit();

        //std::cout << (clock() - t) * 1. / CLOCKS_PER_SEC << '\n';
        /*
        while(ActionControler::instance()->getAction(types)) {
            switch(types.swith_scene) {
                case actionTypes::switchScene::GameSpace: {
                    Game::presentScene = Game::scene::GameSpace;
                    break;
                }
                default: {

                    break;
                }
            }
        }
        */
    }
    
    return 0;
}

void Game::Exit() {
    run = false;
}
