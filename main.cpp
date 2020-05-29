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
    int numControlPads {0};
    // storage drive size
    float storageDriveSize {0.f};
    // usb ports
    int numUsbPorts {0};
    // current game
    std::string currentGame {};
    // network connections
    int networkConnection {0};
    
    GamesConsole() : numControlPads (2), numUsbPorts (4) {}

    // read discs
    void readDisc(std::string gameDisc = "Grand Theft Auto");
    // play games
    void playGame(int numPlayers = 8);
    // connect to network - return if connection successful
    bool connectToNetwork(float connectionSpeed = 1000.f);
};

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

    //fetch 
    void fetch(std::string ballType = "Tennis");
    //sit
    void giveTreat(std::string treatType = "Peanut Butter", int numOfTreats = 4);
    //heel
    float exerciseTime();
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
    std::cout << "You moved forward by: " << (3.14f * wheelRimSize) * numOfRevolutions << std::endl;
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
    //days of work
    int daysOfWork;
    
    bool hitOvertime;

    std::string injuryType;
    std::string name;

    float salary;

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
    hoursOfWork = 40.f;
    daysOfWork = 5;
    hitOvertime = false;
    injuryType = "None";
    salary = 0.f;
    name = {};
}

void Staff::goToWork(float numHoursToday)
{
    std::cout << "Standard working hours in a week for an employee must total " << hoursOfWork << " before they hit overtime." << std::endl;
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
    void numOfFreeParkingSpaces(TeamProgram myTeam);
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

void TrainingComplex::numOfFreeParkingSpaces(TeamProgram myTeam)
{
    std::cout << "The address of the complex is " << address << " and we have " << numCarParkSpots - (myTeam.numPlayersInProgram + myTeam.numCoaches)  << " car parking spots left most days" << std::endl;
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

        ConcessionStand();

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

    //Arrange trip to away match
    float costOfAwayMatchTrip(int noOfSupporters = 20);
    //Add a new member
    float numSeasonTicketsPerMember();
    //Email a member on their birthday
    void emailMemberOnBirthday();

    Supporter mySupporter = {};
};

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
    myLittleBike.handlebarsType = 1;
    myLittleBike.moveForwards(3);
    myLittleBike.popWheelie();
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    
    //4) Electric Guitar
    ElectricGuitar myTelecaster;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "4) Electric Guitar UDT" << "\n";
    myTelecaster.changeTone(false);
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
    std::cout << "We have " << myTeam.advertiseForPlayers() << " spaces left in the team" << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "\n";

    //7) Training Complex
    TrainingComplex myTrainingGround;
    std::cout << "\n";
    std::cout << "-----------------------------------" << "\n";
    std::cout << "7) Training Complex UDT" << "\n";
    myTrainingGround.numOfFreeParkingSpaces(myTeam);
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
    std::string todaysEvent = "Sports";
    myStadium.numTicketsSold = 31138;
    myStadium.remainingTickets();
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
