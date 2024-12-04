#include <QApplication>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <QRandomGenerator>

// Мотивационные цитаты (добавьте больше!)
std::vector<std::string> quotes = {
    "Вы сильнее, чем вы думаете!",
    "Верьте в себя, и у вас всё получится!",
    "Каждый день — это новый шанс!",
    "Не сдавайтесь, даже если трудно!",
    "Вы способны на большее, чем вы себе представляете!",
    "Ваши усилия обязательно окупятся!",
    "У вас есть все, что нужно для успеха!",
    "Не бойтесь рисковать, это того стоит!",
    "Вы — удивительный человек, цените себя!",
    "Сегодняшние трудности — это завтрашние победы!"
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QWidget window;
    window.setWindowTitle("INSPIRE");

    QLabel* label = new QLabel("Нажмите кнопку для мотивации!");
    QPushButton* button = new QPushButton("Получить мотивацию!");

    QObject::connect(button, &QPushButton::clicked, [&]() {
        int randomIndex = QRandomGenerator::global()->bounded(quotes.size());
        label->setText(quotes[randomIndex]);
    });

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(button);
    layout->addWidget(label);
    window.setLayout(layout);

    window.show();
    return app.exec();
}
