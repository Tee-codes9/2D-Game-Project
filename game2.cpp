#include <iostream>
#include <stdio.h>///////////////
#include <windows.h>/////////////
#include <conio.h>
using namespace std;

void DrawScreen(unsigned char world[][300], int disC, int disR, int scR, int scC)
{
    for (int i = 0; i < 80; i++)
    {
        for (int j = 0; j < 300; j++)
        {
            world[i][j] = ' ';
        }
    }

    for (int j = 1; j < 299; j++)
    {
        world[0][j] = 205;
        world[79][j] = 205;
    }

    for (int i = 1; i < 79; i++)
    {
        world[i][0] = 186;
        world[i][299] = 186;
        if (i < 30)
        {
            world[i][149] = 186;
        }
        else
        {
            world[i][119] = 186;
        }
    }

    world[0][0] = 201;
    world[0][299] = 187;
    world[0][149] = 203;
    world[79][0] = 200;
    world[79][119] = 202;
    world[79][299] = 188;

    world[39][0] = 204;
    world[39][299] = 185;
    world[39][119] = 206;
    world[59][119] = 185;
    world[79][119] = 202;

    for (int j = 24; j < 119; j++)
    {
        world[59][j] = 177;
    }

    for (int j = 1; j < 2; j++)
    {
        world[39][j] = 177;
    }

    for (int j = 24; j < 299; j++)
    {
        if (j >= 278 && j <= 298)
        {
            world[39][j] = ' ';
        }
        else
        {
            world[39][j] = 177;
        }
    }

    for (int i = 42; i < 119; i++)
    {
        world[58][i] = 177;
    }
    for (int i = 47; i < 119; i++)
    {
        world[57][i] = 177;
    }
    for (int i = 52; i < 119; i++)
    {
        world[56][i] = 177;
    }

    for (int i = 57; i < 119; i++)
    {
        world[55][i] = 177;
    }
    for (int i = 62; i < 119; i++)
    {
        world[54][i] = 177;
    }
    for (int i = 67; i < 119; i++)
    {
        world[53][i] = 177;
    }
    for (int i = 72; i < 119; i++)
    {
        world[52][i] = 177;
    }

    for (int i = 38; i < 106; i++)
    {
        world[20][i] = '-';
        world[39][i] = '-';
    }
    for (int i = 60; i < 75; i++)
    {
        world[28][i] = '-';
    }
    for (int i = 31; i <= 38; i++)
    {
        world[i][170] = 186;
        world[i][230] = 186;
    }

    for (int j = 231; j < 237; j++)
    {
        world[31][j] = 177;
    }
    for (int j = 236; j < 242; j++)
    {
        world[30][j] = 177;
    }
    for (int j = 241; j < 282; j++)
    {
        world[29][j] = 177;
    }
    
    for (int j = 195; j < 280; j++)
    {
        world[67][j] = 177;
    }
}

void DrawPit(unsigned char world[][300], int waveFrame)
{
    int j = 0;
    int row = 0;
    int pos = 0;

    for (row = 34; row <= 38; row++)
    {
        for (j = 171; j <= 229; j++)
        {
            world[row][j] = 177;
        }
    }

    for (j = 171; j <= 229; j++)
    {
        pos = (j + waveFrame) % 4;
        if (pos == 0)
        {
            world[33][j] = '~';
        }
        else
        {
            if (pos == 1)
            {
                world[33][j] = '^';
            }
            else
            {
                if (pos == 2)
                {
                    world[33][j] = '~';
                }
                else
                {
                    world[33][j] = '_';
                }
            }
        }
    }
}

void LaserDraw(unsigned char world[][300], int LaserCol, int LaserLen, int shouldDraw)
{
    int isProtected = 0;
    if (shouldDraw == 0)
    {
        return;
    }
    if (LaserCol >= 38)
    {
        for (int row = 20; row < 40 && row < 80; row++)
        {
            for (int col = LaserCol; col >= LaserCol - LaserLen && col >= 38; col--)
            {
                isProtected = 0;
                if (row >= 28 && row < 40 && col >= 60 && col < 75)
                {
                    isProtected = 1;
                }
                if (isProtected == 0 && world[row][col] == ' ')
                {
                    world[row][col] = '|';
                }
            }
        }
    }
}

void DragonLaserDraw(unsigned char world[][300], int dragonLaserRow, int dragonLaserStartCol, int dragonLaserCol, int dragonLaserLen, int shouldDraw)
{
    int left = 0;
    if (shouldDraw == 0)
    {
        return;
    }
    left = dragonLaserCol - dragonLaserLen;
    if (left < dragonLaserStartCol)
    {
        left = dragonLaserStartCol;
    }
    for (int col = left; col <= dragonLaserCol && col < 278; col++)
    {
        if (world[dragonLaserRow][col] == ' ')
        {
            world[dragonLaserRow][col] = '=';
        }
    }
}

void LaserMove(int& Laser, int& LaserPause, int& LaserPauseCounter, int LaserLen)
{
    if (Laser - LaserLen > 38)
    {
        Laser--;
    }
    else
    {
        LaserPause = 1;
        LaserPauseCounter = 0;
    }
}

void Screen(unsigned char world[][300], int disC, int disR, int scR, int scC)
{
    system("cls");
    for (int i = scR; i < scR + 31 && i < 80; i++)
    {
        for (int l = scC; l <= scC + 119 && l < 300; l++)
        {
            cout << world[i][l];
        }
        cout << "\n";
    }
}

void DrawPlayer(unsigned char world[][300], int pr, int pc, int hold, int gun, int pDir)
{
    char temp[9][20];

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            temp[i][j] = ' ';
        }
        temp[i][19] = '\0';
    }

    char stand[9][15] = {
        "   .-."
        " __|=|__",
        "(_/`-`\\_)",
        "//\\___/\\\\",
        "<>/   \\<>",
        "  |_._|",
        "  <_I_>",
        "   |||",
        "  /_|_\\"
    };
    char right[9][15] = {
        "   .-.",
        " __|=|__",
        "(_/`-`\\_)",
        "//\\___/ \\",
        "<>/   \\<>",
        "  |_._|",
        " <_I_>",
        "  / |",
        " /  |"
    };
    char left[9][15] = {
        "   .-.",
        " __|=|__",
        "(_/`-`\\_)",
        "/ \\___/\\\\",
        "<>/   \\<>",
        "  |_._|",
        "   <_I_>",
        "    | \\",
        "    |  \\"
    };
    char jump[9][15] = {
        "   .-.",
        " __|=|__",
        "(_/`-`\\_)",
        "||\\___/||",
        "<>/   \\<>",
        "  |_._|",
        "  <_I_>", 
        "   (_)",
        "      "
    };

    char right_gun[9][20] = {
         "   .-.",
         " __|!|_",
         "(_/`-`_)_,______,",
         " \\\\ /  __.==--'",
         "  <>`-'<> ",
         "  |___|",
         " <_I_>",
         "  / |",
         " /  |"
    };
    char left_gun[9][20] = {
        "          .-.",
        "         _|!|__",
        ",_____,_(_`-`l_)",
        "`--==.__  \\  //",
        "       <>`-'<>",
        "          |___|", 
        "           <_I_>", 
        "            | \\", 
        "            |  \\"
    };

    int offsetCol = 0;

    if (world[pr + 9][pc] == ' ' && world[pr + 9][pc + 10] == ' ')
    {
        if (gun == 1)
        {
            if (pDir == -1)
            {
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 20 && left_gun[i][j] != '\0'; j++)
                    {
                        temp[i][j] = left_gun[i][j];
                    }
                }
                offsetCol = -7;
            }
            else
            {
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 20 && right_gun[i][j] != '\0'; j++)
                    {
                        temp[i][j] = right_gun[i][j];
                    }
                }
            }
        }
        else
        {
            for (int i = 0; i < 9; i++)
            {
                for (int j = 0; j < 15 && jump[i][j] != '\0'; j++)
                {
                    temp[i][j] = jump[i][j];
                }
            }
        }
    }
    else
    {
        if (hold == 'd' || hold == 'D' || (hold == 'L' && pDir == 1))
        {
            if (gun == 1)
            {
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 20 && right_gun[i][j] != '\0'; j++)
                    {
                        temp[i][j] = right_gun[i][j];
                    }
                }
            }
            else
            {
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 15 && right[i][j] != '\0'; j++)
                    {
                        temp[i][j] = right[i][j];
                    }
                }
            }
        }
        else
        {
            if (hold == 'a' || hold == 'A' || (hold == 'L' && pDir == -1))
            {
                if (gun == 1)
                {
                    for (int i = 0; i < 9; i++)
                    {
                        for (int j = 0; j < 20 && left_gun[i][j] != '\0'; j++)
                        {
                            temp[i][j] = left_gun[i][j];
                        }
                    }
                    offsetCol = -7;
                }
                else
                {
                    for (int i = 0; i < 9; i++)
                    {
                        for (int j = 0; j < 15 && left[i][j] != '\0'; j++)
                        {
                            temp[i][j] = left[i][j];
                        }
                    }
                }
            }
            else
            {
                for (int i = 0; i < 9; i++)
                {
                    for (int j = 0; j < 15 && stand[i][j] != '\0'; j++)
                    {
                        temp[i][j] = stand[i][j];
                    }
                }
            }
        }
    }

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 20 && temp[i][j] != '\0'; j++)
        {
            if (temp[i][j] != ' ')
            {
                int drawC = pc + j + offsetCol;
                if (drawC >= 0 && drawC < 300)
                {
                    world[pr + i][drawC] = temp[i][j];
                }
            }
        }
    }
}

void Spider(unsigned char world[][300], int sr, int sc)
{
    char SpiderShape[10][20] =
    {
        "       _.._",
        "     .'    '.",
        "    /   __   \\",
        " ,  |   ><   |  ,",
        ". \\  \\      /  / .",
        " \\_'--`(  )'--'_/",
        "   .--'/()\\'--.",
        "  /  /` '' `\\  \\",
        "    |        |",
        "     \\      / "
    };
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20 && SpiderShape[i][j] != '\0'; j++)
        {
            if (SpiderShape[i][j] != ' ')
            {
                world[sr + i][sc + j] = SpiderShape[i][j];
            }
        }
    }
}

void Gun(unsigned char world[][300], int gr, int gc, int gunPickedUp)
{
    if (gunPickedUp == 0)
    {
        char rightGun[3][13] =
        {
            " __,______,",
            "/  __.==--'",
            "`-'",
        };
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 13 && rightGun[i][j] != '\0'; j++)
            {
                if (rightGun[i][j] != ' ')
                {
                    world[gr + i][gc + j] = rightGun[i][j];
                }
            }
        }
    }
}

void Snake(unsigned char world[][300], int snr, int snc, int snakeAlive)
{
    if (snakeAlive == 1)
    {
        char SnakeUp[6][20] =
        {
            "            ___",
            "(!\\   .-.   /_'')",
            " \\\\_//^\\\\_//",
            "  `'`   `'`",
        };
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 20 && SnakeUp[i][j] != '\0'; j++)
            {
                if (SnakeUp[i][j] != ' ')
                {
                    world[snr + i][snc + j] = SnakeUp[i][j];
                }
            }
        }
    }
}

void DrawDragon(unsigned char world[][300], int dr, int dc)
{
    char dragon[14][80] =
    {
        "            ______________",
        "         _.-'            ,'.:===,",
        "     _.-'         __.---'`.:`",
        "  .'         .--'     .:'",
        ".'         .'        ./",
        ",.`-,____   .'         ./    ,),,(",
        "       `.___--,   ./   \\`     ',)",
        "       `         `;./   ,'  .--,  ',",
        "                 ;/    :  /    } ,D{`",
        "                 \\    \\  \\    ',,V",
        "  ,    .---,    .\\-, ',  \\    ;;j",
        " \\',   /  _  \\  /  _  \\ ',  \\   ';/",
        "  \\ '.`  / \\  `'  / \\  \\  `' )   ",
        "   `.__,'   `.__,'   `.___,'"
    };
    for (int i = 0; i < 14; i++)
    {
        for (int j = 0; j < 80 && dragon[i][j] != '\0'; j++)
        {
            if (dragon[i][j] != ' ')
            {
                if (dr + i >= 0 && dr + i < 80 && dc + j >= 0 && dc + j < 300)
                {
                    world[dr + i][dc + j] = dragon[i][j];
                }
            }
        }
    }
}

void Elevator(unsigned char world[][300], int startr, int endr, int startc, int endc)
{
    for (int i = startr; i < endr; i++)
    {
        world[i][endc] = 177;
        world[i][startc] = 177;
    }
    for (int i = startc; i <= endc; i++)
    {
        world[endr][i] = 196;
        world[startr][i] = 196;
    }
}

void ElevatorUp(unsigned char world[][300], int& Edir, int& startr, int& endr, int& EisWaiting)
{
    if (endr >= 43)
    {
        endr--;
        startr--;
    }
    else
    {
        EisWaiting = 1;
        Edir = 0;
    }
}

void ElevatorDown(unsigned char world[][300], int& Edir, int& startr, int& endr, int& EisWaiting)
{
    if (endr <= 77)
    {
        endr++;
        startr++;
    }
    else
    {
        EisWaiting = 1;
        Edir = 1;
    }
}

void HorizontalElevator(unsigned char world[][300], int hstartr, int hendr, int hstartc, int hendc)
{
    for (int i = hstartr; i < hendr; i++)
    {
        world[i][hendc] = 177;
        world[i][hstartc] = 177;
    }
    for (int i = hstartc; i <= hendc; i++)
    {
        world[hendr][i] = 196;
        world[hstartr][i] = 196;
    }
}

void HElevatorRight(unsigned char world[][300], int& Edir, int& hstartc, int& hendc, int& HEisWaiting)
{
    if (hendc <= 228)
    {
        hendc++;
        hstartc++;
    }
    else
    {
        HEisWaiting = 1;
        Edir = 0;
    }
}

void HElevatorLeft(unsigned char world[][300], int& HEdir, int& hstartc, int& hendc, int& HEisWaiting)
{
    if (hstartc >= 172)
    {
        hendc--;
        hstartc--;
    }
    else
    {
        HEisWaiting = 1;
        HEdir = 1;
    }
}

int IsSolidForGravity(unsigned char c)
{
    int result = 1;
    if (c == ' ')
    {
        result = 0;
    }
    if (c == '|')
    {
        result = 0;
    }
    if (c == 'o')
    {
        result = 0;
    }
    if (c == '_')
    {
        result = 0;
    }
    if (c == '\\')
    {
        result = 0;
    }
    if (c == '/')
    {
        result = 0;
    }
    if (c == '.')
    {
        result = 0;
    }
    if (c == '*')
    {
        result = 0;
    }
    if (c == '+')
    {
        result = 0;
    }
    if (c == '~')
    {
        result = 0;
    }
    if (c == '^')
    {
        result = 0;
    }
    if (c == '#')
    {
        result = 0;
    }
    if (c == 179)
    {
        result = 0;
    }
    return result;
}

int IsSolidCeiling(unsigned char c)
{
    int result = 1;
    if (c == ' ')
    {
        result = 0;
    }
    if (c == '=')
    {
        result = 0;
    }
    if (c == 'o')
    {
        result = 0;
    }
    if (c == '_')
    {
        result = 0;
    }
    if (c == '\\')
    {
        result = 0;
    }
    if (c == '/')
    {
        result = 0;
    }
    if (c == '.')
    {
        result = 0;
    }
    if (c == '*')
    {
        result = 0;
    }
    if (c == '+')
    {
        result = 0;
    }
    if (c == '~')
    {
        result = 0;
    }
    if (c == '^')
    {
        result = 0;
    }
    if (c == '#')
    {
        result = 0;
    }
    if (c == 179)
    {
        result = 0;
    }
    if (c == 196)
    {
        result = 0;
    }
    if (c == '|')
    {
        result = 0;
    }
    return result;
}

int IsSolidForBullet(unsigned char c)
{
    int result = 1;
    if (c == ' ')
    {
        result = 0;
    }
    if (c == '|')
    {
        result = 0;
    }
    if (c == '~')
    {
        result = 0;
    }
    if (c == '^')
    {
        result = 0;
    }
    if (c == '_')
    {
        result = 0;
    }
    if (c == '.')
    {
        result = 0;
    }
    if (c == '*')
    {
        result = 0;
    }
    if (c == '+')
    {
        result = 0;
    }
    if (c == 'o')
    {
        result = 0;
    }
    if (c == 179)
    {
        result = 0;
    }
    if (c == 196)
    {
        result = 0;
    }
    return result;
}

int Gravity(unsigned char world[][300], int& pr, int pc, int startr, int startc, int endc)
{
    int air = 0;
    int result = 0;
    if (IsSolidForGravity(world[pr + 9][pc + 3]) == 1)
    {
        air = 1;
    }
    if (air == 0 && pr < 70)
    {
        pr++;
    }
    else
    {
        if (pr + 9 == startr && pc + 5 >= startc && pc + 5 <= endc && pr + 9 != ' ')
        {
            result = 1;
        }
    }
    return result;
}

int Passable(unsigned char world[][300], int row, int col)
{
    int result = 0;
    if (world[row][col] == ' ')
    {
        result = 1;
    }
    if (world[row][col] == '|')
    {
        result = 1;
    }
    if (world[row][col] == '=')
    {
        result = 1;
    }
    if (world[row][col] == 'o')
    {
        result = 1;
    }
    if (world[row][col] == '_')
    {
        result = 1;
    }
    if (world[row][col] == '\\')
    {
        result = 1;
    }
    if (world[row][col] == '/')
    {
        result = 1;
    }
    if (world[row][col] == '.')
    {
        result = 1;
    }
    if (world[row][col] == '*')
    {
        result = 1;
    }
    if (world[row][col] == '+')
    {
        result = 1;
    }
    if (world[row][col] == '-')
    {
        result = 1;
    }
    if (world[row][col] == 179)
    {
        result = 1;
    }
    if (world[row][col] == 196)
    {
        result = 1;
    }
    return result;
}

void PlayerJump(unsigned char world[][300], int& pr, int pc, int spiderKeyCollected)
{
    int jump = 1;
    for (int i = 0; i < 2; i++)
    {
        jump = 1;
        for (int j = 0; j < 9; j++)
        {
            if (IsSolidCeiling(world[pr - 1][pc + j]) == 1)
            {
                jump = 0;
                break;
            }
        }
        if (jump == 1 && pr > 0)
        {
            pr -= 5;
            if (spiderKeyCollected == 0 && pr < 40)
            {
                pr = 40;
            }
        }
    }
}

void PlayerJumpLeft(unsigned char world[][300], int& pr, int& pc, int spiderKeyCollected)
{
    int jump = 1;
    for (int i = 0; i < 2; i++)
    {
        jump = 1;
        for (int j = 0; j < 9; j++)
        {
            if (IsSolidCeiling(world[pr - 1][pc - j]) == 1)
            {
                jump = 0;
                break;
            }
        }
        if (jump == 1 && pr > 0)
        {
            pr -= 5;
            pc -= 5;
            if (spiderKeyCollected == 0 && pr < 40)
            {
                pr = 40;
            }
        }
    }
}

void PlayerJumpRight(unsigned char world[][300], int& pr, int& pc, int spiderKeyCollected)
{
    int jump = 1;
    for (int i = 0; i < 2; i++)
    {
        jump = 1;
        for (int j = 0; j < 9; j++)
        {
            if (IsSolidCeiling(world[pr - 1][pc + j]) == 1)
            {
                jump = 0;
                break;
            }
        }
        if (jump == 1 && pr > 0)
        {
            pr -= 7;
            pc += 5;
            if (spiderKeyCollected == 0 && pr < 40)
            {
                pr = 40;
            }
        }
    }
}

void MovePlayer(unsigned char world[][300], int& pr, int& pc, int& disC, int& disR, int& scR, int& scC, int hold, int spiderKeyCollected)
{
    int standing = 0;
    if (hold == 'a' && pc > 1 && Passable(world, pr + 4, pc - 1) == 1)
    {
        pc--;
        if (scC > 0 && pc < scC + 40)
        {
            scC--;
            disC--;
        }
    }
    else
    {
        if (hold == 'd' && Passable(world, pr + 4, pc + 9) == 1 && Passable(world, pr + 8, pc + 5) == 1 && pc < 290)
        {
            pc++;
            if (pc > scC + 35 && scC + 119 < 299)
            {
                disC++;
                scC++;
            }
        }
        else
        {
            if (hold == 'w' && Passable(world, pr - 1, pc + 5) == 1 && pr > 1)
            {
                pr--;
            }
            else
            {
                if (hold == 's' && Passable(world, pr + 9, pc + 5) == 1 && pr < 70)
                {
                    pr++;
                }
                else
                {
                    if (hold == ' ')
                    {
                        standing = 0;
                        for (int i = 0; i < 12; i++)
                        {
                            if (Passable(world, pr + 9, pc + i) == 0)
                            {
                                standing = 1;
                                break;
                            }
                        }
                        if (standing == 1)
                        {
                            PlayerJump(world, pr, pc, spiderKeyCollected);
                        }
                    }
                    else
                    {
                        if (hold == 'q' || hold == 'Q')
                        {
                            standing = 0;
                            for (int i = 0; i < 12; i++)
                            {
                                if (Passable(world, pr + 9, pc - i) == 0)
                                {
                                    standing = 1;
                                    break;
                                }
                            }
                            if (standing == 1)
                            {
                                PlayerJumpLeft(world, pr, pc, spiderKeyCollected);
                            }
                        }
                        else
                        {
                            if (hold == 'e' || hold == 'E')
                            {
                                standing = 0;
                                for (int i = 0; i < 12; i++)
                                {
                                    if (Passable(world, pr + 9, pc + i) == 0)
                                    {
                                        standing = 1;
                                        break;
                                    }
                                }
                                if (standing == 1)
                                {
                                    PlayerJumpRight(world, pr, pc, spiderKeyCollected);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void SnapCamera(int pr, int pc, int& scR, int& scC, int& disR, int& disC)
{
    scC = pc - 50;
    if (scC < 0)
    {
        scC = 0;
    }
    if (scC + 119 > 299)
    {
        scC = 180;
    }

    scR = pr - 15;
    if (scR < 0)
    {
        scR = 0;
    }
    if (scR + 30 > 79)
    {
        scR = 49;
    }

    disC = scC + 120;
    disR = scR + 40;
}

void DrawPowerUp(unsigned char world[][300], int puRow, int puCol, int collected)
{
    if (collected == 0)
    {
        world[puRow + 0][puCol + 0] = '\\';
        world[puRow + 0][puCol + 1] = '_';
        world[puRow + 0][puCol + 2] = '_';
        world[puRow + 0][puCol + 3] = '/';
        world[puRow + 1][puCol + 0] = '/';
        world[puRow + 1][puCol + 1] = ' ';
        world[puRow + 1][puCol + 2] = ' ';
        world[puRow + 1][puCol + 3] = '\\';
    }
}

int PlayerTouchesPowerUp(int pr, int pc, int puRow, int puCol)
{
    int result = 0;
    if (pc + 3 <= puCol + 3 && pc + 10 >= puCol)
    {
        if (pr + 1 <= puRow + 1 && pr + 8 >= puRow)
        {
            result = 1;
        }
    }
    return result;
}

void DrawCheckpoint(unsigned char world[][300], int cpRow, int cpCol, int reached)
{
    if (reached == 1)
    {
        world[cpRow + 0][cpCol + 0] = 'o';
        world[cpRow + 0][cpCol + 1] = '_';
        world[cpRow + 0][cpCol + 2] = '_';
        world[cpRow + 0][cpCol + 3] = '_';
        world[cpRow + 0][cpCol + 4] = '_';
        world[cpRow + 1][cpCol + 0] = '|';
        world[cpRow + 1][cpCol + 1] = '\\';
        world[cpRow + 1][cpCol + 2] = '/';
        world[cpRow + 1][cpCol + 3] = '/';
        world[cpRow + 1][cpCol + 4] = '|';
        world[cpRow + 2][cpCol + 0] = '|';
        world[cpRow + 2][cpCol + 1] = '/';
        world[cpRow + 2][cpCol + 2] = '/';
        world[cpRow + 2][cpCol + 3] = '\\';
        world[cpRow + 2][cpCol + 4] = '|';
        world[cpRow + 3][cpCol + 0] = '|';
        world[cpRow + 4][cpCol + 0] = '|';
    }
    else
    {
        world[cpRow + 0][cpCol + 0] = 'o';
        world[cpRow + 0][cpCol + 1] = '_';
        world[cpRow + 0][cpCol + 2] = '_';
        world[cpRow + 0][cpCol + 3] = '_';
        world[cpRow + 0][cpCol + 4] = '_';
        world[cpRow + 1][cpCol + 0] = '|';
        world[cpRow + 1][cpCol + 1] = ' ';
        world[cpRow + 1][cpCol + 2] = ' ';
        world[cpRow + 1][cpCol + 3] = ' ';
        world[cpRow + 1][cpCol + 4] = '|';
        world[cpRow + 2][cpCol + 0] = '|';
        world[cpRow + 2][cpCol + 1] = ' ';
        world[cpRow + 2][cpCol + 2] = ' ';
        world[cpRow + 2][cpCol + 3] = ' ';
        world[cpRow + 2][cpCol + 4] = '|';
        world[cpRow + 3][cpCol + 0] = '|';
        world[cpRow + 4][cpCol + 0] = '|';
    }
}

void DrawKey(unsigned char world[][300], int kRow, int kCol, int collected)
{
    if (collected == 0)
    {
        world[kRow + 0][kCol + 0] = '-';
        world[kRow + 0][kCol + 1] = 'o';
        world[kRow + 1][kCol + 0] = ' ';
        world[kRow + 1][kCol + 1] = '|';
        world[kRow + 2][kCol + 0] = '-';
        world[kRow + 2][kCol + 1] = '+';
        world[kRow + 2][kCol + 2] = '-';
    }
}

int PlayerTouchesKey(int pr, int pc, int kRow, int kCol)
{
    int result = 0;
    if (pc + 3 <= kCol + 2 && pc + 10 >= kCol)
    {
        if (pr + 1 <= kRow + 2 && pr + 8 >= kRow)
        {
            result = 1;
        }
    }
    return result;
}

int PlayerTouchesGun(int pr, int pc, int gr, int gc)
{
    int result = 0;
    if (pc + 3 <= gc + 10 && pc + 10 >= gc)
    {
        if (pr + 1 <= gr + 2 && pr + 8 >= gr)
        {
            result = 1;
        }
    }
    return result;
}

void DrawGateH(unsigned char world[][300], int gateRow, int gateColStart, int gateColEnd, int unlocked)
{
    int j = 0;
    if (unlocked == 0)
    {
        for (j = gateColStart; j <= gateColEnd; j++)
        {
            world[gateRow][j] = '=';
        }
    }
}

void DrawLadder(unsigned char world[][300], int startRow, int endRow, int col, int unlocked)
{
    if (unlocked == 1)
    {
        for (int i = startRow + 1; i <= endRow; i += 2)
        {
            world[i][col] = '|';
            if (i % 2 == 0)
            {
                for (int j = 1; j <= 17; j++)
                {
                    world[i][col + j] = '-';
                    world[i][col + j + 1] = '|';
                }
            }
        }
    }
}

int BulletHitsSpider(int br, int bc, int sr, int sc, int spiderAlive)
{
    int result = 0;
    if (spiderAlive == 1)
    {
        if (br >= sr && br <= sr + 9 && bc >= sc && bc <= sc + 19)
        {
            result = 1;
        }
    }
    return result;
}

int BulletHitsSnake(int br, int bc, int snr, int snc, int snakeAlive)
{
    int result = 0;
    if (snakeAlive == 1)
    {
        if (br >= snr && br <= snr + 3 && bc >= snc && bc <= snc + 19)
        {
            result = 1;
        }
    }
    return result;
}

int BulletHitsDragon(int br, int bc, int dr, int dc, int dragonAlive)
{
    int result = 0;
    if (dragonAlive == 1)
    {
        if (br >= dr && br <= dr + 13 && bc >= dc && bc <= dc + 39)
        {
            result = 1;
        }
    }
    return result;
}

int MoveBullet(unsigned char world[][300], int& br, int& bc, int bdir,
    int sr, int sc, int& spiderAlive, int& key_visible0,
    int snr, int snc, int& snakeAlive, int& key_visible2,
    int dr, int dc, int& dragonAlive, int& dragonHealth, int& key_visible3)
{
    int result = 0;
    bc = bc + bdir * 2;

    if (bc < 1 || bc >= 299)
    {
        result = 1;
    }
    else
    {
        if (BulletHitsSpider(br, bc, sr, sc, spiderAlive) == 1)
        {
            spiderAlive = 0;
            key_visible0 = 1;
            result = 1;
        }
        else
        {
            if (BulletHitsSnake(br, bc, snr, snc, snakeAlive) == 1)
            {
                snakeAlive = 0;
                key_visible2 = 1;
                result = 1;
            }
            else
            {
                if (BulletHitsDragon(br, bc, dr, dc, dragonAlive) == 1)
                {
                    dragonHealth--;
                    if (dragonHealth <= 0)
                    {
                        dragonAlive = 0;
                        key_visible3 = 1;
                    }
                    result = 1;
                }
                else
                {
                    if (br >= 0 && br < 80 && bc >= 0 && bc < 300)
                    {
                        if (IsSolidForBullet(world[br][bc]) == 1)
                        {
                            result = 1;
                        }
                    }
                }
            }
        }
    }
    return result;
}

void DrawBullet(unsigned char world[][300], int br, int bc, int bdir)
{
    if (br >= 0 && br < 80 && bc >= 0 && bc < 300)
    {
        if (bdir == 1)
        {
            world[br][bc] = '>';
        }
        else
        {
            world[br][bc] = '<';
        }
    }
}

int main()
{
    unsigned char world[80][300];
    char hold = 'L';

    int startr = 75, endr = 78, startc = 3, endc = 22, Edir = 1;
    int EwaitCounter = 0;
    int EisWaiting = 0;

    int hstartr = 30, hendr = 33, hstartc = 171, hendc = 191, HEdir = 1;
    int HEwaitCounter = 0;
    int HEisWaiting = 0;

    int pr = 60, pc = 66, pDir = 1;

    int sr = 41, sc = 98;
    int spiderShake = 0;
    int spiderAlive = 1;

    int snr = 33, snc = 232;
    int snakeAlive = 1;
    int snakeTriggered = 0;
    int snakeDir = 0;
    int snakeMoveTimer = 0;

    int dr = 55, dc = 150;
    int dragonAlive = 1;
    int dragonHealth = 3;

    int DragonLaserRow = dr + 7;
    int DragonLaserStartCol = dc + 40;
    int DragonLaserCol = DragonLaserStartCol;
    int DragonLaserLen = 0;
    int DragonLaserPause = 0;
    int DragonLaserPauseCounter = 0;
    int DragonLaserPhase = 0;
    int DragonLaserVisible = 1;
    int DragonLaserHitCooldown = 0;

    int gr = 55, gc = 29;
    int gunPickedUp = 0;
    int gun = 0;

    int disC = 145, disR = 80;
    int scC = 0, scR = 49;

    int sBulletR = 0, sBulletC = 0, sBulletDir = 0, sBulletActive = 0;

    int bBulletR[10], bBulletC[10], bBulletDir[10], bBulletActive[10];
    int bulletsInFlight = 0;
    for (int i = 0; i < 10; i++)
    {
        bBulletR[i] = 0;
        bBulletC[i] = 0;
        bBulletDir[i] = 0;
        bBulletActive[i] = 0;
    }

    int mode = 1;

    int LaserPause = 0;
    int LaserPauseCounter = 0;
    int Laser = 105;
    int LaserLen = 15;
    int LaserStartDisappear = 0;
    int LaserVisible = 1;

    int cp_pr[5] = { 69, 29, 29, 29, 0 };
    int cp_pc[5] = { 25, 27, 122, 255, 0 };
    int cp_reached[5] = { 1, 0, 0, 0, 0 };
    int cpFlag_row[5] = { 74, 34, 34, 34, 0 };
    int cpFlag_col[5] = { 25, 27, 122, 255, 0 };

    int playerHealth = 100;
    int playerMaxHealth = 100;
    int playerLives = 3;
    int spawn_pr = cp_pr[0];
    int spawn_pc = cp_pc[0];

    int old_startr = 0;
    int diff = 0;
    int onElevator = 0;

    int old_hstartc = 171;
    int old_hendc = 191;
    int hdiff = 0;
    int onHElevator = 0;

    int hitLaser = 0;
    int laserLeft = 0;
    int laserRight = 0;
    int playerLeft = 0;
    int playerRight = 0;
    int playerTop = 0;
    int playerBottom = 0;
    int inSafeZone = 0;

    int hitLaserMove = 0;
    int laserLeft2 = 0;
    int laserRight2 = 0;
    int playerLeft2 = 0;
    int playerRight2 = 0;
    int playerTop2 = 0;
    int playerBottom2 = 0;
    int inSafeZone2 = 0;

    int hbRow = 0;
    int hbCol = 0;
    int hbLen = 20;
    int filled = 0;

    int waveFrame = 0;
    int waveCounter = 0;

    int inPit = 0;

    int pu_row[3] = { 37, 37, 37 };
    int pu_col[3] = { 30, 155, 270 };
    int pu_collected[3] = { 0, 0, 0 };

    int burstTimer = 0;

    int key_row[4] = { 41, 36, 34, 76 };
    int key_col[4] = { 98, 134, 232, 210 };
    int key_visible[4] = { 0, 1, 0, 0 };
    int key_collected[4] = { 0, 0, 0, 0 };

    int gate0_row = 39;
    int gate0_colStart = 3;
    int gate0_colEnd = 22;
    int gate1_row = 30;
    int gate1_colStart = 148;
    int gate1_colEnd = 169;
    int gate2_row = 39;
    int gate2_colStart = 278;
    int gate2_colEnd = 298;

    DrawScreen(world, disC, disR, scR, scC);

    SnapCamera(pr, pc, scR, scC, disR, disC);

    while (1)
    {
        while (_kbhit() == 0)
        {
            old_startr = startr;
            old_hstartc = hstartc;
            old_hendc = hendc;

            if (EisWaiting == 1)
            {
                EwaitCounter++;
                if (EwaitCounter > 60)
                {
                    EisWaiting = 0;
                    EwaitCounter = 0;
                }
            }
            else
            {
                if (Edir == 1)
                {
                    ElevatorUp(world, Edir, startr, endr, EisWaiting);
                }
                else
                {
                    ElevatorDown(world, Edir, startr, endr, EisWaiting);
                }
            }

            if (HEisWaiting == 1)
            {
                HEwaitCounter++;
                if (HEwaitCounter > 20)
                {
                    HEisWaiting = 0;
                    HEwaitCounter = 0;
                }
            }
            else
            {
                if (HEdir == 1)
                {
                    HElevatorRight(world, HEdir, hstartc, hendc, HEisWaiting);
                }
                else
                {
                    HElevatorLeft(world, HEdir, hstartc, hendc, HEisWaiting);
                }
            }

            if (LaserPause == 1)
            {
                LaserPauseCounter++;
                LaserVisible = 0;
                if (LaserPauseCounter > 33)
                {
                    LaserPause = 0;
                    LaserPauseCounter = 0;
                    Laser = 105;
                    LaserLen = 15;
                    LaserStartDisappear = 0;
                    LaserVisible = 1;
                }
            }
            else
            {
                if (Laser - LaserLen <= 38 && LaserStartDisappear == 0)
                {
                    LaserStartDisappear = 1;
                }

                if (LaserStartDisappear == 1)
                {
                    Laser--;
                    LaserLen--;
                    if (LaserLen <= 0)
                    {
                        LaserPause = 1;
                        LaserPauseCounter = 0;
                        LaserLen = 15;
                    }
                }
                else
                {
                    Laser--;
                }
            }

            if (dragonAlive == 1)
            {
                if (DragonLaserPause == 1)
                {
                    DragonLaserPauseCounter++;
                    DragonLaserVisible = 0;
                    if (DragonLaserPauseCounter > 25)
                    {
                        DragonLaserPause = 0;
                        DragonLaserPauseCounter = 0;
                        DragonLaserCol = DragonLaserStartCol;
                        DragonLaserLen = 0;
                        DragonLaserPhase = 0;
                        DragonLaserVisible = 1;
                    }
                }
                else
                {
                    if (DragonLaserPhase == 0)
                    {
                        DragonLaserCol++;
                        if (DragonLaserLen < DragonLaserCol - DragonLaserStartCol)
                        {
                            DragonLaserLen = DragonLaserCol - DragonLaserStartCol;
                        }
                        if (DragonLaserCol >= 277)
                        {
                            DragonLaserCol = 277;
                            DragonLaserPhase = 1;
                        }
                    }
                    else
                    {
                        DragonLaserLen--;
                        if (DragonLaserLen <= 0)
                        {
                            DragonLaserPause = 1;
                            DragonLaserPauseCounter = 0;
                        }
                    }
                }
            }
            else
            {
                DragonLaserVisible = 0;
            }

            if (DragonLaserHitCooldown > 0)
            {
                DragonLaserHitCooldown--;
            }

            waveCounter++;
            if (waveCounter >= 8)
            {
                waveCounter = 0;
                waveFrame++;
                if (waveFrame >= 4)
                {
                    waveFrame = 0;
                }
            }

            if (burstTimer > 0)
            {
                burstTimer--;
                if (burstTimer == 0)
                {
                    mode = 1;
                }
            }

            diff = startr - old_startr;

            onElevator = 0;
            if (pr + 9 == old_startr && pc + 5 >= startc && pc + 2 <= endc)
            {
                onElevator = 1;
            }

            if (onElevator == 1)
            {
                pr += diff;
                if (key_collected[0] == 0 && pr < 40)
                {
                    pr = 40;
                }
            }

            hdiff = hstartc - old_hstartc;

            onHElevator = 0;
            if (pr + 9 == hstartr && pc + 5 >= hstartc && pc + 5 <= hendc)
            {
                onHElevator = 1;
            }

            if (onHElevator == 1)
            {
                pc += hdiff;
            }

            if (onHElevator == 1)
            {
                if (pc > scC + 35 && scC + 119 < 299)
                {
                    disC++;
                    scC++;
                }
                if (scC > 0 && pc < scC + 40)
                {
                    scC--;
                    disC--;
                }
            }

            if (sBulletActive == 1)
            {
                int hit = MoveBullet(world, sBulletR, sBulletC, sBulletDir,
                    sr, sc, spiderAlive, key_visible[0],
                    snr, snc, snakeAlive, key_visible[2],
                    dr, dc, dragonAlive, dragonHealth, key_visible[3]);
                if (hit == 1)
                {
                    sBulletActive = 0;
                }
            }

            for (int i = 0; i < 10; i++)
            {
                if (bBulletActive[i] == 1)
                {
                    int hit = MoveBullet(world, bBulletR[i], bBulletC[i], bBulletDir[i],
                        sr, sc, spiderAlive, key_visible[0],
                        snr, snc, snakeAlive, key_visible[2],
                        dr, dc, dragonAlive, dragonHealth, key_visible[3]);
                    if (hit == 1)
                    {
                        bBulletActive[i] = 0;
                        bulletsInFlight--;
                        if (bulletsInFlight < 0)
                        {
                            bulletsInFlight = 0;
                        }
                    }
                }
            }

            DrawScreen(world, disC, disR, scR, scC);
            Elevator(world, startr, endr, startc, endc);
            HorizontalElevator(world, hstartr, hendr, hstartc, hendc);
            LaserDraw(world, Laser, LaserLen, LaserVisible);
            DrawPit(world, waveFrame);

            DrawPowerUp(world, pu_row[0], pu_col[0], pu_collected[0]);
            DrawPowerUp(world, pu_row[1], pu_col[1], pu_collected[1]);
            DrawPowerUp(world, pu_row[2], pu_col[2], pu_collected[2]);

            DrawCheckpoint(world, cpFlag_row[0], cpFlag_col[0], cp_reached[0]);
            DrawCheckpoint(world, cpFlag_row[1], cpFlag_col[1], cp_reached[1]);
            DrawCheckpoint(world, cpFlag_row[2], cpFlag_col[2], cp_reached[2]);
            DrawCheckpoint(world, cpFlag_row[3], cpFlag_col[3], cp_reached[3]);
            DrawCheckpoint(world, cpFlag_row[4], cpFlag_col[4], cp_reached[4]);

            if (key_visible[0] == 1)
            {
                DrawKey(world, key_row[0], key_col[0], key_collected[0]);
            }
            if (key_visible[1] == 1)
            {
                DrawKey(world, key_row[1], key_col[1], key_collected[1]);
            }
            if (key_visible[2] == 1)
            {
                key_row[2] = snr + 3;
                key_col[2] = snc + 8;
                DrawKey(world, key_row[2], key_col[2], key_collected[2]);
            }
            if (key_visible[3] == 1)
            {
                DrawKey(world, key_row[3], key_col[3], key_collected[3]);
            }

            DrawLadder(world, 39, 78, 279, 1);

            DrawGateH(world, gate0_row, gate0_colStart, gate0_colEnd, key_collected[0]);
            DrawGateH(world, gate1_row, gate1_colStart, gate1_colEnd, key_collected[1]);
            DrawGateH(world, gate2_row, gate2_colStart, gate2_colEnd, key_collected[2]);

            Gun(world, gr, gc, gunPickedUp);

            if (spiderAlive == 1)
            {
                if (spiderShake == 0)
                {
                    sc++;
                    spiderShake = 1;
                }
                else
                {
                    sc--;
                    spiderShake = 0;
                }
                Spider(world, sr, sc);
            }

            if (snakeAlive == 1)
            {
                if (pc >= 180 && pc <= 299 && pr < 45)
                {
                    snakeTriggered = 1;
                }
            }

            if (snakeAlive == 1)
            {
                if (snakeTriggered == 1)
                {
                    snakeMoveTimer++;
                    if (snakeMoveTimer >= 4)
                    {
                        snakeMoveTimer = 0;
                        if (snakeDir == 0)
                        {
                            snc++;
                            if (snc >= 298)
                            {
                                snakeDir = 1;
                            }
                        }
                        else
                        {
                            if (snakeDir == 1)
                            {
                                snc--;
                                if (snc <= 232)
                                {
                                    snakeDir = 0;
                                }
                            }
                        }
                    }
                }
            }
            Snake(world, snr, snc, snakeAlive);

            if (dragonAlive == 1)
            {
                DrawDragon(world, dr, dc);
            }

            DragonLaserDraw(world, DragonLaserRow, DragonLaserStartCol, DragonLaserCol, DragonLaserLen, DragonLaserVisible);

            if (sBulletActive == 1)
            {
                DrawBullet(world, sBulletR, sBulletC, sBulletDir);
            }
            for (int i = 0; i < 10; i++)
            {
                if (bBulletActive[i] == 1)
                {
                    DrawBullet(world, bBulletR[i], bBulletC[i], bBulletDir[i]);
                }
            }

            int onLadder = 0;
            if (key_collected[2] == 1 && pc >= 275 && pc <= 295 && pr >= 30 && pr <= 78)
            {
                onLadder = 1;
            }

            if (onElevator == 0 && onLadder == 0)
            {
                Gravity(world, pr, pc, startr, startc, endc);
            }

            if (pr < scR + 22 && scR > 0)
            {
                scR--;
                disR--;
            }
            if (pr > scR + 15 && scR + 30 < 79)
            {
                scR++;
                disR++;
            }

            DrawPlayer(world, pr, pc, hold, gun, pDir);
            hold = 'L';

            if (gunPickedUp == 0 && PlayerTouchesGun(pr, pc, gr, gc) == 1)
            {
                gunPickedUp = 1;
            }

            if (cp_reached[0] == 1 && cp_reached[1] == 0 && pc + 5 >= 27 && pc + 5 <= 40 && pr + 9 >= 37)
            {
                cp_reached[1] = 1;
                spawn_pr = cp_pr[1];
                spawn_pc = cp_pc[1];
            }
            if (cp_reached[1] == 1 && cp_reached[2] == 0 && pc + 5 >= 122 && pc + 5 <= 140 && pr + 9 >= 37)
            {
                cp_reached[2] = 1;
                spawn_pr = cp_pr[2];
                spawn_pc = cp_pc[2];
            }
            if (cp_reached[2] == 1 && cp_reached[3] == 0 && pc + 5 >= 250 && pc + 5 <= 265 && pr + 9 >= 37)
            {
                cp_reached[3] = 1;
                spawn_pr = cp_pr[3];
                spawn_pc = cp_pc[3];
            }
            if (pu_collected[0] == 0 && PlayerTouchesPowerUp(pr, pc, pu_row[0], pu_col[0]) == 1)
            {
                pu_collected[0] = 1;
                mode = 2;
                burstTimer = 667;
            }
            if (pu_collected[1] == 0 && PlayerTouchesPowerUp(pr, pc, pu_row[1], pu_col[1]) == 1)
            {
                pu_collected[1] = 1;
                mode = 2;
                burstTimer = 667;
            }
            if (pu_collected[2] == 0 && PlayerTouchesPowerUp(pr, pc, pu_row[2], pu_col[2]) == 1)
            {
                pu_collected[2] = 1;
                mode = 2;
                burstTimer = 667;
            }

            if (key_visible[0] == 1 && key_collected[0] == 0 && PlayerTouchesKey(pr, pc, key_row[0], key_col[0]) == 1)
            {
                key_collected[0] = 1;
            }
            if (key_visible[1] == 1 && key_collected[1] == 0 && PlayerTouchesKey(pr, pc, key_row[1], key_col[1]) == 1)
            {
                key_collected[1] = 1;
            }
            if (key_visible[2] == 1 && key_collected[2] == 0 && PlayerTouchesKey(pr, pc, key_row[2], key_col[2]) == 1)
            {
                key_collected[2] = 1;
            }
            if (key_visible[3] == 1 && key_collected[3] == 0 && PlayerTouchesKey(pr, pc, key_row[3], key_col[3]) == 1)
            {
                system("cls");
                cout << "Game Over!\n";
                cout << "You Won!\n";
                return 0;
            }

            inPit = 0;
            if (pc + 3 >= 171 && pc + 10 <= 229)
            {
                if (pr + 9 >= 33 && pr + 9 <= 38)
                {
                    inPit = 1;
                }
            }

            if (inPit == 1)
            {
                playerHealth = 0;
            }

            hitLaser = 0;
            if (LaserVisible == 1)
            {
                laserLeft = Laser - LaserLen;
                laserRight = Laser;
                if (laserLeft < 38)
                {
                    laserLeft = 38;
                }
                playerLeft = pc + 3;
                playerRight = pc + 10;
                playerTop = pr + 1;
                playerBottom = pr + 7;

                if (playerLeft <= laserRight && playerRight >= laserLeft)
                {
                    if (playerTop <= 39 && playerBottom >= 20)
                    {
                        inSafeZone = 0;
                        if (playerLeft >= 60 && playerRight <= 75 && playerTop >= 28 && playerBottom < 40)
                        {
                            inSafeZone = 1;
                        }
                        if (inSafeZone == 0)
                        {
                            hitLaser = 1;
                        }
                    }
                }
            }

            if (hitLaser == 1)
            {
                playerHealth -= 10;
                pc -= 5;
                if (pc < 1)
                {
                    pc = 1;
                }
            }

            if (DragonLaserVisible == 1 && DragonLaserHitCooldown == 0)
            {
                playerLeft = pc + 3;
                playerRight = pc + 10;
                playerTop = pr + 1;
                playerBottom = pr + 8;

                int beamLeft = DragonLaserCol - DragonLaserLen;
                if (beamLeft < DragonLaserStartCol)
                {
                    beamLeft = DragonLaserStartCol;
                }

                if (playerTop <= DragonLaserRow && playerBottom >= DragonLaserRow)
                {
                    if (playerLeft <= DragonLaserCol && playerRight >= beamLeft)
                    {
                        playerHealth -= 20;
                        DragonLaserHitCooldown = 133;
                    }
                }
            }

            if (snakeAlive == 1)
            {
                if (pc + 10 >= snc && pc + 3 <= snc + 19)
                {
                    if (pr + 8 >= snr && pr + 1 <= snr + 3)
                    {
                        playerHealth = 0;
                    }
                }
            }

            if (playerHealth <= 0)
            {
                playerLives--;
                if (playerLives <= 0)
                {
                    system("cls");
                    cout << "Game Over!\n";
                    cout << "You Lost!\n";
                    return 0;
                }
                pr = spawn_pr;
                pc = spawn_pc;
                playerHealth = playerMaxHealth;
                DragonLaserHitCooldown = 0;

                SnapCamera(pr, pc, scR, scC, disR, disC);
            }

            hbRow = scR;
            hbCol = scC;
            hbLen = 20;
            filled = (playerHealth * hbLen) / playerMaxHealth;
            for (int i = 0; i < hbLen; i++)
            {
                if (i < filled)
                {
                    world[hbRow][hbCol + i] = 219;
                }
                else
                {
                    world[hbRow][hbCol + i] = '-';
                }
            }
            if (hbRow < 80 && hbCol + hbLen + 5 < 300)
            {
                world[hbRow][hbCol + hbLen + 1] = 'L';
                world[hbRow][hbCol + hbLen + 2] = ':';
                if (playerLives < 10)
                {
                    world[hbRow][hbCol + hbLen + 3] = '0' + playerLives;
                }
            }

            if (gun == 1)
            {
                world[hbRow][hbCol + hbLen + 5] = '[';
                if (mode == 1)
                {
                    world[hbRow][hbCol + hbLen + 6] = 'S';
                }
                else
                {
                    world[hbRow][hbCol + hbLen + 6] = 'B';
                }
                world[hbRow][hbCol + hbLen + 7] = ']';
            }

            Screen(world, disC, disR, scR, scC);
            Sleep(15);
        }
        hold = _getch();

        if (hold == '1')
        {
            if (gunPickedUp == 1)
            {
                if (gun == 0)
                {
                    gun = 1;
                }
                else
                {
                    gun = 0;
                }
            }
        }
        else
        {
            if (hold == 'f' || hold == 'F')
            {
                if (gun == 1)
                {
                    if (mode == 1)
                    {
                        if (sBulletActive == 0)
                        {
                            sBulletActive = 1;
                            sBulletR = pr + 3;
                            if (pDir == 1)
                            {
                                sBulletC = pc + 17;
                            }
                            else
                            {
                                sBulletC = pc - 8;
                            }
                            sBulletDir = pDir;
                        }
                    }
                    else
                    {
                        if (bulletsInFlight < 10)
                        {
                            for (int i = 0; i < 10; i++)
                            {
                                if (bBulletActive[i] == 0)
                                {
                                    bBulletActive[i] = 1;
                                    bBulletR[i] = pr + 3;
                                    if (pDir == 1)
                                    {
                                        bBulletC[i] = pc + 17;
                                    }
                                    else
                                    {
                                        bBulletC[i] = pc - 8;
                                    }
                                    bBulletDir[i] = pDir;
                                    bulletsInFlight++;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                if (hold == 'd' || hold == 'D')
                {
                    pDir = 1;
                }
                if (hold == 'a' || hold == 'A')
                {
                    pDir = -1;
                }
                MovePlayer(world, pr, pc, disC, disR, scR, scC, hold, key_collected[0]);
            }
        }

        hitLaserMove = 0;
        if (LaserVisible == 1)
        {
            laserLeft2 = Laser - LaserLen;
            laserRight2 = Laser;
            if (laserLeft2 < 38)
            {
                laserLeft2 = 38;
            }
            playerLeft2 = pc + 3;
            playerRight2 = pc + 10;
            playerTop2 = pr + 1;
            playerBottom2 = pr + 7;

            if (playerLeft2 <= laserRight2 && playerRight2 >= laserLeft2)
            {
                if (playerTop2 <= 39 && playerBottom2 >= 20)
                {
                    inSafeZone2 = 0;
                    if (playerLeft2 >= 60 && playerRight2 <= 75 && playerTop2 >= 28 && playerBottom2 < 40)
                    {
                        inSafeZone2 = 1;
                    }
                    if (inSafeZone2 == 0)
                    {
                        hitLaserMove = 1;
                    }
                }
            }
        }

        if (hitLaserMove == 1)
        {
            playerHealth -= 10;
            pc -= 5;
            if (pc < 1)
            {
                pc = 1;
            }
        }

        if (playerHealth <= 0)
        {
            playerLives--;
            if (playerLives <= 0)
            {
                system("cls");
                cout << "Game Over!\n";
                cout << "You Lost!\n";
                return 0;
            }
            pr = spawn_pr;
            pc = spawn_pc;
            playerHealth = playerMaxHealth;
            DragonLaserHitCooldown = 0;

            SnapCamera(pr, pc, scR, scC, disR, disC);
        }
    }
    return 0;
}