
#include<iostream>
#include<iomanip>
#include<conio.h>
#include<cstdlib>

#include "Processor.h"

using namespace std;

int main()
{
    const string csvFilePath = "data/data_source_test.txt";
    ifstream inFile( csvFilePath );
    Vector<string> csvFilePaths;
    Vector<WindRecType> windRecLog;
    WindRecType windRecType;

    Processor::GetInstance();
    Processor::GetInstance().LoadCSVFilePathToVector( csvFilePaths, inFile, csvFilePath );
    Processor::GetInstance().LoadCSVDataToVector( csvFilePaths, windRecLog, windRecType );

    char user_choice;
    do
    {
        std::cout   << Constant::MENU_OPTIONS_MSG
                    << Constant::MENU_OPTION_ONE_MSG
                    << Constant::MENU_OPTION_TWO_MSG
                    << Constant::MENU_OPTION_THREE_MSG
                    << Constant::MENU_OPTION_FOUR_MSG
                    << Constant::MENU_OPTION_FIVE_MSG << std::endl;

        std::cout << Constant::SELECTION_INPUT;
        user_choice = getch();
        switch( user_choice )
        {
        case '1':
            std::cout << Constant::SELECTED_OPTION_ONE_MSG << std::endl;
            cout << "Test One: This is the option one u selected." << endl;
            break;
        case '2':
            std::cout << Constant::SELECTED_OPTION_TWO_MSG << std::endl;

            break;
        case '3':
            std::cout << Constant::SELECTED_OPTION_THREE_MSG << std::endl;
            break;
        case '4':
            std::cout << Constant::SELECTED_OPTION_FOUR_MSG << std::endl;
            break;
        case '5':
            std::cout << Constant::SELECTED_OPTION_FIVE_MSG << std::endl;
            exit(0);
            break;
        default:
            break;
        }
        std::cout << Constant::INFO( Constant::PRESS_ENTER_TO_CONTINUE_MSG ) << std::endl;
        while( getch() != 13 );
        system("cls");
    }
    while( user_choice !=27 );


    return 0;
}
