/*
Name: Cobain Irwin
Date: 20260909
Module 3 Program 1

We are going to making a trivia game about one of the games I know the most about and totally havnt spent the
last 20 years playing :D... WORLD OF WARCRAFT

_____                                                   _____
( ___ )-------------------------------------------------( ___ )
|   |                                                   |   |
|   |                                                   |   |
|   |                                                   |   |
|   |                                                   |   |
|   |       __        __         _     _                |   |
|   |       \ \      / /__  _ __| | __| |               |   |
|   |        \ \ /\ / / _ \| '__| |/ _` |               |   |
|   |         \ V  V / (_) | |  | | (_| |               |   |
|   |          \_/\_/ \___/|_|__|_|\__,_|               |   |
|   |                  / _ \|  ___|                     |   |
|   |                 | | | | |_                        |   |
|   |                 | |_| |  _|                       |   |
|   |   __        __   \___/|_|___            __ _      |   |
|   |   \ \      / /_ _ _ __ / ___|_ __ __ _ / _| |_    |   |
|   |    \ \ /\ / / _` | '__| |   | '__/ _` | |_| __|   |   |
|   |     \ V  V / (_| | |  | |___| | | (_| |  _| |_    |   |
|   |      \_/\_/ \__,_|_|   \____|_|  \__,_|_|  \__|   |   |
|   |                                                   |   |
|   |                                                   |   |
|   |                                                   |   |
|___|                                                   |___|
(_____)-------------------------------------------------(_____)
*/

#include <iostream>
#include <set>
#include <string>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <string>
#include <cctype>
// Im testing something with chrono for a time func
#include <chrono>





using namespace std;

int main()
{
    /*
     * what are out inputs?
     *  -We are going to be getting user input to answer the questions we give them
     *  -How do we plan on doing this?
     *      - More than likely using Interger instead of letters, I find Ints easier to press rather than going and
     *        and looking for the Char on my keyboard... but maybe Im weird... dont answer that.
     *
     * What are our cals?
     *  - Ill get to that, but pretty sure we will determine how many points a question is worth and add that to a total
     *    score that we will print at the end of each round. so points += new_points... gg
     *
     * what are out outputs?
     *  - We will be out putting to the user the questions so : cout << "Question " << questions_num_1 << ": How many toasters can you fit inside a bathtub full of water?\n";
     *    then we list off questions and have one of those preset as the correct answer with a switch statement
     *  - then we will output total score. If they get more than 50% then they are Cool and can join the HORDE... if they get under 50% they are a chud of the Alliance.
     *  - please dont questions me and lets hope I dont keep this comment section... ((realistically what I should do... I have Horde and Alliance questions. I have a secret var I track for each horde question
     *      and each alliance question they get right... and then at the end we tell them which side they got more right they get to join. if they get them all wrong we throw them into the Maelstrom.))
     *          TO ADD ONTO, if they get a Horde question wrong the ally score goes up and vise versa?????
     *  - GG THIS IS THE PLAN
     *
     */

    

    // testing nums

    // vars
    // game loop start
    bool playing_trivia(true);
    string playing_trivia_restart("");

    // ints
    int hidden_alliance(0);
    int hidden_horde(0);
    int points(0);
    int trivia_game_choice(0);

    int sus_points(0);
    int width_of_panel(70);

    // vars for question answers
    int answer_2_question_1(0);
    int answer_2_question_2(0);
    int answer_2_question_3(0);
    int answer_2_question_4(0);
    int answer_2_question_5(0);
    int answer_2_question_6(0);
    int answer_2_question_7(0);
    int answer_2_question_8(0);
    int answer_2_question_9(0);
    int answer_2_question_10(0);

    // vars for unhinged questions
    int answer_2_unhinged_question_1(0);
    int answer_2_unhinged_question_2(0);
    int answer_2_unhinged_question_3(0);
    int answer_2_unhinged_question_4(0);
    int answer_2_unhinged_question_5(0);
    int answer_2_unhinged_question_6(0);
    int answer_2_unhinged_question_7(0);
    int answer_2_unhinged_question_8(0);
    int answer_2_unhinged_question_9(0);
    int answer_2_unhinged_question_10(0);
    int answer_2_unhinged_question_11(0);
    int answer_2_anti_brain_rot(0);

    // strings
    //
    string contestants_name("");
    // questions to be asked
    //  Normal questions
    const string WARCRAFT_TRIVIA_QUESTION_1 = "What was name of the item Thrall used to \"Defeat\" Deathwing!\n";
    const string WARCRAFT_TRIVIA_QUESTION_2 = "What is the name of Arthas Menethil's legendary runeblade?\n";
    const string WARCRAFT_TRIVIA_QUESTION_3 = "What is the capital city of the Orcs?\n";
    const string WARCRAFT_TRIVIA_QUESTION_4 = "What was Deathwing's original name before becoming Deathwing?\n";
    const string WARCRAFT_TRIVIA_QUESTION_5 = "Who is known as \"The Betrayer\"?\n";
    const string WARCRAFT_TRIVIA_QUESTION_6 = "Which raid is home to the Lich King encounter?\n";
    const string WARCRAFT_TRIVIA_QUESTION_7 = "Which dragonflight did Deathwing lead before his corruption?\n";
    const string WARCRAFT_TRIVIA_QUESTION_8 = "Who is the leader of the Burning Legion who corrupted the eredar and eventually turned against the other Titans?\n";
    const string WARCRAFT_TRIVIA_QUESTION_9 = "What is the capital city of the human kingdom of Stormwind?\n";
    const string WARCRAFT_TRIVIA_QUESTION_10 = "What was the name of Arthas's kingdom before he became the Lich King?\n";

    // The book is open source and gotten from "https://www.gutenberg.org/cache/epub/72572/pg72572-images.html"
    //  The book is called Computers-- The machines we think with | Project Gutenberg
    //  Author: D. S. Halacy
    //  Release date: January 1, 2024
    //  Original publication: New York: Harper & Row, 1962

    const string ANTI_BRAIN_ROT_TRIVIA_QUESTION_1 = R"(
    ======================================================================
                             REQUIRED READING
    ======================================================================
    
    Among the computer's unusual talents is the ability to compose music.
    Such music has been published and is of a quality to give rise to
    thoughtful speculation that perhaps great composers are simply good
    selectors of music. In other words, all the combinations of notes and
    meter exist: the composer just picks the right ones.
    
    No less an authority than Aaron Copland suggests that "we'll get our
    new music by feeding information into an electronic computer." Not
    content with merely writing music, some computers can even play a tune.
    At Christmas time, carols are rendered by computers specially
    programmed for the task. The result is not unlike a melody played on
    a pipe organ.
    
    In an interesting switch of this musical ability on the part of the
    machine, Russian engineers check the reliability of their computers
    by having them memorize Mozart and Grieg. Each part of the complex
    machines is assigned a definite musical value, and when the composition
    is "played back" by the computer, the engineer can spot any defects
    existing in its circuitry. Such computer maintenance would seem to be
    an ideal field for the music lover.
    
    In a playful mood, computers match pennies with visitors, explain their
    inner workings as they whiz through complex mathematics, and are even
    capable of what is called heuristic reasoning. This amounts to playing
    hunches to reach short-cut solutions to otherwise unsolvable problems.
    
    A Rand Corporation computer named JOHNNIAC demonstrated this recently.
    It was given some basic axioms and asked to prove some theorems.
    JOHNNIAC came up with the answers, and in one case produced a proof
    that was simpler than that given in the text. As one scientist puts it,
    "If computers don't really think, they at least put on a pretty
    creditable imitation of the real thing."
    
    Computers are here to stay; this has been established beyond doubt.
    The only question remaining is how fast the predictions made by
    dreamers and science-fiction writers -- and now by sober scientists --
    will come to be a reality.
    
    When we consider that in the few years since the 1953 crop of computers,
    their capacity and speed has been increased more than fiftyfold, and is
    expected to jump another thousandfold in two years, these dreams begin
    to sound more and more plausible.
    
    One quite probable use for computers is medical diagnosis and
    prescription of treatment. Electronic equipment can already monitor an
    ailing patient, and send an alarm when help is needed. We may one day
    see computers with a built-in bedside manner aiding the family doctor.
    
    The accomplished inroads of computing machines in business are as
    nothing to what will eventually take place. Already computer
    "game-playing" has extended to business management, and serious
    executives participate to improve their administrative ability.
    
    We speak of decision-making machines; business decisions are logical
    applications for this ability. Computers have been given the job of
    evaluating personnel and assigning salaries on a strictly logical
    basis. Perhaps this is why in surveys questioning increased use of the
    machines, each executive level in general tends to rate the machine's
    ability just below its own.
    
    ======================================================================
    )";

    // Unhinged questions
    const string UNHINGED_QUESTION_1 = "What the name of the host of the Trivia game!\n";
    const string UNHINGED_QUESTION_2 = "Whos's on first?\n";
    const string UNHINGED_QUESTION_3 = "How long is TDS( Towed Decoy System) of the B1-Bomber?\n";
    const string UNHINGED_QUESTION_4 = "If I were to ask for 20$ would you give it to me?\n";
    const string UNHINGED_QUESTION_5 = "How many raccoons do you think it would take to defeat a grown man?\n";
    const string UNHINGED_QUESTION_6 = "Which is more dangerous: a bear with a sword or a guy who says 'trust me, I know computers'?\n";
    const string UNHINGED_QUESTION_7 = "If a hotdog is technically a sandwich, does that make cereal a soup?\n";
    const string UNHINGED_QUESTION_8 = "How many times can you say 'I'm just the intern' before it legally becomes your job title?\n";
    const string UNHINGED_QUESTION_9 = "If you delete System32, does Windows become System31?\n";
    const string UNHINGED_QUESTION_10 = "You have 10 seconds to answer this question. What happens if you take 11?\n";
    const string UNHINGED_QUESTION_11 = "A NEW HAND TOUCHES THE BEACON\n";
    const string UNHINGED_QUESTION_12 = "Final question: Are you absolutely sure you want me to calculate your score?\n";

    // bools
    bool answering_q1(true);
    bool answering_q2(true);
    bool answering_q3(true);
    bool answering_q4(true);
    bool answering_q5(true);
    bool answering_q6(true);
    bool answering_q7(true);
    bool answering_q8(true);
    bool answering_q9(true);
    bool answering_q10(true);
    bool answering_q11(true);
    bool answering_q12(true);

    // We start dah code here

    while (playing_trivia == true)
    {

        // RESET GAME VALUES
        points = 0;
        hidden_alliance = 0;
        hidden_horde = 0;
        sus_points = 0;
        answering_q1 = true;
        answering_q2 = true;
        answering_q3 = true;
        answering_q4 = true;
        answering_q5 = true;
        answering_q6 = true;
        answering_q7 = true;
        answering_q8 = true;
        answering_q9 = true;
        answering_q10 = true;
        answering_q11 = true;
        answering_q12 = true;

        cout << "=========================================================\n";
        cout << "Welcome To Warcraft Trivia night! Hosted by Sargeras!\n";
        cout << "=========================================================\n";
        cout << "Before we begin can we get your name! We promise not to sell your information to the Legion!\n";
        cout << "Contestants name: ";
        getline(cin, contestants_name);

        cout << string(width_of_panel, '=') << endl;

        cout << "Now for my next question, " << contestants_name << " , do you want to play Trivia... or\n";
        cout << "DO YOU WANT TO PLAY TRIVIA WHERE I KINDA MAKE FUN OF YOU, jokingly, in minecraft... yea in minecraft...\n";
        cout << string(width_of_panel, '=') << endl;

        cout << "For normal Trivia: 1\n";
        cout << "For funny haha Trivia: 2\n";
        cout << contestants_name << "'s Response: ";
        cin >> trivia_game_choice;
        cout << endl
             << endl;
        cout << string(width_of_panel, '=') << endl;

        switch (trivia_game_choice)
        {
            case 1: // This is normal trivia...
            {
                while (answering_q1 == true) //happy with this one.
                {

                    cout << string(width_of_panel, '=') << endl;
                    cout << "Okay " << contestants_name << " for your first question:" << endl;
                    cout << WARCRAFT_TRIVIA_QUESTION_1;
                    cout << "1. Man Idk Im just the intern\n";
                    cout << "2. Dragon Soul.\n";
                    cout << "3. Demon Soul.\n";
                    cout << "4. Dark Souls.\n";
                    cout << "5. ThunderFury, Blessed Blade of the Windseeker.\n\n";
                    cout << string(width_of_panel, '=') << endl;

                    cout << contestants_name << "'s answer: ";
                    cin >> answer_2_question_1;
                    cout << string(width_of_panel, '=') << endl;

                    switch (answer_2_question_1)
                    {
                        case 1:
                            cout << "The correct answer was Dragon Soul.\n";
                            cout << "Same... same... I wasnt even there\n";
                            hidden_alliance--;
                            points -= 100;
                            cout << "Sadly that is incorrect!\n";
                            cout << " You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q1 = false;

                            break;

                        case 2:
                            cout << "That is correct! congradulations Youve earned 100 points!\n";
                            hidden_horde++;
                            hidden_alliance--;
                            points += 100;
                            cout << "You will be given 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q1 = false;
                            break;

                        case 3:
                            cout << "The correct answer was Dragon Soul.\n";
                            cout << "Now even I knew that wasnt the right answer, and Im the master of all demons!\n";
                            hidden_alliance--;
                            points -= 100;
                            cout << "Sadly that is incorrect!\n";
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q1 = false;
                            break;

                        case 4:
                            cout << "The correct answer was Dragon Soul.\n";
                            cout << "Did you just get done playing a FromSoft game??? This is a Blizzard tittle man...\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "Sadly that is incorrect!\n";
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q1 = false;
                            break;

                        case 5:
                            cout << "The correct answer was Dragon Soul.\n";
                            cout << "DID SOMEONE SAY THUNDERFURY BLESSED BLADE OF THE WINDSEEKER?... yes, well more than likely...\n";
                            cout << "Sadly however that isnt the correct answer, youre going to be deducted 100 points...";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q1 = false;
                            break;

                        default:
                            cout << "Please Give and answer using 1,2,3,4 or 5 please...\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    } // end of while case.
                } // end of case 1/question 1

                while (answering_q2 == true) // happy with this q2
                {

                    // we get question 2 asked here and answered
                    cout << WARCRAFT_TRIVIA_QUESTION_2;
                    cout << "1. Ashbringer\n";
                    cout << "2. Shadowmourne.\n";
                    cout << "3. Frostmourne.\n";
                    cout << "4. ThunderFury, Blessed Blade of the Windseeker.\n";
                    cout << "5. Light's Vengeance.\n\n";
                    cin >> answer_2_question_2;
                    cout << string(width_of_panel, '=') << endl;

                    switch (answer_2_question_2)
                    { // switch for question 2 choices.
                        case 1:
                            cout << "The correct answer was Frostmourne.\n";
                            cout << "sorry but thats incorrect...\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q2 = false;
                            break;

                        case 2:
                            cout << "The correct answer was Frostmourne.\n";
                            cout << "sorry but thats incorrect...\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q2 = false;
                            break;

                        case 3:
                            cout << "sorry but thats... Wait no thats correct, nevermind!\n";
                            hidden_alliance++;
                            hidden_horde--;
                            points += 100;
                            cout << "You've earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q2 = false;
                            break;

                        case 4:
                            cout << "The correct answer was Frostmourne.\n";
                            cout << "sorry but thats incorrect...\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q2 = false;
                            break;

                        case 5:
                            cout << "The correct answer was Frostmourne.\n";
                            cout << "Listen youre kinda right, that its a weapon once weilded by Arthas... but its not a runeblade!\n";
                            cout << "You will be deducted 100 points!\n\n";
                            hidden_horde++;
                            hidden_alliance--;
                            points -= 100;
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q2 = false;
                            break;

                        default:

                            cout << "Please Give and answer using 1,2,3 or 4 please...\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    } // end of while loop 2
                } // end of question 2 put question 3 here

                while (answering_q3 == true)// happy with 3
                {
                    cout << WARCRAFT_TRIVIA_QUESTION_3;
                    cout << "1. Thunder Bluff.\n";
                    cout << "2. Silvermoon City.\n";
                    cout << "3. Undercity.\n";
                    cout << "4. Orgrimmar.\n";
                    cout << "5. Stormwind City\n\n";
                    cin >> answer_2_question_3;
                    cout << string(width_of_panel, '=') << endl;
    
                    switch (answer_2_question_3)
                    { // switch for question 3 choices.
                        case 1:
                            cout << "The correct answer was Orgrimmar.\n";
                            cout << "sorry but thats incorrect...\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q3 = false;
                            break;
    
                        case 2:
                            cout << "The correct answer was Orgrimmar.\n";
                            cout << "sorry but thats incorrect...\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q3 = false;
                            break;
    
                        case 3:
                            cout << "The correct answer was Orgrimmar.\n";
                            cout << "sorry but thats incorrect...\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q3 = false;
                            break;
    
                        case 4:
                            cout << "sorry but thats... Wait no thats correct, nevermind!\n";
                            hidden_alliance++;
                            hidden_horde--;
                            points += 100;
                            cout << "You've earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q3 = false;
                            break;
    
                        case 5:
                            cout << "The correct answer was Orgrimmar.\n";
                            cout << "Did... did you just... I think you should leave... that wasnt even the right faction.\n";
                            hidden_alliance += 2;
                            hidden_horde -= 2;
                            points -= 100;
                            cout << "You've lost 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q3 = false;
                            break;
    
                        default:
                            cout << "Please Give and answer using 1,2,3,4 or 5 please...\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }//end of while loop for 3
                } // end of question 3 put question 4 here
                
                while (answering_q4 == true) //happy with 4
                {
                    cout << WARCRAFT_TRIVIA_QUESTION_4;
                    cout << "1. Malygos.\n";
                    cout << "2. Nozdormu.\n";
                    cout << "3. Neltharion.\n";
                    cout << "4. Nefarian.\n";
                    cout << "5. Gulduron\n\n";
                    cin >> answer_2_question_4;
                    cout << string(width_of_panel, '=') << endl;
    
                    switch (answer_2_question_4)
                    { // switch for question 4 choices.
                        case 1:
                            cout << "The correct answer was Neltharion.\n";
                            cout << "Close, he was head of the Blue Dragon flight\n";
                            cout << "So with that being said thats incorrect...\n";
                            hidden_alliance--;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q4 = false;
                            break;
    
                        case 2:
                            cout << "The correct answer was Neltharion.\n";
                            cout << "This is the leader of the Bronze Dragon flight.\n";
                            cout << "With that being said but thats incorrect...\n";
                            hidden_alliance--;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q4 = false;
                            break;
    
                        case 3:
                            cout << "Thats correct!\n";
                            hidden_horde--;
                            hidden_alliance++;
                            points += 100;
                            cout << "You've earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q4 = false;
                            break;
    
                        case 4:
                            cout << "The correct answer was Neltharion.\n";
                            cout << "sorry but thats incorrect...\n";
                            hidden_alliance--;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q4 = false;
                            break;
    
                        case 5:
                            cout << "The correct answer was Neltharion.\n";
                            cout << "Sadly my Fire Mage isnt nearly as strong as a world breaking dragon...\n";
                            cout << "BECAUSE HE IS STRONGER, IVE DEFEAT THAT DRAGON HUNDREDS OF TIMES...\n";
                            cout << "Sadly youre still going to lose points for that one though...";
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            hidden_alliance--;
                            hidden_horde++;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q4 = false;
                            break;
    
                        default:
                            cout << "Please Give and answer using 1,2,3,4 or 5 please...\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }//end of while loop for 4
                }// end of question 4 put question 5 here
                while(answering_q5 == true)//happy with 5
                {
                    cout << WARCRAFT_TRIVIA_QUESTION_5;
                    cout << "1. Arthas Menethil.\n";
                    cout << "2. Gul'dan.\n";
                    cout << "3. Kael'thas Sunstrider.\n";
                    cout << "4. Illidan Stormrage.\n";
                    cout << "5. Legionnaire Kigamusha\n\n";
                    cin >> answer_2_question_5;
                    cout << string(width_of_panel, '=') << endl;
    
                    switch (answer_2_question_5)
                    { // switch for question 5 choices.
                        case 1:
                            cout << "The correct answer was Illidan Stormrage.\n";
                            cout << "Did you know that Illidan, aka The Betrayer, once fought but Arthas as to strong?\n";
                            cout << "Sadly youve still answered incorrectly\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q5 = false;
                            break;
    
                        case 2:
                            cout << "The correct answer was Illidan Stormrage.\n";
                            cout << "No, this isnt correct. Gul'dan was a power hungry orc who died trying TO betray me...\n";
                            cout << "The Betrayer Illidan just absorbed the power of the fel from his corpse.\n";
                            cout << "sorry but thats incorrect...\n";
                            hidden_horde++;
                            hidden_alliance--;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q5 = false;
                            break;
    
                        case 3:
                            cout << "The correct answer was Illidan Stormrage.\n";
                            cout << "Kael'thas Sunstrider. was actually just General and the King of the Blood Elves.\n";
                            cout << "So you didnt choose correctly\n";
                            hidden_horde ++;
                            hidden_alliance--;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q5 = false;
                            break;
    
                        case 4:
                            cout << "The correct answer was infact Illidan Stormrage!\n";
                            hidden_alliance++;
                            hidden_horde --;
                            points += 100;
                            cout << "Congradulations, you've earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q5 = false;
                            break;
    
                        case 5:
                            cout << "The correct answer was Illidan Stormrage.\n";
                            cout << "HEY THE ONLY THING MY WARRIOR BETRAYED WAS NOT MAKING IT TO GLADIATOR...\n";
                            cout << "This was the actual name and title of my warrior, listen I used to have a lot more time on my hands.\n";
                            hidden_horde++;
                            hidden_alliance--;
                            points -= 100;
                            cout << "You've earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q5 = false;
                            break;
    
                        default:
                            cout << string(width_of_panel, '=') << endl;
                            cout << "Please Give and answer using 1,2,3,4 or 5 please...\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }//end of while loop/switch
                } // end of question 5 put question 6 here

                while(answering_q6 == true) //happy with 6
                {
                    cout << WARCRAFT_TRIVIA_QUESTION_6;
                    cout << "1. Naxxramas.\n";
                    cout << "2. Ulduar.\n";
                    cout << "3. Icecrown Citadel.\n";
                    cout << "4. Trial of the Crusader.\n";
                    cout << "5. Stratholme\n\n";
                    cin >> answer_2_question_6;
                    cout << string(width_of_panel, '=') << endl;
                    
    
                    switch (answer_2_question_6) //happy with 6
                    { // switch for question 6 choices.
                        case 1:
                            cout << "The correct answer was Icecrown Citadel.\n";
                            cout << "We dont defeat Arthas/The Lich King here.\n";
                            cout << "Instead we \"Defeat\" Kel Thuzad and he returns to his phylactery ";
                            cout << "However with that being said" << contestants_name << ", sorry but thats incorrect...\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q6 = false;
                            break;
    
                        case 2:
                            cout << "The correct answer was Icecrown Citadel.\n";
                            cout << "This is the raid where we defeat Yogg-Saron, Not The Litch King.\n";
                            cout << "sorry but thats incorrect...\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q6 = false;
                            break;
                            
    
                        case 3:
                            cout << "Youre correct! and now I'll deliver to you one of my favorite exchanges from wow with you.\n";
                            cout << R"(
                            Arthas Menethil says: Father! Is it... over?
                            
                            Terenas Menethil II says: At long last, no king rules forever, my son
                            
                            Terenas lays a comforting hand on Arthas' gauntlet.
                            Arthas Menethil says: I see... only darkness.. before... me)";
                            hidden_alliance++;
                            hidden_horde--;
                            points += 100;
                            cout << "You've earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q6 = false;
                            break;
    
                        case 4:
                            cout << "The correct answer was Icecrown Citadel.\n";
                            cout << "He makes a brief apperance here but we do not defeat him at this time.\n";
                            cout << "Sorry but youve chosen the wrong answer.\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q6 = false;
                            break;
    
                        case 5:
                            cout << "The correct answer was Icecrown Citadel.\n";
                            cout << "Thats not the raid hes in, just the city he burned to the ground...\n";
                            cout << "Sorry but youve chosen the wrong answer.";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q6 = false;
                            break;
    
                        default:
                            cout << string(width_of_panel, '=') << endl;
                            cout << "Please Give and answer using 1,2,3,4 or 5 please...\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }
                } // end of question 6 put question 7 here

                while(answering_q7 == true) // happy with 7
                {
                    cout << WARCRAFT_TRIVIA_QUESTION_7;
                    cout << "1. Red Dragonflight.\n";
                    cout << "2. Blue Dragonflight.\n";
                    cout << "3. Bronze Dragonflight.\n";
                    cout << "4. Black Dragonflight.\n";
                    cout << "5. Green Dragonflight\n\n";
                    cin >> answer_2_question_7;
                    cout << string(width_of_panel, '=') << endl;
    
                    switch (answer_2_question_7)
                    { // switch for question 7 choices.
                        case 1:
                            cout << "The correct answer was Black Dragonflight.\n";
                            cout << "sorry but thats incorrect due to being the wrong Dragonflight.\n";
                            cout << "Alexstrasza the Life-Binder, is the leader of the Red Dragonflight\n";
                            cout << "Deathwing was the leader of the Black Dragonflight!.\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q7 = false;
                            break;
    
                        case 2:
                            cout << "The correct answer was Black Dragonflight.\n";
                            cout << "sorry but thats incorrect due to being the wrong Dragonflight.\n";
                            cout << "Kalecgos is the Aspect of the blue dragonflight.\n";
                            cout << "Deathwing was the leader of the Black Dragonflight!.\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q7 = false;
                            break;
    
                        case 3:
                            cout << "The correct answer was Black Dragonflight.\n";
                            cout << "sorry but thats incorrect due to being the wrong Dragonflight.\n";
                            cout << "Nozdormu the Timeless One, is the aspect of the Bronze Dragonflight\n";
                            cout << "Deathwing was the leader of the Black Dragonflight!.\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q7 = false;
                            break;
    
                        case 4:
                            cout << "Thats correct! Deathwing was the leader of the Black Dragonflight!.\n";
                            hidden_alliance++;
                            hidden_horde--;
                            points += 100;
                            cout << "You've earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q7 = false;
                            break;
    
                        case 5:
                            cout << "The correct answer was Black Dragonflight.\n";
                            cout << "sorry but thats incorrect due to being the wrong Dragonflight.\n";
                            cout << "Ysera, the Dreamer is the leader of the Green Dragon Flight.\n";
                            cout << "Deathwing was the leader of the Black Dragonflight!.\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q7 = false;
                            break;
    
                        default:
                            
                            cout << "Please Give and answer using 1,2,3,4 or 5 please...\n";
                            cout << string(width_of_panel, '=') << endl;
                            
                            break;
                    }//end of while loop
                } // end of question 7 put question 8 here

                while (answering_q8 == true) // Question 8
                {
                    cout << WARCRAFT_TRIVIA_QUESTION_8;
                    cout << "1. Kil'jaeden.\n";
                    cout << "2. Archimonde.\n";
                    cout << "3. Gul'dan.\n";
                    cout << "4. Sargeras.\n";
                    cout << "5. Arthas Menethil\n\n";
                
                    cout << contestants_name << "'s answer: ";
                    cin >> answer_2_question_8;
                    cout << string(width_of_panel, '=') << endl;
                
                    switch (answer_2_question_8)
                    {
                        case 1:
                            cout << "The correct answer was Sargeras.\n";
                            cout << "Kil'jaeden? Close... VERY close actually.\n";
                            cout << "He was one of my most powerful servants after joining the Burning Legion,\n";
                            cout << "but he wasnt the Titan who started this whole mess.\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q8 = false;
                            break;
                
                        case 2:
                            cout << "The correct answer was Sargeras.\n";
                            cout << "Archimonde was powerful, I'll give you that...\n";
                            cout << "But he worked FOR the Burning Legion. He didnt create it.\n";
                            cout << "Sadly thats incorrect.\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q8 = false;
                            break;
                
                        case 3:
                            cout << "The correct answer was Sargeras.\n";
                            cout << "Gul'dan?! The Orc warlock?\n";
                            cout << "Listen, he caused A LOT of problems, but Titan is definitely not on his resume.\n";
                            cout << "Sadly thats incorrect.\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q8 = false;
                            break;
                
                        case 4:
                            cout << "SARGERAS! Thats correct!\n";
                            cout << "Wait... you remembered the name of the guy HOSTING THIS TRIVIA GAME?\n";
                            cout << "Im actually impressed.\n";
                            hidden_alliance++;
                            hidden_horde--;
                            points += 100;
                            cout << "You've earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q8 = false;
                            break;
                
                        case 5:
                            cout << "The correct answer was Sargeras.\n";
                            cout << "Arthas Menethil? No no no... wrong evil guy.\n";
                            cout << "He became the Lich King. He did NOT lead the Burning Legion.\n";
                            cout << "There are too many corrupted people in this game, I understand the confusion.\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q8 = false;
                            break;
                
                        default:
                            cout << "Please Give and answer using 1,2,3,4 or 5 please...\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }
                } // end of question 8 put question 9 here
                
                
                while (answering_q9 == true) // Question 9
                {
                    cout << WARCRAFT_TRIVIA_QUESTION_9;
                    cout << "1. Ironforge.\n";
                    cout << "2. Stormwind City.\n";
                    cout << "3. Lordaeron.\n";
                    cout << "4. Gilneas.\n";
                    cout << "5. Orgrimmar\n\n";
                
                    cout << contestants_name << "'s answer: ";
                    cin >> answer_2_question_9;
                    cout << string(width_of_panel, '=') << endl;
                
                    switch (answer_2_question_9)
                    {
                        case 1:
                            cout << "The correct answer was Stormwind City.\n";
                            cout << "Ironforge is an Alliance capital, so at least youre in the right neighborhood...\n";
                            cout << "Unfortunately its the Dwarven capital, not Stormwind's.\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q9 = false;
                            break;
                
                        case 2:
                            cout << "Stormwind City! Thats correct!\n";
                            cout << "The question practically gave you the answer, but hey, 100 points is 100 points.\n";
                            hidden_alliance++;
                            hidden_horde--;
                            points += 100;
                            cout << "You've earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q9 = false;
                            break;
                
                        case 3:
                            cout << "The correct answer was Stormwind City.\n";
                            cout << "Lordaeron was a human kingdom, but it definitely isnt Stormwind.\n";
                            cout << "Keep that name in mind though... You MIGHT need it very soon.\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q9 = false;
                            break;
                
                        case 4:
                            cout << "The correct answer was Stormwind City.\n";
                            cout << "Gilneas is another human kingdom, but thats not the one I asked for.\n";
                            cout << "Greymane would probably be happy you remembered them though.\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q9 = false;
                            break;
                
                        case 5:
                            cout << "The correct answer was Stormwind City.\n";
                            cout << "We went over this earlier...\n";
                            cout << "ORGRIMMAR IS THE HORDE CAPITAL!\n";
                            cout << "You have somehow answered an Alliance question with the most Horde answer possible.\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q9 = false;
                            break;
                
                        default:
                            cout << "Please Give and answer using 1,2,3,4 or 5 please...\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }
                } // end of question 9 put question 10 here
                
                
                while (answering_q10 == true) // Question 10
                {
                    cout << WARCRAFT_TRIVIA_QUESTION_10;
                    cout << "1. Stormwind.\n";
                    cout << "2. Gilneas.\n";
                    cout << "3. Alterac.\n";
                    cout << "4. Lordaeron.\n";
                    cout << "5. Icecrown Citadel\n\n";
                
                    cout << contestants_name << "'s answer: ";
                    cin >> answer_2_question_10;
                    cout << string(width_of_panel, '=') << endl;
                
                    switch (answer_2_question_10)
                    {
                        case 1:
                            cout << "The correct answer was Lordaeron.\n";
                            cout << "Stormwind? Wrong human kingdom.\n";
                            cout << "Arthas was a prince, but definitely not Prince of Stormwind.\n";
                            cout << "Sorry, thats incorrect.\n";
                            hidden_alliance--;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q10 = false;
                            break;
                
                        case 2:
                            cout << "The correct answer was Lordaeron.\n";
                            cout << "Gilneas? Nope.\n";
                            cout << "Different kingdom, different prince, substantially fewer cursed swords involved.\n";
                            hidden_alliance--;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q10 = false;
                            break;
                
                        case 3:
                            cout << "The correct answer was Lordaeron.\n";
                            cout << "Alterac is another human kingdom, but Arthas wasnt its prince.\n";
                            cout << "Sadly thats incorrect.\n";
                            hidden_alliance--;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q10 = false;
                            break;
                
                        case 4:
                            cout << "LORDAERON! Thats correct!\n";
                            cout << "Arthas Menethil was the Prince of Lordaeron before everything went...\n";
                            cout << "well... EXTREMELY poorly.\n";
                            hidden_alliance++;
                            points += 100;
                            cout << "You've earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q10 = false;
                            break;
                
                        case 5:
                            cout << "The correct answer was Lordaeron.\n";
                            cout << "I... Thats not even a kingdom.\n";
                            cout << "Icecrown Citadel is where we eventually fight Arthas AS the Lich King.\n";
                            cout << "You were several years and one very cursed sword too late with that answer.\n";
                            hidden_alliance--;
                            hidden_horde++;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q10 = false;
                            break;
                
                        default:
                            cout << string(width_of_panel, '=') << endl;
                            cout << "Please Give and answer using 1,2,3,4 or 5 please...\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }
                } // end of question 10

                break;
            } // closes case 1 block

            case 2: // this is unhinged trivia
            {       // start of case 2
                cout << "\n";
                cout << string(width_of_panel, '=') << endl;
                cout << "                    UNHINGED TRIVIA MODE\n";
                cout << string(width_of_panel, '=') << endl;
                cout << "I cant believe you actually selected 2...\n";
                cout << "You had a perfectly normal trivia game sitting RIGHT THERE.\n";
                cout << "But no...\n";
                cout << "You wanted this.\n";
                cout << string(width_of_panel, '=') << endl;

                // Unhinged question 1
                while (answering_q1 == true)
                {
                    cout << "\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << "                       QUESTION 1\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << UNHINGED_QUESTION_1;
                    cout << "1. " << contestants_name << endl;
                    cout << "2. Sargeras\n";
                    cout << "3. George Bush\n";
                    cout << "4. I didnt actually read any of the outputs on the screen...\n";
                    cout << string(width_of_panel, '-') << endl;
                    cout << contestants_name << "'s answer: ";
                    cin >> answer_2_unhinged_question_1;
                    cout << string(width_of_panel, '=') << endl;

                    switch (answer_2_unhinged_question_1)
                    {
                        case 1:
                            cout << "Wait was that really my name? I dont think I said that was my name?\n";
                            cout << "Did I say I was " << contestants_name << "?\n";
                            cout << "NO... I said my name was Sargeras...\n";
                            sus_points += 100;
                            points -= 100;
                            cout << "Sadly that is incorrect!\n";
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q1 = false;
                            break;

                        case 2:
                            cout << "SARGERAS! Thats correct!\n";
                            cout << "Congratulations, you remembered the name of the person hosting the game.\n";
                            sus_points += 420;
                            points += 100;
                            cout << "You will be given 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q1 = false;
                            break;

                        case 3:
                            cout << "Thats odd that you thought it was him in the month of September.\n";
                            cout << "Did you know JetPhuel melts steel beams?\n\n";
                            cout << "Whats funny... I have known of a fire mage named JetPhuel...\n";
                            points -= 100;
                            sus_points += 69;
                            cout << "Sadly that is incorrect!\n";
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q1 = false;
                            break;

                        case 4:
                            cout << "I dont blame you, I dont know how to read myself, thats why I just get paid to talk to you!\n";
                            sus_points -= 42;
                            points -= 100;
                            cout << "Sadly that is incorrect!\n";
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q1 = false;
                            break;

                        default:
                            cout << "Please Give an answer using 1,2,3 or 4 please...\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }
                } // end of unhinged question 1

                while (answering_q2 == true)
                {
                    cout << "\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << "                       QUESTION 2\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << UNHINGED_QUESTION_2;
                    cout << "1. Yea, Who's on first.\n";
                    cout << "2. No, What is on Second.\n";
                    cout << "3. I don't know is on Third.\n";
                    cout << "4. Nobody is on right field.\n";
                    cout << string(width_of_panel, '=') << endl;
                
                    cout << contestants_name << "'s answer: ";
                    cin >> answer_2_unhinged_question_2;
                    cout << string(width_of_panel, '=') << endl;
                
                    switch (answer_2_unhinged_question_2)
                    {
                        case 1:
                            cout << "THATS RIGHT! WHO'S ON FIRST!\n";
                            cout << "I'm glad somebody around here understands how baseball works...\n";
                            cout << "Or at least understands a comedy routine from 80 years ago.\n";
                            points += 100;
                            sus_points += 25;
                            cout << "You've earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            answering_q2 = false;
                            break;
                
                        case 2:
                            cout << "Yes, WHAT is on second...\n";
                            cout << "BUT I ASKED YOU WHO'S ON FIRST!\n";
                            cout << "You somehow knew the joke and STILL answered the wrong question.\n";
                            points -= 100;
                            sus_points += 50;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            answering_q2 = false;
                            break;
                
                        case 3:
                            cout << "Correct... I Don't Know IS on third.\n";
                            cout << "Unfortunately, I wasn't asking who's on third.\n";
                            cout << "WHO'S ON FIRST!\n";
                            points -= 100;
                            sus_points += 69;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            answering_q2 = false;
                            break;
                
                        case 4:
                            cout << "Nobody is on right field?!\n";
                            cout << "We have completely abandoned the original conversation at this point.\n";
                            cout << "I asked WHO'S ON FIRST, not whether our team has enough players.\n";
                            points -= 100;
                            sus_points += 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            answering_q2 = false;
                            break;
                
                        default:
                            cout << "Please Give an answer using 1,2,3 or 4 please...\n";
                            cout << "I know the question is confusing, but the NUMBERS shouldn't be.\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }
                } // end of unhinged question 2 put question 3 here

                // Unhinged question 3
                while (answering_q3 == true)
                {
                    cout << "\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << "                       QUESTION 3\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << UNHINGED_QUESTION_3;
                
                    cout << "1. **REDACTED**\n";
                    cout << "2. ███████████████\n";
                    cout << "3. I legally cannot tell you.\n";
                    cout << "4. Nice try, OSI.\n";
                
                    cout << string(width_of_panel, '=') << endl;
                
                    cout << contestants_name << "'s answer: ";
                    cin >> answer_2_unhinged_question_3;
                
                    cout << string(width_of_panel, '=') << endl;
                
                    switch (answer_2_unhinged_question_3)
                    {
                        case 1:
                            cout << "Did you seriously just select REDACTED?\n";
                            cout << "You know what...\n";
                            cout << "I'm not even going to ask where you got that information.\n";
                            cout << "Actually, I dont WANT to know.\n";
                
                            points -= 100;
                            sus_points += 250;
                
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q3 = false;
                            break;
                
                        case 2:
                            cout << "████████████████████████\n";
                            cout << "██████ ACCESS DENIED ██████\n";
                            cout << "████████████████████████\n";
                
                            cout << "Wait...\n";
                            cout << "Why did the trivia game just classify its own answer?\n";
                            cout << "I'm the host and EVEN I cant read that.\n";
                
                            points += 100;
                            sus_points += 420;
                
                            cout << "I'm giving you 100 points because honestly I'm scared.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q3 = false;
                            break;
                
                        case 3:
                            cout << "I legally cannot tell you.\n";
                            cout << "Interesting...\n";
                            cout << "That is EXACTLY what someone who knows the answer would say.\n";
                            cout << "I'm watching you, " << contestants_name << "...\n";
                
                            points += 100;
                            sus_points += 500;
                
                            cout << "You have somehow earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q3 = false;
                            break;
                
                        case 4:
                            cout << "Nice try, OSI.\n";
                            cout << "WAIT.\n";
                            cout << "Why are YOU saying nice try OSI?\n";
                            cout << "THATS MY LINE.\n";
                            cout << "This interview is over.\n";
                
                            points += 100;
                            sus_points += 1000;
                
                            cout << "Take your 100 points and please leave my security clearance alone.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q3 = false;
                            break;
                
                        default:
                            cout << "Please Give an answer using 1,2,3 or 4 please...\n";
                            cout << "Any other number has been REDACTED.\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }
                }//end of q3

                //start of Q4 unhinged, like myself.
                while (answering_q4 == true)
                {
                    cout << "\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << "                       QUESTION 4\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << UNHINGED_QUESTION_4;
                
                    cout << "1. Bro, Thanks I really needed that!\n";
                    cout << "2. What do you mean? I'll pay you back this time...\n";
                    cout << "3. What do I need it for? uh...\n";
                    cout << "4. Chicken nuggies. :D\n";
                
                    cout << string(width_of_panel, '=') << endl;
                
                    cout << contestants_name << "'s answer: ";
                    cin >> answer_2_unhinged_question_4;
                
                    cout << string(width_of_panel, '=') << endl;
                
                    switch (answer_2_unhinged_question_4)
                    {
                        case 1:
                            cout << "WAIT... YOU'RE ACTUALLY GIVING ME THE $20?!\n";
                            cout << "I didnt think I would get this far...\n";
                            cout << "Honestly I was just testing you.\n";
                            cout << "But since you already agreed, I'm not giving it back.\n";
                
                            points += 100;
                            sus_points += 200;
                
                            cout << "You have earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q4 = false;
                            break;
                
                        case 2:
                            cout << "\"I'll pay you back THIS time\"?!\n";
                            cout << "THIS TIME?!\n";
                            cout << "How many times have we apparently done this before?!\n";
                            cout << "I dont remember you lending me money... like ever... and now I'm concerned.\n";
        
                            points -= 100;
                            sus_points += 420;
                
                            cout << "You will be deducted 100 points for financial suspiciousness.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q4 = false;
                            break;
                
                        case 3:
                            cout << "What do I need it for?\n";
                            cout << "Uh...\n";
                            cout << "You know...\n";
                            cout << "Things.\n";
                            cout << "Completely normal things that definitely cost exactly $20.\n";
                            cout << "Please stop asking follow-up questions.\n";
                
                            points += 50;
                            sus_points += 500;
                
                            cout << "I'll give you 50 points for not immediately calling the authorities.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q4 = false;
                            break;
                
                        case 4:
                            cout << "CHICKEN NUGGIES?!\n";
                            cout << "FINALLY. Someone who understands responsible financial planning.\n";
                            cout << "$20 worth of chicken nuggets is not a purchase...\n";
                            cout << "It's an INVESTMENT.\n";
                            cout << "You have my respect, " << contestants_name << ".\n";
                
                            points += 200;
                            sus_points -= 100;
                
                            cout << "You have earned 200 points for making the objectively correct financial decision.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q4 = false;
                            break;
                
                        default:
                            cout << "Please Give an answer using 1,2,3 or 4 please...\n";
                            cout << "I asked for $20, not your PIN number.\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }
                } // end of unhinged question 4 put question 5 here

                // Unhinged question 5
                while (answering_q5 == true)
                {
                    cout << "\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << "                       QUESTION 5\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << UNHINGED_QUESTION_5;
                
                    cout << "1. 2 raccoons\n";
                    cout << "2. 7 raccoons\n";
                    cout << "3. Were they trained by Batman?\n";
                    cout << "4. Then it depends on whether the raccoons have prep time\n";
                
                    cout << string(width_of_panel, '=') << endl;
                
                    cout << contestants_name << "'s answer: ";
                    cin >> answer_2_unhinged_question_5;
                
                    cout << string(width_of_panel, '=') << endl;
                
                    switch (answer_2_unhinged_question_5)
                    {
                        case 1:
                            cout << "TWO RACCOONS?!\n";
                            cout << "You have WAY too much confidence in the average raccoon.\n";
                            cout << "One of them is getting distracted by a trash can immediately.\n";
                            cout << "The other one is probably just watching.\n";
                            cout << "That grown man is walking away mildly inconvenienced.\n";
                
                            points -= 100;
                            sus_points += 50;
                
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q5 = false;
                            break;
                
                        case 2:
                            cout << "Seven raccoons...\n";
                            cout << "Now THAT sounds like a reasonable amount of chaos.\n";
                            cout << "At that point the grown man isnt fighting raccoons anymore...\n";
                            cout << "He's participating in a boss encounter.\n";
                            cout << "I'm giving you this one.\n";
                
                            points += 100;
                            sus_points += 100;
                
                            cout << "You have earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q5 = false;
                            break;
                
                        case 3:
                            cout << "Were they trained by BATMAN?!\n";
                            cout << "WHY WOULD BATMAN BE TRAINING RACCOONS?!\n";
                            cout << "Actually...\n";
                            cout << "No. Don't answer that.\n";
                            cout << "Because if Batman trained them, this stopped being a fair fight a LONG time ago.\n";
                
                            points += 150;
                            sus_points += 500;
                
                            cout << "You have earned 150 points for asking the important questions.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q5 = false;
                            break;
                
                        case 4:
                            cout << "PREP TIME?!\n";
                            cout << "Oh no...\n";
                            cout << "You brought Batman logic into a raccoon fight.\n";
                            cout << "If the raccoons have prep time, the grown man never stood a chance.\n";
                            cout << "They've already learned his schedule, stolen his wallet,\n";
                            cout << "and somehow theyve acquired a small utility belt.\n";
                
                            points += 200;
                            sus_points += 1000;
                
                            cout << "You have earned 200 points for understanding the true power of prep time.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q5 = false;
                            break;
                
                        default:
                            cout << "Please Give an answer using 1,2,3 or 4 please...\n";
                            cout << "The raccoons are getting impatient.\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }
                } // end of unhinged question 5 put question 6 here

                while (answering_q6 == true)
                {
                    cout << "\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << "                       QUESTION 6\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << UNHINGED_QUESTION_6;
                
                    cout << "1. Is it a polar bear or a brown bear?\n";
                    cout << "2. How big was the sword?\n";
                    cout << "3. Its me I can totally corrupt all the memory on your computer.\n";
                    cout << "4. Listen, I wouldnt do that. It was just a statement... but I could, who needs memory anyway?\n";
                
                    cout << string(width_of_panel, '=') << endl;
                
                    cout << contestants_name << "'s answer: ";
                    cin >> answer_2_unhinged_question_6;
                
                    cout << string(width_of_panel, '=') << endl;
                
                    switch (answer_2_unhinged_question_6)
                    {
                        case 1:
                            cout << "OH, so NOW we need details about the bear?\n";
                            cout << "Honestly... thats a fair question.\n";
                            cout << "A black bear with a butter knife and a polar bear with a greatsword\n";
                            cout << "are two VERY different situations.\n";
                            cout << "I respect the risk assessment.\n";
                
                            points += 100;
                            sus_points += 100;
                
                            cout << "You have earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q6 = false;
                            break;
                
                        case 2:
                            cout << "HOW BIG WAS THE SWORD?!\n";
                            cout << "You looked at a BEAR holding a weapon and your concern was weapon size?!\n";
                            cout << "Listen, if the bear figured out how to use ANY sword,\n";
                            cout << "I think we already have a much bigger problem.\n";
                
                            points += 50;
                            sus_points += 300;
                
                            cout << "You have earned 50 points for asking a technically important question.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q6 = false;
                            break;
                
                        case 3:
                            cout << "Wait... YOU think you're the dangerous one?\n";
                            cout << "No no no, " << contestants_name << "...\n";
                            cout << "You're just answering the questions.\n";
                            cout << "I'M the one who wrote this program.\n";
                            cout << "If anybody here is going to destroy something on your computer...\n";
                            cout << "Well... lets just say you should be nice to the creator.\n";
                        
                            points -= 50;
                            sus_points += 500;
                        
                            cout << "You lose 50 points for forgetting who actually has control here.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                        
                            answering_q6 = false;
                            break;
                        
                        case 4:
                            cout << "Listen, I wouldnt actually do that...\n";
                            cout << "It was just a statement.\n";
                            cout << "A completely harmless statement from the guy who wrote the program you're running.\n";
                            cout << "But COULD I corrupt your memory?\n";
                            cout << "...\n";
                            cout << "Probably best we dont test that.\n";
                            cout << "Who needs memory anyway?\n";
                            cout << "I'm kidding.\n";
                            cout << "Mostly.\n";
                        
                            points += 200;
                            sus_points += 1000;
                        
                            cout << "You have earned 200 points for wisely not questioning the creator.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                        
                            answering_q6 = false;
                            break;
                
                        default:
                            cout << "Please Give an answer using 1,2,3 or 4 please...\n";
                            cout << "The bear is getting closer while you decide.\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }
                } // end of unhinged question 6 put question 7 here

                // Unhinged question 7
                while (answering_q7 == true)
                {
                    cout << "\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << "                       QUESTION 7\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << UNHINGED_QUESTION_7;
                
                    cout << "1. Please dont make me think about this... Just let me enjoy my food\n";
                    cout << "2. Ketchup is a Soda...\n";
                    cout << "3. I cry myself to sleep\n";
                    cout << "4. Im sorry... I cant think of anything to put here, this is the correct answer please pick it...\n";
                
                    cout << string(width_of_panel, '=') << endl;
                
                    cout << contestants_name << "'s answer: ";
                    cin >> answer_2_unhinged_question_7;
                
                    cout << string(width_of_panel, '=') << endl;
                
                    switch (answer_2_unhinged_question_7)
                    {
                        case 1:
                            cout << "Honestly...\n";
                            cout << "Thats probably the healthiest response you've given all night.\n";
                            cout << "You came here to eat food, not debate its taxonomic classification.\n";
                            cout << "Unfortunately, I already ruined that for you.\n";
                            cout << "You will now think about this every time you eat cereal.\n";
                
                            points += 100;
                            sus_points += 50;
                
                            cout << "You have earned 100 points for attempting to preserve your sanity.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q7 = false;
                            break;
                
                        case 2:
                            cout << "KETCHUP IS A SODA?!\n";
                            cout << "NO.\n";
                            cout << "Absolutely not.\n";
                            cout << "You cannot just say something like that and expect me to move on.\n";
                            cout << "Does that make mustard an energy drink?!\n";
                            cout << "What have you done, " << contestants_name << "...\n";
                
                            points -= 100;
                            sus_points += 1000;
                
                            cout << "You will be deducted 100 points for creating a worse question than mine.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q7 = false;
                            break;
                
                        case 3:
                            cout << "I...\n";
                            cout << "That wasnt really one of the philosophical positions I was expecting.\n";
                            cout << "But honestly, after thinking about whether cereal is soup...\n";
                            cout << "I kind of understand.\n";
                            cout << "Lets just pretend this question never happened.\n";
                
                            points += 50;
                            sus_points += 300;
                
                            cout << "You have earned 50 points for making the host uncomfortable.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q7 = false;
                            break;
                
                        case 4:
                            cout << "THANK YOU.\n";
                            cout << "FINALLY.\n";
                            cout << "I ran out of ideas writing this question.\n";
                            cout << "I literally TOLD you which answer was correct.\n";
                            cout << "If you somehow missed this one, I was going to shut the program down.\n";
                            cout << "Please take your points and lets never discuss cereal soup again.\n";
                
                            points += 200;
                            sus_points -= 100;
                
                            cout << "You have earned 200 points for following extremely obvious instructions.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q7 = false;
                            break;
                
                        default:
                            cout << "Please Give an answer using 1,2,3 or 4 please...\n";
                            cout << "I literally told you which answer was correct and you STILL found a fifth option.\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }
                } // end of unhinged question 7 put question 8 here

                // Unhinged question 8
                while (answering_q8 == true)
                {
                    cout << "\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << "                       QUESTION 8\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << UNHINGED_QUESTION_8;
                
                    cout << "1. 1\n";
                    cout << "2. 2\n";
                    cout << "3. 3\n";
                    cout << "4. Wait they fired you to hire someone overseas for one-tenth the price...\n";
                
                    cout << string(width_of_panel, '=') << endl;
                
                    cout << contestants_name << "'s answer: ";
                    cin >> answer_2_unhinged_question_8;
                
                    cout << string(width_of_panel, '=') << endl;
                
                    switch (answer_2_unhinged_question_8)
                    {
                        case 1:
                            cout << "ONE TIME?!\n";
                            cout << "Thats not enough commitment to the bit.\n";
                            cout << "You dont become 'The Intern' after saying it once.\n";
                            cout << "Thats just a disclaimer.\n";
                            cout << "You need repetition. You need confidence. You need DENIAL.\n";
                
                            points -= 100;
                            sus_points += 100;
                
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q8 = false;
                            break;
                
                        case 2:
                            cout << "Twice?\n";
                            cout << "Okay... now HR is starting to notice.\n";
                            cout << "Once is a joke.\n";
                            cout << "Twice is suspicious.\n";
                            cout << "A third time and they're updating your badge.\n";
                
                            points += 50;
                            sus_points += 250;
                
                            cout << "You have earned 50 points for being dangerously close.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q8 = false;
                            break;
                
                        case 3:
                            cout << "THREE TIMES.\n";
                            cout << "Yep. Thats it.\n";
                            cout << "The paperwork has already been submitted.\n";
                            cout << "Your email signature now says 'Intern'.\n";
                            cout << "Your parking spot has been revoked.\n";
                            cout << "And somehow you are still responsible for production outages.\n";
                
                            points += 100;
                            sus_points += 420;
                
                            cout << "You have earned 100 points and an unpaid internship!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q8 = false;
                            break;
                
                        case 4:
                            cout << "Wait...\n";
                            cout << "They FIRED me?!\n";
                            cout << "I thought we were joking about being the intern!\n";
                            cout << "I didnt even get a meeting?!\n";
                            cout << "They just disabled my account and changed the password?!\n";
                            cout << "You know what...\n";
                            cout << "I'm keeping the company mousepad.\n";
                            cout << "THATS MINE NOW.\n";
                
                            points += 200;
                            sus_points += 1000;
                
                            cout << "You have earned 200 points for completely derailing the question.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q8 = false;
                            break;
                
                        default:
                            cout << "Please Give an answer using 1,2,3 or 4 please...\n";
                            cout << "HR only gave me four options in the dropdown.\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }
                } // end of unhinged question 8 put question 9 here

                // Unhinged question 9
                while (answering_q9 == true)
                {
                    cout << "\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << "                       QUESTION 9\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << UNHINGED_QUESTION_9;
                
                    cout << "1. [CORRUPTED] 53 79 73 74 65 6D 33 32 20 68 61 73 20 6C 65 66 74 20 74 68 65 20 63 68 61 74\n";
                    cout << "2. ERROR_0x31: Windows has evolved backwards.\n";
                    cout << "3. U3lzdGVtMzEgaXMgYSBmZWF0dXJlLCBub3QgYSBidWcu\n";
                    cout << "4. ████ DATA LOST ████ Please insert Windows 95 Disc 7 of 38.\n";
                
                    cout << string(width_of_panel, '=') << endl;
                
                    cout << contestants_name << "'s answer: ";
                    cin >> answer_2_unhinged_question_9;
                
                    cout << string(width_of_panel, '=') << endl;
                
                    switch (answer_2_unhinged_question_9)
                    {
                        case 1:
                            cout << "\nDecrypting data...\n";
                            cout << "Decrypted Message: System32 has left the chat.\n";
                            cout << "Honestly, thats probably the most peaceful way System32 could disappear.\n";
                            cout << "No warning. No goodbye. Just gone.\n";
                            cout << "Windows is now emotionally unavailable.\n";
                
                            points += 100;
                            sus_points += 500;
                
                            cout << "You have earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q9 = false;
                            break;
                
                        case 2:
                            cout << "\nDecrypting error code...\n";
                            cout << "Decrypted Message: Windows has evolved backwards.\n";
                            cout << "Congratulations.\n";
                            cout << "You have successfully unlocked Windows 94.\n";
                            cout << "Please enjoy 640x480 resolution and seventeen consecutive driver errors.\n";
                
                            points += 50;
                            sus_points += 420;
                
                            cout << "You have earned 50 points for technically discovering time travel.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q9 = false;
                            break;
                
                        case 3:
                            cout << "\nDecoding Base64...\n";
                            cout << "Decrypted Message: System31 is a feature, not a bug.\n";
                            cout << "Oh good.\n";
                            cout << "We're using THAT excuse now.\n";
                            cout << "Nothing is broken if you just call every problem a feature.\n";
                            cout << "Microsoft would be proud.\n";
                
                            points += 150;
                            sus_points += 750;
                
                            cout << "You have earned 150 points for embracing corporate troubleshooting logic.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q9 = false;
                            break;
                
                        case 4:
                            cout << "\nAttempting data recovery...\n";
                            cout << "Decrypted Message: DATA LOST - Please insert Windows 95 Disc 7 of 38.\n";
                            cout << "DISC 7 OF 38?!\n";
                            cout << "We are going to be here ALL NIGHT.\n";
                            cout << "And you KNOW disc 37 is going to be corrupted.\n";
                            cout << "At this point just throw the computer away and start over.\n";
                
                            points += 200;
                            sus_points += 1000;
                
                            cout << "You have earned 200 points for surviving legacy Windows installation media.\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q9 = false;
                            break;
                
                        default:
                            cout << "Please Give an answer using 1,2,3 or 4 please...\n";
                            cout << "ERROR: User input not found in System32.\n";
                            cout << "Please reboot contestant and try again.\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }
                } // end of unhinged question 9 put question 10 here


                // Unhinged question 10... this is the chronos question do later

                // unhinged question 11 A NEW HAND TOUCHES THE BEACON
                while (answering_q11 == true)
                {
                    cout << "\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << "                  A NEW HAND TOUCHES\n";
                    cout << "                       THE BEACON\n";
                    cout << string(width_of_panel, '=') << endl;
                    cout << UNHINGED_QUESTION_11;
                
                    cout << "1. Pick up the beacon.\n";
                    cout << "2. Fine... I'll do the quest.\n";
                    cout << "3. Throw the beacon away.\n";
                    cout << "4. Take it to Mount Kilkreath and question every decision that led me here.\n";
                
                    cout << string(width_of_panel, '=') << endl;
                
                    cout << contestants_name << "'s answer: ";
                    cin >> answer_2_unhinged_question_11;
                
                    cout << string(width_of_panel, '=') << endl;
                
                    switch (answer_2_unhinged_question_11)
                    {
                        case 1:
                            cout << "You picked up the beacon...\n";
                            cout << "Oh no.\n";
                            cout << "You fool.\n";
                            cout << "You absolute fool.\n";
                            cout << "You hear a voice screaming directly into your skull:\n\n";
                            cout << "\"A NEW HAND TOUCHES THE BEACON.\"\n\n";
                            cout << "Congratulations, " << contestants_name << ".\n";
                            cout << "You have acquired a quest whether you wanted one or not.\n";
                
                            points += 100;
                            sus_points += 500;
                
                            cout << "You have earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q11 = false;
                            break;
                
                        case 2:
                            cout << "Fine... you'll do the quest?\n";
                            cout << "Thats the spirit.\n";
                            cout << "Not because you WANT to...\n";
                            cout << "but because Meridia has already decided that you are doing it.\n";
                            cout << "Your consent was apparently more of a suggestion.\n";
                            cout << "Time to go clean out another dungeon full of angry undead.\n";
                
                            points += 150;
                            sus_points += 300;
                
                            cout << "You have earned 150 points for accepting your fate!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q11 = false;
                            break;
                
                        case 3:
                            cout << "You throw the beacon away.\n";
                            cout << "It rolls across the ground...\n";
                            cout << "You turn around and begin walking away.\n";
                            cout << "Finally.\n";
                            cout << "Peace and quiet.\n\n";
                
                            cout << "...\n";
                            cout << "...\n";
                            cout << "...\n\n";
                
                            cout << "A NEW HAND TOUCHES THE BEACON.\n";
                            cout << "WAIT WHAT?!\n";
                            cout << "HOW IS IT BACK IN YOUR INVENTORY?!\n";
                            cout << "NO.\n";
                            cout << "YOU ARE NOT ESCAPING THIS QUEST.\n\n";
                
                            points -= 50;
                            sus_points += 1000;
                
                            cout << "You lose 50 points for attempting to escape Meridia.\n";
                            cout << "Try again.\n\n";
                
                            // DO NOT set answering_q11 to false here.
                            // This makes the entire question restart.
                            break;
                
                        case 4:
                            cout << "Mount Kilkreath...\n";
                            cout << "You already know where you're going?!\n";
                            cout << "You've done this before, havent you?\n";
                            cout << "You saw the weird geometric golf ball in the chest\n";
                            cout << "and immediately knew your afternoon was ruined.\n";
                            cout << "Go restore Meridia's temple and collect Dawnbreaker.\n";
                            cout << "At least you get a cool sword out of this mess.\n";
                
                            points += 200;
                            sus_points += 69;
                
                            cout << "You have earned 200 points for knowing exactly how this nonsense ends!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                
                            answering_q11 = false;
                            break;
                
                        default:
                            cout << "Please Give an answer using 1,2,3 or 4 please...\n";
                            cout << "Meridia does not recognize your pathetic fifth option.\n";
                            cout << "A NEW HAND TOUCHES THE BEACON.\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }
                } // end of unhinged question 11
                
                // Unhinged question 12
                cout << "\n";
                cout << string(width_of_panel, '=') << endl;
                cout << "                     FINAL QUESTION\n";
                cout << "                  ANTI-BRAIN-ROT TEST\n";
                cout << string(width_of_panel, '=') << endl;
                cout << ANTI_BRAIN_ROT_TRIVIA_QUESTION_1;

                // Put question 12 answer options here
                // cout << "1. \n";
                // cout << "2. \n";
                // cout << "3. \n";
                // cout << "4. \n";

                cout << contestants_name << "'s answer: ";
                cin >> answer_2_anti_brain_rot;

                switch (answer_2_anti_brain_rot)
                { // switch for unhinged question 12 choices.
                    case 1:
                        // Put response for answer 1 here
                        // Add or subtract points here
                        // Add or subtract sus_points here
                        break;

                    case 2:
                        // Put response for answer 2 here
                        // Add or subtract points here
                        // Add or subtract sus_points here
                        break;

                    case 3:
                        // Put response for answer 3 here
                        // Add or subtract points here
                        // Add or subtract sus_points here
                        break;

                    case 4:
                        // Put response for answer 4 here
                        // Add or subtract points here
                        // Add or subtract sus_points here
                        break;

                    default:
                        cout << "Please Give and answer using 1,2,3 or 4 please...\n";
                        break;
                } // end of unhinged question 12
            }

            break;

            default: // def of inital switch
                cout << "Please choose 1 or 2.\n";
                break;
        } // end of inital switch, for choosing game style

        bool valid_restart_answer = false;

        // This is the loop to see if the user wants to replay the game.
        while (valid_restart_answer == false)
        {
            cout << "\n";
            cout << string(width_of_panel, '=') << endl;
            cout << "TRIVIA COMPLETE!\n";
            cout << contestants_name << "'s FINAL SCORE: " << points << endl;
            cout << string(width_of_panel, '=') << endl;
            cout << "We were also trying to help you decided which faction to join for the release of\n";
            cout << "WoW Forever!\n";
            cout << "Which ever faction you scored higher on is the one we give you!\n";
            if (hidden_alliance > hidden_horde) 
            {
                cout << "We suggest that you join... The Alliance but the only race you can pick is a gnome...\n\n";
            }
            else 
            {
                cout << "Welcome to the horde, we have undead, trolls, ORCS, and Taurens!\n\n";
            }

            
            cout << "Do you want to play the game again? (yes/no): ";
            cin >> playing_trivia_restart;

            // https://www.geeksforgeeks.org/cpp/tolower-function-in-cpp/
            //  the & allows direct access and change to the string.
            for (auto &i : playing_trivia_restart)
            {
                i = (char)tolower(i);
            }

            if (playing_trivia_restart == "yes" || playing_trivia_restart == "y")
            {
                playing_trivia = true;
                valid_restart_answer = true;
                cin.ignore(); // need this because restarting the game... we ask for the name and its a getline()
            }
            else if (playing_trivia_restart == "no" || playing_trivia_restart == "n")
            {
                playing_trivia = false;
                valid_restart_answer = true;
            }
            else
            {
                cout << "Invalid input. Please type yes/no or y/n.\n";
            }
        } // end of game restart loop

    } // end of game loop

} // end of int main.
