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
        static constexpr double EPSILON = std::numeric_limits<double>::epsilon();

        // Вспомогательный метод для сравнения double с погрешностью
        static bool areEqual(double expected, double actual, double epsilon = EPSILON)
        {
            return std::abs(expected - actual) < epsilon;
        }

    public:
 

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

        // 3. Тест конструктора с координатами
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

        // 18. Тест статического метода ToString
        TEST_METHOD(TestStaticToString)
        {
            Pentagon pentagon(2.0, 0.0, 0.618, 1.902, -1.618, 1.176, -1.618, -1.176, 0.618, -1.902);
            std::string result = Pentagon::ToString(pentagon);

            Assert::IsTrue(result.find("Pentagon") != std::string::npos);
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

        // 20. Тест оператора ввода >> (формат как в вашем коде)
        TEST_METHOD(TestInputStreamOperator)
        {
            Pentagon pentagon;
            std::string input = "(2, 0) (0.618, 1.902) (-1.618, 1.176) (-1.618, -1.176) (0.618, -1.902)";
            std::stringstream ss(input);

            ss >> pentagon;

            Assert::IsTrue(pentagon.getPerimeter() > 0);
        }

        // 21. Тест метода read()
        TEST_METHOD(TestReadMethod)
        {
            Pentagon pentagon;
            std::string input = "(2, 0) (0.618, 1.902) (-1.618, 1.176) (-1.618, -1.176) (0.618, -1.902)";
            std::stringstream ss(input);

            pentagon.read(ss);

            Assert::IsTrue(pentagon.getPerimeter() > 0);
        }

        // 22. Тест статического метода readFromStream
        TEST_METHOD(TestReadFromStream)
        {
            std::string input = "(2, 0) (0.618, 1.902) (-1.618, 1.176) (-1.618, -1.176) (0.618, -1.902)";
            std::stringstream ss(input);

            Pentagon pentagon = Pentagon::readFromStream(ss);

            Assert::IsTrue(pentagon.getPerimeter() > 0);
        }

        // 23. Тест оператора ввода >> без пробелов
        TEST_METHOD(TestInputStreamOperator_NoSpaces)
        {
            Pentagon pentagon;
            std::string input = "(2,0)(0.618,1.902)(-1.618,1.176)(-1.618,-1.176)(0.618,-1.902)";
            std::stringstream ss(input);

            ss >> pentagon;

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

            Assert::AreEqual(5, vertices.size(), 0.0);
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

            Assert::AreEqual(3, polygons.size(), 0.0);
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
    };
}