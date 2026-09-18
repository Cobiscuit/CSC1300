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
    const string UNHINGED_QUESTION_11 = "Final question: Are you absolutely sure you want me to calculate your score?\n";

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


                while (answering_q4 == true)
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
                            cout << "sorry but thats incorrect...\n";
                            hidden_alliance--;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q4 = false;
                            break;
    
                        case 2:
                            cout << "sorry but thats incorrect...\n";
                            hidden_alliance--;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q4 = false;
                            break;
    
                        case 3:
                            cout << "sorry but thats... Wait no thats correct, nevermind!\n";
                            hidden_alliance++;
                            points += 100;
                            cout << "You've earned 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q4 = false;
                            break;
    
                        case 4:
                            cout << "sorry but thats incorrect...\n";
                            hidden_alliance--;
                            points -= 100;
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q4 = false;
                            break;
    
                        case 5:
                            cout << "Sadly my Fire Mage isnt nearly as strong as a world breaking dragon...\n";
                            cout << "BECAUSE HE IS STRONGER, IVE DEFEAT THAT DRAGON HUNDREDS OF TIMES...\n";
                            cout << "Sadly youre still going to lose points for that one though...";
                            cout << "You will be deducted 100 points!\n\n";
                            cout << contestants_name << "'s total points: " << points << endl;
                            cout << string(width_of_panel, '=') << endl;
                            answering_q4 = false;
                            break;
    
                        default:
                            cout << "Please Give and answer using 1,2,3,4 or 5 please...\n";
                            cout << string(width_of_panel, '=') << endl;
                            break;
                    }//end of while loop for 4
                }// end of question 4 put question 5 here

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
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        cout << string(width_of_panel, '=') << endl;
                        break;

                    case 2:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        cout << string(width_of_panel, '=') << endl;
                        break;

                    case 3:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        cout << string(width_of_panel, '=') << endl;
                        break;

                    case 4:
                        cout << "sorry but thats... Wait no thats correct, nevermind!\n";
                        hidden_alliance++;
                        points += 100;
                        cout << "You've earned 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        cout << string(width_of_panel, '=') << endl;
                        break;

                    case 5:
                        cout << "HEY THE ONLY THING MY WARRIOR BETRAYED WAS NOT MAKING IT TO GLADIATOR...\n";
                        hidden_horde++;
                        hidden_alliance--;
                        points -= 100;
                        cout << "You've earned 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        cout << string(width_of_panel, '=') << endl;
                        break;

                    default:
                        cout << string(width_of_panel, '=') << endl;
                        cout << "Please Give and answer using 1,2,3,4 or 5 please...\n";
                        cout << string(width_of_panel, '=') << endl;
                        break;
                } // end of question 5 put question 6 here

                cout << WARCRAFT_TRIVIA_QUESTION_6;
                cout << "1. Naxxramas.\n";
                cout << "2. Ulduar.\n";
                cout << "3. Icecrown Citadel.\n";
                cout << "4. Trial of the Crusader.\n";
                cout << "5. Stratholme\n\n";
                cin >> answer_2_question_6;
                cout << string(width_of_panel, '=') << endl;

                switch (answer_2_question_6)
                { // switch for question 6 choices.
                    case 1:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        hidden_horde++;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        cout << string(width_of_panel, '=') << endl;
                        break;

                    case 2:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        hidden_horde++;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 3:
                        cout << "sorry but thats... Wait no thats correct, nevermind!\n";
                        hidden_alliance++;
                        hidden_horde--;
                        points += 100;
                        cout << "You've earned 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 4:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        hidden_horde++;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 5:
                        cout << "Thats not the raid hes in, just the city he burned to the ground...\n";
                        hidden_alliance--;
                        hidden_horde++;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    default:
                        cout << "Please Give and answer using 1,2,3,4 or 5 please...\n";
                        break;
                } // end of question 6 put question 7 here

                cout << WARCRAFT_TRIVIA_QUESTION_7;
                cout << "1. Red Dragonflight.\n";
                cout << "2. Blue Dragonflight.\n";
                cout << "3. Bronze Dragonflight.\n";
                cout << "4. Black Dragonflight.\n";
                cout << "5. Green Dragonflight\n\n";
                cin >> answer_2_question_7;

                switch (answer_2_question_7)
                { // switch for question 7 choices.
                    case 1:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        hidden_horde++;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 2:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        hidden_horde++;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 3:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        hidden_horde++;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 4:
                        cout << "sorry but thats... Wait no thats correct, nevermind!\n";
                        hidden_alliance++;
                        hidden_horde--;
                        points += 100;
                        cout << "You've earned 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 5:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        hidden_horde++;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    default:
                        cout << "Please Give and answer using 1,2,3,4 or 5 please...\n";
                        break;
                } // end of question 7 put question 8 here

                cout << WARCRAFT_TRIVIA_QUESTION_8;
                cout << "1. Kil'jaeden.\n";
                cout << "2. Archimonde.\n";
                cout << "3. Gul'dan.\n";
                cout << "4. Sargeras.\n";
                cout << "5. Arthas Menethil\n\n";
                cin >> answer_2_question_8;

                switch (answer_2_question_8)
                { // switch for question 8 choices.
                    case 1:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        hidden_horde++;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 2:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        hidden_horde++;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 3:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        hidden_horde++;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 4:
                        cout << "sorry but thats... Wait no thats correct, nevermind!\n";
                        hidden_alliance++;
                        hidden_horde--;
                        points += 100;
                        cout << "You've earned 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 5:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        hidden_horde++;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    default:
                        cout << "Please Give and answer using 1,2,3,4 or 5 please...\n";
                        break;
                } // end of question 8 put question 9 here

                cout << WARCRAFT_TRIVIA_QUESTION_9;
                cout << "1. Ironforge.\n";
                cout << "2. Stormwind City.\n";
                cout << "3. Lordaeron.\n";
                cout << "4. Gilneas.\n";
                cout << "5. Orgrimmar\n\n";
                cin >> answer_2_question_9;

                switch (answer_2_question_9)
                { // switch for question 9 choices.
                    case 1:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 2:
                        cout << "sorry but thats... Wait no thats correct, nevermind!\n";
                        hidden_alliance++;
                        points += 100;
                        cout << "You've earned 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 3:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 4:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 5:
                        cout << "We went over this earlier...\n";
                        cout << "This is the Horde capital! but I know why you picked this one.\n";
                        hidden_alliance--;
                        hidden_horde++;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    default:
                        cout << "Please Give and answer using 1,2,3,4 or 5 please...\n";
                        break;
                } // end of question 9 put question 10 here

                cout << WARCRAFT_TRIVIA_QUESTION_10;
                cout << "1. Stormwind.\n";
                cout << "2. Gilneas.\n";
                cout << "3. Alterac.\n";
                cout << "4. Lordaeron.\n";
                cout << "5. Icecrown Citadel\n\n";
                cin >> answer_2_question_10;

                switch (answer_2_question_10)
                { // switch for question 10 choices.
                    case 1:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 2:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 3:
                        cout << "sorry but thats incorrect...\n";
                        hidden_alliance--;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 4:
                        cout << "sorry but thats... Wait no thats correct, nevermind!\n";
                        hidden_alliance++;
                        points += 100;
                        cout << "You've earned 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 5:
                        cout << "I... Thats not a city, but the raid he was defeated in while he was the Lich King.\n";
                        hidden_alliance--;
                        hidden_horde++;
                        points -= 100;
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    default:
                        cout << "Please Give and answer using 1,2,3,4 or 5 please...\n";
                        break;
                } // end of question 10

                break;
            } // closes case 1 block

            case 2: // this is unhinged trivia
            {       // start of cast 2
                cout << "I can believe you actually selected 2...\n";
                cout << "I Suppose we need to start with our first question then... no?\n\n";
                cout << UNHINGED_QUESTION_1;
                cout << "1. " << contestants_name << endl;
                cout << "2. Sargeras\n";
                cout << "3. George Bush\n";
                cout << "4. I didnt acutally read any of the outputs on the screen...\n";
                cin >> answer_2_unhinged_question_1;

                switch (answer_2_unhinged_question_1)
                {
                    case 1:
                        cout << "Wait was that really my name? I dont think I said that was my name?\n";
                        cout << "Did I say I was " << contestants_name << "?\n";
                        sus_points += 100;
                        points -= 100;
                        cout << "Sadly that is incorrect!\n";
                        cout << " You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 2:
                        cout << "That is correct! congradulations Youve earned 100 points!\n";
                        sus_points += 420;
                        points += 100;
                        cout << "You will be given 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        answering_q1 = false;
                        break;

                    case 3:
                        cout << "Thats odds that you thought it was him in the month of september.\n";
                        cout << "Did you know JetPhuel melts steel beam?\n\n";
                        cout << "Whats funny... I have a fire mage named JetPhuel...";
                        points -= 100;
                        sus_points += 69;
                        cout << "Sadly that is incorrect!\n";
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    case 4:
                        cout << "I dont blame you, I dont know how to read myself, thats why I just get paid to talk to you!\n";
                        sus_points -= 42;
                        points -= 100;
                        cout << "Sadly that is incorrect!\n";
                        cout << "You will be deducted 100 points!\n\n";
                        cout << contestants_name << "'s total points: " << points << endl;
                        break;

                    default:
                        cout << "Please Give and answer using 1,2,3 or 4 please...\n";
                        break;
                } // end of case 1/question 1

                // Unhinged question 2
                cout << UNHINGED_QUESTION_2;

                // Put question 2 answer options here
                cout << "1. Yea, Whos on first. \n";
                cout << "2. No, What is on Second.\n";
                cout << "3. I dont know is on Third \n";
                cout << "4. Nobody is on right field\n";

                cout << contestants_name << "'s answer: ";
                cin >> answer_2_unhinged_question_2;

                switch (answer_2_unhinged_question_2)
                { // switch for unhinged question 2 choices.
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
                } // end of unhinged question 2 put question 3 here

                // Unhinged question 3
                cout << UNHINGED_QUESTION_3;

                // Put question 3 answer options here
                cout << "1. **REDACTED**\n";
                cout << "2. ███████████████\n";
                cout << "3. I legally cannot tell you.\n";
                cout << "4. Nice try, OSI.\n";

                cout << contestants_name << "'s answer: ";
                cin >> answer_2_unhinged_question_3;

                switch (answer_2_unhinged_question_3)
                { // switch for unhinged question 3 choices.
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
                } // end of unhinged question 3 put question 4 here

                // Unhinged question 4
                cout << UNHINGED_QUESTION_4;

                // Put question 4 answer options here
                cout << "1. Bro, Thanks I really needed that! \n";
                cout << "2. What do you mean? I'll pay you back this time...\n";
                cout << "3. What do I need it for? uh...\n";
                cout << "4. Chicken nuggies. :D\n";

                cout << contestants_name << "'s answer: ";
                cin >> answer_2_unhinged_question_4;

                switch (answer_2_unhinged_question_4)
                { // switch for unhinged question 4 choices.
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
                } // end of unhinged question 4 put question 5 here

                // Unhinged question 5
                cout << UNHINGED_QUESTION_5;

                // Put question 5 answer options here
                cout << "1. 2 raccoons\n";
                cout << "2. 7 raccoons\n";
                cout << "3. Were the they trained by Batman?\n";
                cout << "4. Then it depends on whether the raccoons have prep time\n";

                cout << contestants_name << "'s answer: ";
                cin >> answer_2_unhinged_question_5;

                switch (answer_2_unhinged_question_5)
                { // switch for unhinged question 5 choices.
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
                } // end of unhinged question 5 put question 6 here

                // Unhinged question 6
                cout << UNHINGED_QUESTION_6;

                // Put question 6 answer options here
                cout << "1. Is it a polar bear or a brown bear? \n";
                cout << "2. How big was the sword?\n";
                cout << "3. Its me I can totally corrupt all the memory on your computer.\n";
                cout << "4. chicken nuggies. :D\n";

                cout << contestants_name << "'s answer: ";
                cin >> answer_2_unhinged_question_6;

                switch (answer_2_unhinged_question_6)
                { // switch for unhinged question 6 choices.
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
                } // end of unhinged question 6 put question 7 here

                // Unhinged question 7
                cout << UNHINGED_QUESTION_7;

                // Put question 7 answer options here
                cout << "1. Please dont make me think about this... Just let me enjoy my food \n";
                cout << "2. Ketchup is a Soda... \n";
                cout << "3. I cry myself to sleep\n";
                cout << "4. Im sorry... I cant think of anything to put here, this is the correct answer please pick it...\n";

                cout << contestants_name << "'s answer: ";
                cin >> answer_2_unhinged_question_7;

                switch (answer_2_unhinged_question_7)
                { // switch for unhinged question 7 choices.
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
                } // end of unhinged question 7 put question 8 here

                // Unhinged question 8
                cout << UNHINGED_QUESTION_8;

                // Put question 8 answer options here
                cout << "1. 1\n";
                cout << "2. 2\n";
                cout << "3. 3\n";
                cout << "4. wait they fired you to hire someone overseas for one-tenth the price...\n";

                cout << contestants_name << "'s answer: ";
                cin >> answer_2_unhinged_question_8;

                switch (answer_2_unhinged_question_8)
                { // switch for unhinged question 8 choices.
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
                } // end of unhinged question 8 put question 9 here

                // Unhinged question 9
                cout << UNHINGED_QUESTION_9;

                // Put question 9 answer options here
                cout << "1. [CORRUPTED] 53 79 73 74 65 6D 33 32 20 68 61 73 20 6C 65 66 74 20 74 68 65 20 63 68 61 74\n";
                cout << "2. ERROR_0x31: Windows has evolved backwards.\n";
                cout << "3. U3lzdGVtMzEgaXMgYSBmZWF0dXJlLCBub3QgYSBidWcu\n";
                cout << "4. ████ DATA LOST ████ Please insert Windows 95 Disc 7 of 38.\n";

                cout << contestants_name << "'s answer: ";
                cin >> answer_2_unhinged_question_9;

                switch (answer_2_unhinged_question_9)
                {
                    case 1:
                        cout << "\nDecrypting data...\n";
                        cout << "Decrypted Message: System32 has left the chat.\n";
                        // add points / sus_points here
                        break;

                    case 2:
                        cout << "\nDecrypting error code...\n";
                        cout << "Decrypted Message: Windows has evolved backwards.\n";
                        // add points / sus_points here
                        break;

                    case 3:
                        cout << "\nDecoding Base64...\n";
                        cout << "Decrypted Message: System31 is a feature, not a bug.\n";
                        // add points / sus_points here
                        break;

                    case 4:
                        cout << "\nAttempting data recovery...\n";
                        cout << "Decrypted Message: DATA LOST - Please insert Windows 95 Disc 7 of 38.\n";
                        // add points / sus_points here
                        break;

                    default:
                        cout << "Please Give an answer using 1,2,3 or 4 please...\n";
                        break;
                } // end of unhinged question 9 put question 10 here

                // Unhinged question 10
                cout << UNHINGED_QUESTION_10;

                // Put question 10 answer options here
                cout << "1. you legit only have 10 seconds... \n";
                cout << "2. I wrote a code block and Im testing it here...\n";
                cout << "3. I really hope this works\n";
                cout << "4. Are you keeping track of the time?\n";

                cout << contestants_name << "'s answer: ";
                cin >> answer_2_unhinged_question_10;

                switch (answer_2_unhinged_question_10)
                { // switch for unhinged question 10 choices.
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
                } // end of unhinged question 10 put question 11 here

                // Unhinged question 11
                cout << ANTI_BRAIN_ROT_TRIVIA_QUESTION_1;

                // Put question 11 answer options here
                // cout << "1. \n";
                // cout << "2. \n";
                // cout << "3. \n";
                // cout << "4. \n";

                cout << contestants_name << "'s answer: ";
                cin >> answer_2_anti_brain_rot;

                switch (answer_2_anti_brain_rot)
                { // switch for unhinged question 11 choices.
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
                } // end of unhinged question 11
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
