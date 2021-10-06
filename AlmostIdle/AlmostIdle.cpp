#include "AlmostIdle.h"

static const float VIEW_HEIGHT = 1000.0f;
static const float ASPECT_RATIO = 16.0f / 10.0f;
static const float ZOOM = 1.5f;

int main()
{
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    sf::RenderWindow window(sf::VideoMode(1280, 800), "AlmostIdle");

    sf::View view(sf::Vector2f(310, 270), sf::Vector2f(VIEW_HEIGHT * ASPECT_RATIO / ZOOM, VIEW_HEIGHT / ZOOM));
    window.setView(view);

    ImGui::SFML::Init(window);

    sf::Font font;
    if (!font.loadFromFile("assets/ProggySquare.ttf")) {
        printf("Failed to load font file\n");
        return -1;
    }

    Scene scene(font);
    Room room(font);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock clock;
    double lag = 0.0;
    int frameCount = 0;
    while (window.isOpen())
    {
        auto elapsed = clock.restart();
        lag += elapsed.asMilliseconds();

        sf::Event evnt;
        while (window.pollEvent(evnt)) {
            ImGui::SFML::ProcessEvent(evnt);

            switch (evnt.type) {
            case sf::Event::Closed:
                window.close();
                break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        // Update
        while (lag >= MS_PER_UPDATE) {
            scene.Update();

            lag -= MS_PER_UPDATE;
        }        

        ImGui::SFML::Update(window, elapsed);
        
        // Render
        window.clear(sf::Color(128, 128, 128));
        // view.setCenter(player.GetPosition());
        // window.setView(view);

        room.Draw(window);
        scene.Draw(window, lag / MS_PER_UPDATE);

        ImGui::SFML::Render(window);

        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}