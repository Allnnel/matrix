## Отчет по заданию "matrix":

Проект разрабатывает библиотеку функций для работы с матрицами на языке программирования C. Он включает в себя реализацию основных операций с матрицами, таких как создание, очистка, сравнение, сложение, вычитание, умножение, транспонирование, вычисление определителя, алгебраических дополнений и нахождение обратной матрицы. Разработка проводится с соблюдением стандарта C11, стиля кодирования Google и принципов структурированного программирования. Также в проекте предусмотрено полное покрытие кода юнит-тестами с использованием библиотеки Check.

## Дополнительная информация о сборке проекта:

Цель all компилирует и архивирует библиотеку s21_matrix.a.

Цель test собирает и запускает тесты, используя собранную библиотеку.

Цель leaks проверяет утечки памяти при выполнении тестов.

Цель clean удаляет временные файлы и папки, созданные в процессе сборки и тестирования.

Цель style форматирует исходный код в соответствии со стилем Google и проверяет его на наличие ошибок с помощью cppcheck.

Цель gcov_report генерирует отчет о покрытии кода тестами с использованием gcov и lcov.

Команды make используются для запуска указанных целей: all, test, leaks, clean, style, gcov_report.
