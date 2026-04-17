#include "../Task2/pentagon.h"
#include "../Task2/point.h"
#include "CppUnitTest.h"
#include <sstream>
#include <cmath>
#include <limits>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace geometry;

namespace Tests
{
    TEST_CLASS(PentagonTests)
    {
    private:
        // Константа для сравнения double с учётом погрешности
        static constexpr double EPSILON = std::numeric_limits<double>::epsilon() * 1000;

        // Вспомогательный метод для сравнения double с погрешностью
        static bool areEqual(double expected, double actual, double epsilon = EPSILON)
        {
            return std::abs(expected - actual) < epsilon;
        }

    public:
        // ==================== КОНСТРУКТОРЫ ====================

        // 1. Тест конструктора по умолчанию
        TEST_METHOD(TestDefaultConstructor)
        {
            Pentagon pentagon;
            Assert::IsTrue(true);
        }

        // 2. Тест конструктора с точками
        TEST_METHOD(TestConstructorWithPoints)
        {
            Point p1(2.0, 0.0);
            Point p2(0.618, 1.902);
            Point p3(-1.618, 1.176);
            Point p4(-1.618, -1.176);
            Point p5(0.618, -1.902);

            Pentagon pentagon(p1, p2, p3, p4, p5);

            Assert::IsTrue(pentagon.getPerimeter() > 0);
            Assert::IsTrue(pentagon.getArea() > 0);
            Assert::IsTrue(pentagon.getCircumradius() > 0);
        }

        // 3. Тест конструктора с координатами (const параметры)
        TEST_METHOD(TestConstructorWithCoordinates)
        {
            Pentagon pentagon(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);

            Assert::IsTrue(pentagon.getPerimeter() > 0);
            Assert::IsTrue(pentagon.getArea() > 0);
        }

        // 4. Тест конструктора копирования
        TEST_METHOD(TestCopyConstructor)
        {
            Pentagon original(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);
            Pentagon copy(original);

            Assert::IsTrue(areEqual(original.getPerimeter(), copy.getPerimeter()));
            Assert::IsTrue(areEqual(original.getArea(), copy.getArea()));
            Assert::IsTrue(areEqual(original.getCircumradius(), copy.getCircumradius()));
        }

        // 5. Тест конструктора перемещения
        TEST_METHOD(TestMoveConstructor)
        {
            Pentagon original(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);
            double originalPerimeter = original.getPerimeter();
            double originalArea = original.getArea();
            double originalRadius = original.getCircumradius();

            Pentagon moved(std::move(original));

            Assert::IsTrue(areEqual(originalPerimeter, moved.getPerimeter()));
            Assert::IsTrue(areEqual(originalArea, moved.getArea()));
            Assert::IsTrue(areEqual(originalRadius, moved.getCircumradius()));
        }

        // ==================== ОПЕРАТОРЫ ПРИСВАИВАНИЯ ====================

        // 6. Тест оператора присваивания (копирование)
        TEST_METHOD(TestAssignmentOperator)
        {
            Pentagon original(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);
            Pentagon assigned;

            assigned = original;

            Assert::IsTrue(areEqual(original.getPerimeter(), assigned.getPerimeter()));
            Assert::IsTrue(areEqual(original.getArea(), assigned.getArea()));
            Assert::IsTrue(areEqual(original.getCircumradius(), assigned.getCircumradius()));
        }

        // 7. Тест самоприсваивания
        TEST_METHOD(TestSelfAssignment)
        {
            Pentagon pentagon(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);
            double originalPerimeter = pentagon.getPerimeter();

            pentagon = pentagon;

            Assert::IsTrue(areEqual(originalPerimeter, pentagon.getPerimeter()));
        }

        // 8. Тест оператора перемещения
        TEST_METHOD(TestMoveAssignmentOperator)
        {
            Pentagon original(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);
            double originalPerimeter = original.getPerimeter();
            double originalArea = original.getArea();
            Pentagon assigned;

            assigned = std::move(original);

            Assert::IsTrue(areEqual(originalPerimeter, assigned.getPerimeter()));
            Assert::IsTrue(areEqual(originalArea, assigned.getArea()));
        }

        // 9. Тест цепочечного присваивания
        TEST_METHOD(TestChainedAssignment)
        {
            Pentagon pentagon1(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);
            Pentagon pentagon2, pentagon3;

            pentagon3 = pentagon2 = pentagon1;

            Assert::IsTrue(areEqual(pentagon1.getPerimeter(), pentagon2.getPerimeter()));
            Assert::IsTrue(areEqual(pentagon1.getPerimeter(), pentagon3.getPerimeter()));
        }

        // ==================== ОПЕРАТОРЫ СРАВНЕНИЯ ====================

        // 10. Тест оператора сравнения == (равные)
        TEST_METHOD(TestEqualityOperator_Equal)
        {
            Pentagon pentagon1(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);
            Pentagon pentagon2(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);

            Assert::IsTrue(pentagon1 == pentagon2);
        }

        // 11. Тест оператора сравнения == (разные)
        TEST_METHOD(TestEqualityOperator_Different)
        {
            Pentagon pentagon1(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);
            Pentagon pentagon2(3.0, 0.0, 0.927, 2.853, -2.427, 1.764, -2.427, -1.764, 0.927, -2.853);

            Assert::IsFalse(pentagon1 == pentagon2);
        }

        // 12. Тест оператора сравнения !=
        TEST_METHOD(TestInequalityOperator)
        {
            Pentagon pentagon1(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);
            Pentagon pentagon2(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);
            Pentagon pentagon3(3.0, 0.0, 0.927, 2.853, -2.427, 1.764, -2.427, -1.764, 0.927, -2.853);

            Assert::IsFalse(pentagon1 != pentagon2);
            Assert::IsTrue(pentagon1 != pentagon3);
        }

        // ==================== МЕТОДЫ ВЫЧИСЛЕНИЙ ====================

        // 13. Тест метода getPerimeter()
        TEST_METHOD(TestGetPerimeter)
        {
            Pentagon pentagon(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);
            double expected = 11.7558;
            Assert::IsTrue(areEqual(expected, pentagon.getPerimeter(), 0.01));
        }

        // 14. Тест метода getArea()
        TEST_METHOD(TestGetArea)
        {
            Pentagon pentagon(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);
            double expected = 9.5106;
            Assert::IsTrue(areEqual(expected, pentagon.getArea(), 0.01));
        }

        // 15. Тест метода getCircumradius()
        TEST_METHOD(TestGetCircumradius)
        {
            Pentagon pentagon1(1.0, 0.0, 0.309, 0.951, -0.809, 0.588, -0.809, -0.588, 0.309, -0.951);
            Pentagon pentagon2(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);

            Assert::IsTrue(areEqual(1.0, pentagon1.getCircumradius(), 0.01));
            Assert::IsTrue(areEqual(2.0, pentagon2.getCircumradius(), 0.01));
        }

        // 16. Тест зависимости площади от радиуса
        TEST_METHOD(TestAreaScaling)
        {
            Pentagon small(1.0, 0.0, 0.309, 0.951, -0.809, 0.588, -0.809, -0.588, 0.309, -0.951);
            Pentagon medium(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);
            Pentagon large(3.0, 0.0, 0.927, 2.853, -2.427, 1.764, -2.427, -1.764, 0.927, -2.853);

            Assert::IsTrue(medium.getArea() > small.getArea());
            Assert::IsTrue(large.getArea() > medium.getArea());
        }

        // ==================== МЕТОДЫ СЕРИАЛИЗАЦИИ ====================

        // 17. Тест метода ToString()
        TEST_METHOD(TestToString)
        {
            Pentagon pentagon(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);
            std::string result = pentagon.ToString();

            Assert::IsTrue(result.find("Pentagon") != std::string::npos);
            Assert::IsTrue(result.find("v1=") != std::string::npos);
            Assert::IsTrue(result.find("v2=") != std::string::npos);
            Assert::IsTrue(result.find("v3=") != std::string::npos);
            Assert::IsTrue(result.find("v4=") != std::string::npos);
            Assert::IsTrue(result.find("v5=") != std::string::npos);
        }

        // 18. Тест сериализации через оператор <<
        TEST_METHOD(TestSerializationViaOperator)
        {
            Pentagon pentagon(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);
            std::stringstream ss;
            ss << pentagon;

            std::string result = ss.str();
            Assert::IsTrue(result.find("Pentagon") != std::string::npos);
            Assert::IsTrue(result.find("v1=") != std::string::npos);
        }

        // ==================== ОПЕРАТОРЫ ВВОДА/ВЫВОДА ====================

        // 19. Тест оператора вывода <<
        TEST_METHOD(TestOutputStreamOperator)
        {
            Pentagon pentagon(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);
            std::stringstream ss;
            ss << pentagon;

            std::string result = ss.str();
            Assert::IsTrue(result.find("Pentagon") != std::string::npos);
        }

        // 20. Тест оператора ввода >> (формат (x, y) с пробелами)
        TEST_METHOD(TestInputStreamOperator_WithSpaces)
        {
            Pentagon pentagon;
            std::string input = "(2, 0) (0.618, 1.902) (-1.618, 1.176) (-1.618, -1.176) (0.618, -1.902)";
            std::stringstream ss(input);

            ss >> pentagon;

            Assert::IsTrue(pentagon.getPerimeter() > 0);
        }

        // 21. Тест оператора ввода >> (формат (x,y) без пробелов)
        TEST_METHOD(TestInputStreamOperator_NoSpaces)
        {
            Pentagon pentagon;
            std::string input = "(2,0)(0.618,1.902)(-1.618,1.176)(-1.618,-1.176)(0.618,-1.902)";
            std::stringstream ss(input);

            ss >> pentagon;

            Assert::IsTrue(pentagon.getPerimeter() > 0);
        }

        // 22. Тест метода read()
        TEST_METHOD(TestReadMethod)
        {
            Pentagon pentagon;
            std::string input = "(2, 0) (0.618, 1.902) (-1.618, 1.176) (-1.618, -1.176) (0.618, -1.902)";
            std::stringstream ss(input);

            pentagon.read(ss);

            Assert::IsTrue(pentagon.getPerimeter() > 0);
        }

        // 23. Тест статического метода readFromStream
        TEST_METHOD(TestReadFromStream)
        {
            std::string input = "(2, 0) (0.618, 1.902) (-1.618, 1.176) (-1.618, -1.176) (0.618, -1.902)";
            std::stringstream ss(input);

            Pentagon pentagon = Pentagon::readFromStream(ss);

            Assert::IsTrue(pentagon.getPerimeter() > 0);
        }

        // ==================== ОБРАБОТКА ОШИБОК ====================

        // 24. Тест на некорректный пятиугольник (выбрасывает исключение)
        TEST_METHOD(TestInvalidPentagonThrowsException)
        {
            auto func = []() {
                Pentagon invalid(0, 0, 2, 0, 2, 2, 0, 2, 1, 3);
                };

            Assert::ExpectException<std::invalid_argument>(func);
        }

        // 25. Тест метода getPerimeter с некорректным объектом
        TEST_METHOD(TestGetPerimeterWithInvalidObject)
        {
            Pentagon pentagon;
            Assert::IsTrue(areEqual(0.0, pentagon.getPerimeter()));
        }

        // 26. Тест метода getArea с некорректным объектом
        TEST_METHOD(TestGetAreaWithInvalidObject)
        {
            Pentagon pentagon;
            Assert::IsTrue(areEqual(0.0, pentagon.getArea()));
        }

        // 27. Тест метода getCircumradius с некорректным объектом
        TEST_METHOD(TestGetCircumradiusWithInvalidObject)
        {
            Pentagon pentagon;
            Assert::IsTrue(areEqual(0.0, pentagon.getCircumradius()));
        }

        // ==================== МЕТОД ПОЛУЧЕНИЯ ВЕРШИН ====================

        // 28. Тест метода getVertices()
        TEST_METHOD(TestGetVertices)
        {
            Point p1(2.0, 0.0);
            Point p2(0.618, 1.902);
            Point p3(-1.618, 1.176);
            Point p4(-1.618, -1.176);
            Point p5(0.618, -1.902);

            Pentagon pentagon(p1, p2, p3, p4, p5);
            std::vector<Point> vertices = pentagon.getVertices();

            Assert::AreEqual(5u, vertices.size(), DBL_EPSILON);
            Assert::IsTrue(p1 == vertices[0]);
            Assert::IsTrue(p2 == vertices[1]);
            Assert::IsTrue(p3 == vertices[2]);
            Assert::IsTrue(p4 == vertices[3]);
            Assert::IsTrue(p5 == vertices[4]);
        }

        // ==================== ПОЛИМОРФИЗМ ====================

        // 29. Тест полиморфизма через базовый класс
        TEST_METHOD(TestPolymorphism)
        {
            std::unique_ptr<Polygon> polygon = std::make_unique<Pentagon>(
                2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902
            );

            Assert::IsTrue(polygon->getPerimeter() > 0);
            Assert::IsTrue(polygon->getArea() > 0);
            Assert::IsTrue(polygon->getCircumradius() > 0);
        }

        // 30. Тест коллекции объектов базового класса
        TEST_METHOD(TestCollectionOfPolygons)
        {
            std::vector<std::unique_ptr<Polygon>> polygons;

            polygons.push_back(std::make_unique<Pentagon>(
                1.0, 0.0, 0.309, 0.951, -0.809, 0.588, -0.809, -0.588, 0.309, -0.951
            ));
            polygons.push_back(std::make_unique<Pentagon>(
                2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902
            ));
            polygons.push_back(std::make_unique<Pentagon>(
                3.0, 0.0, 0.927, 2.853, -2.427, 1.764, -2.427, -1.764, 0.927, -2.853
            ));

            Assert::AreEqual(3u, polygons.size(), DBL_EPSILON);
            Assert::IsTrue(polygons[1]->getPerimeter() > polygons[0]->getPerimeter());
            Assert::IsTrue(polygons[2]->getPerimeter() > polygons[1]->getPerimeter());
        }

        // ==================== ДОПОЛНИТЕЛЬНЫЕ ТЕСТЫ ====================

        // 31. Тест консистентности (повторные вызовы дают тот же результат)
        TEST_METHOD(TestConsistency)
        {
            Pentagon pentagon(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);

            double area1 = pentagon.getArea();
            double area2 = pentagon.getArea();
            double perimeter1 = pentagon.getPerimeter();
            double perimeter2 = pentagon.getPerimeter();
            double radius1 = pentagon.getCircumradius();
            double radius2 = pentagon.getCircumradius();

            Assert::IsTrue(areEqual(area1, area2));
            Assert::IsTrue(areEqual(perimeter1, perimeter2));
            Assert::IsTrue(areEqual(radius1, radius2));
        }

        // 32. Тест сравнения разных размеров
        TEST_METHOD(TestCompareDifferentSizes)
        {
            Pentagon small(1.0, 0.0, 0.309, 0.951, -0.809, 0.588, -0.809, -0.588, 0.309, -0.951);
            Pentagon large(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);

            Assert::IsTrue(large.getPerimeter() > small.getPerimeter());
            Assert::IsTrue(large.getArea() > small.getArea());
            Assert::IsTrue(large.getCircumradius() > small.getCircumradius());
        }

        // 33. Тест десериализации после сериализации
        TEST_METHOD(TestDeserializationAfterSerialization)
        {
            Pentagon original(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);

            // Сериализуем в строку через ToString()
            std::string serialized = original.ToString();

            // Для десериализации нужно прочитать из потока в формате (x, y)
            std::stringstream ss;
            for (const auto& v : original.getVertices()) {
                ss << v;
            }

            Pentagon deserialized;
            ss >> deserialized;

            Assert::IsTrue(areEqual(original.getPerimeter(), deserialized.getPerimeter()));
            Assert::IsTrue(areEqual(original.getArea(), deserialized.getArea()));
        }
    };
}

// ==================== ТЕСТЫ ДЛЯ КЛАССА POINT ====================

namespace Tests
{
    TEST_CLASS(PointTests)
    {
    public:
        // 1. Тест конструктора по умолчанию
        TEST_METHOD(TestDefaultConstructor)
        {
            Point p;
            Assert::AreEqual(0.0, p.getX());
            Assert::AreEqual(0.0, p.getY());
        }

        // 2. Тест конструктора с параметрами
        TEST_METHOD(TestParameterizedConstructor)
        {
            Point p(3.5, 7.2);
            Assert::AreEqual(3.5, p.getX());
            Assert::AreEqual(7.2, p.getY());
        }

        // 3. Тест конструктора копирования
        TEST_METHOD(TestCopyConstructor)
        {
            Point original(3.5, 7.2);
            Point copy(original);

            Assert::AreEqual(original.getX(), copy.getX());
            Assert::AreEqual(original.getY(), copy.getY());
        }

        // 4. Тест конструктора перемещения
        TEST_METHOD(TestMoveConstructor)
        {
            Point original(3.5, 7.2);
            double originalX = original.getX();
            double originalY = original.getY();

            Point moved(std::move(original));

            Assert::AreEqual(originalX, moved.getX());
            Assert::AreEqual(originalY, moved.getY());
        }

        // 5. Тест оператора присваивания (копирование)
        TEST_METHOD(TestAssignmentOperator)
        {
            Point original(3.5, 7.2);
            Point assigned;

            assigned = original;

            Assert::AreEqual(original.getX(), assigned.getX());
            Assert::AreEqual(original.getY(), assigned.getY());
        }

        // 6. Тест оператора присваивания (перемещение)
        TEST_METHOD(TestMoveAssignmentOperator)
        {
            Point original(3.5, 7.2);
            double originalX = original.getX();
            double originalY = original.getY();
            Point assigned;

            assigned = std::move(original);

            Assert::AreEqual(originalX, assigned.getX());
            Assert::AreEqual(originalY, assigned.getY());
        }

        // 7. Тест самоприсваивания
        TEST_METHOD(TestSelfAssignment)
        {
            Point p(3.5, 7.2);
            p = p;

            Assert::AreEqual(3.5, p.getX());
            Assert::AreEqual(7.2, p.getY());
        }

        // 8. Тест метода getX()
        TEST_METHOD(TestGetX)
        {
            Point p(4.5, 6.7);
            Assert::AreEqual(4.5, p.getX());
        }

        // 9. Тест метода getY()
        TEST_METHOD(TestGetY)
        {
            Point p(4.5, 6.7);
            Assert::AreEqual(6.7, p.getY());
        }

        // 10. Тест метода distanceTo()
        TEST_METHOD(TestDistanceTo)
        {
            Point p1(0, 0);
            Point p2(3, 4);
            Assert::AreEqual(5.0, p1.distanceTo(p2));
        }

        // 11. Тест оператора равенства == (равные точки)
        TEST_METHOD(TestEqualityOperator_EqualPoints)
        {
            Point p1(2.5, 3.5);
            Point p2(2.5, 3.5);
            Assert::IsTrue(p1 == p2);
        }

        // 12. Тест оператора равенства == (разные точки)
        TEST_METHOD(TestEqualityOperator_DifferentPoints)
        {
            Point p1(2.5, 3.5);
            Point p2(2.5, 4.0);
            Assert::IsFalse(p1 == p2);
        }

        // 13. Тест оператора неравенства !=
        TEST_METHOD(TestInequalityOperator)
        {
            Point p1(2.5, 3.5);
            Point p2(2.5, 3.5);
            Point p3(2.5, 4.0);

            Assert::IsFalse(p1 != p2);
            Assert::IsTrue(p1 != p3);
        }

        // 14. Тест оператора вывода <<
        TEST_METHOD(TestOutputStreamOperator)
        {
            Point p(3.14, 2.71);
            std::stringstream ss;
            ss << p;

            std::string result = ss.str();
            Assert::IsTrue(result.find("(") != std::string::npos);
            Assert::IsTrue(result.find(")") != std::string::npos);
            Assert::IsTrue(result.find("3.14") != std::string::npos);
            Assert::IsTrue(result.find("2.71") != std::string::npos);
        }

        // 15. Тест оператора ввода >> (формат (x, y))
        TEST_METHOD(TestInputStreamOperator_ValidFormat)
        {
            Point p;
            std::string input = "(15.5, 20.3)";
            std::stringstream ss(input);

            ss >> p;

            Assert::AreEqual(15.5, p.getX());
            Assert::AreEqual(20.3, p.getY());
        }

        // 16. Тест оператора ввода >> (формат (x,y) без пробелов)
        TEST_METHOD(TestInputStreamOperator_NoSpaces)
        {
            Point p;
            std::string input = "(15.5,20.3)";
            std::stringstream ss(input);

            ss >> p;

            Assert::AreEqual(15.5, p.getX());
            Assert::AreEqual(20.3, p.getY());
        }

        // 17. Тест оператора ввода >> с отрицательными числами
        TEST_METHOD(TestInputStreamOperator_NegativeValues)
        {
            Point p;
            std::string input = "(-7.5, -12.3)";
            std::stringstream ss(input);

            ss >> p;

            Assert::AreEqual(-7.5, p.getX());
            Assert::AreEqual(-12.3, p.getY());
        }

        // 18. Тест оператора ввода >> с пробелами
        TEST_METHOD(TestInputStreamOperator_WithSpaces)
        {
            Point p;
            std::string input = "(  10  ,   20  )";
            std::stringstream ss(input);

            ss >> p;

            Assert::AreEqual(10.0, p.getX());
            Assert::AreEqual(20.0, p.getY());
        }

        // 19. Тест цепочечного ввода
        TEST_METHOD(TestChainedInputStream)
        {
            Point p1, p2;
            std::string input = "(1.0,2.0)(3.0,4.0)";
            std::stringstream ss(input);

            ss >> p1 >> p2;

            Assert::AreEqual(1.0, p1.getX());
            Assert::AreEqual(2.0, p1.getY());
            Assert::AreEqual(3.0, p2.getX());
            Assert::AreEqual(4.0, p2.getY());
        }

        // 20. Тест оператора равенства с очень близкими числами (эпсилон)
        TEST_METHOD(TestEqualityOperator_VeryCloseNumbers)
        {
            Point p1(0.1 + 0.2, 0.3);
            Point p2(0.3, 0.3);
            Assert::IsTrue(p1 == p2);
        }
    };
}
