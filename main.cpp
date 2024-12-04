#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

int main() {
    // Инициализация генератора случайных чисел
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Мотивационные предложения
    std::vector<std::string> quotes = {
        "Вы способны на большее, чем думаете.",
        "Каждый день — это новая возможность.",
        "Не бойтесь делать ошибки, они — ваши учителя.",
        "Успех — это сумма маленьких усилий.",
        "Сделайте сегодня то, что другие не хотят, завтра вы будете жить так, как другие не могут.",
        "Верьте в себя и все станет возможным.",
        "Ваши мечты не имеют срока годности. Действуйте сейчас.",
        "Вы — автор своей жизни. Не позволяйте никому другому писать сценарий."
    };

    // Создание окна
    sf::RenderWindow window(sf::VideoMode(800, 600), "INSPIRE - Motivational Quotes");

    // Установка шрифта
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) { // Убедитесь, что файл шрифта находится в той же папке
        return -1; // Ошибка загрузки шрифта
    }

    sf::Text text("", font, 30);
    text.setFillColor(sf::Color::White);
    text.setPosition(50, 250); // Позиция текста

    // Основной цикл программы
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            // Проверка на клик мыши
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    // Генерация случайного мотивационного предложения
                    int randomIndex = std::rand() % quotes.size();
                    text.setString(quotes[randomIndex]);
                }
            }
        }

        // Очистка окна
        window.clear(sf::Color::Black);
        window.draw(text); // Рисуем текст
        window.display(); // Отображаем содержимое окна
    }

    return 0;
}
