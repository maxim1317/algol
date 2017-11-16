# Практикум по предмету Комбинаторика и Теория Графов

## Суть программы

Реализация класса [Graph](https://github.com/maxim1317/algol/blob/master/graph/headers/graph.h), который представляет собой ненаправленный граф.
А также, методы работы с ним - базовые алгоритмы в работе с графами:

- [Список пучков дуг](https://github.com/maxim1317/algol/blob/master/graph/headers/graph_main.hpp)
- [Поиск в глубину](https://github.com/maxim1317/algol/blob/master/graph/headers/graph_dfs.hpp)
- [Поиск в ширину](https://github.com/maxim1317/algol/blob/master/graph/headers/graph_bfs.hpp)
- [Алгоритм Беллмана-Форда](https://github.com/maxim1317/algol/blob/master/graph/headers/graph_belford.hpp)
- [Алгоритм Дейкстры](https://github.com/maxim1317/algol/blob/master/graph/headers/graph_dijkstra.hpp)

## Вывод

В программе реализовано [два способа вывода](https://github.com/maxim1317/algol/blob/master/graph/headers/graph_prints.hpp):
вывод массивов I-J, IJ, H, L, с цветным выводом ([цвета ascii](https://github.com/maxim1317/algol/blob/master/graph/headers/colors.hpp)), и вывод графов в [DOT файлы](https://github.com/maxim1317/algol/blob/master/graph/headers/graph_prints.hpp).

## Makefile

Также [работает](https://github.com/maxim1317/algol/blob/master/graph/Makefile) автоматическая сборка в UNIX системах при помощи GNU Make. 
Реализован конвеер: 

Исходник **->** Исполнительный файл **->** Конвертирование dot файл в png изображения **->** Вызов стандартного приложения для просмотра изображений

## Сборка

В целом, собирается простым

**clang++ -std=c++11 graph.cpp -o graph**

или, еще проще

**make**

## Иерархия исходных файлов

### /

- [graph.cpp](https://github.com/maxim1317/algol/blob/master/graph/graph.cpp) - main()
- [Makefile](https://github.com/maxim1317/algol/blob/master/graph/Makefile) - собственно, make файл

### /headers/ 

- [graph.h](https://github.com/maxim1317/algol/blob/master/graph/headers/graph.h) - основной заголовочный файл с прототипами функций и методов
- [graph_main.hpp](https://github.com/maxim1317/algol/blob/master/graph/headers/graph_main.hpp) - тело класса Graph с базовыми методами
- [graph_dfs.hpp](https://github.com/maxim1317/algol/blob/master/graph/headers/graph_dfs.hpp) - методы, реализующие поиск в глубину
- [graph_bfs.hpp](https://github.com/maxim1317/algol/blob/master/graph/headers/graph_bfs.hpp) - методы, реализующие поиск в ширино
- [graph_prints.hpp](https://github.com/maxim1317/algol/blob/master/graph/headers/graph_prints.hpp) - методы, касающиеся вывода
- [colors.hpp](https://github.com/maxim1317/algol/blob/master/graph/headers/colors.hpp) - функция для разукрашивания вывода в консоль

### /scripts/

Набор вспомогательных Bash скриптов, использующихся в make

- [dot2png.sh](https://github.com/maxim1317/algol/blob/master/graph/scripts/dot2png.sh)
- [viewpng.sh](https://github.com/maxim1317/algol/blob/master/graph/scripts/viewpng.sh)


