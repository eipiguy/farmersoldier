#include <iostream>
#include <vector>
#include <memory>

class Piece;
class Farmer;
class SoldierGroup;

class Place;

class Player;
class BoardState;

///////////////////////////////////////////////////////////////////////////////

class Piece{

        public:
        Piece( const bool newChild ) : child( newChild ), moved( false ) {}
        ~Piece(){ std::cout << "Piece removed" << std::endl; }

        int move( const int x, const int y );

        private:
        bool child;
        bool moved;
};
///////////////////////////////////////////////////////////////////////////////

class Farmer : public Piece{

        public:
        Farmer( const bool newChild ) : Piece( newChild ) {}
        ~Farmer(){ std::cout << "Farmer removed" << std::endl;}

        private:
};

///////////////////////////////////////////////////////////////////////////////

class SoldierGroup : public Piece{

        public:
        SoldierGroup( const int numIn ) 
                : Piece( false ), numSoldiers( numIn ), fedSoldiers( 0 ) {}

        ~SoldierGroup(){ std::cout << "SoldierGroup removed" << std::endl;}

        int needFood(){ return numSoldiers - fedSoldiers; }
        void feed();
        
        private:
        int numSoldiers;
        int fedSoldiers;
};
///////////////////////////////////////////////////////////////////////////////

class Place{
        
        public:
        Place(  const int playerIn,
                const int xIn,          const int yIn,
                const bool hasFarmer,   const int numSoldiers );
        //~Place(){ std::cout << "Place removed"; }


        int getX(){ return x; }
        int getY(){ return y; }

        private:
        int player;
        int x, y;
        std::unique_ptr<Farmer> localFarmer = nullptr;
        std::unique_ptr<SoldierGroup> localSoldiers = nullptr;
};
///////////////////////////////////////////////////////////////////////////////

class Player{

        public:
        Player( const int playerNumber,
                const int widthIn, const int heightIn,
                std::unique_ptr<Place> startingPlace );
        //~Player(){ std::cout << "Player removed"; }        

        void starve();
        bool hasPieces( const int x, const int y );
        void attack(    const int fromX,        const int fromY,
                        const int toX,          const int toY           );

        private:
        std::vector<std::unique_ptr<Place>> friendlyPlaces; 
};
///////////////////////////////////////////////////////////////////////////////

class BoardState{

        public:
        BoardState(     const int widthIn, 
                        const int heightIn)
                :       width(widthIn),
                        height(heightIn){
                std::cout << "\nNew board, size: " 
                        << width << " by " << height << std::endl;
        }
        ~BoardState(){ std::cout << "BoardState removed" << std::endl; }

        void addPlayer();
        void startGame();
        void nextTurn();

        void printState();

        private:
        const int maxPlayers = 4;
        const int width, height;
        std::vector<Player> players;
        std::vector<Place> places; 
        int turn;
};

