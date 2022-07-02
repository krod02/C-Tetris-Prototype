//
//  Piece.cpp
//  TetrisProject
//
//  Created by Kevin Rodriguez on 4/26/22.
//

#include <iostream>
#include <array>

using std::cout;
using std::string;
using std::array;

class Piece{
protected:
    array<array<char, 3>,3> piece;
    
    //array holding spawn point for the pieces
    //will be used in for loops as a way to track where piece is located within screen array
    const array<int, 2> position = {2,5};
    
    //speed function
    int speed(){
        return 1;
    }
public:
    
    //function to print out piece
    void print_piece(array<array<char, 3>,3> new_piece){
        for(int i = 0; i<3; i++){
            for(int j = 0; j<3; j++){
                cout << new_piece[i][j];
            }
            cout << "\n";
        }
    }
    
    
    
    array<array<char, 3>,3> current_piece;//array holds the current piece being shifted
    
    //function to rotate piece
    void rotate_piece(string rotation, array<array<char, 3>,3> cur_piece){
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
    }
    
    
    
    array<int, 2> current_pos = position;//assigns public array to const array position
    
    array<int, 2> get_pos(){return current_pos;}//get function for position array
    
    void reset_position(){current_pos = position;}//resets postion array back to original values
    
    array<array<char, 3>,3> get_piece(){return piece;}//get function for piece
    
};

class Oblock: public Piece{
private:
    array<char, 2> cell = {'0','0'};
    
    
    
    
    int block_speed;
    
protected:
    //overridden array
    //holds shape of tetris block
    array<array<char, 3>,3> piece = {{
        {'1','1','1'},
        {'1','1','1'},
        {'1','1','1'}
    }};

    //overridden speed functon
    int speed(int new_speed){
        return new_speed;
    }

public:
    
    //default constructor that assigns default speed
    Oblock(){
        block_speed = 1;
    }
    Oblock(int new_speed){
        block_speed = speed(new_speed);//no need to call speed but will be needed eventually once more logic is added
    }
    //getPiece function
    array<array<char, 3>,3> get_piece(){return piece;}
    
    //overriden position function that returns cell
    int position(char cell[2]){
        return cell[2];
    }
    };





class Tblock: public Piece{
private:
    array<char, 2> cell = {'0','0'};//cell block
    
    
    
    int block_spped;//private variable for speed of block
    
protected:
    //overridden array
    //holds shape of tetris block
    array<array<char, 3>,3> piece = {{
        {'.','1','.'},
        {'.','1','.'},
        {'1','1','1'}
    }};
    
    //overridden speed functon
    int speed(int new_speed){
        return new_speed;
    }

public:
 
    //default constructor that assigns default speed
    Tblock(){
        block_spped = 1;
    }
    Tblock(int new_speed){
        block_spped = speed(new_speed);//no need to call speed but will be needed eventually once more logic is added
    }
    //get_piece funtion
    array<array<char, 3>,3> get_piece(){return piece;}

    //overriden position function that returns cell
    int position(char cell[2]){
        return cell[2];
    }
    
    
    
};

class Iblock: public Piece{
private:
    array<char, 2> cell = {'0','0'};//cell block
    
    
    
    int block_spped;//private variable for speed of block
    
protected:
    //overridden array
    //holds shape of tetris block
    array<array<char, 3>,3> piece = {{
        {'.','1','.'},
        {'.','1','.'},
        {'.','1','.'}
    }};
    
    //overridden speed functon
    int speed(int new_speed){
        return new_speed;
    }

public:
 
    //default constructor that assigns default speed
    Iblock(){
        block_spped = 1;
    }
    Iblock(int new_speed){
        block_spped = speed(new_speed);//no need to call speed but will be needed eventually once more logic is added
    }
    //get_piece funtion
    array<array<char, 3>,3> get_piece(){return piece;}

    //overriden position function that returns cell
    int position(char cell[2]){
        return cell[2];
    }
    
    
    
};

class Lblock: public Piece{
private:
    array<char, 2> cell = {'0','0'};//cell block
    
    
    
    int block_spped;//private variable for speed of block
    
protected:
    //overridden array
    //holds shape of tetris block
    array<array<char, 3>,3> piece = {{
        {'1','.','.'},
        {'1','.','.'},
        {'1','1','1'}
    }};
    
    //overridden speed functon
    int speed(int new_speed){
        return new_speed;
    }

public:
 
    //default constructor that assigns default speed
    Lblock(){
        block_spped = 1;
    }
    Lblock(int new_speed){
        block_spped = speed(new_speed);//no need to call speed but will be needed eventually once more logic is added
    }
    //get_piece funtion
    array<array<char, 3>,3> get_piece(){return piece;}

    //overriden position function that returns cell
    int position(char cell[2]){
        return cell[2];
    }
    
    
    
};

class Sblock: public Piece{
private:
    array<char, 2> cell = {'0','0'};//cell block
    
    
    
    int block_spped;//private variable for speed of block
    
protected:
    //overridden array
    //holds shape of tetris block
    array<array<char, 3>,3> piece = {{
        {'.','1','1'},
        {'.','1','.'},
        {'1','1','.'}
    }};
    
    //overridden speed functon
    int speed(int new_speed){
        return new_speed;
    }

public:
 
    //default constructor that assigns default speed
    Sblock(){
        block_spped = 1;
    }
    Sblock(int new_speed){
        block_spped = speed(new_speed);//no need to call speed but will be needed eventually once more logic is added
    }
    //get_piece funtion
    array<array<char, 3>,3> get_piece(){return piece;}

    //overriden position function that returns cell
    int position(char cell[2]){
        return cell[2];
    }
    
    
    
};
