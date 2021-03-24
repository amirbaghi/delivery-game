#include <iostream>
#include "Headers/Game/Game.h"
#include "Headers/Render/Render.h"
#include "Headers/Utils.h"

Render::Render(GameComponent *parent) : GameComponent(parent)
{
}

Render::~Render()
{
}

void Render::initRender()
{
    Game *game = dynamic_cast<Game *>(parent_component);

    Field *field = game->getField();

    int width = field->getWidth();
    int height = field->getHeight();
    char tileChar = field->getCharacter();

    // Initializing the frame buffer with the ground tile
    std::vector<std::vector<char>> frameBuffer(width, std::vector<char>(height, tileChar));
    currentFrameBuffer = frameBuffer;

    Avatar *avatar = game->getAvatar();
    std::vector<Wall *> walls = game->getWalls();
    std::vector<Obstacle *> obstacles = game->getObstacles();
    std::vector<Goal *> goals = game->getGoals();

    // Setting the avatar
    currentFrameBuffer[avatar->getCurrentX() - 1][avatar->getCurrentY() - 1] = avatar->getCharacter();

    // Setting the walls
    for (auto &wall : walls)
    {
        currentFrameBuffer[wall->getX() - 1][wall->getY() - 1] = wall->getCharacter();
    }

    // Setting the goals
    for (auto &goal : goals)
    {
        currentFrameBuffer[goal->getX() - 1][goal->getY() - 1] = goal->getCharacter();
    }

    // Setting the Obstacles
    for (auto &obstacle : obstacles)
    {
        currentFrameBuffer[obstacle->getX() - 1][obstacle->getY() - 1] = obstacle->getCharacter();
    }

    // Setting the previous frame buffer as the current frame
    previousFrameBuffer = currentFrameBuffer;

    // Rendering the first frame
    system("setterm -cursor off");

    // Cleaning the console (as a new screen)
    std::cout << "\033[H\033[J";

    // Resizing the terminal window
    std::cout << "\e[8;30;70t";

    char avatarChar = avatar->getCharacter();
    char obsChar = obstacles.front()->getCharacter();
    char wallChar = walls.front()->getCharacter();
    char goalChar = goals.front()->getCharacter();

    isLogoFullyLit = true;

    printLogo();

    for (size_t i = 0; i < currentFrameBuffer.size(); i++)
    {
        for (size_t j = 0; j < currentFrameBuffer[i].size(); j++)
        {
            // Set the console color appropriately
            if (currentFrameBuffer[i][j] == avatarChar)
            {
                std::cout << avatar->getColor();
            }
            else if (currentFrameBuffer[i][j] == obsChar)
            {
                std::cout << obstacles.front()->getColor();
                // Check to see if it's in place, if so the color should be green
                for (auto &obs : obstacles)
                {
                    if (i + 1 == obs->getX() && j + 1 == obs->getY())
                    {
                        if (obs->getIsInPlace())
                        {
                            std::cout << BRIGHTGREEN;
                        }
                        break;
                    }
                }
            }
            else if (currentFrameBuffer[i][j] == wallChar)
            {
                std::cout << walls.front()->getColor();
            }
            else if (currentFrameBuffer[i][j] == goalChar)
            {
                std::cout << goals.front()->getColor();
            }

            std::cout << currentFrameBuffer[i][j];

            // Reset the color
            std::cout << RESET;
        }
        std::cout << "\n";
    }

    std::cout << "Use " << BRIGHTRED << "ARROW KEYS" << RESET << " to move, " << BRIGHTRED << "U" << RESET << " to undo a move, " BRIGHTRED << "Q" << RESET << " to exit.\n";
    std::cout << "Deliver each " << obstacles.front()->getColor() << obsChar << RESET << " to a " << goals.front()->getColor() << goalChar << RESET << " to win!";
}

void Render::printLogo()
{
    // If the logo should be lit completely
    if (isLogoFullyLit)
    {
        std::cout << BRIGHTYELLOW << "____     _ _    __                  _ \n"
                  << "|  _  \\   | (_)                    | |\n"
                  << "| | | |___| |___   _____ _ __ _   _| |\n"
                  << "| | | / _ \\ | \\ \\ / / _ \\ '__| | | | |\n"
                  << "| |/ /  __/ | |\\ V /  __/ |  | |_| |_|\n"
                  << "|___/ \\___|_|_| \\_/ \\___|_|   \\__, (_)\n"
                  << "                               __/ |  \n"
                  << "                              |___/   \n"
                  << RESET;
    }
    else
    {
        std::cout << RESET << "____     _ " << BRIGHTYELLOW << "_" << RESET << "    __                  _ \n"
                  << "|  _  \\   " << BRIGHTYELLOW << "| (_)" << RESET << "                    | |\n"
                  << "| | | |___" << BRIGHTYELLOW << "| |___   _____" << RESET << " _ __ _   _| |\n"
                  << "| | | / _ \\ " << BRIGHTYELLOW << "| \\ \\ / / _ \\" << RESET << " '__| | | | |\n"
                  << "| |/ /  __/ " << BRIGHTYELLOW << "| |\\ V /  __/" << RESET << " |  | |_| |_|\n"
                  << "|___/ \\___" << BRIGHTYELLOW << "|_|_| \\_/ \\___|" << RESET << "_|   \\__, (_)\n"
                  << "                               __/ |  \n"
                  << "                              |___/   \n"
                  << RESET;
    }
}

void Render::updateFrameBuffer()
{
    // Updating the current frame buffer
    Game *game = dynamic_cast<Game *>(parent_component);

    Field *field = game->getField();

    int width = field->getWidth();
    int height = field->getHeight();
    char tileChar = field->getCharacter();

    // Initializing the frame buffer with the ground tile
    std::vector<std::vector<char>> frameBuffer(width, std::vector<char>(height, tileChar));
    currentFrameBuffer = frameBuffer;

    Avatar *avatar = game->getAvatar();
    std::vector<Wall *> walls = game->getWalls();
    std::vector<Obstacle *> obstacles = game->getObstacles();
    std::vector<Goal *> goals = game->getGoals();

    // Setting the avatar
    currentFrameBuffer[avatar->getCurrentX() - 1][avatar->getCurrentY() - 1] = avatar->getCharacter();

    // Setting the walls
    for (auto &wall : walls)
    {
        currentFrameBuffer[wall->getX() - 1][wall->getY() - 1] = wall->getCharacter();
    }

    // Setting the goals
    for (auto &goal : goals)
    {
        currentFrameBuffer[goal->getX() - 1][goal->getY() - 1] = goal->getCharacter();
    }
    
    // Setting the Obstacles
    for (auto &obstacle : obstacles)
    {
        currentFrameBuffer[obstacle->getX() - 1][obstacle->getY() - 1] = obstacle->getCharacter();
    }

}

void Render::render(clock_t time)
{
    Game *game = dynamic_cast<Game *>(parent_component);

    char avatarChar = game->getAvatar()->getCharacter();
    char obsChar = game->getObstacles().front()->getCharacter();
    char wallChar = game->getWalls().front()->getCharacter();
    char goalChar = game->getGoals().front()->getCharacter();

    // See if the logo should blink (The logo blinks every 2 seconds)
    int diffTime = float(time - game->getCreationTime()) / CLOCKS_PER_SEC;
    if (diffTime % 2 == 0)
    {
        // Invert the Logo's Lighting Status
        isLogoFullyLit = !isLogoFullyLit;

        // Move the cursor to the top
        std::cout << "\033[" << 0 << ";" << 0 << "H";

        printLogo();
    }

    // Render the current frame using a double buffer technique
    for (size_t i = 0; i < currentFrameBuffer.size(); i++)
    {
        for (size_t j = 0; j < currentFrameBuffer[i].size(); j++)
        {
            // Only render the character if it's different than the previous frame
            if (currentFrameBuffer[i][j] != previousFrameBuffer[i][j])
            {
                std::cout << "\033[" << i + 1 + 8 << ";" << j + 1 << "H";

                // Set the console color appropriately
                if (currentFrameBuffer[i][j] == avatarChar)
                {
                    std::cout << game->getAvatar()->getColor();
                }
                else if (currentFrameBuffer[i][j] == obsChar)
                {
                    std::cout << game->getObstacles().front()->getColor();
                    // Check to see if it's in place, if so the color should be green
                    for (auto &obs : game->getObstacles())
                    {
                        if (i + 1 == obs->getX() && j + 1 == obs->getY())
                        {
                            if (obs->getIsInPlace())
                            {
                                std::cout << BRIGHTGREEN;
                            }
                            break;
                        }
                    }
                }
                else if (currentFrameBuffer[i][j] == wallChar)
                {
                    std::cout << game->getWalls().front()->getColor();
                }
                else if (currentFrameBuffer[i][j] == goalChar)
                {
                    std::cout << game->getGoals().front()->getColor();
                }

                std::cout << currentFrameBuffer[i][j];

                // Reset the color
                std::cout << RESET;
            }
        }
    }

    // Set previous buffer as the current buffer
    previousFrameBuffer = currentFrameBuffer;
}