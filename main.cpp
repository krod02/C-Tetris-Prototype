//
//  main.cpp
//  TetrisProject
//
//  Created by Kevin Rodriguez on 4/26/22.
//

#include <iostream>
//#include "Piece.cpp"
#include "Screen.cpp"
#include <array>

using std::cout;
using std::string;
using std::array;
using std::cin;

int main() {
    Tblock t = Tblock();
    Oblock o = Oblock();
    Piece p = Piece();
    Iblock I = Iblock();
    Lblock L = Lblock();
    Sblock S = Sblock();
    
    Screen s = Screen();
    
    bool end_game = true;

    do{
        p.reset_position();//resetting location of piece for new piece
        p.current_piece = s.add_piece(s.generate_piece());//giving variable current piece the value of a randomly generated piece array
        cout << "\n\n";
        s.print_screen();//printing the screen with random piece
        cout << "\n\n";
        
        for(int i = 0; i < 10; i++){//loops thru ten times because thats how long it takes piece to reach the edge of screen
            //gave user choice to end game because game still doesnt work properly
            //gave user choice to spawn piece for testing reasons due to game being unfinished
            char user_choice;
            cout << "Would you like to shift, rotate your piece, spawn new piece or quit game?\n";
            cout << "Shift left = 'L', shift right = 'R', shift down = 'D', rotate = 'T', spawn piece = 'S': \n";
            cout << "Quit game = 'Q': \n";
            cin >> user_choice;
        
            if(user_choice == 'L' || user_choice == 'l'){
                s.shift_left(s.get_screen(), p.get_pos());//shiting piece left
                p.current_pos[1] -= 1;//changing x index by minus one to keep track of correct location in x direction
            }else if(user_choice == 'R' || user_choice == 'r'){
                s.shift_right(s.get_screen(), p.get_pos());//shifting piece right
                p.current_pos[1] += 1;//changing x index by plus one to keep track of correct location in x direction
            }else if(user_choice == 'T' || user_choice == 't'){
                string rot_direction;
                cout << "\nWould you like to rotate your piece to the 'left' or 'right'? \n";
                cin >> rot_direction;
                //to rotate piece, a similar function to add_piece to screen is being used but it is adding rotated piece to last know location indexes
                //s.rotate_piece is using the current initialized piece from line 32 in order to rotate correct piece
                //rotation is buggy. Was unable to figure out how to remove left over '1' char from screen
                s.add_rotated_piece(s.rotate_piece(rot_direction, p.current_piece), p.get_pos());
            }else if(user_choice == 'S' || user_choice == 's'){
                break;
            }else if(user_choice == 'Q' || user_choice == 'q'){
                exit(0);
            }
            //function automatically shifts piece down regardless of input for user_choice
            s.shift_down(s.get_screen(), p.get_pos());
            s.print_screen();
            p.current_pos[0] += 1;//changing y index by adding 1 which keeps track of piece location in y direction
            
        }
        end_game = s.check_height();//checking for char '1' in certain index in order to end game if return value is false
        
    }while(end_game);
    cout << "Game Over!\n";
    
    
    //I was unable to figure out collision and combination of pieces with other pieces due to level of difficulty and not enough time.
    //I enjoyed the challenge and hope to be able to get this project working properly in the future. 
}

