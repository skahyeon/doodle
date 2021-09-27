#include <doodle/doodle.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace doodle;

int TOT_LIMIT = 0;
int STA_LIMIT = 20;

vector<string> stat_name = {"strong", "intelligence", "wisdom", "speed", "defense", "luck"};

vector<string> stat_pos = {"powerful", "smart", "wise", "fast", "robust", "lucky"};
vector<string> stat_neg = {"weak", "stupid", "unwise", "slow", "soft", "unlucky"};

vector<int>  stat_nums(6, 0);
vector<bool> stat_check(6, false);

int stat_sum = 0;
int max_idx = -1, min_idx = -1;
int stat_idx, amount;

constexpr Color orange{255, 100, 0, 190};
string          Race  = "Race";
string          Class = "Class";


void src()
{
    cout << "What is your character's race? android human monster" << endl; // android,human,monster
    cin >> Race;

    cout << "What is your character's class? archer gunner knight" << endl; // archer,gunner,knight
    cin >> Class;
}
void sss() {
    stat_nums[stat_idx] = amount;

    if (min_idx == -1)
        min_idx = stat_idx;

    if (max_idx == -1)
        max_idx = stat_idx;

    if (min_idx >= 0 && stat_nums[min_idx] > amount)
        min_idx = stat_idx;

    if (max_idx >= 0 && stat_nums[max_idx] < amount)
        max_idx = stat_idx;

    stat_check[stat_idx] = true;
    stat_sum += amount;
}
void func(int &a) {
    a = 60;
}
int main(void)
{
    
    func(TOT_LIMIT);
    
    src();
    for (int i = 0; i < 6; i++)
    {
        cout << "Allocate your stat and amount. ex) 5 10 will allocate 10 stats on luck\nStats : strong(0) "
                "intelligence(1) wisdom(2) survive(3) defense(4) luck(5)\nCurrently allocated stat: "
             << stat_sum << endl;

        cin >> stat_idx >> amount;

        if (stat_check[stat_idx] == true || amount > STA_LIMIT || stat_sum + amount > TOT_LIMIT)
        {
            cerr << " Try again\n";
            i--;
            continue;
        }
        // converting stats into their p/n d
        sss();
    }


    
    create_window("Assignment 4 By Jaehyeon Nam", 500, 800);
    set_rectangle_mode(RectMode::Center);

    int    l        = 10 * stat_nums[max_idx];
    double COS_PI_6 = cos(PI / 6);
    double SIN_PI_6 = sin(PI / 6);
    
    while (!is_window_closed())
    {
        update_window();
        clear_background(220);
        set_font_size(23);
        draw_text(stat_neg[min_idx] + " " + stat_pos[max_idx] + " " + Race + " " + Class, -200, l + 20);

        no_fill();

        draw_line(0, l, 0, -l); //|
        draw_line(-l * COS_PI_6, -l * SIN_PI_6, l * COS_PI_6, l * SIN_PI_6);
        draw_line(-l * COS_PI_6, l * SIN_PI_6, l * COS_PI_6, -l * SIN_PI_6);


        for (int i = 1; i <= stat_nums[max_idx]; i++)
        {
            l = 10 * i;
            draw_line(0, l, l * COS_PI_6, l * SIN_PI_6);
            draw_line(0, l, -l * COS_PI_6, l * SIN_PI_6);
            draw_line(-l * COS_PI_6, -l * SIN_PI_6, -l * COS_PI_6, l * SIN_PI_6);

            draw_line(l * COS_PI_6, l * SIN_PI_6, l * COS_PI_6, -l * SIN_PI_6);
            draw_line(l * COS_PI_6, -l * SIN_PI_6, 0, -l);
            draw_line(0, -l, -l * COS_PI_6, -l * SIN_PI_6);
        }

        set_fill_color(orange);

        draw_triangle(0, stat_nums[0] * 10, stat_nums[1] * 10 * COS_PI_6, stat_nums[1] * 10 * SIN_PI_6, 0, 0);
        draw_triangle(stat_nums[1] * 10 * COS_PI_6, stat_nums[1] * 10 * SIN_PI_6, stat_nums[2] * 10 * COS_PI_6,
                      -stat_nums[2] * 10 * SIN_PI_6, 0, 0);
        draw_triangle(stat_nums[2] * 10 * COS_PI_6, -stat_nums[2] * 10 * SIN_PI_6, 0, -stat_nums[3] * 10, 0, 0);

        draw_triangle(0, stat_nums[0] * 10, -stat_nums[5] * 10 * COS_PI_6, stat_nums[5] * 10 * SIN_PI_6, 0, 0);
        draw_triangle(-stat_nums[5] * 10 * COS_PI_6, stat_nums[5] * 10 * SIN_PI_6, -stat_nums[4] * 10 * COS_PI_6,
                      -stat_nums[4] * 10 * SIN_PI_6, 0, 0);
        draw_triangle(-stat_nums[4] * 10 * COS_PI_6, -stat_nums[4] * 10 * SIN_PI_6, 0, -stat_nums[3] * 10, 0, 0);
    }

    return 0;
}