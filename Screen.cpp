//
//  Screen.cpp
//  TetrisProject
//
//  Created by Kevin Rodriguez on 4/27/22.
//

#include <array>
#include <iostream>
#include "Piece.cpp"
#include <stdlib.h>
#include <stdio.h>

using std::array;

class Screen{
private:
    //the screen array
    array<array<char, 13>, 13> screen;
    
    Piece p = Piece();
    Tblock t = Tblock(5);
    Oblock o = Oblock();
    Iblock I = Iblock();
    Lblock L = Lblock();
    Sblock S = Sblock();
    
    
    
public:
    Screen(){ fill_screen();}//default constructor that fills screen
    
    //function that generates a random piece
    //following code for generating a rand num I got from cplusplus.com/reference/cstdlib/rand/
    std::array<array<char, 3>, 3> generate_piece(){
        
        srand(time(NULL));
        int random_piece = rand() % 4;
        array<array<char, 3>,3>empty_array;
        
        
        switch(random_piece){
            case 0:
                empty_array = o.get_piece();
                break;
            case 1:
                empty_array = t.get_piece();
                break;
            case 2:
                empty_array = I.get_piece();
                break;
            case 3:
                empty_array = L.get_piece();
                break;
            case 4:
                empty_array = S.get_piece();
                break;
        }
        return empty_array;//returns array containing random piece
    }
    
    array<int, 2> new_pos = {2,5};
    
    //function to fill up the screen with the character '.'
    void fill_screen(){
        for(auto &s : screen){
            s.fill('.');
        }
    }
    
    //get screen function
    array<array<char, 13>, 13> get_screen(){return screen;}
    
    //function that shifts current piece within the screen array
    //uses current values of position to loop through screen array
    //looping starting at one index under bottom left corner of piece array
    void shift_down(array<array<char, 13>, 13> screen, array<int, 2> position){
        for(int i = position[0]+1; i>=position[0]-2; i--){
            for(int j = position[1]; j<position[1]+3; j++){
                //very little logic for collision do to being unable to figure out correct collision detection
                if(this->screen[i+1][j] == '1'){//checking for collision with char '1' underneath piece
                       break;
                    }
                    else{
                        //checks to see if at bottom edge of screen array
                        if(position[0] >= 12 || (position[0] >= 12 && position[1] >= 10) || (position[0] >= 12 && position[1] == 0)){
                            break;
                        }else{
                            this->screen[i+1][j] = screen[i][j];//moves piece down by one index withing screen
                            this->screen[i][j] = '.';//replaces left behing '1' chars with '.'
                    }
                }
            }
        }
        
        new_pos[0] += 1;
        std::cout << "\n\n";
    }
    
    //function shits piece right
    void shift_right(array<array<char, 13>, 13> screen, array<int, 2> position){
        //using current position values
        //loop starts one index to the right of bottom right index of piece array
        for(int i = position[0]; i>position[0]-3; i--){
            for(int j = position[1]+3; j>=position[1]-2; j--){
                    if(this->screen[i][j+1] == '1'){//checking for collision with char '1' to the right piece
                     
                        break;
                    }
                    else{
                        //checking to see if at right edge of screen
                        if(position[1] >= 10 || (position[0] >= 12 && position[1] >= 10) ){
                            break;
                        }else{
                            this->screen[i][j+1] = screen[i][j];//shifts piece right by one index
                            this->screen[i][j] = '.';//replaces left behing '1' chars with '.'
                        }
                    }
          
            }
        }
        
        new_pos[1] += 1;
        std::cout << "\n\n";
    }
    
    //function shifts piece left
    void shift_left(array<array<char, 13>, 13> screen, array<int, 2> position){
        //using current position values
        //loop starts one index to the left of bottom left index of piece array
        for(int i = position[0]; i>position[0]-3; i--){
            for(int j = position[1]-1; j<=position[1]+2; j++){
                    if(this->screen[i][j-1] == '1' ){//checking collision with char '1' to the left of piece
                     
                        break;
                    }
                    else{
                        //checking to see if at left edge of screen
                        if(position[1] <= 0 || (position[0] >= 12 && position[1] <= 0)){
                            break;
                            
                        }else{
                            this->screen[i][j-1] = screen[i][j];//shifts piece left by one index
                            this->screen[i][j] = '.';//replaces left behing '1' chars with '.'
                        }
                    }
          
            }
        }
        
        new_pos[1] -= 1;
        std::cout << "\n\n";
    }
    
    //function to rotate piece
    //code used to rotate pieces was used from stackoverflow.com/questions/60994928/c-rotate-3x3-grid-made-of-9-character-char-array
    array<array<char, 3>,3> rotate_piece(string rotation, array<array<char, 3>,3> cur_piece){
        if( rotation == "right" || rotation == "Right"){//if input is right, piece will rotate right 90 degrees
            for(int i = 0; i<3/2; i++){
                for(int j = i; j < 3 - i - 1; i++){
                
                    //swapping elements in clockwise direction
                    int temp = cur_piece[i][j];
                    cur_piece[i][j] = cur_piece[3 - 1 - j][i];
                    cur_piece[3 - 1 - j][i] = cur_piece[3 - 1 - i][3 - 1 - j];
                    cur_piece[3 - 1 - i][3 - 1 - j] = cur_piece[j][3 - 1 - i];
                    cur_piece[j][3 - 1 - i] = temp;
                }
            }
        }
        else if( rotation == "left" || rotation == "Left"){//if input is left then piece will rotate left 90 degrees
            for(int i = 0; i<3/2; i++){
                for(int j = i; j < 3 - i - 1; i++){
                    
                    //swapping all elements in the counter-clockwise direction
                    int temp = cur_piece[i][j];
                    cur_piece[i][j] = cur_piece[j][3 - i - 1];
                    cur_piece[j][3 - i - 1] = cur_piece[3 - i - 1][3 - j - 1];
                    cur_piece[3 - i - 1][3 - j - 1] = cur_piece[3 - j - 1][i];
                    cur_piece[3 - j - 1][i] = temp;
                }
            }
        }
        return cur_piece;
    }
    
    
    //function will add tetris pieces to screen to their spawn point of {2,5}
    array<array<char, 3>,3> add_piece( array<array<char, 3>,3> piece){
        for(int i = 0; i<piece.size(); i++){
            for(int j = 0; j<piece.size(); j++){
                this->screen[i][j+5] = piece[i][j];
                
            }
        }
        std::cout << "\n\n";
        return piece;//returns piece array needed for future rotation of piece
    }
    
    
    //function will re-add rotated tetris piece to screen depending on last location
    void add_rotated_piece( array<array<char, 3>,3> piece, array<int, 2> position){
        for(int i = 0; i<piece.size(); i++){
            for(int j = 0; j<piece.size(); j++){
                this->screen[i+position[0]][j+position[1]] = piece[i][j];
            }
        }
        std::cout << "\n\n";
    }
    
    
    //function that checks to see if a piece is near the top
    //if char '1' located at pos {3,5} or anywhere in second row game will end
    bool check_height(){
        bool end_game = true;
        for(int i = 0; i < 13; i++){
            if(this->screen[3][5] == '1' || this->screen[1][i] == '1'){
                end_game = false;
            }
        }
        return end_game;
    }
    

    //function to print out each char in screen array
    void print_screen(){
        for(auto line : screen){
            for(auto pixel : line){
                std::cout << pixel;
            }
            std::cout << "\n";
        }
    }
};
