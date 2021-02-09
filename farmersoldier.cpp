#include "farmersoldier.h"

///////////////////////////////////////////////////////////////////////////////
// Farmer



///////////////////////////////////////////////////////////////////////////////
// SoldierGroup



///////////////////////////////////////////////////////////////////////////////
// Place


Place :: Place( const int xIn,          const int yIn,
                const bool hasFarmer,   const int numSoldiers )
        : x(xIn), y(yIn){

        if(hasFarmer);
        if(numSoldiers>0){

        }if(numSoldiers<0){
                std::cout << "Cannot have negative soldiers" << std::endl;
        }
}


///////////////////////////////////////////////////////////////////////////////
// Player

Player :: Player(       const int playerNumber,
                        const int widthIn, const int heightIn ){

        const int xLoc = (widthIn-1)*(playerNumber%2);
        const int yLoc = (heightIn-1)*((playerNumber%2)-1);
        
        //friendlyPlaces.emplace_back( xLoc, yLoc, 1, 1 );
        std::cout << "New player " << playerNumber 
                << " added friendly place at (" << xLoc << ',' << yLoc
                << ") with\n"
                << "1 farmer and 1 soldier" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// BoardState

void BoardState :: addPlayer(){
        
        const int np = players.size();
        if( np < maxPlayers ){
                players.emplace_back( np, width, height );
                std::cout << "Added player number " << np+1 << std::endl;
        }else{
                std::cout << "Failed to add player;" << std::endl;
                std::cout << "already have max 4 players!" << std::endl;
        }
}
