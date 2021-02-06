#include <vector>
#include <memory>

///////////////////////////////////////////////////////////////////////////////

class Piece{

        public:
        int getX(){ return x; }
        int getY(){ return y; }
        int move(const int x, const int y);

        private:
        int x, y;
};
///////////////////////////////////////////////////////////////////////////////

class Farmer : public Piece{

        public:
        Piece child();

        private:
        bool used;
};
///////////////////////////////////////////////////////////////////////////////

class Soldier : public Piece{

        public:
        void feed();

        private:
        bool fed;
};
///////////////////////////////////////////////////////////////////////////////

class PlayerState{

        public:
        void starve();
        void attack(    const int fromX,        const int fromY,
                        const int toX,          const int toY           );

        private:
        int width, height;
        std::vector<std::unique_ptr<Farmer>> farmers;
        std::vector<std::unique_ptr<Soldier>> soldiers;
        
};
///////////////////////////////////////////////////////////////////////////////

class BoardState{
        
        private:
        std::vector<PlayerState> players;
};

