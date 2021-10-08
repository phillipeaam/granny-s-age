#include <iostream>
#include <string>
#include <ctime>

using namespace std;

void DisplayPortraitASCIIArt()
{
    cout << " ________________________\n";
    cout << "|.----------------------.|\n";
    cout << "||                      ||\n";
    cout << "||       ______         ||\n";
    cout << "||     .;;;;;;;;.       ||\n";
    cout << "||    /;;;;;;;;;;;\"     ||\n";
    cout << "||   /;/`    `-;;;;; . .||\n";
    cout << "||   |;|__  __  \";;;|   ||\n";
    cout << "||.-.|;| e`/e`  |;;;|   ||\n";
    cout << "||   |;|  |     |;;;|'--||\n";
    cout << "||   |;|  '-    |;;;|   ||\n";
    cout << "||   |;;\" --'  /|;;;|   ||\n";
    cout << "||   |;;;;;---'\"|;;;|   ||\n";
    cout << "||   |;;;;|     |;;;|   ||\n";
    cout << "||   |;;.-'     |;;;|   ||\n";
    cout << "||'--|/`        |;;;|--.||\n";
    cout << "||;;;;    .     ;;;;.\";;||\n";
    cout << "||;;;;;-.;_    /.-;;;;;;||\n";
    cout << "||;;;;;;;;;;;;;;;;;;;;;;||\n";
    cout << "||jgs;;;;;;;;;;;;;;;;;;;||\n";
    cout << "'------------------------'";
}

void DisplayIntroduction(int GrannyAgeAtFirstBorn, int YearsDifference, int ChildrenCount, int CurrentJaneAge)
{
    cout << "\n[How Old is Granny Puzzle]\n\nTom asked his Granny how old she was.\nRather than giving him a straight answer, she replied:\n";

    DisplayPortraitASCIIArt();

    cout << "\n\n\"I have " << ChildrenCount << " children, and there are " << YearsDifference << " years between each one and the next.\nI had my first child (your Uncle Peter) when I was " << GrannyAgeAtFirstBorn << ".\nNow the youngest one (Your Auntie Jane) is " << CurrentJaneAge << " herself.\nThat's all I'm telling you!\"\n" << endl;
}

bool DisplayQuestion(string QuestionHeader, int CorrectResult)
{
    const string CorrectAnswer = "~> Correct answer.";
    const string WrongAnswer = "~> Wrong answer.";

    int userInput;

    cout << QuestionHeader;
    cin >> userInput;

    cin.clear();
    cin.ignore();

    if (userInput == CorrectResult)
    {
        cout << CorrectAnswer << "\n\n";
        return true;
    }
    else
    {
        cout << WrongAnswer << "\n\n";
        return false;
    }
}

bool DisplayChildQuestion(int ChildIndex, int GrannyAgeAtFirstBorn, int YearsDifference)
{
    const string QuestionHeaderStart = "[Question]\nHow old was Tom's Granny when the ";
    const string QuestionHeaderEnding = "* child born?\n";

    string Header = QuestionHeaderStart + to_string(ChildIndex) + QuestionHeaderEnding;
    int CorrectAnswer = GrannyAgeAtFirstBorn + (YearsDifference * (ChildIndex - 1));
    
    return DisplayQuestion(Header, CorrectAnswer);
}

bool DisplayFinalQuestion(int GrannyAgeAtFirstBorn, int YearsDifference, int ChildrenCount, int CurrentJaneAge)
{
    string Header = "[Question]\nIf Auntie Jane is " + to_string(CurrentJaneAge) + ", how old is Tom's Granny?\n";
    int CorrectAnswer = GrannyAgeAtFirstBorn + (YearsDifference * (ChildrenCount - 1)) + CurrentJaneAge;

    return DisplayQuestion(Header, CorrectAnswer);
}

int main()
{
    srand(time(NULL));

    const int GrannyAgeAtFirstBorn = 18 + (rand() % 4);
    const int YearsDifference = 3 + (rand() % 4);
    const int CurrentJaneAge = 16 + (rand() % 4);
    const int ChildrenCount = 3 + (rand() % 4);
    
    DisplayIntroduction(GrannyAgeAtFirstBorn, YearsDifference, ChildrenCount, CurrentJaneAge);

    int ChildIndex = 0;
    bool CanContinue = false;
    const bool IsEven = rand() % 2 == 0;

    while(ChildIndex < ChildrenCount)
    {
        ChildIndex++;
        
        if (IsEven && ChildIndex % 2 != 0) continue;
        else if (!IsEven && ChildIndex % 2 == 0) continue;

        CanContinue = DisplayChildQuestion(ChildIndex, GrannyAgeAtFirstBorn, YearsDifference);

        if (!CanContinue) break;
    }

    if (CanContinue)
    {
        CanContinue = DisplayFinalQuestion(GrannyAgeAtFirstBorn, YearsDifference, ChildrenCount, CurrentJaneAge);
    }    

    if (CanContinue)
    {
        cout << "***************************************\n*** Congratulations! You nailed it! ***\n***************************************\n\n";
    }    

    // Added to let the player see the final result before closing the window
    system("pause");

    return 0;
}