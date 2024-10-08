# Домашнее задание к занятию «Структурные шаблоны: Proxy, Decorator, Adapter»

### Цель задания

Выполнив это задание, вы научитесь применять паттерны «Декоратор» и «Заместитель» в программах.

### Подготовка к домашнему заданию
1. Для выполнения задания и прохождения курса понадобится компьютер с операционной системой Windows, macOS или Linux и установленной на нём Microsoft Visual Studio 2022 или любой другой IDE, готовой для разработки консольных программ на C++.
2. Аккаунт на [GitHub](https://github.com/). [Инструкция по регистрации на GitHub](https://github.com/netology-code/cppm-homeworks/tree/main/common/sign%20up).

### Инструкция по выполнению домашнего задания

[Инструкция дана по ссылке](https://github.com/netology-code/cppm-homeworks/blob/main/common/readme.md).

### [Задание 1](Decorator)

В программу рендеринга HTML из лекции (раздел про паттерн «Декоратор») добавьте новые классы для декорирования текста.
```
class Paragraph: ...

auto text_block = new Paragraph(new Text());
text_block->render("Hello world");

>>> <p>Hello world</p>
```

```
class Reversed: ...

auto text_block = new Reversed(new Text());
text_block->render("Hello world");

>>> dlrow olleH
```

```
class Link: ...

auto text_block = new Link(new Text());
text_block->render("netology.ru", "Hello world");

>>> <a href=netology.ru>Hello world</a>
```

Обратите внимание

1. Сигнатура метода `Link::render()` не совпадает с сигнатурой оригинального метода.
2. Для разворота строки используйте функцию `std::reverse` [cppreference](https://en.cppreference.com/w/cpp/algorithm/reverse).

------

### [Задание 2](VeryHeavyDatabase)

В дополнение к классам-заместителям `VeryHeavyDatabase`, реализованным на лекции, реализуйте класс
```
class OneShotDB : VeryHeavyDatabase {
  explicit OneShotDB (VeryHeavyDatabase* real_object, size_t shots=1) : ...
}
```
Он должен возвращать данные по ключу из реального объекта то количество раз, которое указано в конструкторе.
Исчерпав лимит получения данных, метод `GetData` всегда возвращает строку error.
Пример использования:
```
auto real_db = VeryHeavyDatabase();
auto limit_db = OneShotDB(std::addressof(real_db), 2);
std::cout << limit_db.GetData("key") << std::endl;
std::cout << limit_db.GetData("key") << std::endl;
std::cout << limit_db.GetData("key") << std::endl;

Output:
>>> value
>>> value
>>> error
```

------

### Правила приёма домашней работы

Прикрепите в личном кабинете ссылку на ваш репозиторий.

### Критерии оценки домашней работы

1. В личном кабинете прикреплена ссылка на репозиторий с кодом для заданий 1 и 2.
2. По ссылке содержится код, который компилируется и при запуске выполняет описанные в задании задачи.

