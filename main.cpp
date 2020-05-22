/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) initialize some of your member variables either in-class or in the Constructor member initializer list.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
namespace Example {
struct UDT  
{
    int a; //a member variable
    float b { 2.f }; //3) in-class initialization
    UDT() : a(0) { } //3) 'constructor-initializer-list' member variable initialization
    void printThing()  //the member function
    {
        std::cout << "UDT::printThing() a:" << a << " b: " << b << std::endl;  //4) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printThing(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()

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

    GamesConsole();

    // read discs
    void readDisc(std::string gameDisc = "Grand Theft Auto");
    // play games
    void playGame(int numPlayers = 8);
    // connect to network - return if connection successful
    bool connectToNetwork(float connectionSpeed = 1000.f);
};

GamesConsole::GamesConsole()
{
    numControlPads = 0;
    storageDriveSize = 0.f;
    numUsbPorts = 0;
    currentGame = {};
    networkConnection = 0;
}

void GamesConsole::readDisc(std::string myGame)
{
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
    std::string furColour = "Brown";
    //age
    float age = 1.f;
    //breed
    std::string breed = "Shih-Tzu";
    //name
    std::string name = "Luna";
    //sex
    bool isFemale = true;

    Dog();

    //fetch 
    void fetch(std::string ballType = "Tennis");
    //sit
    void giveTreat(std::string treatType = "Peanut Butter", int numOfTreats = 4);
    //heel
    float exerciseTime();
};

Dog::Dog()
{
    
    furColour = {};
    age = 0.f;
    breed = {};
    name = {};
    isFemale = true;
}

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

    Bicycle();

    //move forwards - return 
    float moveForwards(int numOfRevolutions);
    //bunny hop - return height
    float bunnyHop(float maximumWheelHeight);
    //wheelie
    bool popWheelie();
};

Bicycle::Bicycle()
{
    frameSize = 0.f;
    wheelRimSize = 0.f;
    brakesModel = {};
    pedalsType = 0;
    handlebarsType = 1;
}

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
        std::cout << "Popped a sweet Wheelie!" << std::endl;
        return true;
    }
    return false;
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

    ElectricGuitar();

    //output sound
    float outputSound(int fretPlayed);
    //change tone - return tone resistance value
    void changeTone(bool isSoloNow);
    //change pickup - return
    void selectPickup(std::string songStyle);
};

ElectricGuitar::ElectricGuitar()
{
    bodyWoodType = 0;
    isNeckJointGlued = true;
    tonepotSetting = 0.f;
    pickupPositionSelector = 0;
    numFrets = 0;
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
    bool isPlayerMale = true;
    //age
    int age = 22;
    //hours of work
    float hoursOfWork = 37.5f;
    //days of work
    int daysOfWork = 5;
    
    bool hitOvertime = false;

    std::string injuryType;
    std::string name;

    float salary = 20000.f;

    Staff();

    //go to work
    void goToWork(float numHoursToday);
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
    hoursOfWork = 0.f;
    daysOfWork = 0;
    hitOvertime = false;
    injuryType = {};
    salary = 0.f;
    name = {};
}

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
    return false;
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
    

    TeamProgram();

    //enter a league
    std::string enterALeague(float costToEnterLeague);
    //determine number of coaches required
    int numCoachesRequired();
    //advertise for players
    int advertiseForPlayers();
};

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

std::string TeamProgram::enterALeague(float costToEnterLeague)
{
    currentBalance -= costToEnterLeague;
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
    int numMealsServed = 122;
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
    int numOfFreeParkingSpaces(TeamProgram myTeam);
    //feed staff
    float costToFeedStaff(int howManyStaffWorkingToday = 75, int numTrainingSessions = 2);
    //provide player rehab
    void providePlayerRehab(Staff player);
};

TrainingComplex::TrainingComplex()
{
    address = {};
    numMealsServed = 0;
    maxDeadliftWeight = 0.f;
    numLockers = 0;
    numCarParkSpots = 0;
    costPerMeal = 0.f;
    therapyType = {};
}

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
       std::cout << player.name << " has Muscular pain and will require " << therapyType << " treatment" << "\n";
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

    Stadium();

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

        ConcessionStand();

        //check customer ID
        std::string isCustomerOfAge(int customerAge = 22);
        //display which customer order will be ready next
        void displayNextReadyCustomerOrder(int nextCustomerOrderNum);
        //take order from customer
        std::string takeCustomerOrder();
    };
    
    //host an event
    void hostAnEvent(std::string eventType);
    //open gates
    void openGates();
    //staff a concession stand
    int remainingTickets();

    ConcessionStand myConcessionStand;
};

Stadium::Stadium()
{
    numSeats = 0;
    name = {};
    turfType = 0;
    boxesOpen = true;
    numStaircases = 0;                      
    gatesOpen = true;
    numTicketsSold = 0;
    myConcessionStand = {};
}

Stadium::ConcessionStand::ConcessionStand()
{
    type = 0;
    hasLiquorLicense = false;
    minNumStaffRequired = 0;
    maxNumStaffRequired = 0;
    name = {};
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

    SupportersGroup();

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

        Supporter();

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

SupportersGroup::SupportersGroup()
{
    name = {};
    numMembers = 0;
    numSeasonTickets = 0;
    merchDiscountFromClub = 0.f;
    costOfMembership = 0.f;
    mySupporter= {};
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

    // play a match
    void playMatch(TeamProgram, Stadium);
    // run a training session
    float costToFeedStaffPerProgram(TeamProgram, TrainingComplex);
    // sign a player
    bool signAPlayer(Staff, float contractOffer);
};

SportsTeam::SportsTeam()
{
    name = {};
    staffMember = {};
    program = {};
    complex = {};
    stadium = {};
    mySupportersGroup = {};
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
    myXbox.readDisc("Grand Theft Auto");
    std::cout << "Am I connected to a network to play online? " << (myXbox.connectToNetwork(56.7f) ? "Yes" : "No")<< "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    //2) DOG
    Dog myLittlePup;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "2) Dog UDT" << "\n";
    myLittlePup.name = "Luna";
    std::cout << "My dog's name is: " << myLittlePup.name << "\n";
    myLittlePup.fetch("Tennis");
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    //3) BICYCLE
    Bicycle myLittleBike;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "3) Bicycle UDT" << "\n";
    myLittleBike.wheelRimSize = 0.45f;
    myLittleBike.handlebarsType = 1;
    std::cout << "You moved forwards by " << myLittleBike.moveForwards(3) << " meters" << "\n";
    myLittleBike.popWheelie();
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    //4) Electric Guitar
    ElectricGuitar myTelecaster;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "4) Electric Guitar UDT" << "\n";
    myTelecaster.changeTone(false);
    std::cout << "Tonepot is currently at: " << myTelecaster.tonepotSetting << "\n";
    std::cout << "Solo coming up!" << "\n";
    myTelecaster.changeTone(true);
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    //5) Staff
    Staff myStaffMember;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "5) Staff UDT" << "\n";
    myStaffMember.name = "Michael Scott";
    myStaffMember.injuryType = "Muscular";
    myStaffMember.hoursOfWork = 8.f;
    myStaffMember.goToWork(10.f);
    std::cout << "Did I hit Overtime yet? " << (myStaffMember.hitOvertime ? "Yes" : "No") << "\n";
    myStaffMember.attendMeeting();
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    //6) Team Program
    TeamProgram myTeam;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "6) Team Program UDT" << "\n";
    myTeam.numPlayersInProgram = 21;
    myTeam.numCoaches = 4;
    myTeam.currentBalance = 35459.f;
    std::cout << "Team's starting budget is: $" << myTeam.currentBalance << "\n";
    float amountToEnterLeague = 10000.f;
    std::cout << (myTeam.currentBalance >= amountToEnterLeague ? myTeam.enterALeague(amountToEnterLeague) : "You don't have the funds to enter this league" ) << "\n";
    std::cout << "Current budget: $" << myTeam.currentBalance << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    //7) Training Complex
    TrainingComplex myTrainingGround;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "7) Training Complex UDT" << "\n";
    std::cout << "Today we have " << myTrainingGround.numOfFreeParkingSpaces(myTeam) << " available" << "\n";
    myTrainingGround.costPerMeal = 1.23f;
    std::cout << "Total cost for meals will be: $" << myTrainingGround.costToFeedStaff(myTeam.numCoaches + myTeam.numPlayersInProgram, 2) << "\n";
    myTrainingGround.providePlayerRehab(myStaffMember);
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    //8) Stadium
    Stadium myStadium;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "8) Stadium UDT" << "\n";
    myStadium.name = "Pam Beasley Stadium";
    myStadium.numSeats = 30000;
    std::string todaysEvent = "Sports";
    myStadium.hostAnEvent(todaysEvent);
    std::cout << "What type of turf do we have for the event today? " << (myStadium.turfType ? "Grass" : "Turf" ) << "\n";
    std::string customerOrder = myStadium.myConcessionStand.takeCustomerOrder();
    std::cout << (customerOrder == "Beer" ? myStadium.myConcessionStand.isCustomerOfAge(20) : "Order being processed!") << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

        
    //9) Supporters Group
    SupportersGroup mySupportersGroup;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "9) Supporters Group UDT" << "\n";
    mySupportersGroup.mySupporter.name = "Jim Halpert";
    mySupportersGroup.name = "Scranton City Hooligans";
    mySupportersGroup.emailMemberOnBirthday();
    mySupportersGroup.mySupporter.attendMeeting();
    std::cout << mySupportersGroup.mySupporter.name << " has attended " << mySupportersGroup.mySupporter.numMeetingsAttended << " club meeting(s)" "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";
    
    
    //10) Sports Team
    SportsTeam mySportsTeam;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "10) Sports Team UDT" << "\n";
    mySportsTeam.name = "Scranton Paper FC";
    mySportsTeam.staffMember = myStaffMember;
    mySportsTeam.stadium = myStadium;
    mySportsTeam.program = myTeam;
    mySportsTeam.mySupportersGroup = mySupportersGroup;
    std::cout << mySportsTeam.name << " play their games at the " << mySportsTeam.stadium.name << " and are supported by a fan group called the " << mySportsTeam.mySupportersGroup.name << "\n";
    std::cout << "Today they offered a new contract to " << mySportsTeam.staffMember.name << ". ";
    std::cout << (mySportsTeam.signAPlayer(mySportsTeam.staffMember, 2000.f) ? "The offer was accepted" : "The offer was too low and was not accepted") << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";
}
