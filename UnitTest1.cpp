#include <cassert>
#include <sstream>
#include <iostream>
#include "../task3/DoublyLinkedList.h"

using namespace containers;

/**
 * @brief Функция для тестирования конструкторов
 */
void testConstructors() {
    std::cout << "--- Тест конструкторов ---\n";

    // Конструктор по умолчанию
    DoublyLinkedList<int> list1;
    assert(list1.isEmpty() && "Конструктор по умолчанию: список должен быть пустым");
    assert(list1.getSize() == 0 && "Конструктор по умолчанию: размер должен быть 0");
    std::cout << "✓ Конструктор по умолчанию работает корректно\n";

    // Конструктор со списком инициализации
    DoublyLinkedList<int> list2 = { 1, 2, 3, 4, 5 };
    assert(list2.getSize() == 5 && "Список должен содержать 5 элементов");
    assert(list2[0] == 1 && "Первый элемент должен быть 1");
    assert(list2[4] == 5 && "Последний элемент должен быть 5");
    std::cout << "✓ Конструктор со списком инициализации работает корректно\n";

    // Конструктор копирования
    DoublyLinkedList<int> list3(list2);
    assert(list3.getSize() == list2.getSize() && "Размеры списков должны совпадать");
    assert(list3[2] == list2[2] && "Элементы должны совпадать");
    std::cout << "✓ Конструктор копирования работает корректно\n";

    // Конструктор перемещения
    DoublyLinkedList<int> list4(std::move(list3));
    assert(list4.getSize() == 5 && "Перемещённый список должен иметь размер 5");
    assert(list3.isEmpty() && "Исходный список должен быть пустым после перемещения");
    std::cout << "✓ Конструктор перемещения работает корректно\n";
}

/**
 * @brief Функция для тестирования операторов присваивания
 */
void testAssignmentOperators() {
    std::cout << "--- Тест операторов присваивания ---\n";

    DoublyLinkedList<int> list1 = { 10, 20, 30 };
    DoublyLinkedList<int> list2;

    // Оператор присваивания копированием
    list2 = list1;
    assert(list2.getSize() == 3 && "Размер должен быть 3");
    assert(list2[1] == 20 && "Элемент должен быть 20");
    std::cout << "✓ Оператор присваивания копированием работает корректно\n";

    // Самоприсваивание
    list1 = list1;
    assert(list1.getSize() == 3 && "Размер не должен измениться");
    std::cout << "✓ Самоприсваивание работает корректно\n";

    // Оператор присваивания перемещением
    DoublyLinkedList<int> list3;
    list3 = std::move(list2);
    assert(list3.getSize() == 3 && "Перемещённый список должен иметь размер 3");
    assert(list2.isEmpty() && "Исходный список должен быть пустым");
    std::cout << "✓ Оператор присваивания перемещением работает корректно\n";
}

/**
 * @brief Функция для тестирования вставки элементов
 */
void testInsertion() {
    std::cout << "--- Тест вставки элементов ---\n";

    DoublyLinkedList<int> list;

    // push_back
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    assert(list.getSize() == 3 && "Размер должен быть 3");
    assert(list[2] == 3 && "Последний элемент должен быть 3");
    std::cout << "✓ push_back работает корректно\n";

    // push_front
    list.push_front(0);
    assert(list[0] == 0 && "Первый элемент должен быть 0");
    assert(list.getSize() == 4 && "Размер должен быть 4");
    std::cout << "✓ push_front работает корректно\n";

    // insert
    list.insert(2, 99);
    assert(list[2] == 99 && "Вставленный элемент должен быть 99");
    assert(list.getSize() == 5 && "Размер должен быть 5");
    std::cout << "✓ insert работает корректно\n";

    // insert в начало
    list.insert(0, 100);
    assert(list[0] == 100 && "Первый элемент должен быть 100");
    std::cout << "✓ insert в начало работает корректно\n";

    // insert в конец
    list.insert(list.getSize(), 200);
    assert(list[list.getSize() - 1] == 200 && "Последний элемент должен быть 200");
    std::cout << "✓ insert в конец работает корректно\n";
}

/**
 * @brief Функция для тестирования удаления элементов
 */
void testDeletion() {
    std::cout << "--- Тест удаления элементов ---\n";

    DoublyLinkedList<int> list = { 1, 2, 3, 4, 5 };

    // pop_back
    list.pop_back();
    assert(list.getSize() == 4 && "Размер должен быть 4");
    assert(list[list.getSize() - 1] == 4 && "Последний элемент должен быть 4");
    std::cout << "✓ pop_back работает корректно\n";

    // pop_front
    list.pop_front();
    assert(list.getSize() == 3 && "Размер должен быть 3");
    assert(list[0] == 2 && "Первый элемент должен быть 2");
    std::cout << "✓ pop_front работает корректно\n";

    // erase
    list.erase(1);
    assert(list.getSize() == 2 && "Размер должен быть 2");
    assert(list[1] == 4 && "Элемент с индексом 1 должен быть 4");
    std::cout << "✓ erase работает корректно\n";

    // remove
    bool removed = list.remove(4);
    assert(removed && "Элемент должен быть найден и удалён");
    assert(list.getSize() == 1 && "Размер должен быть 1");
    std::cout << "✓ remove работает корректно\n";

    // Удаление до пустого списка
    list.pop_back();
    assert(list.isEmpty() && "Список должен быть пустым");
    std::cout << "✓ Удаление до пустого списка работает корректно\n";
}

/**
 * @brief Функция для тестирования поиска и модификации
 */
void testSearchAndModify() {
    std::cout << "--- Тест поиска и модификации ---\n";

    DoublyLinkedList<int> list = { 10, 20, 30, 20, 50 };

    // find
    int index = list.find(20);
    assert(index == 1 && "Первое вхождение 20 должно быть на индексе 1");
    index = list.find(100);
    assert(index == -1 && "Элемент 100 не должен быть найден");
    std::cout << "✓ find работает корректно\n";

    // modify
    list.modify(2, 99);
    assert(list[2] == 99 && "Элемент должен быть изменён на 99");
    std::cout << "✓ modify работает корректно\n";

    // operator[]
    list[0] = 55;
    assert(list[0] == 55 && "Элемент должен быть изменён на 55");
    std::cout << "✓ operator[] (неконстантный) работает корректно\n";

    const DoublyLinkedList<int>& constList = list;
    assert(constList[0] == 55 && "Константный доступ должен возвращать значение");
    std::cout << "✓ operator[] (константный) работает корректно\n";
}

/**
 * @brief Функция для тестирования операторов сдвига
 */
void testStreamOperators() {
    std::cout << "--- Тест операторов сдвига ---\n";

    DoublyLinkedList<int> list1 = { 1, 2, 3, 4, 5 };

    // Оператор вывода
    std::ostringstream oss;
    oss << list1;
    std::string expected = "[1 <-> 2 <-> 3 <-> 4 <-> 5]";
    assert(oss.str() == expected && "Вывод должен соответствовать ожидаемому формату");
    std::cout << "✓ operator<< работает корректно\n";

    // Оператор ввода
    DoublyLinkedList<int> list2;
    std::istringstream iss("10 20 30");
    iss >> list2;
    assert(list2.getSize() == 3 && "Размер должен быть 3");
    assert(list2[0] == 10 && "Первый элемент должен быть 10");
    assert(list2[2] == 30 && "Последний элемент должен быть 30");
    std::cout << "✓ operator>> работает корректно\n";
}

/**
 * @brief Функция для тестирования исключений
 */
void testExceptions() {
    std::cout << "--- Тест исключений ---\n";

    DoublyLinkedList<int> list;

    // pop_back из пустого списка
    try {
        list.pop_back();
        assert(false && "Должно быть выброшено исключение");
    }
    catch (const std::out_of_range&) {
        std::cout << "✓ pop_back выбрасывает исключение на пустом списке\n";
    }

    // pop_front из пустого списка
    try {
        list.pop_front();
        assert(false && "Должно быть выброшено исключение");
    }
    catch (const std::out_of_range&) {
        std::cout << "✓ pop_front выбрасывает исключение на пустом списке\n";
    }

    // operator[] с неверным индексом
    try {
        list[0];
        assert(false && "Должно быть выброшено исключение");
    }
    catch (const std::out_of_range&) {
        std::cout << "✓ operator[] выбрасывает исключение при неверном индексе\n";
    }

    // insert с неверным индексом
    try {
        list.insert(5, 10);
        assert(false && "Должно быть выброшено исключение");
    }
    catch (const std::out_of_range&) {
        std::cout << "✓ insert выбрасывает исключение при неверном индексе\n";
    }

    // erase с неверным индексом
    try {
        list.erase(0);
        assert(false && "Должно быть выброшено исключение");
    }
    catch (const std::out_of_range&) {
        std::cout << "✓ erase выбрасывает исключение при неверном индексе\n";
    }
}

/**
 * @brief Функция для тестирования двусвязности списка
 */
void testDoublyLinkage() {
    std::cout << "--- Тест двусвязности ---\n";

    DoublyLinkedList<int> list = { 1, 2, 3, 4, 5 };

    // Проверка прямого обхода
    Node<int>* current = list.getHead();
    int expected[] = { 1, 2, 3, 4, 5 };
    size_t i = 0;
    while (current != nullptr) {
        assert(current->data == expected[i] && "Прямой обход: неверное значение");
        current = current->next;
        ++i;
    }
    std::cout << "✓ Прямой обход работает корректно\n";

    // Проверка обратного обхода через индексы
    for (int j = static_cast<int>(list.getSize()) - 1; j >= 0; --j) {
        assert(list[j] == expected[j] && "Обратный обход: неверное значение");
    }
    std::cout << "✓ Обратный обход работает корректно\n";

    // Вставка в середину и проверка связей
    list.insert(2, 99);
    assert(list[1] == 2 && "Предыдущий элемент должен быть 2");
    assert(list[2] == 99 && "Вставленный элемент должен быть 99");
    assert(list[3] == 3 && "Следующий элемент должен быть 3");
    std::cout << "✓ Связи после вставки в середину корректны\n";

    // Удаление из середины и проверка связей
    list.erase(2);
    assert(list[1] == 2 && "Предыдущий элемент должен быть 2");
    assert(list[2] == 3 && "Следующий элемент должен быть 3");
    std::cout << "✓ Связи после удаления из середины корректны\n";
}

/**
 * @brief Функция для тестирования методов isEmpty и clear
 */
void testUtilityMethods() {
    std::cout << "--- Тест вспомогательных методов ---\n";

    DoublyLinkedList<int> list;
    assert(list.isEmpty() && "Новый список должен быть пустым");
    std::cout << "✓ isEmpty работает корректно на пустом списке\n";

    list.push_back(42);
    assert(!list.isEmpty() && "Список не должен быть пустым после добавления");
    std::cout << "✓ isEmpty работает корректно после добавления элемента\n";

    list.clear();
    assert(list.isEmpty() && "Список должен быть пустым после очистки");
    assert(list.getSize() == 0 && "Размер должен быть 0 после очистки");
    std::cout << "✓ clear работает корректно\n";

    // toString
    DoublyLinkedList<int> list2 = { 10, 20, 30 };
    std::string str = list2.ToString();
    assert(str == "[10 <-> 20 <-> 30]" && "ToString должен возвращать правильную строку");
    std::cout << "✓ ToString работает корректно\n";
}

/**
 * @brief Главная функция тестов
 * @return 0, если все тесты пройдены успешно
 */
int main() {
    std::cout << "========================================\n";
    std::cout << "  Тесты линейного двусвязного списка\n";
    std::cout << "========================================\n\n";

    testConstructors();
    std::cout << "\n";
    testAssignmentOperators();
    std::cout << "\n";
    testInsertion();
    std::cout << "\n";
    testDeletion();
    std::cout << "\n";
    testSearchAndModify();
    std::cout << "\n";
    testStreamOperators();
    std::cout << "\n";
    testExceptions();
    std::cout << "\n";
    testDoublyLinkage();
    std::cout << "\n";
    testUtilityMethods();

    std::cout << "\n========================================\n";
    std::cout << "  Все тесты пройдены успешно!\n";
    std::cout << "========================================\n";

    return 0;
}