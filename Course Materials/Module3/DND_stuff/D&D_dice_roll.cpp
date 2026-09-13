/*
Name: Cobain Irwin
Date: 20260904
Module 3 Practice

We are asked to write a program to allow a user to roll dice for stats on a DnD sheet!
I'll update this as we go along, but I want to build the sheet and then also allow
the user to roll dice if wanted.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main()
{
    // Seed rand() so we get different random numbers each run.
    srand(time(0));

    // Character information
    string char_name("");
    string user_choice_yes_no("");
    string main_stat_name("");
    string display_dice_choice("");
    string next_roll_choice("");
    string stat_description_choice("");

    int main_stat_choice(0);
    int stat_choice(0);

    int strength(0);
    int dexterity(0);
    int constitution(0);
    int intelligence(0);
    int wisdom(0);
    int charisma(0);

    // These hold the six stat totals before they are assigned.
    int stat_roll_1(0);
    int stat_roll_2(0);
    int stat_roll_3(0);
    int stat_roll_4(0);
    int stat_roll_5(0);
    int stat_roll_6(0);

    // Dice variables
    int d6_1(0);
    int d6_2(0);
    int d6_3(0);
    int current_die(0);

    // Loop control
    bool choosing_name(true);
    bool main_stat_loop(true);
    bool choosing_dice_display(true);
    bool choosing_description_option(true);

    // Track whether a rolled stat has already been assigned.
    bool roll_1_used(false);
    bool roll_2_used(false);
    bool roll_3_used(false);
    bool roll_4_used(false);
    bool roll_5_used(false);
    bool roll_6_used(false);

    // -------------------------------------------------------------------------
    // CHARACTER NAME
    // -------------------------------------------------------------------------

    cout << "Welcome to the Character Creation Screen!\n";
    cout << "Please give me the name of your character! : ";
    getline(cin, char_name);

    // Confirm the name in case the user misspelled it.
    while (choosing_name == true)
    {
        cout << "Are you sure you want to be named: " << char_name
             << "?\nRespond: Yes/No (Y/N) Either works. : ";

        cin >> user_choice_yes_no;

        if (user_choice_yes_no == "Y" or
            user_choice_yes_no == "y" or
            user_choice_yes_no == "Yes" or
            user_choice_yes_no == "YES" or
            user_choice_yes_no == "yes")
        {
            cout << "Excellent! Welcome, " << char_name << "!\n";
            choosing_name = false;
        }
        else if (user_choice_yes_no == "N" or
                 user_choice_yes_no == "n" or
                 user_choice_yes_no == "No" or
                 user_choice_yes_no == "no" or
                 user_choice_yes_no == "NO")
        {
            cout << "Please provide me with the name you would like to have! : ";
            cin.ignore();
            getline(cin, char_name);
        }
        else
        {
            cout << "That wasn't a valid response.\n";
        }
    }

    // -------------------------------------------------------------------------
    // MAIN STAT CHOICE
    // -------------------------------------------------------------------------

    while (main_stat_loop == true)
    {
        cout << "\nWe are about to roll our stats!\n";
        cout << "Before we do that, I have a question for you!\n";
        cout << "What would you like your main stat to be?\n";
        cout << "We will use this later to calculate your total health and "
             << "determine the type of armor you may wear.\n\n";

        cout << "Your options are as follows:\n\n";

        cout << "1. Strength\n";
        cout << "   A powerful frontline fighter who relies on raw strength and toughness.\n";
        cout << "   Strength characters have the highest health potential.\n";
        cout << "   Armor: Medium or Heavy Armor\n\n";

        cout << "2. Dexterity\n";
        cout << "   A quick and agile fighter who relies on speed, precision, and mobility.\n";
        cout << "   Dexterity characters have moderate health but greater freedom of movement.\n";
        cout << "   Armor: Light or Medium Armor\n\n";

        cout << "3. Intelligence\n";
        cout << "   A clever spellcaster who relies on knowledge, strategy, and magic.\n";
        cout << "   Intelligence characters have lower health but excel through their intellect.\n";
        cout << "   Armor: Light Armor or Robes\n\n";

        cout << "Please choose 1, 2, or 3: ";
        cin >> main_stat_choice;

        if (main_stat_choice == 1)
        {
            main_stat_name = "Strength";
            cout << "\nYou have chosen " << main_stat_name << " as your main stat!\n";
            main_stat_loop = false;
        }
        else if (main_stat_choice == 2)
        {
            main_stat_name = "Dexterity";
            cout << "\nYou have chosen " << main_stat_name << " as your main stat!\n";
            main_stat_loop = false;
        }
        else if (main_stat_choice == 3)
        {
            main_stat_name = "Intelligence";
            cout << "\nYou have chosen " << main_stat_name << " as your main stat!\n";
            main_stat_loop = false;
        }
        else
        {
            cout << "\nThat wasn't a valid option. Please choose 1, 2, or 3.\n";
        }
    }

    // -------------------------------------------------------------------------
    // DICE ROLLING
    // -------------------------------------------------------------------------

    while (choosing_dice_display == true)
    {
        cout << "\nWould you like to roll your dice one stat at a time?\n";
        cout << "If you choose Yes, each die will be displayed using ASCII art.\n";
        cout << "You will choose when you are ready for each new stat roll.\n";
        cout << "If you choose No, all six stat rolls will be generated at once.\n";
        cout << "Respond Yes/No (Y/N): ";

        cin >> display_dice_choice;

        // ---------------------------------------------------------------------
        // ASCII-ART MODE
        // ---------------------------------------------------------------------

        if (display_dice_choice == "Y" or
            display_dice_choice == "y" or
            display_dice_choice == "Yes" or
            display_dice_choice == "yes" or
            display_dice_choice == "YES")
        {
            cout << "\nExcellent! Let's roll some dice!\n";

            // Roll six different stat totals.
            for (int stat_number = 1; stat_number <= 6; stat_number++)
            {
                // Roll #1 happens immediately.
                // Rolls #2 through #6 wait until the player says they are ready.
                if (stat_number > 1)
                {
                    bool ready_for_next_roll(false);

                    while (ready_for_next_roll == false)
                    {
                        cout << "\nAre you ready for Stat Roll #"
                             << stat_number << "?\n";
                        cout << "Respond Yes/No (Y/N): ";

                        cin >> next_roll_choice;

                        if (next_roll_choice == "Y" or
                            next_roll_choice == "y" or
                            next_roll_choice == "Yes" or
                            next_roll_choice == "yes" or
                            next_roll_choice == "YES")
                        {
                            ready_for_next_roll = true;
                        }
                        else if (next_roll_choice == "N" or
                                 next_roll_choice == "n" or
                                 next_roll_choice == "No" or
                                 next_roll_choice == "no" or
                                 next_roll_choice == "NO")
                        {
                            cout << "\nNo problem! Take your time.\n";
                        }
                        else
                        {
                            cout << "\nThat wasn't a valid response.\n";
                            cout << "Please enter Yes, No, Y, or N.\n";
                        }
                    }
                }

                cout << "\n========================\n";
                cout << "     STAT ROLL #" << stat_number << '\n';
                cout << "========================\n";

                // Dice are not generated until the player is ready.
                d6_1 = rand() % 6 + 1;
                d6_2 = rand() % 6 + 1;
                d6_3 = rand() % 6 + 1;

                // Display each of the three dice one at a time.
                for (int die_number = 1; die_number <= 3; die_number++)
                {
                    if (die_number == 1)
                    {
                        current_die = d6_1;
                    }
                    else if (die_number == 2)
                    {
                        current_die = d6_2;
                    }
                    else
                    {
                        current_die = d6_3;
                    }

                    cout << "\nDie " << die_number
                         << " rolled a " << current_die << "!\n";

                    switch (current_die)
                    {
                        case 1:
                            cout << "+-------+\n";
                            cout << "|       |\n";
                            cout << "|   o   |\n";
                            cout << "|       |\n";
                            cout << "+-------+\n";
                            break;

                        case 2:
                            cout << "+-------+\n";
                            cout << "| o     |\n";
                            cout << "|       |\n";
                            cout << "|     o |\n";
                            cout << "+-------+\n";
                            break;

                        case 3:
                            cout << "+-------+\n";
                            cout << "| o     |\n";
                            cout << "|   o   |\n";
                            cout << "|     o |\n";
                            cout << "+-------+\n";
                            break;

                        case 4:
                            cout << "+-------+\n";
                            cout << "| o   o |\n";
                            cout << "|       |\n";
                            cout << "| o   o |\n";
                            cout << "+-------+\n";
                            break;

                        case 5:
                            cout << "+-------+\n";
                            cout << "| o   o |\n";
                            cout << "|   o   |\n";
                            cout << "| o   o |\n";
                            cout << "+-------+\n";
                            break;

                        case 6:
                            cout << "+-------+\n";
                            cout << "| o   o |\n";
                            cout << "| o   o |\n";
                            cout << "| o   o |\n";
                            cout << "+-------+\n";
                            break;

                        default:
                            cout << "Something went wrong with the dice roll!\n";
                            break;
                    }
                }

                int current_stat_roll = d6_1 + d6_2 + d6_3;

                cout << "\nRoll #" << stat_number << ": "
                     << d6_1 << " + "
                     << d6_2 << " + "
                     << d6_3 << " = "
                     << current_stat_roll << '\n';

                // Store the current stat roll.
                if (stat_number == 1)
                {
                    stat_roll_1 = current_stat_roll;
                }
                else if (stat_number == 2)
                {
                    stat_roll_2 = current_stat_roll;
                }
                else if (stat_number == 3)
                {
                    stat_roll_3 = current_stat_roll;
                }
                else if (stat_number == 4)
                {
                    stat_roll_4 = current_stat_roll;
                }
                else if (stat_number == 5)
                {
                    stat_roll_5 = current_stat_roll;
                }
                else
                {
                    stat_roll_6 = current_stat_roll;
                }
            }

            choosing_dice_display = false;
        }

        // ---------------------------------------------------------------------
        // QUICK-ROLL MODE
        // ---------------------------------------------------------------------

        else if (display_dice_choice == "N" or
                 display_dice_choice == "n" or
                 display_dice_choice == "No" or
                 display_dice_choice == "no" or
                 display_dice_choice == "NO")
        {
            cout << "\nRolling all six stat totals...\n";

            for (int stat_number = 1; stat_number <= 6; stat_number++)
            {
                d6_1 = rand() % 6 + 1;
                d6_2 = rand() % 6 + 1;
                d6_3 = rand() % 6 + 1;

                int current_stat_roll = d6_1 + d6_2 + d6_3;

                if (stat_number == 1)
                {
                    stat_roll_1 = current_stat_roll;
                }
                else if (stat_number == 2)
                {
                    stat_roll_2 = current_stat_roll;
                }
                else if (stat_number == 3)
                {
                    stat_roll_3 = current_stat_roll;
                }
                else if (stat_number == 4)
                {
                    stat_roll_4 = current_stat_roll;
                }
                else if (stat_number == 5)
                {
                    stat_roll_5 = current_stat_roll;
                }
                else
                {
                    stat_roll_6 = current_stat_roll;
                }
            }

            choosing_dice_display = false;
        }

        // Invalid response
        else
        {
            cout << "\nThat wasn't a valid response.\n";
            cout << "Please enter Yes, No, Y, or N.\n";
        }
    }

    // -------------------------------------------------------------------------
    // DISPLAY AVAILABLE ROLLS
    // -------------------------------------------------------------------------

    cout << "\n========================\n";
    cout << "   YOUR AVAILABLE STATS\n";
    cout << "========================\n";

    cout << "Roll 1: " << stat_roll_1 << '\n';
    cout << "Roll 2: " << stat_roll_2 << '\n';
    cout << "Roll 3: " << stat_roll_3 << '\n';
    cout << "Roll 4: " << stat_roll_4 << '\n';
    cout << "Roll 5: " << stat_roll_5 << '\n';
    cout << "Roll 6: " << stat_roll_6 << '\n';

    // -------------------------------------------------------------------------
    // OPTIONAL STAT DESCRIPTIONS
    // -------------------------------------------------------------------------

    while (choosing_description_option == true)
    {
        cout << "\nWould you like a brief description of each stat before assigning them?\n";
        cout << "Respond Yes/No (Y/N): ";
        cin >> stat_description_choice;

        if (stat_description_choice == "Y" or
            stat_description_choice == "y" or
            stat_description_choice == "Yes" or
            stat_description_choice == "yes" or
            stat_description_choice == "YES")
        {
            cout << "\nStrength\n";
            cout << "  Physical power and melee capability.\n";
            cout << "  Useful for characters who rely on brute force and heavy weapons.\n\n";

            cout << "Dexterity\n";
            cout << "  Agility, reflexes, speed, and precision.\n";
            cout << "  Useful for quick fighters, ranged attacks, and lighter armor.\n\n";

            cout << "Constitution\n";
            cout << "  Toughness, endurance, and survivability.\n";
            cout << "  A higher Constitution helps make your character harder to kill.\n\n";

            cout << "Intelligence\n";
            cout << "  Knowledge, reasoning, memory, and magical aptitude.\n";
            cout << "  Useful for characters who rely on strategy or spellcasting.\n\n";

            cout << "Wisdom\n";
            cout << "  Awareness, intuition, judgment, and perception.\n";
            cout << "  Useful for noticing danger and understanding the world around you.\n\n";

            cout << "Charisma\n";
            cout << "  Confidence, leadership, persuasion, and social presence.\n";
            cout << "  Useful for characters who rely on communication and influence.\n\n";

            choosing_description_option = false;
        }
        else if (stat_description_choice == "N" or
                 stat_description_choice == "n" or
                 stat_description_choice == "No" or
                 stat_description_choice == "no" or
                 stat_description_choice == "NO")
        {
            choosing_description_option = false;
        }
        else
        {
            cout << "\nThat wasn't a valid response.\n";
            cout << "Please enter Yes, No, Y, or N.\n";
        }
    }

    // -------------------------------------------------------------------------
    // ASSIGN STRENGTH
    // -------------------------------------------------------------------------

    bool assigning_strength(true);

    while (assigning_strength == true)
    {
        cout << "\nAvailable Rolls:\n";
        cout << "1. " << stat_roll_1 << '\n';
        cout << "2. " << stat_roll_2 << '\n';
        cout << "3. " << stat_roll_3 << '\n';
        cout << "4. " << stat_roll_4 << '\n';
        cout << "5. " << stat_roll_5 << '\n';
        cout << "6. " << stat_roll_6 << '\n';

        cout << "\nWhich roll would you like to assign to Strength?\n";
        cout << "Choose 1-6: ";
        cin >> stat_choice;

        if (stat_choice == 1 and roll_1_used == false)
        {
            strength = stat_roll_1;
            roll_1_used = true;
            assigning_strength = false;
        }
        else if (stat_choice == 2 and roll_2_used == false)
        {
            strength = stat_roll_2;
            roll_2_used = true;
            assigning_strength = false;
        }
        else if (stat_choice == 3 and roll_3_used == false)
        {
            strength = stat_roll_3;
            roll_3_used = true;
            assigning_strength = false;
        }
        else if (stat_choice == 4 and roll_4_used == false)
        {
            strength = stat_roll_4;
            roll_4_used = true;
            assigning_strength = false;
        }
        else if (stat_choice == 5 and roll_5_used == false)
        {
            strength = stat_roll_5;
            roll_5_used = true;
            assigning_strength = false;
        }
        else if (stat_choice == 6 and roll_6_used == false)
        {
            strength = stat_roll_6;
            roll_6_used = true;
            assigning_strength = false;
        }
        else if (stat_choice >= 1 and stat_choice <= 6)
        {
            cout << "That roll has already been assigned!\n";
        }
        else
        {
            cout << "Invalid choice. Please choose a number from 1-6.\n";
        }
    }

    // -------------------------------------------------------------------------
    // ASSIGN DEXTERITY
    // -------------------------------------------------------------------------

    bool assigning_dexterity(true);

    while (assigning_dexterity == true)
    {
        cout << "\nWhich roll would you like to assign to Dexterity?\n";
        cout << "Choose 1-6: ";
        cin >> stat_choice;

        if (stat_choice == 1 and roll_1_used == false)
        {
            dexterity = stat_roll_1;
            roll_1_used = true;
            assigning_dexterity = false;
        }
        else if (stat_choice == 2 and roll_2_used == false)
        {
            dexterity = stat_roll_2;
            roll_2_used = true;
            assigning_dexterity = false;
        }
        else if (stat_choice == 3 and roll_3_used == false)
        {
            dexterity = stat_roll_3;
            roll_3_used = true;
            assigning_dexterity = false;
        }
        else if (stat_choice == 4 and roll_4_used == false)
        {
            dexterity = stat_roll_4;
            roll_4_used = true;
            assigning_dexterity = false;
        }
        else if (stat_choice == 5 and roll_5_used == false)
        {
            dexterity = stat_roll_5;
            roll_5_used = true;
            assigning_dexterity = false;
        }
        else if (stat_choice == 6 and roll_6_used == false)
        {
            dexterity = stat_roll_6;
            roll_6_used = true;
            assigning_dexterity = false;
        }
        else if (stat_choice >= 1 and stat_choice <= 6)
        {
            cout << "That roll has already been assigned!\n";
        }
        else
        {
            cout << "Invalid choice. Please choose a number from 1-6.\n";
        }
    }

    // -------------------------------------------------------------------------
    // ASSIGN CONSTITUTION
    // -------------------------------------------------------------------------

    bool assigning_constitution(true);

    while (assigning_constitution == true)
    {
        cout << "\nWhich roll would you like to assign to Constitution?\n";
        cout << "Choose 1-6: ";
        cin >> stat_choice;

        if (stat_choice == 1 and roll_1_used == false)
        {
            constitution = stat_roll_1;
            roll_1_used = true;
            assigning_constitution = false;
        }
        else if (stat_choice == 2 and roll_2_used == false)
        {
            constitution = stat_roll_2;
            roll_2_used = true;
            assigning_constitution = false;
        }
        else if (stat_choice == 3 and roll_3_used == false)
        {
            constitution = stat_roll_3;
            roll_3_used = true;
            assigning_constitution = false;
        }
        else if (stat_choice == 4 and roll_4_used == false)
        {
            constitution = stat_roll_4;
            roll_4_used = true;
            assigning_constitution = false;
        }
        else if (stat_choice == 5 and roll_5_used == false)
        {
            constitution = stat_roll_5;
            roll_5_used = true;
            assigning_constitution = false;
        }
        else if (stat_choice == 6 and roll_6_used == false)
        {
            constitution = stat_roll_6;
            roll_6_used = true;
            assigning_constitution = false;
        }
        else if (stat_choice >= 1 and stat_choice <= 6)
        {
            cout << "That roll has already been assigned!\n";
        }
        else
        {
            cout << "Invalid choice. Please choose a number from 1-6.\n";
        }
    }

    // -------------------------------------------------------------------------
    // ASSIGN INTELLIGENCE
    // -------------------------------------------------------------------------

    bool assigning_intelligence(true);

    while (assigning_intelligence == true)
    {
        cout << "\nWhich roll would you like to assign to Intelligence?\n";
        cout << "Choose 1-6: ";
        cin >> stat_choice;

        if (stat_choice == 1 and roll_1_used == false)
        {
            intelligence = stat_roll_1;
            roll_1_used = true;
            assigning_intelligence = false;
        }
        else if (stat_choice == 2 and roll_2_used == false)
        {
            intelligence = stat_roll_2;
            roll_2_used = true;
            assigning_intelligence = false;
        }
        else if (stat_choice == 3 and roll_3_used == false)
        {
            intelligence = stat_roll_3;
            roll_3_used = true;
            assigning_intelligence = false;
        }
        else if (stat_choice == 4 and roll_4_used == false)
        {
            intelligence = stat_roll_4;
            roll_4_used = true;
            assigning_intelligence = false;
        }
        else if (stat_choice == 5 and roll_5_used == false)
        {
            intelligence = stat_roll_5;
            roll_5_used = true;
            assigning_intelligence = false;
        }
        else if (stat_choice == 6 and roll_6_used == false)
        {
            intelligence = stat_roll_6;
            roll_6_used = true;
            assigning_intelligence = false;
        }
        else if (stat_choice >= 1 and stat_choice <= 6)
        {
            cout << "That roll has already been assigned!\n";
        }
        else
        {
            cout << "Invalid choice. Please choose a number from 1-6.\n";
        }
    }

    // -------------------------------------------------------------------------
    // ASSIGN WISDOM
    // -------------------------------------------------------------------------

    bool assigning_wisdom(true);

    while (assigning_wisdom == true)
    {
        cout << "\nWhich roll would you like to assign to Wisdom?\n";
        cout << "Choose 1-6: ";
        cin >> stat_choice;

        if (stat_choice == 1 and roll_1_used == false)
        {
            wisdom = stat_roll_1;
            roll_1_used = true;
            assigning_wisdom = false;
        }
        else if (stat_choice == 2 and roll_2_used == false)
        {
            wisdom = stat_roll_2;
            roll_2_used = true;
            assigning_wisdom = false;
        }
        else if (stat_choice == 3 and roll_3_used == false)
        {
            wisdom = stat_roll_3;
            roll_3_used = true;
            assigning_wisdom = false;
        }
        else if (stat_choice == 4 and roll_4_used == false)
        {
            wisdom = stat_roll_4;
            roll_4_used = true;
            assigning_wisdom = false;
        }
        else if (stat_choice == 5 and roll_5_used == false)
        {
            wisdom = stat_roll_5;
            roll_5_used = true;
            assigning_wisdom = false;
        }
        else if (stat_choice == 6 and roll_6_used == false)
        {
            wisdom = stat_roll_6;
            roll_6_used = true;
            assigning_wisdom = false;
        }
        else if (stat_choice >= 1 and stat_choice <= 6)
        {
            cout << "That roll has already been assigned!\n";
        }
        else
        {
            cout << "Invalid choice. Please choose a number from 1-6.\n";
        }
    }

    // -------------------------------------------------------------------------
    // ASSIGN CHARISMA
    // -------------------------------------------------------------------------

    bool assigning_charisma(true);

    while (assigning_charisma == true)
    {
        cout << "\nWhich roll would you like to assign to Charisma?\n";
        cout << "Choose 1-6: ";
        cin >> stat_choice;

        if (stat_choice == 1 and roll_1_used == false)
        {
            charisma = stat_roll_1;
            roll_1_used = true;
            assigning_charisma = false;
        }
        else if (stat_choice == 2 and roll_2_used == false)
        {
            charisma = stat_roll_2;
            roll_2_used = true;
            assigning_charisma = false;
        }
        else if (stat_choice == 3 and roll_3_used == false)
        {
            charisma = stat_roll_3;
            roll_3_used = true;
            assigning_charisma = false;
        }
        else if (stat_choice == 4 and roll_4_used == false)
        {
            charisma = stat_roll_4;
            roll_4_used = true;
            assigning_charisma = false;
        }
        else if (stat_choice == 5 and roll_5_used == false)
        {
            charisma = stat_roll_5;
            roll_5_used = true;
            assigning_charisma = false;
        }
        else if (stat_choice == 6 and roll_6_used == false)
        {
            charisma = stat_roll_6;
            roll_6_used = true;
            assigning_charisma = false;
        }
        else if (stat_choice >= 1 and stat_choice <= 6)
        {
            cout << "That roll has already been assigned!\n";
        }
        else
        {
            cout << "Invalid choice. Please choose a number from 1-6.\n";
        }
    }

    // -------------------------------------------------------------------------
    // FINAL CHARACTER STATS
    // -------------------------------------------------------------------------

    cout << "\n================================\n";
    cout << "       CHARACTER CREATED\n";
    cout << "================================\n";

    cout << "Name:          " << char_name << '\n';
    cout << "Main Stat:     " << main_stat_name << "\n\n";

    cout << "Strength:      " << strength << '\n';
    cout << "Dexterity:     " << dexterity << '\n';
    cout << "Constitution:  " << constitution << '\n';
    cout << "Intelligence:  " << intelligence << '\n';
    cout << "Wisdom:        " << wisdom << '\n';
    cout << "Charisma:      " << charisma << '\n';

    cout << "\nCharacter creation complete!\n";

    return 0;
}
