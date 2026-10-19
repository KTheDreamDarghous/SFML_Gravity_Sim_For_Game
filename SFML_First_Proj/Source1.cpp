#include <SFML/Graphics.hpp>
#include <iostream>

void onKeyPressedSource(
    const sf::Event::KeyPressed& keyPressed,
    sf::RenderWindow& window,
    sf::Shape*& activeEntity,
    double& y_velocity
    )
{
    std::cout << "I am in onKeyPressed func\n";
    if (keyPressed.scancode == sf::Keyboard::Scancode::Escape)
        window.close();
    if (keyPressed.scancode == sf::Keyboard::Scan::W)
    {
        std::cout << "the W key was pressed" << std::endl;
        std::cout << "scancode: " << static_cast<int>(keyPressed.scancode) << std::endl;
        std::cout << "code: " << static_cast<int>(keyPressed.code) << std::endl;
        std::cout << "control: " << keyPressed.control << std::endl;
        std::cout << "alt: " << keyPressed.alt << std::endl;
        std::cout << "shift: " << keyPressed.shift << std::endl;
        std::cout << "system: " << keyPressed.system << std::endl;
        std::cout << "description: " << sf::Keyboard::getDescription(keyPressed.scancode).toAnsiString() << std::endl;
        std::cout << "localize: " << static_cast<int>(sf::Keyboard::localize(keyPressed.scancode)) << std::endl;
        std::cout << "delocalize: " << static_cast<int>(sf::Keyboard::delocalize(keyPressed.code)) << std::endl;
        y_velocity -= 100;

    }
    if (keyPressed.scancode == sf::Keyboard::Scan::S)
    {
        std::cout << "the S key was pressed" << std::endl;
        std::cout << "scancode: " << static_cast<int>(keyPressed.scancode) << std::endl;
        std::cout << "code: " << static_cast<int>(keyPressed.code) << std::endl;
        std::cout << "control: " << keyPressed.control << std::endl;
        std::cout << "alt: " << keyPressed.alt << std::endl;
        std::cout << "shift: " << keyPressed.shift << std::endl;
        std::cout << "system: " << keyPressed.system << std::endl;
        std::cout << "description: " << sf::Keyboard::getDescription(keyPressed.scancode).toAnsiString() << std::endl;
        std::cout << "localize: " << static_cast<int>(sf::Keyboard::localize(keyPressed.scancode)) << std::endl;
        std::cout << "delocalize: " << static_cast<int>(sf::Keyboard::delocalize(keyPressed.code)) << std::endl;
        y_velocity += 100;

    }
    if (keyPressed.scancode == sf::Keyboard::Scan::D)
    {
        std::cout << "the D key was pressed" << std::endl;
        std::cout << "scancode: " << static_cast<int>(keyPressed.scancode) << std::endl;
        std::cout << "code: " << static_cast<int>(keyPressed.code) << std::endl;
        std::cout << "control: " << keyPressed.control << std::endl;
        std::cout << "alt: " << keyPressed.alt << std::endl;
        std::cout << "shift: " << keyPressed.shift << std::endl;
        std::cout << "system: " << keyPressed.system << std::endl;
        std::cout << "description: " << sf::Keyboard::getDescription(keyPressed.scancode).toAnsiString() << std::endl;
        std::cout << "localize: " << static_cast<int>(sf::Keyboard::localize(keyPressed.scancode)) << std::endl;
        std::cout << "delocalize: " << static_cast<int>(sf::Keyboard::delocalize(keyPressed.code)) << std::endl;
        if (activeEntity != nullptr)
        {
            float x = activeEntity->getPosition().x;
            float y = activeEntity->getPosition().y;
            std::cout << "--------\nThe active entity is moved from position: x:" << x << " ,y: " << y << std::endl;
            x = x + 25;
            activeEntity->setPosition({ x,y });
            std::cout << "to position: x:" << x << " ,y: " << y << std::endl << "--------" << std::endl;
        }
    }
}