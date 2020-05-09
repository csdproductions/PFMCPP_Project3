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





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 */



/*
1) Games Console
5 properties:
    1) control pads
    2) disc drive
    3) usb ports
    4) hdmi outputs
    5) network connection
3 things it can do:
    1) read discs
    2) play games
    3) connect to network
 */

struct GamesConsole
{
    //control pads
    int noOfControlPads = 2;
    // storage drive size
    float storageDriveSize = 128.f;
    // usb ports
    int noOfUsbPorts = 4;
    // hdmi outputs
    int noOfHdmiOutputs = 3;
    // network connections
    int networkConnection = 2;

    // read discs
    void readDisc(std::string gameDisc = "Grand Theft Auto");
    // play games
    void playGame(int noOfPlayers = 8);
    // connect to network - return if connection successful
    bool connectToNetwork(float connectionSpeed = 1000.f);
};

/*
2) Dog
5 properties:
    1) fur colour
    2) age
    3) breed
    4) name
    5) sex
3 things it can do:
    1) fetch
    2) sit
    3) heel
 */

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
    void sit(std::string treatType = "Peanut Butter");
    //heel
    void heel();
};

/*
3) Bicycle
5 properties:
    1) frame size
    2) wheel size
    3) brakes model
    4) pedals type
    5) handlebars type
3 things it can do:
    1) move forwards
    2) bunny hop
    3) wheelie
 */

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
    float moveForwards();
    //bunny hop - return height
    float bunnyHop();
    //wheelie
    bool popWheelie();
};

/*
4) Electric Guitar
5 properties:
    1) body wood
    2) is neck joint glued
    3) high e string gauge
    4) pickups type
    5) no of frets 
3 things it can do:
    1) output sound
    2) change tone
    3) change pickup
 */

struct ElectricGuitar
{
    //body wood - 1 = maple, 2 = oak
    int bodyWoodType = 1;
    //neck joint glued
    bool isNeckJointGlued = false;
    //strings gauge
    int eStringGauge = 13;
    //pickups type
    std::string pickupsType = "Humbucker";
    //no of frets 
    int numFrets = 24;

    //output sound
    void outputSound(int fretPlayed);
    //change tone - return tone resistance value
    float changeTone(bool isSoloNow);
    //change pickup - return
    int selectPickup(int songStyle);
};


/*
5) Staff
5 properties:
    1) type
    2) sex
    3) age
    4) hours of work
    5) days of work
3 things it can do:
    1) go to work
    2) attend meeting
    3) sign a contract
 */

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

    //go to work
    void goToWork();
    //attend meeting
    void attendMeeting();
    //sign a contract
    bool signContract(float contractOffer = 20000.f);
 };

/*
6) program (male, female, or junior team)
5 properties:
    1) sex
    2) maximum age
    3) professional status
    4) number of staff
    5) total number of programs
3 things it can do:
    1) enter a league
    2) determine player's program
    3) advertise for players
 */

struct TeamProgram
{
    //sex
    bool isMale = true;
    //maximum age
    int maxAge = 21;
    //professional status
    std::string profStatus = "Semi-Professional";
    //number of staff
    int numStaff = 6;
    //total number of programs
    int numPlayersInProgram = 22;


    //enter a league
    void enterALeague();
    //determine player's program
    void playersProgram();
    //advertise for players
    void advertiseForPlayers(int howManySpacesLeft = 4);
};

/*
7) Training Complex
5 properties:
    1) receptionist of the day
    2) no of meals served in canteen a day
    3) maximum deadlift weight in gym
    4) no of lockers in locker room
    5) no of car park spots
3 things it can do:
    1) host training session
    2) feed staff
    3) provide player rehab
 */

struct TrainingComplex
{
    //receptionist of the day
    std::string receptionistName = "Dave";
    //no of meals served in canteen a day
    int noOfMealsServed = 122;
    //maximum deadlift weight in gym
    float maxDeadliftWeight = 500.f;
    //no of lockers in locker room
    int noOfLockers = 100;
    //no of car park spots
    int noOfCarParkSpots = 75;

    //host training session
    void hostTrainingSession();
    //feed staff
    void feedStaff(int howManyStaffWorkingToday = 75);
    //provide player rehab
    void providePlayerRehab(Staff player);
};


/*
8) Stadium
5 properties:
    1) capacity
    2) name
    3) turf type
    4) bool executive boxes open
    5) staircase names
3 things it can do:
    1) host an event
    2) open gates
    3) restock a concession stand
 */

struct Stadium
{
    //capacity
    int noOfSeats = 44000;
    //stadium name
    std::string name = "Paul Brown Stadium";
    //turf type (1 = grass, 2 = turf)
    int turfType = 1;
    //are executive boxes open
    bool boxesOpen = true;
    //no of staircases
    int noOfStaircases = 22;

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
        int displayNextReadyCustomerOrders();
        //take order from customer
        void takeCustomerOrder();
    };
    
    //host an event
    void hostAnEvent();
    //open gates
    void openGates();
    //restock a concession stand
    void restockConcessionStand(ConcessionStand myConcessionStand);

    ConcessionStand myConcessionStand;
};


/*
9) Supporter Group
5 properties:
    1) name
    2) no of members
    3) no of season tickets
    4) merch discount from club
    5) cost of membership
3 things it can do:
    1) arrange trip to away match
    2) add a new member
    3) email a member on their birthday
 */

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

        // join supporters group
        void joinSupportersGroup();
        // buy jersey
        void buyJersey();
        // go to away match
        void goToAwayMatch(std::string awayCity = "Salt Lake");
    };

    //Arrange trip to away match
    void organiseAwayMatchTrip(int noOfSupporters = 20);
    //Add a new member
    void admitNewMember(Supporter mySupporter);
    //Email a member on their birthday
    void emailMemberOnBirthday(Supporter mySupporter);

    Supporter mySupporter;
};


/*
10) Sports Team
5 properties:
    1) staff
    2) program
    3) training complex
    4) stadium
    5) supporter
3 things it can do:
    1) play a match
    2) run a training session
    3) sign a player
 */

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
    void runTrainingSession(TeamProgram, TrainingComplex);
    // sign a player
    bool signAPlayer(Staff);
 };

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
