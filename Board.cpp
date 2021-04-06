#include <iostream>
#include "Board.hpp"
#include <ctype.h>
using namespace std;

namespace ariel {

    void Board::post(uint row, uint column, Direction direction, const string & message) {
    //FIRST - ROW SECOND COLUMN

       max_.first=max(max_.first,row);
       max_.second=max(max_.second,column);
       min_.first = min(min_.first,row);
       min_.second=min(min_.second,column);


       
        for(char char_: message){
            map[row][column]=char_;

            if(direction == Direction::Horizontal){
                column++ ;
            }else{
                row++;
            } 
        }
}
     string Board::read(unsigned int r, unsigned int c, Direction d, unsigned int length)
    {
        string msg;

        for(uint i=0; i<length; i++){
        if(map[r][c] == '\0'){
            msg += '_';
        }else{
           msg += map[r][c];
        }
           if (d == Direction::Horizontal){
              c++;
           }  
           else{
              r++;
           } 
        }
        return msg;
    }

    void Board::show() {
        std::cout << min_.first <<" "<< max_.first << std::endl;
           std::cout << min_.second <<" "<< max_.second << std::endl;
        for (uint i = this-> min_.first-1; i <= this->max_.first+3; i++) {
            for (uint j = this->min_.second-1; j <= this->max_.second+3; j++) {
                if(map[i][j] == '\0'){
                     cout << '_' ;
                }else{
                     cout << this->map[i][j] ;
                }
            }
            cout << "\n\n";
        }
    }
        
        } 
        
