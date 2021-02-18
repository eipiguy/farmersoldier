#include "farmersoldier.h"

///////////////////////////////////////////////////////////////////////////////
// Farmer



///////////////////////////////////////////////////////////////////////////////
// SoldierGroup



///////////////////////////////////////////////////////////////////////////////
// Place


Place :: Place( const int playerIn,
                const int xIn,          const int yIn,
                const bool hasFarmer,   const int numSoldiers )
        : player(playerIn), x(xIn), y(yIn){

        std::cout << "Creating place (" << xIn << ',' << yIn 
                << ") with ";
        
        if(hasFarmer){
                localFarmer = std::unique_ptr<Farmer>( new Farmer(false) );
                std::cout << "1 farmer";
        }else   std::cout << "no farmer";
        
        if(numSoldiers>0){
                localSoldiers = std::unique_ptr<SoldierGroup>
                        ( new SoldierGroup( 1 ) );
                std::cout << " and " << numSoldiers 
                        << " soldiers" << std::endl;
                
        }if(numSoldiers<0){
                std::cout << "\nCannot have negative soldiers" << std::endl;
        }
}


///////////////////////////////////////////////////////////////////////////////
// Player

Player :: Player(       const int playerNumber,
                        const int widthIn, const int heightIn,
                        std::unique_ptr<Place> startingPlace    ){

        std::cout << "Creating player number " << playerNumber << std::endl;

        std::cout << "Player number " << playerNumber
                << " adding starting place at (" << startingPlace -> getX()
                << ',' << startingPlace -> getY() 
                << ") with 1 farmer, and 1 soldier" << std::endl;

        friendlyPlaces.push_back( std::move(startingPlace) );

        std::cout << "Player " << playerNumber 
                << " added friendly place at (" 
                << friendlyPlaces.back() -> getX() << ',' 
                << friendlyPlaces.back() -> getY()
                << ") with 1 farmer and 1 soldier" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////
// BoardState

void BoardState :: addPlayer(){
        
        const int np = players.size();
        if( np < maxPlayers ){
                std::cout << "\nAdding player number " << np << std::endl;

                const int xLoc = (width-1) * ( np %2 );
                const int yLoc = (height-1) * ( ( (np/2)+(np%2) ) %2 ) ;
                
                places.emplace_back( np, xLoc, yLoc, true, 1 );

                players.emplace_back( np, width, height, 
                                std::move( 
                                        std::unique_ptr<Place>(&places.back()) 
                                ) );

                std::cout << "Added player number " << np << std::endl;
        }else{
                std::cout << "Failed to add player;" << std::endl;
                std::cout << "already have max 4 players!" << std::endl;
        }
}

/*****************************************************************************/

void BoardState :: printState(){

        

}
