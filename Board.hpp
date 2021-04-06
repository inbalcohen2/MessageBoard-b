#include <string>
#include "Direction.hpp"
#include <limits>
#include <map>
using namespace std;

namespace ariel
{
    class Board {

        private:
        map<uint,map<uint,char>>  map;
        pair<uint,uint> max_;
        pair<uint,uint> min_;

        public:
        Board() { 
            max_.first=0 ;
             max_.second = 0;
            min_.first =numeric_limits<int>::max();
             min_.second = numeric_limits<int>::max();

        }
        const uint & getRow() const {
            return max_.first; }
        const uint & getColumn() const {
            return  max_.second;}
        void post(unsigned int,unsigned int,Direction,const string &);
        std::string read(unsigned int,unsigned int,Direction,unsigned int);
        void show();
        ~Board(){ }

        };
}