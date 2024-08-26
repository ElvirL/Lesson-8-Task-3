/*
Задание 3. Реализация программы управления окном рабочего стола
Что нужно сделать
Реализуйте симуляцию работы окна в визуальном интерфейсе пользователя.
Окно располагается на виртуальном экране монитора, размером 80 ? 50 точек. У окна есть несколько параметров, которые также 
задаются в пикселях: двумерные координаты левого верхнего угла и размеры, ширина и высота. Ширина и высота при этом не могут 
быть отрицательными, а координаты не могут выходить за область экрана.

Пользователь взаимодействует с программой с помощью команд:

• Команда move принимает вектор, на который надо сместить окно на экране. Сообщение с новыми координатами окна появляется на экране.
• Команда resize запрашивает из стандартного ввода новый размер окна. После изменения размера сообщение с новым размером 
выводится на экране.
• Команда display выводит текущее изображение монитора в консоль. 0 — это пиксель вне области окна, 1 — с окном.
• Команда close закрывает окно, выход из программы.

Советы и рекомендации
Сам экран монитора вы тоже можете реализовать с помощью класса.
*/

#include <iostream>

struct math_vector
{
    int x;
    int y;
};

class Monitor{
    int monitor[80][50] {};
};

class Window {
    int x = 0;
    int y = 0;
    int width = 10;
    int height = 10;

    bool check_correct_coordinates(int new_x, int new_y){
        if (new_x < 0 || new_y < 0){
            return false;
        }
        if (new_x + height >= 80 || new_y + width >=50){
            return false;
        }
        return true;
    }

    bool check_correct_size(int new_height, int new_width){
        if (new_height < 0 || new_width < 0){
            return false;
        } 
        if (new_height + x >=80 || new_width +y >=50){
            return false;
        }
        return true;
    }

    public:
    void move(math_vector vec){
        if (check_correct_coordinates(x + vec.x, y + vec.y)){
            x = x + vec.x;
            y = y + vec.y;
            std::cout << "New coordinates: (" << x << "," << y << ")" << std::endl;
        }
        else {
            std::cout << "Incorrect coordinates" << std::endl;
        }
    }

    void resize(){
        std::cout << "Enter new window sizes: " << std::endl;
        std::cout << "Height: ";
        int new_height;
        std::cin >> new_height;
        std::cout << "Width: ";
        int new_width;
        std::cin >> new_width;

        if (check_correct_size(new_height,new_width)){
            height = new_height;
            width = new_width;
            std::cout << "New size: height - " << height << ", width - " << width << std::endl;
        }
        else {
            std::cout << "Incorrect size" << std::endl;
        }
    }

    void display(){
        Monitor m;
        for (int i=0; i<80; ++i){
            for (int j=0; j<50; ++j){
                if (i >= x && i<x+height && j >= y && j < y+width){
                    std::cout << 1;
                }
                else {
                    std::cout << 0;
                }
            }
            std::cout << std::endl;
        }
    }
};

int main(){
    Window w;

    std::cout << "Enter the command: ";
    std::string command;
    std::cin >> command;

    while (command != "close"){
        if (command == "move"){
            int x,y;
            std::cout << "Enter offset coordinates x y: ";
            std::cin >> x >> y;
            math_vector vec;
            vec.x = x;
            vec.y = y;
            w.move(vec);
        }
        else if (command == "resize"){
            w.resize();
        }
        else if (command == "display"){
            w.display();
        }

        std::cout << "Enter the command: ";
        std::cin >> command;
    }
}