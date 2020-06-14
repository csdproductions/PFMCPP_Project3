/*
 Project 3 - Part 5 / 5
 video: Chapter 2 - Part 10
 Scope and Lifetime tasks
 
Create a branch named Part5

 video covered:
    variable scope and lifetime relative to { }
    while loops
    for loops()
 
 tasks
 
 1) add some new member functions to your types. 
 
 2) use while() or for() loops to do something interesting inside these new member functions.
         a) for example: have a loop that modifies a member variable of some object created outside the loop.
         b) when that member variable reaches a certain threshold, return it mid-loop.
         c) maybe use function parameters to control the starting value of that member variable or control the threshold
         
 3) call those new member functions in main()
 
 4) use std::cout statements to print out information about what your loops did.
 
 5) click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
namespace Example 
{
struct Bar 
{ 
    int num = 0; 
    Bar(int n) : num(n) { } 
};
struct Foo
{
    Bar scopeLifetimeFunc( int threshold, int startingVal ) //3), 4c) 
    {
        Bar bar(startingVal);                //4a)
        while( bar.num < threshold )         //4a) 
        { 
            bar.num += 1;                    //4a)
            
            if( bar.num >= threshold )       //4b)
                return bar;
        }
        
        return Bar {-1}; //if your startingValue >= threshold, the while loop never runs
    }
};

int main()
{
    Foo foo;
    auto bar = foo.scopeLifetimeFunc(3, 1);        //5) 
    
    std::cout << "bar.num: " << bar.num << std::endl;     //6) 
    return 0;
}
}

//call Example::main() in main()




struct GamesConsole
{
    //control pads
    int numControlPads {0};
    // storage drive size
    float storageDriveSize {0.f};
    // usb ports
    int numUsbPorts {0};
    // current game
    std::string currentGame {};
    // network connections
    int networkConnection {0};
    
    int recordNumKills;

    GamesConsole() : numControlPads (2), numUsbPorts (4) {}

    //
    void goingForRecordNumKills(int); 
    // read discs
    void readDisc(std::string gameDisc = "Grand Theft Auto");
    // play games
    void playGame(int numPlayers = 8);
    // connect to network - return if connection successful
    bool connectToNetwork(float connectionSpeed = 1000.f);
};

void GamesConsole::goingForRecordNumKills(int currentKillsInGame)
{
    int currentKillsOnLevel = currentKillsInGame;

    while(currentKillsOnLevel <= recordNumKills)
    {
        ++currentKillsOnLevel;
        std::cout << "Still haven't beaten the record. Keep hunting." << std::endl;
    }
    recordNumKills = currentKillsOnLevel;
}

void GamesConsole::readDisc(std::string myGame)
{
    std::cout << "This console has " << numUsbPorts << " USB ports and " << numControlPads << " controller pads as a default." << std::endl;
    std::cout << "You are about to play " << myGame << " - Enjoy!" << std::endl;
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
    return false;
}

struct Dog
{
    //fur colour
    std::string furColour;
    //age
    float age;
    //breed
    std::string breed;
    //name
    std::string name;
    //sex
    bool isFemale;

    Dog();

    struct Exercise
    {
        int totalTime;
        int currentSessionTime;
        int numOfSessions;
    };

    bool doesDogNeedAnymoreExercise();
    //fetch 
    void fetch(std::string ballType = "Tennis");
    //sit
    void giveTreat(std::string treatType = "Peanut Butter", int numOfTreats = 4);
    //heel
    float exerciseTime();

    Exercise routine;
};

Dog::Dog() :
    furColour ("brown"),
    age (0.f),
    breed ("Shih-Tzu"),
    name ("Luna"),
    isFemale (false)
{}


void Dog::fetch(std::string ballType)
{
    if(ballType == "Tennis")
    {
        giveTreat("Dog Biscuits");
    }
}

void Dog::giveTreat(std::string treatType, int numOfTreats)
{
    std::cout << "This dog has " << furColour << " colored fur and " << (isFemale ? "is a female." : "is a male.") << std::endl;
    if(name == "Luna")
    {
        std::cout << "Give Luna " << numOfTreats << " " << treatType << std::endl;
    }
}

float Dog::exerciseTime()
{
    float exerciseTimeCalculator = age * 12 * 6;
    if(exerciseTimeCalculator > 75.f)
    {
        return 75.f;
    }
    return exerciseTimeCalculator;
}

bool Dog::doesDogNeedAnymoreExercise()
{   
    float maxTimeAllowed = exerciseTime();
    for(int i = 0; i < maxTimeAllowed; ++i)
    {
        ++routine.currentSessionTime;
        ++routine.totalTime;
        
    }

    if(routine.totalTime >= maxTimeAllowed)
    {      
        return true;
    }
    
    return false;
}

struct Bicycle
{
    //frame size
    float frameSize;
    //wheel size
    float wheelRimSize;
    //brakes model
    std::string brakesModel;
    //pedals type (1 for standard, 2 for cleats)
    int pedalsType;
    //handlebars type (1 for drops, 2 for straight)
    int handlebarsType;



    Bicycle() : frameSize(51.f), wheelRimSize(18.f), brakesModel("Shimano"), pedalsType(1), handlebarsType(1) {}

    //move forwards - return 
    void moveForwards(int numOfRevolutions);
    //bunny hop - return height
    float bunnyHop(float maximumWheelHeight);
    //wheelie
    bool popWheelie();
};

/*
Bicycle::Bicycle()
{
    frameSize = 0.f;
    wheelRimSize = 0.f;
    brakesModel = {};
    pedalsType = 0;
    handlebarsType = 1;
}
*/

void Bicycle::moveForwards(int numOfRevolutions)
{
    std::cout << "Our standard bike model has " << brakesModel << " brakes and the wheel rims have a diameter of " << wheelRimSize << " inches." << std::endl;
    int brakesPumped={};
    while(brakesPumped < 3)
    {
        std::cout << "You moved forward by: " << (3.14f * wheelRimSize) * numOfRevolutions << std::endl;
        ++brakesPumped;
    }
    std::cout << "You stopped moving." << std::endl;
}

float Bicycle::bunnyHop(float maximumWheelHeight)
{
    return maximumWheelHeight - wheelRimSize;
}

bool Bicycle::popWheelie()
{
    if(handlebarsType == 1)
    {
        std::cout << "Popped a sweet Wheelie!" << std::endl;
        return true;
    }
    return false;
}

struct ElectricGuitar
{
    //body wood - 1 = maple, 2 = oak
    int bodyWoodType;
    //neck joint glued
    bool isNeckJointGlued;
    //strings gauge
    float tonepotSetting;
    //pickups position
    int pickupPositionSelector;
    //no of frets 
    int numFrets;

    ElectricGuitar();

    void printElectriGuitarConstruct() 
    {  
        std::cout << "4) Tonepot is set to " << tonepotSetting << " at the start of the song. " << std::endl;
    }

    void playEachFret();

    //output sound
    float outputSound(int fretPlayed);
    //change tone - return tone resistance value
    void changeTone(bool isSoloNow);
    //change pickup - return
    void selectPickup(std::string songStyle);
};

ElectricGuitar::ElectricGuitar()
{
    bodyWoodType = 1;
    isNeckJointGlued = true;
    tonepotSetting = 10.f;
    pickupPositionSelector = 1;
    numFrets = 24;
}

void ElectricGuitar::playEachFret()
{
    std::cout << "Notes will be played every three frets" << std::endl;
    for(int i=0;i<numFrets;++i)
    {
        if(i%3 == 0)
        {
            std::cout << "Note played at fret " << i << std::endl;
        }
    }
}

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
        std::cout << "CURRENTLY RIPPING A SOLO WITH A NEW TONEPOT SETTING OF: " << tonepotSetting << "\n";
    }
    else
    {
        std::cout << "No solo right now, tonepot still at starting point of: " << tonepotSetting << "\n";
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
    std::string type;
    //sex
    bool isPlayerMale;
    //age
    int age;
    //hours of work
    float hoursOfWork;
    float requiredHoursOfWork;
    //days of work
    int daysOfWork;
    
    bool hitOvertime;

    std::string injuryType;
    std::string name;

    float salary;

    Staff();

    void daysAndHoursCalculator(int typeOfDay);

    //go to work
    bool overtimeCalculator();
    //attend meeting
    void attendMeeting();
    //sign a contract
    bool signContract(float contractOffer = 20000.f);
};

Staff::Staff()
{
    type = {};
    isPlayerMale = true;
    age = 0;
    hoursOfWork = 40.f;
    requiredHoursOfWork = 40.f;
    daysOfWork = 5;
    hitOvertime = false;
    injuryType = "None";
    salary = 0.f;
    name = {};
}

void Staff::daysAndHoursCalculator(int dayType)
{
    if(dayType)
    {
        hoursOfWork -= 8.f;
        daysOfWork -= 1;
    }
    else
    {
        hoursOfWork -= 4.f;
        daysOfWork -= 0.5;
    }
}

bool Staff::overtimeCalculator()
{
    std::cout << "Standard working hours in a week for an employee must total " << requiredHoursOfWork << " before they hit overtime." << std::endl;
    if(hoursOfWork < 0)
    {
        return true;
    }
    return false;
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
    return false;
}

struct TeamProgram
{
    //sex
    bool isMale{};
    //maximum age
    int maxAge;
    //professional status
    std::string profStatus{};
    //number of staff
    int numCoaches;
    //total number of programs
    int numPlayersInProgram = 0;
    int maxNumPlayersInProgram;

    float budgetPerAnnum = 0.f;
    float currentBalance = 0.f;

    bool isGameAtHome = {};
    
    TeamProgram() : maxAge(40), numCoaches(6), maxNumPlayersInProgram(24) {}

    //enter a league
    std::string enterALeague(float costToEnterLeague);
    //determine number of coaches required
    int numCoachesRequired();
    //advertise for players
    int advertiseForPlayers();
};

/*
TeamProgram::TeamProgram()
{
    isMale = true;
    maxAge = 0;
    profStatus = {};
    numCoaches = 0;
    numPlayersInProgram = 0;
    maxNumPlayersInProgram = 0;
    budgetPerAnnum = 0.f;
    currentBalance = 0.f;
    isGameAtHome = true;
}
*/

std::string TeamProgram::enterALeague(float costToEnterLeague)
{
    if(costToEnterLeague > budgetPerAnnum){
        return "We can't afford to enter this league";
    }

    for(int i = 0; i < 3; ++i)
    {
        currentBalance -= costToEnterLeague;
        if(currentBalance < 0)
        {
            return "We've run out of cash!";
        }
        else
        {
            std::cout << "We can enter for another year" << std::endl;
            if(i > 2)
            {
                std::cout << "We can enter the league for 3 seasons" << std::endl;
            }
        }
    }
    return "We've still got some money left!";
}

int TeamProgram::numCoachesRequired()
{
    if(isGameAtHome)
    {
        return numCoaches;
    }
    return numCoaches/2;
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
    int numMealsServed;
    //maximum deadlift weight in gym
    float maxDeadliftWeight = 500.f;
    //no of lockers in locker room
    int numLockers = 100;
    //no of car park spots
    int numCarParkSpots = 75;

    float costPerMeal = 1.23f;

    std::string therapyType;

    TrainingComplex();

    //host training session
    void numOfFreeParkingSpaces(int, TeamProgram);
    //feed staff
    float costToFeedStaff(int howManyStaffWorkingToday = 75, int numTrainingSessions = 2);
    //provide player rehab
    void providePlayerRehab(Staff player);
};

TrainingComplex::TrainingComplex()
{
    numMealsServed = 0;
    therapyType = {};
}

void TrainingComplex::numOfFreeParkingSpaces(int numStaffToday, TeamProgram myTeam)
{
    std::cout << "The address of the complex is " << address << " and we have " << numCarParkSpots - (myTeam.numPlayersInProgram + myTeam.numCoaches)  << " car parking spots left most days" << std::endl;

    int numCarParkSpotsToday = {};

    if(numStaffToday < numCarParkSpots)
    {
        for(int i=0; i<numStaffToday; ++i)
        {
            ++numCarParkSpotsToday;
        }
        std::cout << "Today we have " << (numCarParkSpots - numCarParkSpotsToday) << " left" << std::endl;
    }
    else
    {
        std::cout << "We don't have enough spots for everyone today - please try and car pull!" << std::endl;
    }  
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
       std::cout << player.name << " has Muscular pain and will require " << therapyType << " treatment" << "\n";
    }
}

struct Stadium
{
    //capacity
    int numSeats;
    //stadium name
    std::string name;
    //turf type (1 = grass, 2 = turf)
    int turfType = 1;
    //are executive boxes open
    bool boxesOpen = true;
    //no of staircases
    int numStaircases = 22;

    bool gatesOpen;
    int numTicketsSold;

    Stadium();

    struct ConcessionStand
    {
        //stand type (1 for food/drink, 2 for merchandise)
        int type;
        //does it have a liqour license
        bool hasLiquorLicense;
        //min no of staff required to run it
        int minNumStaffRequired;
        //max no of staff required
        int maxNumStaffRequired;
        //name of stand
        std::string name;

        int numStaff;

        ConcessionStand();

        std::string staffStatus();
        //check customer ID
        std::string isCustomerOfAge(int customerAge = 22);
        //display which customer order will be ready next
        void displayNextReadyCustomerOrder(int nextCustomerOrderNum);
        //take order from customer
        std::string takeCustomerOrder();
    };
    
    void printStadiumConstruct()
    {
        std::cout << "8) The stadiums name is the " << name << " and can hold up to " << numSeats << " fans." << std::endl;
        std::cout << "As a standard, our Concession stand's " << (myConcessionStand.hasLiquorLicense ? "DO" : "DON'T") << " have a liquor license" << std::endl;
    }


    //host an event
    void hostAnEvent(std::string eventType);
    //open gates
    void openGates();
    //staff a concession stand
    void remainingTickets();

    ConcessionStand myConcessionStand;
};

Stadium::Stadium()
{
    numSeats = 44000;
    name = "Paul Brown Stadium";
    turfType = 1;
    boxesOpen = true;
    numStaircases = 22;                      
    gatesOpen = true;
    numTicketsSold = 0;
    myConcessionStand = {};
}

Stadium::ConcessionStand::ConcessionStand()
{
    type = 0;
    hasLiquorLicense = false;
    numStaff = 0;
    minNumStaffRequired = 0;
    maxNumStaffRequired = 0;
    name = {};
}

std::string Stadium::ConcessionStand::staffStatus()
{
    if(numStaff < minNumStaffRequired)
    {
        std::cout << "We need to hire some more guys!" << std::endl;
        for(int i = 0; i < minNumStaffRequired; ++i)
        {
            ++numStaff;
        }
        return "We now have enough staff";
    }

    if(numStaff > maxNumStaffRequired){
        int numStaffToCut = numStaff - maxNumStaffRequired;
        std::cout << "We've got too many staff! Need to cut " << numStaffToCut << " staff from today's shift." << std::endl;
        for(int i = 0; i < numStaffToCut; ++i)
        {
            --numStaff;
        }
        return "We now have enough staff";
    }

    return "We've got the right amount of staff"; 
}

std::string Stadium::ConcessionStand::isCustomerOfAge(int customerAge)
{
    if(customerAge >= 21)
    {
        return "Here's your warm, overpriced beer.";
    }
    return "GET OUTTA HERE YOU UNDERARGE SCOUNDREL";
}

void Stadium::ConcessionStand::displayNextReadyCustomerOrder(int nextCustomerOrderNum)
{
    std::cout << nextCustomerOrderNum << " is ready for Collection!" << std::endl;
}

std::string Stadium::ConcessionStand::takeCustomerOrder()
{
    std::cout << "What would you like today" << std::endl;
    return "Beer";
}

void Stadium::hostAnEvent(std::string eventType)
{
    if(eventType == "Sports")
    {
        turfType = 1;
    }
    else
    {
        turfType = 2;
    }
}

void Stadium::openGates()
{
    gatesOpen = true;
    boxesOpen = true;
}

void Stadium::remainingTickets()
{
    std::cout << "Today we have " << numSeats-numTicketsSold << " tickets left for sale" << std::endl;
}

struct SupportersGroup
{
    //name of group
    std::string name;
    //number of members
    int numMembers;
    //num of season tickets in group
    int numSeasonTickets;
    //merch discount
    float merchDiscountFromClub;
    //cost of membership
    float costOfMembership;

    SupportersGroup() : name("Queen City Hooligans"), numMembers (0), numSeasonTickets(60), merchDiscountFromClub(10.f), costOfMembership(100.f) {}

    struct Supporter
    {
        //jersey size
        std::string jerseySize;
        //location
        std::string whereDoYouLive;
        //distance from club's city
        float distanceFromClubsCity;
        //season ticket holder
        bool isSeasonTicketHolder = false;
        //no of meetings attended
        int numMeetingsAttended;

        std::string name;

        Supporter();

        // join supporters group
        void buySeasonTicket();
        // buy jersey
        float totalCostOfMerchandise(float jerseyCost);
        // go to away match
        void attendMeeting();
    };

    float totalValueMerchSold(int);

    //Arrange trip to away match
    float costOfAwayMatchTrip(int noOfSupporters = 20);
    //Add a new member
    float numSeasonTicketsPerMember();
    //Email a member on their birthday
    void emailMemberOnBirthday();

    Supporter mySupporter = {};
};

float SupportersGroup::totalValueMerchSold(int numSupportersPurchasing)
{
    float countingTotal={};
    for(int i=0; i<numSupportersPurchasing; ++i)
    {
        countingTotal += mySupporter.totalCostOfMerchandise(89.99f);
    }
    return countingTotal;
}

SupportersGroup::Supporter::Supporter()
{
    jerseySize = {};
    whereDoYouLive = {};
    distanceFromClubsCity = 0.f;
    isSeasonTicketHolder = true;
    numMeetingsAttended = 0;
    name = {};
}

void SupportersGroup::Supporter::buySeasonTicket()
{
    isSeasonTicketHolder = true;
}

float SupportersGroup::Supporter::totalCostOfMerchandise(float jerseyCost)
{
    if(jerseySize == "Youth" || jerseySize == "S")
    {
        return jerseyCost * 0.75f;
    }
    return jerseyCost;
}

void SupportersGroup::Supporter::attendMeeting()
{
    ++numMeetingsAttended;
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
    std::cout << "Happy Birthday " << mySupporter.name << " from the " << name << ". Remember you get a discount of " << merchDiscountFromClub << "% if you want to buy yourself a present!" << std::endl;
}

struct SportsTeam
{   
    std::string name;
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

    SportsTeam();

    bool doWeHaveATeam();

    // play a match
    void playMatch(TeamProgram, Stadium);
    // run a training session
    float costToFeedStaffPerProgram(TeamProgram, TrainingComplex);
    // sign a player
    bool signAPlayer(Staff, float contractOffer);
};

SportsTeam::SportsTeam()
{
    name = "Dunder Mifflin United";
    staffMember = {};
    program = {};
    complex = {};
    stadium = {};
    mySupportersGroup = {};
}

bool SportsTeam::doWeHaveATeam()
{
    for(int i = 0; i < program.maxNumPlayersInProgram; ++i)
    {
        ++program.numPlayersInProgram;
        if(program.numPlayersInProgram == program.maxNumPlayersInProgram)
        {
            return true;
        }
    }
    return false;
}

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


bool SportsTeam::signAPlayer(Staff myPlayer, float contractOffer)
{
    if(myPlayer.signContract(contractOffer))
    {
        return true;
    } 
    return false;
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
    Example::main();

    //1) GAMES CONSOLE
    GamesConsole myXbox;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "1) Games Console UDT" << "\n";
    /*myXbox.readDisc("Grand Theft Auto");
    std::cout << "Am I connected to a network to play online? " << (myXbox.connectToNetwork(56.7f) ? "Yes" : "No")<< "\n";*/
    myXbox.recordNumKills = 6;
    myXbox.goingForRecordNumKills(4);
    std::cout << "Wow, you beat the kills. New record is: " << myXbox.recordNumKills << std::endl; 
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";
    
    
    //2) DOG
    Dog myLittlePup;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "2) Dog UDT" << "\n";
    /*myLittlePup.name = "Luna";
    std::cout << "My dog's name is: " << myLittlePup.name << "\n";
    myLittlePup.fetch("Tennis");*/
    myLittlePup.age = 3;
    myLittlePup.routine.numOfSessions = 1;
    myLittlePup.routine.totalTime = 40;
    std::cout << "Dog should be exercised for a futher " << myLittlePup.exerciseTime() - myLittlePup.routine.totalTime << " minutes" << std::endl;
    ++myLittlePup.routine.numOfSessions;
    std::cout << "After the second session, the dog " << (myLittlePup.doesDogNeedAnymoreExercise() ? "does not" : "does") << " need more exercise" << std::endl;
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    
    //3) BICYCLE
    Bicycle myLittleBike;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "3) Bicycle UDT" << "\n";
    //myLittleBike.handlebarsType = 1;
    myLittleBike.moveForwards(3);
    //myLittleBike.popWheelie();
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    
    //4) Electric Guitar
    ElectricGuitar myTelecaster;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "4) Electric Guitar UDT" << "\n";
    myTelecaster.numFrets = 26;
    myTelecaster.playEachFret();
    /*myTelecaster.changeTone(false);
    std::cout << "Solo coming up!" << "\n";
    myTelecaster.changeTone(true);*/
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    
    //5) Staff
    Staff myStaffMember;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "5) Staff UDT" << "\n";
    for(int i = 0; i < 3; ++i)
    {
        myStaffMember.daysAndHoursCalculator(1);
    }
    std::cout << "Staff member has worked " << myStaffMember.hoursOfWork << " hours this week over " << myStaffMember.daysOfWork << " days" << std::endl;
    std::cout << (myStaffMember.overtimeCalculator() ? "You have" : "You have NOT") << " hit overtime rate" << std::endl;

    /*myStaffMember.name = "Michael Scott";
    myStaffMember.injuryType = "Muscular";
    myStaffMember.goToWork(10.f);
    std::cout << "Did I hit Overtime yet? " << (myStaffMember.hitOvertime ? "Yes" : "No") << "\n";
    myStaffMember.attendMeeting();*/
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";
    

    //6) Team Program
    TeamProgram myTeam;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "6) Team Program UDT" << "\n";
    //myTeam.numPlayersInProgram = 21;
    //myTeam.numCoaches = 4;
    myTeam.currentBalance = 35459.f;
    std::cout << "Team's starting budget is: $" << myTeam.currentBalance << "\n";
    std::cout << myTeam.enterALeague(50000) << std::endl;
    //float amountToEnterLeague = 10000.f;
    //std::cout << (myTeam.currentBalance >= amountToEnterLeague ? myTeam.enterALeague(amountToEnterLeague) : "You don't have the funds to enter this league" ) << "\n";
    //std::cout << "Current budget: $" << myTeam.currentBalance << "\n";
    //std::cout << "We have " << myTeam.advertiseForPlayers() << " spaces left in the team" << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    
    //7) Training Complex
    TrainingComplex myTrainingGround;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "7) Training Complex UDT" << "\n";
    myTrainingGround.numOfFreeParkingSpaces(80, myTeam);
    //myTrainingGround.costPerMeal = 1.23f;
    //std::cout << "Total cost for meals will be: $" << myTrainingGround.costToFeedStaff(myTeam.numCoaches + myTeam.numPlayersInProgram, 2) << "\n";
    //myTrainingGround.providePlayerRehab(myStaffMember);
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    
    //8) Stadium
    Stadium myStadium;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "8) Stadium UDT" << "\n";
    myStadium.myConcessionStand.minNumStaffRequired = 4;
    myStadium.myConcessionStand.maxNumStaffRequired = 6;
    myStadium.myConcessionStand.numStaff = 7;
    std::cout << myStadium.myConcessionStand.staffStatus() << std::endl;
    /*std::string todaysEvent = "Sports";
    myStadium.numTicketsSold = 31138;
    myStadium.remainingTickets();
    myStadium.hostAnEvent(todaysEvent);
    std::cout << "What type of turf do we have for the event today? " << (myStadium.turfType ? "Grass" : "Turf" ) << "\n";
    std::string customerOrder = myStadium.myConcessionStand.takeCustomerOrder();
    std::cout << (customerOrder == "Beer" ? myStadium.myConcessionStand.isCustomerOfAge(20) : "Order being processed!") << "\n";*/
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";
    
    //9) Supporters Group
    SupportersGroup mySupportersGroup;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "9) Supporters Group UDT" << "\n";
    std::cout << "We've sold $" << mySupportersGroup.totalValueMerchSold(60) << " of merch" << std::endl;
    /*mySupportersGroup.mySupporter.name = "Jim Halpert";
    mySupportersGroup.emailMemberOnBirthday();
    mySupportersGroup.mySupporter.attendMeeting();
    std::cout << mySupportersGroup.mySupporter.name << " has attended " << mySupportersGroup.mySupporter.numMeetingsAttended << " club meeting(s)" "\n";*/
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";
    
    
    //10) Sports Team
    SportsTeam mySportsTeam;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "10) Sports Team UDT" << "\n";
    mySportsTeam.staffMember = myStaffMember;
    mySportsTeam.stadium = myStadium;
    mySportsTeam.program = myTeam;
    mySportsTeam.mySupportersGroup = mySupportersGroup;
    std::cout << "We" << (mySportsTeam.doWeHaveATeam() ? "": "DON'T") << " have a team!" << std::endl;
    //std::cout << mySportsTeam.name << " play their games at the " << mySportsTeam.stadium.name << " and are supported by a fan group called the " << mySportsTeam.mySupportersGroup.name << "\n";
    //std::cout << "Today they offered a new contract to " << mySportsTeam.staffMember.name << ". ";
    //std::cout << (mySportsTeam.signAPlayer(mySportsTeam.staffMember, 2000.f) ? "The offer was accepted" : "The offer was too low and was not accepted") << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";
    
}
