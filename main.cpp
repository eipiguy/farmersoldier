#include "farmersoldier.h"

///////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv){

        const int w = 3, h = 3;         // board size
        const int p = 2;                // number of players

        BoardState board(w,h);
        for(int i=0;i<p;++i){ board.addPlayer(); }

        return 0;
}
