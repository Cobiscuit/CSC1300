#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    srand(time(0));

    // Character information
    string character_name("");

    // Dice values
    int d6_1(0);
    int d6_2(0);
    int d6_3(0);

    // Current stat total
    int current_stat(0);

    // Saved stat rolls
    int stat_roll_1(0);
    int stat_roll_2(0);
    int stat_roll_3(0);
    int stat_roll_4(0);
    int stat_roll_5(0);
    int stat_roll_6(0);

    // Tracks whether each stat roll has been used
    bool stat_roll_1_used(false);
    bool stat_roll_2_used(false);
    bool stat_roll_3_used(false);
    bool stat_roll_4_used(false);
    bool stat_roll_5_used(false);
    bool stat_roll_6_used(false);

    // Final ability scores
    int main_stat(0);
    int strength(0);
    int dexterity(0);
    int constitution(0);
    int intelligence(0);
    int wisdom(0);
    int charisma(0);

    // Main stat / armor information
    string main_stat_name("");
    string armor_type("");
    int armor_class(0);

    // Variables used while assigning stat rolls
    int selected_roll(0);
    int selected_value(0);
    bool valid_choice(false);
    string ability_name("");

    // Get character name
    cout << "Enter your character's name: ";
    getline(cin, character_name);

    // Roll six stats
    for (int stat_roll_count = 1; stat_roll_count <= 6; stat_roll_count++)
    {
        // Roll three dice
        d6_1 = rand() % 6 + 1;
        d6_2 = rand() % 6 + 1;
        d6_3 = rand() % 6 + 1;

        current_stat = d6_1 + d6_2 + d6_3;

        // Rows for each die
        string d1_row1, d1_row2, d1_row3;
        string d2_row1, d2_row2, d2_row3;
        string d3_row1, d3_row2, d3_row3;

        // Die 1
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
        cout << "\nStat Roll #" << stat_roll_count << endl;

        cout << "    " << d6_1
             << "           " << d6_2
             << "           " << d6_3 << endl;

        cout << "+-------+   +-------+   +-------+\n";
        cout << d1_row1 << "   " << d2_row1 << "   " << d3_row1 << endl;
        cout << d1_row2 << "   " << d2_row2 << "   " << d3_row2 << endl;
        cout << d1_row3 << "   " << d2_row3 << "   " << d3_row3 << endl;
        cout << "+-------+   +-------+   +-------+\n";

        cout << "Stat total: " << current_stat << endl;

        // Save the current stat total into the correct stat variable
        switch (stat_roll_count)
        {
            case 1:
                stat_roll_1 = current_stat;
                break;

            case 2:
                stat_roll_2 = current_stat;
                break;

            case 3:
                stat_roll_3 = current_stat;
                break;

            case 4:
                stat_roll_4 = current_stat;
                break;

            case 5:
                stat_roll_5 = current_stat;
                break;

            case 6:
                stat_roll_6 = current_stat;
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

        valid_choice = false;

        while (valid_choice == false)
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
                        valid_choice = true;
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
                        valid_choice = true;
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
                        valid_choice = true;
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
                        valid_choice = true;
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
                        valid_choice = true;
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
                        valid_choice = true;
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

    // Choose the character's main stat and armor type
    while (main_stat < 1 || main_stat > 3)
    {
        cout << "\nChoose your Main Stat:\n";
        cout << "1. Strength\n";
        cout << "2. Dexterity\n";
        cout << "3. Intelligence\n";
        cout << "Selection: ";

        cin >> main_stat;

        switch (main_stat)
        {
            case 1:
                main_stat_name = "Strength";
                armor_type = "Plate";
                armor_class = 5;
                break;

            case 2:
                main_stat_name = "Dexterity";
                armor_type = "Leather";
                armor_class = 3;
                break;

            case 3:
                main_stat_name = "Intelligence";
                armor_type = "Cloth";
                armor_class = 1;
                break;

            default:
                cout << "Please enter 1, 2, or 3.\n";
        }
    }

    // Display finished character
    //I also had AI design the Char sheet... I didnt wanna, once again im sorry.
    cout << "\n";
    cout << "+==================================================+\n";
    cout << "|              *** CHARACTER SHEET ***             |\n";
    cout << "+==================================================+\n";
    
    cout << "| " << left << setw(48)
         << ("Character: " + character_name) << "|\n";
    
    cout << "| " << setw(48)
         << ("Main Stat: " + main_stat_name) << "|\n";
    
    cout << "| " << setw(48)
         << ("Armor Type: " + armor_type) << "|\n";
    
    cout << "| Armor Class: +" << left << setw(34)
         << armor_class << "|\n";
    
    cout << "+--------------------------------------------------+\n";
    cout << "|                    ATTRIBUTES                    |\n";
    cout << "+--------------------------------------------------+\n";
    
    cout << "| Strength:     " << left << setw(33) << strength << "|\n";
    cout << "| Dexterity:    " << left << setw(33) << dexterity << "|\n";
    cout << "| Constitution: " << left << setw(33) << constitution << "|\n";
    cout << "| Intelligence: " << left << setw(33) << intelligence << "|\n";
    cout << "| Wisdom:       " << left << setw(33) << wisdom << "|\n";
    cout << "| Charisma:     " << left << setw(33) << charisma << "|\n";
    
    cout << "+==================================================+\n";
    cout << "|               READY FOR ADVENTURE                |\n";
    cout << "+==================================================+\n";

    return 0;
}
