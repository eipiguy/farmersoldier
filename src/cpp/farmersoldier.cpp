#include "farmersoldier.h"

///////////////////////////////////////////////////////////////////////////////
// Board

Game :: Game( const int width, const int height ):
                rows(height),
                columns(width)
{
        
        std::cout << "Creating " 
                << width << " by " << height 
                << " game." << std::endl;
                
//---------------------------------------------------------------------------//
// Add all board board

        const int n = width*height;
        
        std::cout << "Adding " << n << " board to board." 
                << std::endl;

        for(int i=0;i<n;++i){ board.emplace_back(); }

        std::cout << board.size() << " board added."
                << std::endl;

// Places added
//---------------------------------------------------------------------------//
// Set up starting positions

        std::cout << "Setting up starting positions." << std::endl;
       
        std::cout << "Setting up position 0,0 for player 1" << std::endl;
        
        board.front().controller = 1;
        board.front().unmovedFarmers = 1;
        board.front().unmovedSoldiers = 1;
       
        std::cout << board[0].controller << std::endl;
        

        std::cout << "Setting up position " 
                << rows-1 << ',' << columns-1 
                << " for player 2" << std::endl;
        
        board.back().controller = 2;
        board.back().unmovedFarmers = 1;
        board.back().unmovedSoldiers = 1;

        std::cout << "Starting positions set up." << std::endl;

// Starting positions set up
//---------------------------------------------------------------------------//

        
        std::cout << "Game made.\n" << std::endl;
        
}

/*****************************************************************************/
// Print game state

void Game :: print(){

        int m,n;
        char p[2];
        char q[2];

        for(int i=0;i<rows;++i){
                
                m = i*columns; 
 
                for(int j=0;j<columns;++j){ std::printf(" _____"); }
                std::cout << std::endl;

//---------------------------------------------------------------------------//
// coordinates

                for(int j=0;j<columns;++j){ std::printf( "|%2d,%2d", i, j ); }
                std::cout << '|' << std::endl;

//---------------------------------------------------------------------------//
// child status and player number
                
                for(int j=0;j<columns;++j){
                      
                        n = m+j; 
                        
                        if(board[n].controller > 0){
                                p[0] = 'P';
                                p[1] = '0' + board[n].controller;
                        }else{ p[0]=' '; p[1]=' '; } 
                        
                        std::printf( "| %c %c%c", 
                                board[n].hasChild ? 'c' : ' ',
                                p[0], p[1]
                        );
                }
                std::cout << '|' << std::endl;

//---------------------------------------------------------------------------//
// number of farmers

                for(int j=0;j<columns;++j){
                      
                        n = m+j; 
                        
                        if(board[n].unmovedFarmers > 0){
                                p[0] = '0' + board[n].unmovedFarmers;
                                p[1] = 'F';
                        }else{ p[0]=' '; p[1]=' '; } 
                        
                        if(board[n].movedFarmers > 0){
                                q[0] = '0' + board[n].movedFarmers;
                                q[1] = 'F';
                        }else{ q[0]=' '; q[1]=' '; } 
                        
                        std::printf( "|%c%c %c%c", p[0], p[1], q[0], q[1] );
                }
                std::cout << '|' << std::endl;

//---------------------------------------------------------------------------//
// number of soldiers

                for(int j=0;j<columns;++j){
                      
                        n = m+j; 
                        
                        if(board[n].unmovedSoldiers > 0){
                                p[0] = '0' + board[n].unmovedSoldiers;
                                p[1] = 'S';
                        }else{ p[0]=' '; p[1]=' '; } 
                        
                        if(board[n].movedSoldiers > 0){
                                q[0] = '0' + board[n].movedSoldiers;
                                q[1] = 'S';
                        }else{ q[0]=' '; q[1]=' '; } 
                        
                        std::printf( "|%c%c %c%c", p[0], p[1], q[0], q[1] );
                }
                std::cout << '|' << std::endl;

        }

        for(int j=0;j<columns;++j){ std::printf(" _____"); }
        std::cout << std::endl;
}
