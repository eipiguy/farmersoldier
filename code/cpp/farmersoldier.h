#include <iostream>
#include <vector>
#include <memory>

///////////////////////////////////////////////////////////////////////////////
// Game Class

class Game{

        private:
        int turn = -1;
        const int rows;
        const int columns;

/*****************************************************************************/
// Nested Place Class

        struct Place{

                int controller = 0;
                
                bool hasChild = false;
                
                int unmovedFarmers = 0;
                int movedFarmers = 0;
                
                int unmovedSoldiers = 0;
                int movedSoldiers = 0;

        };

// End Nested Place Class
/*****************************************************************************/
// Continue Game Class Definition
 
        std::vector<Place> board;

/*****************************************************************************/
// Continue Game Class Definition

        public:
        Game( const int width, const int height );

/*****************************************************************************/
// Nested Player Class
        
        class Player{

                private:
                int number;

                public:
        };

// End Nested Player Class
/*****************************************************************************/
// Continue Game Class Definition

        std::unique_ptr<Player> addPlayer(){
                return std::make_unique<Player>(); 
        }
        void print();

};
