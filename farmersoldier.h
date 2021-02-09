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
        Piece( const bool newChild ) : child(newChild), moved(false) {}

        int move( const int x, const int y );

        private:
        bool child;
        bool moved;
};
///////////////////////////////////////////////////////////////////////////////

class Farmer : public Piece{

        public:

        private:
};

///////////////////////////////////////////////////////////////////////////////

class SoldierGroup : public Piece{

        public:
        SoldierGroup( const int numIn ) 
                : Piece(false), numSoldiers(numIn), fedSoldiers(0) {}
                
        int needFood(){ return numSoldiers - fedSoldiers; }
        void feed();
        
        private:
        int numSoldiers;
        int fedSoldiers;
};
///////////////////////////////////////////////////////////////////////////////

class Place{
        
        public:
        Place(  const int xIn,          const int yIn,
                const bool hasFarmer,   const int numSoldiers );

        private:
        int x, y;
        std::unique_ptr<Farmer> localFarmer = nullptr;
        std::unique_ptr<SoldierGroup> localSoldiers = nullptr;
};
///////////////////////////////////////////////////////////////////////////////

class Player{

        public:
        Player( const int playerNumber,
                const int widthIn, const int heightIn );
        
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
                std::cout << "New board, size: " 
                        << width << " by " << height << std::endl;
        }

        void addPlayer();
        void startGame();
        void nextTurn();

        private:
        const int maxPlayers = 4;
        const int width, height;
        std::vector<Player> players;
        std::vector<Place> places; 
        int turn;
};

