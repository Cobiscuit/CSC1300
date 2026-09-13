/*
Title: DnD_FullyCommitted
Author: Cobain Irwin
Date: 20260906
Purpose: DnD character sheet and dice roller. This version combines the
different pieces into one program.
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    /*
     * Main goals:
     * 1. Get the character's name.
     * 2. Ask whether the user wants fully randomized stats or wants to choose.
     * 3. Validate the user's yes/no response.
     * 4. If fully randomized, generate all six ability scores using 3d6.
     * 5. If manual, visually roll six 3d6 stat totals.
     * 6. Let the user assign those six rolls to STR, DEX, CON, INT, WIS, CHA.
     * 7. Prevent the same saved roll from being used more than once.
     */

    // Seed random number generator
    srand(time(0));

    // Strings
    string usr_char_name("");
    string usr_creation_choice("");
    string ability_name("");
    string main_stat_name("");

    // Dice
    int d6_1(0);
    int d6_2(0);
    int d6_3(0);

    // Current stat total
    int current_stat_total(0);

    // Saved stat rolls for manual assignment
    int stat_roll_1(0);
    int stat_roll_2(0);
    int stat_roll_3(0);
    int stat_roll_4(0);
    int stat_roll_5(0);
    int stat_roll_6(0);

    // Used during manual stat assignment
    int selected_roll(0);
    int selected_value(0);

    // Main stat / HP
    int main_stat_choice(0);
    int main_stat_value(0);
    int hit_points(0);
    double hp_multiplier(0.0);

    // Validation / loop control
    bool creation_choice_valid(false);
    bool choosing_stats(false);
    bool stat_choice_valid(false);
    bool main_stat_choice_valid(false);

    // Track whether each saved stat roll has already been used
    bool stat_roll_1_used(false);
    bool stat_roll_2_used(false);
    bool stat_roll_3_used(false);
    bool stat_roll_4_used(false);
    bool stat_roll_5_used(false);
    bool stat_roll_6_used(false);

    // Final ability scores
    int strength(0);
    int dexterity(0);
    int constitution(0);
    int intelligence(0);
    int wisdom(0);
    int charisma(0);

    // Get character name
    cout << "\nWelcome to D&D Character Creator!" << endl;
    cout << "Before we can begin throwing dice, we need a name for your character!\n";
    cout << "Character name: ";
    getline(cin, usr_char_name);

    cout << "\nNow thats out of the way, do you want to fully randomize your stats?\n";
    cout << "Or do you want to have a choice in what goes where!\n";

    // Validate yes/no choice
    while (creation_choice_valid == false)
    {
        cout << "\nTo randomize everything: Respond Yes/y,"
             << "\nTo select your own stats: Respond No/n: ";

        cin >> usr_creation_choice;

        // Learned from:
        // https://www.geeksforgeeks.org/cpp/tolower-function-in-cpp/
        // The & gives direct access to each character in the string.
        for (auto& x : usr_creation_choice)
        {
            x = tolower(x);
        }

        // Fully randomized stats
        if (usr_creation_choice == "yes" || usr_creation_choice == "y")
        {
            creation_choice_valid = true;

            // Each ability score is 3d6
            strength = (rand() % 6 + 1) +
                       (rand() % 6 + 1) +
                       (rand() % 6 + 1);

            dexterity = (rand() % 6 + 1) +
                        (rand() % 6 + 1) +
                        (rand() % 6 + 1);

            constitution = (rand() % 6 + 1) +
                           (rand() % 6 + 1) +
                           (rand() % 6 + 1);

            intelligence = (rand() % 6 + 1) +
                           (rand() % 6 + 1) +
                           (rand() % 6 + 1);

            wisdom = (rand() % 6 + 1) +
                     (rand() % 6 + 1) +
                     (rand() % 6 + 1);

            charisma = (rand() % 6 + 1) +
                       (rand() % 6 + 1) +
                       (rand() % 6 + 1);
        }

        // Manual stat rolling / assignment path
        else if (usr_creation_choice == "no" || usr_creation_choice == "n")
        {
            creation_choice_valid = true;
            choosing_stats = true;

            while (choosing_stats == true)
            {
                cout << "\nAlright " << usr_char_name
                     << ", lets roll six stat totals!\n";

                // Roll six stats
                for (int stat_roll_count = 1; stat_roll_count <= 6; stat_roll_count++)
                {
                    // Roll three dice
                    d6_1 = rand() % 6 + 1;
                    d6_2 = rand() % 6 + 1;
                    d6_3 = rand() % 6 + 1;

                    current_stat_total = d6_1 + d6_2 + d6_3;

                    // Rows for each die
                    string d1_row1, d1_row2, d1_row3;
                    string d2_row1, d2_row2, d2_row3;
                    string d3_row1, d3_row2, d3_row3;

                    // Die 1
                    // see I would of prefered to make these switches a func and just pass the 
                    // dice args into the parameters... BUT ALAS
                    switch (d6_1)
                    {
                        case 1:
                            d1_row1 = "|       |";
                            d1_row2 = "|   o   |";
                            d1_row3 = "|       |";
                            break;

                        case 2:
                            d1_row1 = "| o     |";
                            d1_row2 = "|       |";
                            d1_row3 = "|     o |";
                            break;

                        case 3:
                            d1_row1 = "| o     |";
                            d1_row2 = "|   o   |";
                            d1_row3 = "|     o |";
                            break;

                        case 4:
                            d1_row1 = "| o   o |";
                            d1_row2 = "|       |";
                            d1_row3 = "| o   o |";
                            break;

                        case 5:
                            d1_row1 = "| o   o |";
                            d1_row2 = "|   o   |";
                            d1_row3 = "| o   o |";
                            break;

                        case 6:
                            d1_row1 = "| o   o |";
                            d1_row2 = "| o   o |";
                            d1_row3 = "| o   o |";
                            break;
                    }

                    // Die 2
                    switch (d6_2)
                    {
                        case 1:
                            d2_row1 = "|       |";
                            d2_row2 = "|   o   |";
                            d2_row3 = "|       |";
                            break;

                        case 2:
                            d2_row1 = "| o     |";
                            d2_row2 = "|       |";
                            d2_row3 = "|     o |";
                            break;

                        case 3:
                            d2_row1 = "| o     |";
                            d2_row2 = "|   o   |";
                            d2_row3 = "|     o |";
                            break;

                        case 4:
                            d2_row1 = "| o   o |";
                            d2_row2 = "|       |";
                            d2_row3 = "| o   o |";
                            break;

                        case 5:
                            d2_row1 = "| o   o |";
                            d2_row2 = "|   o   |";
                            d2_row3 = "| o   o |";
                            break;

                        case 6:
                            d2_row1 = "| o   o |";
                            d2_row2 = "| o   o |";
                            d2_row3 = "| o   o |";
                            break;
                    }

                    // Die 3
                    switch (d6_3)
                    {
                        case 1:
                            d3_row1 = "|       |";
                            d3_row2 = "|   o   |";
                            d3_row3 = "|       |";
                            break;

                        case 2:
                            d3_row1 = "| o     |";
                            d3_row2 = "|       |";
                            d3_row3 = "|     o |";
                            break;

                        case 3:
                            d3_row1 = "| o     |";
                            d3_row2 = "|   o   |";
                            d3_row3 = "|     o |";
                            break;

                        case 4:
                            d3_row1 = "| o   o |";
                            d3_row2 = "|       |";
                            d3_row3 = "| o   o |";
                            break;

                        case 5:
                            d3_row1 = "| o   o |";
                            d3_row2 = "|   o   |";
                            d3_row3 = "| o   o |";
                            break;

                        case 6:
                            d3_row1 = "| o   o |";
                            d3_row2 = "| o   o |";
                            d3_row3 = "| o   o |";
                            break;
                    }

                    // Display the three dice side-by-side
                    // This is also from the AI help cuz tiny brain.
                    cout << "\nStat Roll #" << stat_roll_count << endl;

                    cout << "    " << d6_1
                         << "           " << d6_2
                         << "           " << d6_3 << endl;

                    cout << "+-------+   +-------+   +-------+\n";
                    cout << d1_row1 << "   " << d2_row1 << "   " << d3_row1 << endl;
                    cout << d1_row2 << "   " << d2_row2 << "   " << d3_row2 << endl;
                    cout << d1_row3 << "   " << d2_row3 << "   " << d3_row3 << endl;
                    cout << "+-------+   +-------+   +-------+\n";

                    cout << "Stat total: " << current_stat_total << endl;

                    // Save the current stat total into the correct stat variable
                    switch (stat_roll_count)
                    {
                        case 1:
                            stat_roll_1 = current_stat_total;
                            break;

                        case 2:
                            stat_roll_2 = current_stat_total;
                            break;

                        case 3:
                            stat_roll_3 = current_stat_total;
                            break;

                        case 4:
                            stat_roll_4 = current_stat_total;
                            break;

                        case 5:
                            stat_roll_5 = current_stat_total;
                            break;

                        case 6:
                            stat_roll_6 = current_stat_total;
                            break;
                    }
                }

                // Assign the six stat rolls to the six abilities
                for (int ability_count = 1; ability_count <= 6; ability_count++)
                {
                    // Determine which ability is being assigned
                    switch (ability_count)
                    {
                        case 1:
                            ability_name = "Strength";
                            break;

                        case 2:
                            ability_name = "Dexterity";
                            break;

                        case 3:
                            ability_name = "Constitution";
                            break;

                        case 4:
                            ability_name = "Intelligence";
                            break;

                        case 5:
                            ability_name = "Wisdom";
                            break;

                        case 6:
                            ability_name = "Charisma";
                            break;
                    }

                    stat_choice_valid = false;

                    while (stat_choice_valid == false)
                    {
                        cout << "\nAvailable Stat Rolls\n";
                        cout << "--------------------\n";

                        // Show each roll and whether it has already been used
                        for (int stat_count = 1; stat_count <= 6; stat_count++)
                        {
                            cout << "Stat Roll #" << stat_count << ": ";

                            switch (stat_count)
                            {
                                case 1:
                                    cout << stat_roll_1;
                                    if (stat_roll_1_used)
                                        cout << " - USED";
                                    else
                                        cout << " - AVAILABLE";
                                    break;

                                case 2:
                                    cout << stat_roll_2;
                                    if (stat_roll_2_used)
                                        cout << " - USED";
                                    else
                                        cout << " - AVAILABLE";
                                    break;

                                case 3:
                                    cout << stat_roll_3;
                                    if (stat_roll_3_used)
                                        cout << " - USED";
                                    else
                                        cout << " - AVAILABLE";
                                    break;

                                case 4:
                                    cout << stat_roll_4;
                                    if (stat_roll_4_used)
                                        cout << " - USED";
                                    else
                                        cout << " - AVAILABLE";
                                    break;

                                case 5:
                                    cout << stat_roll_5;
                                    if (stat_roll_5_used)
                                        cout << " - USED";
                                    else
                                        cout << " - AVAILABLE";
                                    break;

                                case 6:
                                    cout << stat_roll_6;
                                    if (stat_roll_6_used)
                                        cout << " - USED";
                                    else
                                        cout << " - AVAILABLE";
                                    break;
                            }

                            cout << endl;
                        }

                        cout << "\nChoose a stat roll for "
                             << ability_name << " (1-6): ";

                        cin >> selected_roll;

                        // Check which roll the user selected
                        // and make sure it has not already been used
                        switch (selected_roll)
                        {
                            case 1:
                                if (stat_roll_1_used == false)
                                {
                                    selected_value = stat_roll_1;
                                    stat_roll_1_used = true;
                                    stat_choice_valid = true;
                                }
                                else
                                {
                                    cout << "That stat roll has already been used.\n";
                                }
                                break;

                            case 2:
                                if (stat_roll_2_used == false)
                                {
                                    selected_value = stat_roll_2;
                                    stat_roll_2_used = true;
                                    stat_choice_valid = true;
                                }
                                else
                                {
                                    cout << "That stat roll has already been used.\n";
                                }
                                break;

                            case 3:
                                if (stat_roll_3_used == false)
                                {
                                    selected_value = stat_roll_3;
                                    stat_roll_3_used = true;
                                    stat_choice_valid = true;
                                }
                                else
                                {
                                    cout << "That stat roll has already been used.\n";
                                }
                                break;

                            case 4:
                                if (stat_roll_4_used == false)
                                {
                                    selected_value = stat_roll_4;
                                    stat_roll_4_used = true;
                                    stat_choice_valid = true;
                                }
                                else
                                {
                                    cout << "That stat roll has already been used.\n";
                                }
                                break;

                            case 5:
                                if (stat_roll_5_used == false)
                                {
                                    selected_value = stat_roll_5;
                                    stat_roll_5_used = true;
                                    stat_choice_valid = true;
                                }
                                else
                                {
                                    cout << "That stat roll has already been used.\n";
                                }
                                break;

                            case 6:
                                if (stat_roll_6_used == false)
                                {
                                    selected_value = stat_roll_6;
                                    stat_roll_6_used = true;
                                    stat_choice_valid = true;
                                }
                                else
                                {
                                    cout << "That stat roll has already been used.\n";
                                }
                                break;

                            default:
                                cout << "Please choose a stat roll from 1 through 6.\n";
                        }
                    }

                    // Save the selected value into the correct ability
                    switch (ability_count)
                    {
                        case 1:
                            strength = selected_value;
                            break;

                        case 2:
                            dexterity = selected_value;
                            break;

                        case 3:
                            constitution = selected_value;
                            break;

                        case 4:
                            intelligence = selected_value;
                            break;

                        case 5:
                            wisdom = selected_value;
                            break;

                        case 6:
                            charisma = selected_value;
                            break;
                    }

                    cout << ability_name << " set to " << selected_value << ".\n";
                }

                choosing_stats = false;
            }
        }

        else
        {
            cout << "\nPlease enter Yes or No.\n";
        }
    }


    // Main stat selection
    cout << "\nNow choose your character's MAIN STAT.\n";
    cout << "Your main stat also helps determine your starting HP.\n\n";

    cout << "1. Strength\n";
    cout << "   Physical power and brute force. Useful for heavy-hitting characters.\n";
    cout << "   HP bonus: 50% of Strength.\n\n";

    cout << "2. Dexterity\n";
    cout << "   Agility, speed, reflexes, and precision. Useful for quick characters.\n";
    cout << "   HP bonus: 30% of Dexterity.\n\n";

    cout << "3. Intelligence\n";
    cout << "   Knowledge, reasoning, and magical ability. Useful for spellcasters.\n";
    cout << "   HP bonus: 25% of Intelligence.\n\n";

    while (main_stat_choice_valid == false)
    {
        cout << "Choose your main stat (1-3): ";
        cin >> main_stat_choice;

        switch (main_stat_choice)
        {
            case 1:
                main_stat_name = "Strength";
                main_stat_value = strength;
                hp_multiplier = 0.50;
                main_stat_choice_valid = true;
                break;

            case 2:
                main_stat_name = "Dexterity";
                main_stat_value = dexterity;
                hp_multiplier = 0.30;
                main_stat_choice_valid = true;
                break;

            case 3:
                main_stat_name = "Intelligence";
                main_stat_value = intelligence;
                hp_multiplier = 0.25;
                main_stat_choice_valid = true;
                break;

            default:
                cout << "Please enter 1, 2, or 3.\n\n";
        }
    }

    /*
     * HP formula:
     * Constitution + (Main Stat * multiplier)
     *
     * Strength     -> CON + (STR * 0.50)
     * Dexterity    -> CON + (DEX * 0.30)
     * Intelligence -> CON + (INT * 0.25)
     *
     * Adding 0.5 before converting to int rounds the result
     * to the nearest whole hit point.
     */
    hit_points = static_cast<int>(constitution + (main_stat_value * hp_multiplier) + 0.5);

    // Stat descriptions
    // I just googled descriptions and copy and pasted them from the DND site...
    cout << "\nAbility Score Descriptions\n";
    cout << "--------------------------\n";
    cout << "Strength:     Physical power, lifting, melee force, and brute strength.\n";
    cout << "Dexterity:    Agility, balance, speed, reflexes, and precision.\n";
    cout << "Constitution: Toughness, endurance, stamina, and overall health.\n";
    cout << "Intelligence: Knowledge, logic, reasoning, memory, and magical study.\n";
    cout << "Wisdom:       Awareness, intuition, perception, and practical judgment.\n";
    cout << "Charisma:     Confidence, personality, persuasion, and social presence.\n";

    // Final character sheet
    // I also had AI design the Char sheet... I didnt wanna, once again im sorry.
    cout << "\n====================================\n";
    cout << "Character:     " << usr_char_name << endl;
    cout << "Main Stat:     " << main_stat_name << endl;
    cout << "Hit Points:    " << hit_points << endl;
    cout << "====================================\n";
    cout << "Strength:      " << strength << endl;
    cout << "Dexterity:     " << dexterity << endl;
    cout << "Constitution:  " << constitution << endl;
    cout << "Intelligence:  " << intelligence << endl;
    cout << "Wisdom:        " << wisdom << endl;
    cout << "Charisma:      " << charisma << endl;
    cout << "====================================\n";

    return 0;
}
