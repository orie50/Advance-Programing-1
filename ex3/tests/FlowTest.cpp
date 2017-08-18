#include <fstream>
#include "gtest/gtest.h"
#include "../src/Flow.h"
/******************************************************************************
* The Test Operation: redircet cin and cout to files, and verify correct output
* and that there are no exceptions
******************************************************************************/
TEST(FlowTest, initializeAndRunTest){
    string buffer;
    const int NUM_OF_LINES_IN_CORRECT_OUTPUT = 9;
    ifstream in("../testsFiles/flow.txt");
    ofstream out("../testsFiles/output.txt");
    cin.rdbuf(in.rdbuf()); //redirect std::cin
    streambuf *coutbuf = cout.rdbuf(); //save old buf
    cout.rdbuf(out.rdbuf()); //redirect std::cout
    Flow flow;
    // flow running loop
    while (!flow.shouldStop) {
        EXPECT_NO_THROW(flow.initialize());
        if (!flow.shouldStop) {
            EXPECT_NO_THROW(flow.run());
        }
    }
    // close and clear the streams
    in.close();
    out.close();
    cin.clear();
    cout.clear();
    //verify that the output is correct according to correct.txt
    ifstream correct("../testsFiles/correct.txt");
    ifstream test("../testsFiles/output.txt");
    string fromCorrect;
    string fromTest;
    int numOfLines = 0;
    //compare line by line
    while(!correct.eof() && !test.eof()){
        getline(correct, fromCorrect);
        getline(test,fromTest);
        EXPECT_EQ(strcmp(fromCorrect.c_str(), fromTest.c_str()) , 0);
        numOfLines++;
    }
    EXPECT_EQ(numOfLines , NUM_OF_LINES_IN_CORRECT_OUTPUT);
    correct.close();
    test.close();
    // restore old cout buff
    cout.rdbuf(coutbuf);
}
