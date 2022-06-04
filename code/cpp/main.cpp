#include "farmersoldier.h"

typedef Game::Player Player;

///////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv){

        const int w = 3, h = 3;         // board size
        Game game(w,h);
        game.print();

        std::unique_ptr<Player> player1 = game.addPlayer();
        return 0;
}
