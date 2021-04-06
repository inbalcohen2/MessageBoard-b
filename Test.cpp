#include "Board.hpp"
#include "Direction.hpp"
#include "doctest.h"
using namespace ariel;
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

ariel::Board b;
string expectd; string actual;


TEST_CASE("test 1 : insert an empty word-the length of the board does not changed "){
Board bo;
int row=0, column=4;
 b.post(0, 4, Direction::Vertical, "");
 CHECK(row == b.getRow());
 CHECK(column == b.getColumn());
}

TEST_CASE( "test 2 :checking length 0 -empty board")
{
    Board b;
    CHECK(b.read(0, 0, Direction::Horizontal, 0) == "");
    CHECK(b.read(3, 2, Direction::Horizontal, 0) == "");
    CHECK(b.read(5, 1, Direction::Horizontal, 1) == string("_"));
    CHECK(b.read(6, 3, Direction::Vertical, 1) == string("_"));
    CHECK(b.read(7, 10, Direction::Horizontal, 5) == string("_____"));
    CHECK(b.read(11, 4, Direction::Vertical, 5) == string("_____"));
}


TEST_CASE("test 4 : check if the read function read words more than the post ") {
            Board b;
            b.post(1,2, Direction::Vertical,"inbalCohenCpp");
            expectd = "inbalCohenCpp__";
            actual = b.read(1,2, Direction::Vertical,15);
            CHECK(expectd == actual);

          }

// TEST_CASE("test 5 :The distances between ad and ad are very large. ")
// {
//     Board board;
//     unsigned int test_max = 12345678;
//     b.post(0,0,Direction::Vertical,"inbalCohen");
//     CHECK_THROWS(b.post(test_max, 1200, Direction::Vertical, "inbal"));
//     CHECK_THROWS(b.post(12, test_max, Direction::Horizontal, "inbal"));
// }

TEST_CASE("test 6 : insert an empty word -check if the read function return empty word") {
        Board b;
         int  row = 3 , column = 4;
            b.post(3, 4, Direction::Vertical,"");
            CHECK(b.read(3, 4, Direction::Vertical, 1) == "_");
            expectd = "";
            actual = b.read(3, 4, Direction::Vertical,0);
            CHECK(expectd == actual);
        }

TEST_CASE("Test 7 : Checking strings and overriding text")
{
    Board b;

    b.post(0, 0, Direction::Horizontal, "Message");
	b.post(1, 0, Direction::Vertical, "board");
    CHECK(b.read(0, 0, Direction::Horizontal, 7) + " "
    + b.read(1, 0, Direction::Vertical, 5) == "Message board");
    CHECK(b.read(0, 0, Direction::Horizontal, 4) == "Mess");
    CHECK(b.read(1, 1, Direction::Horizontal, 3) == "___");
    //   Message__
    //   b__
    //   o__
    //   a__
    //   r__
    //   d__
    b.post(0, 1, Direction::Horizontal, "inbal");
    CHECK(b.read(0, 1, Direction::Horizontal, 5) == "inbal");
	CHECK(b.read(0, 0, Direction::Horizontal, 7) == "Minbale"); 
    //   Minbale__
    //   b__
    //   o__
    //   a__
    //   r__
    //   d__
    b.post(0, 0, Direction::Horizontal, "inbalCohen");
    b.post(1, 0, Direction::Vertical, "_");
    CHECK(b.read(0, 0, Direction::Horizontal, 10) == "inbalCohen");
    CHECK(b.read(1, 0, Direction::Vertical, 3) == "_oa");
    
    b.post(1, 5, Direction::Vertical, "pp");
    CHECK(b.read(0, 5, Direction::Vertical, 3) == "Cpp");

    b.post(1, 1, Direction::Vertical, "otice");
    CHECK(b.read(0, 1, Direction::Vertical, 6) == "notice");

    b.post(1, 2, Direction::Vertical, "oard");
    CHECK(b.read(0, 2, Direction::Vertical, 5) == "board");
    // inbalCohen__
    // oop___
    // tap___
    // ir__
    // cd__
    // e___
    // __
}

TEST_CASE("Test 8 :  Checking strings and overriding text ")
{ 
    Board b;
    b.post(0, 0, Direction::Horizontal, "IIIII");
    CHECK(b.read(0, 0, Direction::Horizontal, 5) == "IIIII");
    b.post(0, 0, Direction::Vertical, "IIIII");
    CHECK(b.read(0, 0, Direction::Horizontal, 5) == "IIIII");
    b.post(0, 1, Direction::Vertical, "NNNNN");
    CHECK(b.read(0, 0, Direction::Horizontal, 5) == "INIII");
    b.post(0, 2, Direction::Vertical, "BBBBB");
    CHECK(b.read(0, 0, Direction::Horizontal, 5) == "INBII");
    b.post(0, 3, Direction::Vertical, "AAAAA");
    CHECK(b.read(0, 0, Direction::Horizontal, 5) == "INBAI");
    b.post(0, 4, Direction::Vertical, "LLLLL");
    b.post(0, 6, Direction::Horizontal, "COHEN");
    CHECK(b.read(0, 0, Direction::Horizontal, 11) == "INBAL_COHEN");
    CHECK(b.read(1, 0, Direction::Horizontal, 5) == "INBAL");
    CHECK(b.read(2, 0, Direction::Horizontal, 5) == "INBAL");
    CHECK(b.read(3, 0, Direction::Horizontal, 5) == "INBAL");
    CHECK(b.read(4, 0, Direction::Horizontal, 5) == "INBAL");
    CHECK(b.read(4, 0, Direction::Horizontal, 5) == "INBAL");
    //   INBAL_COHEN_
    //   INBAL___
    //   INBAL___
    //   INBAL___
    //   INBAL___
}

 TEST_CASE("test 9 : insert numbers, symbols, spaces and drop a line in the message")
{
    Board b;

    CHECK_NOTHROW(b.post(30, 30, Direction::Horizontal, "*"));
    CHECK(b.read(30, 30, Direction::Horizontal, 1) == "*");
    CHECK_NOTHROW(b.post(31, 31, Direction::Horizontal, "@"));
    CHECK(b.read(31, 31, Direction::Horizontal, 1) == "@");
    CHECK_NOTHROW(b.post(32, 32, Direction::Vertical, "126%7"));
    CHECK(b.read(32, 32, Direction::Vertical, 5) == "126%7");
    CHECK_NOTHROW(b.post(33, 33, Direction::Vertical, "?><%"));
    CHECK(b.read(33, 33, Direction::Vertical, 3) == "?><");
}





