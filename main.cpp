#include <string> 
#include <iostream>
 
/*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   - you should be left with only your UDTs.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */
struct Person
{
    int age;
    int height;
    float hairLength;
    bool isFemale;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    void run(int howFast, bool startWithLeftFoot);

    struct Foot
    {   
        int numOfSteps;
        void stepForward(int howFast);
        int stepSize(float averageStepSize);
    };

    Foot leftFoot;
    Foot rightFoot;
};

void Person::Foot::stepForward(int howFast)
{
    numOfSteps += (1*howFast);
}

int Person::Foot::stepSize(float averageStepSize)
{
    return static_cast<int>(numOfSteps * averageStepSize);
}

void Person::run(int howFast, bool startWithLeftFoot)
{ 
    if(startWithLeftFoot)
    {
        leftFoot.stepForward(howFast);
        rightFoot.stepForward(howFast);
    }
    else
    {
        rightFoot.stepForward(howFast);
        leftFoot.stepForward(howFast);
    }
    
    

    //To find approximate stride size for women, multiply 0.413 by height in centimeters. Men should multiply 0.415 by their height in centimeters.
    
    //distanceTraveled output will be in cm's
    if(isFemale)
    {   

        distanceTraveled = leftFoot.stepSize(height * 0.413f) + rightFoot.stepSize(height * 0.413f);
    }
    else
    {
        distanceTraveled = leftFoot.stepSize(height * 0.415f) + rightFoot.stepSize(height * 0.415f);
    }
        
}





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 */


struct GamesConsole
{
    //control pads
    int numControlPads = 2;
    // storage drive size
    float storageDriveSize = 128.f;
    // usb ports
    int numUsbPorts = 4;
    // current game
    std::string currentGame;
    // network connections
    int networkConnection = 2;

    // read discs
    void readDisc(std::string gameDisc = "Grand Theft Auto");
    // play games
    void playGame(int numPlayers = 8);
    // connect to network - return if connection successful
    bool connectToNetwork(float connectionSpeed = 1000.f);
};

void GamesConsole::readDisc(std::string myGame)
{
    currentGame = myGame;
}

void GamesConsole::playGame(int numPlayers)
{
    if(numPlayers > numControlPads)
    {
        std::cout << "Sorry, Not enough control pads" << std::endl;
    }
}

bool GamesConsole::connectToNetwork(float connectionSpeed)
{
    if(connectionSpeed > 1.f)
    {
        return true;
    }     
    else
    {
        return false;
    }
}

struct Dog
{
    //fur colour
    std::string furColour = "Brown";
    //age
    float age = 1.f;
    //breed
    std::string breed = "Shih-Tzu";
    //name
    std::string name = "Luna";
    //sex
    bool isFemale = true;

    //fetch 
    void fetch(std::string ballType = "Tennis");
    //sit
    void giveTreat(std::string treatType = "Peanut Butter", int numOfTreats = 4);
    //heel
    float exerciseTime();
};

void Dog::fetch(std::string ballType)
{
    if(ballType == "Tennis")
    {
        giveTreat("Dog Biscuits");
    }
}

void Dog::giveTreat(std::string treatType, int numOfTreats)
{
    if(name == "Luna")
    {
        std::cout << "Give Luna " << numOfTreats << " of " << treatType << std::endl;
    }
}

float Dog::exerciseTime()
{
    float exerciseTimeCalculator = age * 12 * 6;
    if(exerciseTimeCalculator > 75.f)
    {
        return 75.f;
    }
    else
    {
        return exerciseTimeCalculator;
    } 
}

struct Bicycle
{
    //frame size
    float frameSize = 51.1f;
    //wheel size
    float wheelRimSize = 18.f;
    //brakes model
    std::string brakesModel = "Shimano";
    //pedals type (1 for standard, 2 for cleats)
    int pedalsType = 1;
    //handlebars type (1 for drops, 2 for straight)
    int handlebarsType = 1;

    //move forwards - return 
    float moveForwards(int numOfRevolutions);
    //bunny hop - return height
    float bunnyHop(float maximumWheelHeight);
    //wheelie
    bool popWheelie();
};

float Bicycle::moveForwards(int numOfRevolutions)
{
    return (3.14f * wheelRimSize) * numOfRevolutions;
}

float Bicycle::bunnyHop(float maximumWheelHeight)
{
    return maximumWheelHeight - wheelRimSize;
}

bool Bicycle::popWheelie()
{
    if(handlebarsType == 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

struct ElectricGuitar
{
    //body wood - 1 = maple, 2 = oak
    int bodyWoodType = 1;
    //neck joint glued
    bool isNeckJointGlued = false;
    //strings gauge
    float tonepotSetting = 1.0f;
    //pickups position
    int pickupPositionSelector = 1;
    //no of frets 
    int numFrets = 24;

    //output sound
    float outputSound(int fretPlayed);
    //change tone - return tone resistance value
    void changeTone(bool isSoloNow);
    //change pickup - return
    void selectPickup(std::string songStyle);
};

float ElectricGuitar::outputSound(int fretPlayed)
{
    //very simplified frequency calculator/just plain wrong but you get the jist!
    return 344/(2*(numFrets - fretPlayed));
}

void ElectricGuitar::changeTone(bool isSoloNow)
{
    if(isSoloNow)
    {
        tonepotSetting = 1.0f;
    }
    else
    {
        tonepotSetting = 10.0f;
    }
}

void ElectricGuitar::selectPickup(std::string songStyle)
{
    if(songStyle == "Rock")
    {
        pickupPositionSelector = 5;
    }
    else if(songStyle == "pop")
    {
        pickupPositionSelector = 1;
    }
    else
    {
        pickupPositionSelector = 3;
    }
}

struct Staff
{
    //type
    std::string type = "Player";
    //sex
    std::string sex = "Male";
    //age
    int age = 22;
    //hours of work
    float hoursOfWork = 37.5f;
    //days of work
    int daysOfWork = 5;
    
    bool hitOvertime = false;

    std::string injuryType;

    float salary = 20000.f;

    //go to work
    void goToWork(float numHoursToday);
    //attend meeting
    void attendMeeting();
    //sign a contract
    bool signContract(float contractOffer = 20000.f);
};

void Staff::goToWork(float numHoursToday)
{
    hoursOfWork -= numHoursToday;
    if(hoursOfWork < 0)
    {
        hitOvertime = true;
    }
}

void Staff::attendMeeting()
{
    std::cout << "All onsite meetings cancelled - login to Zoom" << std::endl;
}

bool Staff::signContract(float contractOffer)
{
    if(contractOffer > 20000.f)
    {
        return true;
    }
    else
    {
        return false;
    }
}

struct TeamProgram
{
    //sex
    bool isMale = true;
    //maximum age
    int maxAge = 21;
    //professional status
    std::string profStatus = "Semi-Professional";
    //number of staff
    int numCoaches = 6;
    //total number of programs
    int numPlayersInProgram = 22;
    int maxNumPlayersInProgram = 26;

    float budgetPerAnnum;
    float currentBalance;

    bool isGameAtHome;

    //enter a league
    void enterALeague(float costToEnterLeague);
    //determine number of coaches required
    int numCoachesRequired();
    //advertise for players
    int advertiseForPlayers();
};

void TeamProgram::enterALeague(float costToEnterLeague)
{
    currentBalance -= costToEnterLeague;
}

int TeamProgram::numCoachesRequired()
{
    if(isGameAtHome)
    {
        return numCoaches;
    }
    else
    {
        return numCoaches/2;
    }
}

int TeamProgram::advertiseForPlayers()
{
    return maxNumPlayersInProgram - numPlayersInProgram;
}

struct TrainingComplex
{
    //address of complex
    std::string address = "1234 Sports Street";
    //no of meals served in canteen a day
    int numMealsServed = 122;
    //maximum deadlift weight in gym
    float maxDeadliftWeight = 500.f;
    //no of lockers in locker room
    int numLockers = 100;
    //no of car park spots
    int numCarParkSpots = 75;

    float costPerMeal = 1.23f;

    std::string therapyType;

    //host training session
    int numOfFreeParkingSpaces(TeamProgram myTeam);
    //feed staff
    float costToFeedStaff(int howManyStaffWorkingToday = 75, int numTrainingSessions = 2);
    //provide player rehab
    void providePlayerRehab(Staff player);
};

int TrainingComplex::numOfFreeParkingSpaces(TeamProgram myTeam)
{
    return (myTeam.numPlayersInProgram + myTeam.numCoaches) - numCarParkSpots;
}

float TrainingComplex::costToFeedStaff(int howManyStaffWorkingToday, int numTrainingSessions)
{
    numMealsServed = howManyStaffWorkingToday * numTrainingSessions;
    return numMealsServed * costPerMeal;
}

void TrainingComplex::providePlayerRehab(Staff player)
{
    if(player.injuryType == "Muscular")
    {
        therapyType = "Massage";
    }
}

struct Stadium
{
    //capacity
    int numSeats = 44000;
    //stadium name
    std::string name = "Paul Brown Stadium";
    //turf type (1 = grass, 2 = turf)
    int turfType = 1;
    //are executive boxes open
    bool boxesOpen = true;
    //no of staircases
    int numStaircases = 22;

    bool gatesOpen;

    int numTicketsSold;

    struct ConcessionStand
    {
        //stand type (1 for food/drink, 2 for merchandise)
        int type = 1;
        //does it have a liqour license
        bool hasLiquorLicense = false;
        //min no of staff required to run it
        int minNumStaffRequired = 6;
        //max no of staff required
        int maxNumStaffRequired = 8;
        //name of stand
        std::string name = "Dave's magical hot-dogs";


        //check customer ID
        bool isCustomerOfAge(int customerAge = 22);
        //display which customer order will be ready next
        void displayNextReadyCustomerOrder(int nextCustomerOrderNum);
        //take order from customer
        void takeCustomerOrder();
    };
    
    //host an event
    void hostAnEvent(std::string eventType);
    //open gates
    void openGates();
    //staff a concession stand
    int remainingTickets();

    ConcessionStand myConcessionStand;
};

bool Stadium::ConcessionStand::isCustomerOfAge(int customerAge)
{
    if(customerAge >= 21)
    {
        return true;
    }else
    {
        return false;
    }
}

void Stadium::ConcessionStand::displayNextReadyCustomerOrder(int nextCustomerOrderNum)
{
    std::cout << nextCustomerOrderNum << " is ready for Collection!" << std::endl;
}

void Stadium::ConcessionStand::takeCustomerOrder()
{
    std::cout << "What would you like today" << std::endl;
}

void Stadium::hostAnEvent(std::string eventType)
{
    if(eventType == "Sports")
    {
        turfType = 1;
    }else
    {
        turfType = 2;
    }
}

void Stadium::openGates()
{
    gatesOpen = true;
    boxesOpen = true;
}

int Stadium::remainingTickets()
{
    return numSeats-numTicketsSold;
}

struct SupportersGroup
{
    //name of group
    std::string name = "Queen City Hooligans";
    //number of members
    int numMembers = 120;
    //num of season tickets in group
    int numSeasonTickets = 60;
    //merch discount
    float merchDiscountFromClub = 10.f;
    //cost of membership
    float costOfMembership = 100.f;

    struct Supporter
    {
        //jersey size
        std::string jerseySize = "M";
        //location
        std::string whereDoYouLive = "Cincinnati";
        //distance from club's city
        float distanceFromClubsCity = 123.f;
        //season ticket holder
        bool isSeasonTicketHolder = false;
        //no of meetings attended
        int numMeetingsAttended = 3;

        std::string name;

        // join supporters group
        void buySeasonTicket();
        // buy jersey
        float totalCostOfMerchandise(float jerseyCost);
        // go to away match
        void attendMeeting();
    };

    //Arrange trip to away match
    float costOfAwayMatchTrip(int noOfSupporters = 20);
    //Add a new member
    float numSeasonTicketsPerMember();
    //Email a member on their birthday
    void emailMemberOnBirthday();

    Supporter mySupporter;
};

void SupportersGroup::Supporter::buySeasonTicket()
{
    isSeasonTicketHolder = true;
}

float SupportersGroup::Supporter::totalCostOfMerchandise(float jerseyCost)
{
    if(jerseySize == "Youth" || jerseySize == "S")
    {
        return jerseyCost * 0.75f;
    }else
        return jerseyCost;
}

void SupportersGroup::Supporter::attendMeeting()
{
    numMeetingsAttended++;
}

float SupportersGroup::costOfAwayMatchTrip(int noOfSupporters)
{
    float totalCostofFlights = 200.f * noOfSupporters;
    float totalHotelCosts = 100.f * noOfSupporters;
    return totalCostofFlights + totalHotelCosts;
}

float SupportersGroup::numSeasonTicketsPerMember()
{
    return numSeasonTickets/numMembers;
}

void SupportersGroup::emailMemberOnBirthday()
{
    std::cout << "Happy Birthday " << mySupporter.name << " from the " << name << std::endl;
}

struct SportsTeam
{
    // staff
    Staff staffMember;
    // program
    TeamProgram program;
    //training complex
    TrainingComplex complex;
    //stadium
    Stadium stadium;
    //supporter
    SupportersGroup mySupportersGroup;

    // play a match
    void playMatch(TeamProgram, Stadium);
    // run a training session
    float costToFeedStaffPerProgram(TeamProgram, TrainingComplex);
    // sign a player
    bool signAPlayer(Staff);
};

void SportsTeam::playMatch(TeamProgram myProgram, Stadium myStadium)
{
    if(myProgram.isGameAtHome)
    {
        myStadium.hostAnEvent("Sports");
    }
}

float SportsTeam::costToFeedStaffPerProgram(TeamProgram myProgram, TrainingComplex myTrainingComplex)
{
    return myTrainingComplex.costToFeedStaff(myProgram.maxNumPlayersInProgram, 2);
}


bool SportsTeam::signAPlayer(Staff myPlayer)
{
    if(myPlayer.signContract(20000.f))
    {
        return true;
    }else 
    {
        return false;
    }

}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
